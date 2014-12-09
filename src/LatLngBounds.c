#include "LatLngBounds.h"

/** 
 * @mainpage Gaikai Code Example Overview
 *
 * \section Structures 
 *
 * typedef LatLngBounds_s LatLngBounds
 *
 * typedef LatLng_s LatLng
 *
 * \section Functions
 *
 * fn int latlngbounds_contains(LatLng * point, LatLngBounds * bounds) {
 *
 */

/**
 * Initializes an instance of <code>LatLngBounds *</code>. Uses a <code>LatLng *</code> for the southwest and northeast corners
 * of the bounds in order to create a rectangular box which is the bounds. <code>LatLng *</code> is used, so all positioning is in
 * degrees.
 *
 * @sa LatLng
 * @param ne LatLng * southwest coordinates
 * @param sw LatLng * northeast coordinates
 * @return retval instance of LatLngBounds *
 */
LatLngBounds * latlngbounds_init(LatLng * ne, LatLng * sw) {
    LatLngBounds * retval = (LatLngBounds *)malloc(sizeof(struct LatLngBounds_s));
    retval->ne = ne;
    retval->sw = sw;
    return retval;
}

/**
 * Frees memory from all connected objects of the given <code>LatLngBounds *</code> instance
 *
 * @param tofree LatLngBounds * instance to free
 */
void latlngbounds_free(LatLngBounds * tofree) {
    latlng_free(tofree->sw);
    latlng_free(tofree->ne);
    free(tofree);
}

/**
 * Function that checks if a <code>LatLng</code> is withing the <code>LatLngBounds</code> instance. 
 *
 * @param point LatLng * pointer of the location to be checked.
 * @param bounds LatLngBounds * pointer for the bounds to check within.
 * @return 1 for true or 0 for false
 */
int latlngbounds_contains(LatLng * point, LatLngBounds * bounds) {
    int retval = 1;

    if (point->lat > 0) {
        if (point->lat >= bounds->ne->lat) {
            return 0;
        }
    }
    else {
        if (point->lat <= bounds->sw->lat) {
            return 0;
        }
    }

    if (point->lng > 0) {
        if (point->lng >= bounds->ne->lng) {
            return 0;
        }
    }
    else {
        if (point->lng <= bounds->sw->lng) {
            return 0;
        }
    }

    return retval;
}
