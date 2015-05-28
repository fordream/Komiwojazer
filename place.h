#ifndef PLACE_H
#define PLACE_H
#include <coordinates.h>
#include <QString>
#include <marble/GeoDataPlacemark.h>

class Place
{
public:
    Place();
    Place(Coordinates coor, QString name);
    Place(Marble::GeoDataPlacemark);
    Coordinates getCoordinates();
    QString getName();

private:
    Coordinates coordinates;
    QString name;
};

#endif // PLACE_H
