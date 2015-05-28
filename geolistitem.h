#ifndef GEOLISTITEM_H
#define GEOLISTITEM_H
#include <QListWidgetItem>
#include <place.h>

class GeoListItem : public QListWidgetItem
{
public:
    GeoListItem(QString);
    ~GeoListItem();
    GeoListItem(Place* place);
    Place *getPlace();

private:
    Place* place;
};

#endif // GEOLISTITEM_H
