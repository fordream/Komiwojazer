#include "geolistitem.h"

GeoListItem::GeoListItem(QString text) : QListWidgetItem(text)
{
    this->place=nullptr;
}

GeoListItem::GeoListItem(Place *place) :
    QListWidgetItem(place->getName()), place(place)
{
}

Place* GeoListItem::getPlace()
{
    return this->place;
}

GeoListItem::~GeoListItem()
{
    delete this->place;
}
