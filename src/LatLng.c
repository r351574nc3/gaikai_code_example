#include "LatLng.h"

/**
 * @file 
 * @brief Implementation of functions that support the LatLng datastructure
 */

/*!
 * Constructs a <code>LatLng *</code> instance. If <code>no_wrap</code> is on, it ignores the basic <code>LatLng</code> behavior.
 *
 * \param lat latitude to assign
 * \param lng longitude to assign
 * \param no_wrap ignore preset boundaries for latitude and longitude
 * \return LatLng * instance
 */
LatLng * latlng_init(int lat, int lng, int no_wrap) {
    LatLng * retval = (LatLng *) malloc(sizeof(struct LatLng_s));

    retval->lat = no_wrap ? lat : latlng_clamp(lat, LAT_BOUND);
    retval->lng = no_wrap ? lng : latlng_wrap(lng, LNG_BOUND);
    return retval;
}

/*!
 * Frees up the LatLng * instance
 * 
 * \param tofree LatLng * instance to free.
 */
void latlng_free(LatLng * tofree) {
    free(tofree);
}

/*!
 * Return the coordinate wrapped given the provided bounds
 * 
 * \param coord number coordinate to wrap
 * \param bound boundary used to calculate the wrapped coordinate
 * \return newly wrap coordinates
 */
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

/*!
 * Returns the coordinate clamped given the provided bounds
 *
 * \param coord number coordinate to wrap
 * \param bound boundary used to calculate the clamped coordinate
 * \return newly clamped coordinates
 */
int latlng_clamp(int coord, int bound) {
    if (coord > 0 && coord > bound) {
        return bound;
    }
    if (coord < 0 && coord < (-1 * bound)) {
        return (-1 * bound);
    }
    return coord;
}

