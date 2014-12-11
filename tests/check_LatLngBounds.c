#include <check.h>
#include <stdio.h>
#include "LatLngBounds.h"

START_TEST(lng_in_bounds)
{
    LatLng * bounds_ne = latlng_init(50, 50, 0);
    LatLng * bounds_sw = latlng_init(-50, -50, 0);
    LatLng * point = latlng_init(10, 30, 0);
    LatLngBounds * bounds = latlngbounds_init(bounds_ne, bounds_sw);

    ck_assert_int_eq(latlngbounds_contains(point, bounds), 1);


    latlngbounds_free(bounds);
    latlng_free(point);
}
END_TEST

START_TEST(lat_in_bounds)
{
    LatLng * bounds_ne = latlng_init(50, 50, 0);
    LatLng * bounds_sw = latlng_init(-50, -50, 0);
    LatLng * point = latlng_init(10, 30, 0);
    LatLngBounds * bounds = latlngbounds_init(bounds_ne, bounds_sw);

    ck_assert_int_eq(latlngbounds_contains(point, bounds), 1);

    latlngbounds_free(bounds);
    latlng_free(point);
}
END_TEST

START_TEST(lat_out_bounds)
{
    LatLng * bounds_ne = latlng_init(50, 50, 0);
    LatLng * bounds_sw = latlng_init(-50, -50, 0);
    LatLng * point = latlng_init(60, 10, 0);
    LatLngBounds * bounds = latlngbounds_init(bounds_ne, bounds_sw);

    ck_assert_int_eq(latlngbounds_contains(point, bounds), 0);

    latlngbounds_free(bounds);
    latlng_free(point);
}
END_TEST

START_TEST(lat_out_bounds_clamp)
{
    LatLng * bounds_ne = latlng_init(50, 50, 0);
    LatLng * bounds_sw = latlng_init(-50, -50, 0);
    LatLng * point = latlng_init(90, 50, 0);
    LatLngBounds * bounds = latlngbounds_init(bounds_ne, bounds_sw);

    ck_assert_int_eq(latlngbounds_contains(point, bounds), 0);

    latlngbounds_free(bounds);
    latlng_free(point);
}
END_TEST

START_TEST(lat_out_bounds_clamp2)
{
    LatLng * bounds_ne = latlng_init(90, 60, 0);
    LatLng * bounds_sw = latlng_init(-90, -60, 0);
    LatLng * point = latlng_init(100, 50, 0);
    LatLngBounds * bounds = latlngbounds_init(bounds_ne, bounds_sw);

    ck_assert_int_eq(latlngbounds_contains(point, bounds), 1);

    latlngbounds_free(bounds);
    latlng_free(point);
}
END_TEST

START_TEST(lat_out_bounds_nowrap)
{
    LatLng * bounds_ne = latlng_init(500, 500, 1);
    LatLng * bounds_sw = latlng_init(-500, -500, 1);
    LatLng * point = latlng_init(300, 20, 1);
    LatLngBounds * bounds = latlngbounds_init(bounds_ne, bounds_sw);

    ck_assert_int_eq(latlngbounds_contains(point, bounds), 1);

    latlngbounds_free(bounds);
    latlng_free(point);
}
END_TEST


START_TEST(lng_out_bounds)
{
    LatLng * bounds_ne = latlng_init(50, 50, 0);
    LatLng * bounds_sw = latlng_init(-50, -50, 0);
    LatLng * point = latlng_init(10, 60, 0);
    LatLngBounds * bounds = latlngbounds_init(bounds_ne, bounds_sw);

    ck_assert_int_eq(latlngbounds_contains(point, bounds), 0);

    latlngbounds_free(bounds);
    latlng_free(point);
}
END_TEST

START_TEST(lng_out_bounds_wrap)
{
    LatLng * bounds_ne = latlng_init(50, 50, 0);
    LatLng * bounds_sw = latlng_init(-50, -50, 0);
    LatLng * point = latlng_init(10, 200, 0);
    LatLngBounds * bounds = latlngbounds_init(bounds_ne, bounds_sw);

    ck_assert_int_eq(latlngbounds_contains(point, bounds), 0);

    latlngbounds_free(bounds);
    latlng_free(point);
}
END_TEST

START_TEST(lng_out_bounds2)
{
    LatLng * bounds_ne = latlng_init(50, 50, 0);
    LatLng * bounds_sw = latlng_init(-50, -50, 0);
    LatLng * point = latlng_init(10, 1000, 0);
    LatLngBounds * bounds = latlngbounds_init(bounds_ne, bounds_sw);

    ck_assert_int_eq(latlngbounds_contains(point, bounds), 1);

    latlngbounds_free(bounds);
    latlng_free(point);
}
END_TEST

START_TEST(lng_out_bounds_nowrap)
{
    LatLng * bounds_ne = latlng_init(500, 500, 1);
    LatLng * bounds_sw = latlng_init(-500, -500, 1);
    LatLng * point = latlng_init(10, 300, 1);
    LatLngBounds * bounds = latlngbounds_init(bounds_ne, bounds_sw);

    ck_assert_int_eq(latlngbounds_contains(point, bounds), 1);

    latlngbounds_free(bounds);
    latlng_free(point);
}
END_TEST

Suite * latlng_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("LatLngBounds");

    /* Core test case */
    tc_core = tcase_create("Core");
    
    /* tcase_add_test(tc_core, lat_in_bounds);
    tcase_add_test(tc_core, lat_out_bounds);
    tcase_add_test(tc_core, lat_out_bounds_nowrap);
    tcase_add_test(tc_core, lat_out_bounds_clamp);
    tcase_add_test(tc_core, lat_out_bounds_clamp2);
    tcase_add_test(tc_core, lng_in_bounds);
    tcase_add_test(tc_core, lng_out_bounds);
    tcase_add_test(tc_core, lng_out_bounds2);*/
    tcase_add_test(tc_core, lng_out_bounds_wrap);
    
    // tcase_add_test(tc_core, lng_out_bounds_nowrap);
    suite_add_tcase(s, tc_core);
    
    return s;
}
 	
int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = latlng_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
