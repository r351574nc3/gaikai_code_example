#include "LatLng.h"


LatLng * latlng_init(int lat, int lng, int no_wrap) {
    LatLng * retval = (LatLng *) malloc(sizeof(LatLng));

    retval->lat = no_wrap ? lat : latlng_clamp(lat, LAT_BOUND);
    retval->lng = no_wrap ? lng : latlng_wrap(lng, LNG_BOUND);
    return retval;
}

void latlng_free(LatLng * tofree) {
    free(tofree);
}

int latlng_wrap(int coord, int bound) {
    if (coord > 0 && coord > bound) {
        int interval = coord - bound;
        return (-1 * bound) + interval;
    }
    if (coord < 0 && coord < bound) {
        int interval = (coord - bound) * -1;
        return (-1 * bound) - interval;
    }

    return coord;
}

int latlng_clamp(int coord, int bound) {
    if (coord > 0 && coord > bound) {
        return bound;
    }
    if (coord < 0 && coord < (-1 * bound)) {
        return (-1 * bound);
    }
    return coord;
}

int latlng_lat(LatLng * latlng);

int latlng_lng(LatLng * latlng);

int latlng_equals(LatLng * source, LatLng * other);

