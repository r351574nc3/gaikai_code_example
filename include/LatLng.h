#include <stdlib.h>

#define LAT_BOUND 90
#define LNG_BOUND 180


struct LatLng_s {
    int lat;
    int lng;
};
typedef struct LatLng_s LatLng;

LatLng * latlng_init(int, int, int);

void latlng_free(LatLng *);

int latlng_wrap(int, int);

int latlng_clamp(int, int);

int latlng_lat(LatLng *);

int latlng_lng(LatLng *);

int latlng_equals(LatLng *, LatLng *);
