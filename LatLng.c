#include "LatLng.h"

LatLng * latlng_init(int lat, int lng, int no_wrap);

int latlng_lat(LatLng * latlng);

int latlng_lng(LatLng * latlng);

int latlng_equals(LatLng * source, LatLng * other);

