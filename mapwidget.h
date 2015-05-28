#ifndef MAPWIDGET_H
#define MAPWIDGET_H
#include <marble/MarbleWidget.h>
#include <marble/MarbleMap.h>
#include <marble/MarbleModel.h>
#include <marble/SearchRunnerManager.h>
#include <marble/GeoDataPlacemark.h>
#include <marble/ReverseGeocodingRunnerManager.h>
#include <marble/GeoPainter.h>
#include <QMouseEvent>
#include <coordinates.h>
#include <marble/RouteRequest.h>
#include <marble/RoutingManager.h>
#include <marble/Route.h>
#include <marble/RoutingModel.h>
#include <map>

using namespace Marble;

class MapWidget : public MarbleWidget
{
    Q_OBJECT

public:
    MapWidget();
    QVector<Marble::GeoDataPlacemark*> findPlaceByName(QString name);
    QString findPlaceByCoordinates(double lon, double lat);
    void drawLine();
    void drawRoute(Route route);
    Route findRoute(Coordinates from, Coordinates to);
    void mouseDoubleClickEvent ( QMouseEvent * event );
    void setFocusedMarker(double lon, double lat);
    void setFocusedMarker(Coordinates marker);
    enum MarkerType {Normal, Selected};
    void center(Coordinates);

private:
    Marble::MarbleModel marbleModel;
    MarbleMap map;
    virtual void customPaint(Marble::GeoPainter* painter);
    std::map<Coordinates, MarkerType> markers;
    QImage getMarkerIcon(MarkerType type);
    Coordinates focusedMarker;

public slots:
    void putMarker(qreal lon, qreal lat, MarkerType type=Normal);
    void putMarker(Coordinates marker, MarkerType type=Normal);
    void deleteMarker(Coordinates marker);

signals:
    void placeSelected(double, double, QString);


};

#endif // MAPWIDGET_H
