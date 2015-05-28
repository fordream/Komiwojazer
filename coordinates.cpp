#include "coordinates.h"

Coordinates::Coordinates()
{

}

Coordinates::Coordinates(double lon, double lat): lon(lon), lat(lat)
{

}

Coordinates::Coordinates(Marble::GeoDataCoordinates c)
{
    this->lon=c.longitude();
    this->lat=c.latitude();
}

double Coordinates::getLon() const
{
    return this->lon;
}

double Coordinates::getLat() const
{
    return this->lat;
}

bool Coordinates::operator < (const Coordinates& that) const
{
    if(that.lat>this->lat)
    {
        return true;
    }
    else
    {
        if(that.lat<this->lat)
        {
            return false;
        }
        return that.lon>this->lon;
    }
}
