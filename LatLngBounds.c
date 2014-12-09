#include "LatLngBounds.h"


LatLngBounds * latlngbounds_init(LatLng * ne, LatLng * sw) {
    LatLngBounds * retval = (LatLngBounds *)malloc(sizeof(LatLngBounds));
    return retval;
}

void latlngbounds_free(LatLngBounds * tofree) {
    latlng_free(tofree->sw);
    latlng_free(tofree->ne);
    free(tofree);
}

int latlngbounds_contains(LatLng * point, LatLngBounds * bounds) {
    int retval = 1;
    if (point->lat > 0) {
        if (point->lat >= bounds->ne->lat) {
            return false;
        }
    }
    else {
        if (point->lat <= bounds->sw->lat) {
            return false;
        }
    }

    if (point->lng > 0) {
        if (point->lng >= bounds->ne->lng) {
            return false;
        }
    }
    else {
        if (point->lng <= bounds->sw->lng) {
            return false;
        }
    }
    return retval;
}
