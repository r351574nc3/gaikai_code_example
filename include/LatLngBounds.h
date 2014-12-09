#include <stdlib.h>
#include "LatLng.h"

struct LatLngBounds_s {
    LatLng * ne;
    LatLng * sw;
};
typedef struct LatLngBounds_s LatLngBounds;

/*!
 * Initializes an instance of <code>LatLngBounds *</code>. Uses a <code>LatLng *</code> for the southwest and northeast corners
 * of the bounds in order to create a rectangular box which is the bounds. <code>LatLng *</code> is used, so all positioning is in
 * degrees.
 *
 * \sa LatLng
 * \param LatLng * southwest coordinates
 * \param LatLng * northeast coordinates
 * \param instance of LatLngBounds *
 */
LatLngBounds * latlngbounds_init(LatLng *, LatLng *);

/*!
 * Function that checks if a <code>LatLng</code> is withing the <code>LatLngBounds</code> instance. 
 *
 * \param LatLng * pointer of the location to be checked.
 * \param LatLngBounds * pointer for the bounds to check within.
 * \return 1 for true or 0 for false
 */
int latlngbounds_contains(LatLng *, LatLngBounds *);

/*!
 * Frees memory from all connected objects of the given <code>LatLngBounds *</code> instance
 *
 * \param LatLngBounds * instance to free
 */
void latlngbounds_free(LatLngBounds *);
