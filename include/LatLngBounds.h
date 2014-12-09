#include <stdlib.h>
#include "LatLng.h"

#ifndef _LATLNGBOUNDS_H_
#define _LATLNGBOUNDS_H_

/*!
 * Bounds structure for latitude and longitude coordinates. It's made up of a northeast and southwest point that represent
 * a diagonal of a rectangle.
 */
struct LatLngBounds_s {
    //! northeast point
    LatLng * ne;
    
    //! soutwest point
    LatLng * sw;
};

/*!
 * For standardization of a simple type
 */
typedef struct LatLngBounds_s LatLngBounds;

/**
 * Initializes an instance of <code>LatLngBounds *</code>. Uses a <code>LatLng *</code> for the southwest and northeast corners
 * of the bounds in order to create a rectangular box which is the bounds. <code>LatLng *</code> is used, so all positioning is in
 * degrees.
 *
 * @sa LatLng
 * @param ne LatLng * northeast coordinates
 * @param sw LatLng * southwest coordinates
 * @retval instance of LatLngBounds *
 */
LatLngBounds * latlngbounds_init(LatLng *, LatLng *);

/**
 * Function that checks if a <code>LatLng</code> is withing the <code>LatLngBounds</code> instance. 
 *
 * @param point LatLng * pointer of the location to be checked.
 * @param bounds LatLngBounds * pointer for the bounds to check within.
 * @return 1 for true or 0 for false
 */
int latlngbounds_contains(LatLng *, LatLngBounds *);

/**
 * Frees memory from all connected objects of the given <code>LatLngBounds *</code> instance
 *
 * @param tofree LatLngBounds * instance to free
 */
void latlngbounds_free(LatLngBounds *);

#endif
