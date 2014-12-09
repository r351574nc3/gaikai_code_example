

struct LatLng_s {
    int lat;
    int lng;
};
typedef struct LatLng_s LatLng;

LatLng * latlng_init(int, int, int);

int latlng_lat(LatLng *);

int latlng_lng(LatLng *);

int latlng_equals(LatLng *, LatLng *);
