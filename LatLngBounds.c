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

int latlngbounds_contains(LatLng * point, LatLngBounds * LatLngBounds) {
    return 0;
}
