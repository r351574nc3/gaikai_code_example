#include <stdlib.h>

#ifndef _LATLNG_H_
#define _LATLNG_H_

#define LAT_BOUND 90
#define LNG_BOUND 180


/*!
 * Data structure for holding latitude and longitude coordinates.
 *
 * Taken from Google:
 *
 * A LatLng is a point in geographical coordinates: latitude and longitude.
 * Latitude ranges between -90 and 90 degrees, inclusive. Values above or 
 * below this range will be clamped to the range [-90, 90]. This means that 
 * if the value specified is less than -90, it will be set to -90. And if the 
 * value is greater than 90, it will be set to 90.
 * Longitude ranges between -180 and 180 degrees, inclusive. Values above or 
 * below this range will be wrapped so that they fall within the range. For 
 * example, a value of -190 will be converted to 170. A value of 190 will be 
 * converted to -170. This reflects the fact that longitudes wrap around the 
 * globe.

 * Although the default map projection associates longitude with the 
 * x-coordinate of the map, and latitude with the y-coordinate, the latitude 
 * coordinate is always written first, followed by the longitude.
 * Notice that you cannot modify the coordinates of a LatLng. If you want to 
 * compute another point, you have to create a new one.
 */
struct LatLng_s {
    //! Latitude 
    int lat;

    //! Longitude
    int lng;
};
                                                
/*!
 * For standardization of a simple type.
 */
typedef struct LatLng_s LatLng;

/*!
 * Constructs a <code>LatLng *</code> instance. If <code>no_wrap</code> is on, it ignores the basic <code>LatLng</code> behavior.
 *
 * \param latitude to assign
 * \param longitude to assign
 * \param no_wrap ignore preset boundaries for latitude and longitude
 * \return LatLng * instance
 */
LatLng * latlng_init(int, int, int);

/*!
 * Frees up the LatLng * instance
 * 
 * \param LatLng * instance to free.
 */
void latlng_free(LatLng *);

/*!
 * Return the coordinate wrapped given the provided bounds
 * 
 * \param coord number coordinate to wrap
 * \param bounds boundary used to calculate the wrapped coordinate
 * \return newly wrap coordinates
 */
int latlng_wrap(int, int);

/*!
 * Returns the coordinate clamped given the provided bounds
 *
 * \param coord number coordinate to wrap
 * \param bounds boundary used to calculate the clamped coordinate
 * \return newly clamped coordinates
 */
int latlng_clamp(int, int);
#endif
