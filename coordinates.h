#ifndef COORDINATES_H
#define COORDINATES_H
#include <marble/GeoDataCoordinates.h>

class Coordinates
{
public:
    Coordinates();
    Coordinates(double lon, double lat);
    Coordinates(Marble::GeoDataCoordinates);
    double getLon() const;
    double getLat() const;
    bool operator < (const Coordinates& that) const;

private:
    double lon;
    double lat;
};

#endif // Coordinates_H
