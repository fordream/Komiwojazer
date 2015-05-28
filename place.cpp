#include "place.h"

Place::Place()
{
}

Place::Place(Coordinates coor, QString name): coordinates(coor), name(name)
{

}

Place::Place(Marble::GeoDataPlacemark place)
{
    this->name = place.name();
    this->coordinates = place.coordinate();
}

Coordinates Place::getCoordinates()
{
    return this->coordinates;
}

QString Place::getName()
{
    return this->name;
}
