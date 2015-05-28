#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mapwidget.h>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QVector>
#include <geolistitem.h>
#include <qcombobox.h>
#include <coordinates.h>
#include <place.h>
#include <graph.h>
#include <komiwojazerinterface.h>
#include <marble/Route.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MapWidget map;
    QPushButton searchButton;
    QLineEdit searchInput;
    QListWidget suggestionsList;
    QPushButton addPlaceButton;
    QListWidget placesList;
    QPushButton deleteButton;
    QPushButton calculateButton;
    QComboBox methodsBox;
    QPushButton hideList;
    QPushButton showList;
    void prepareGUI();
    Place *selectedPlace;
    void selectPlace(Place *p);
    bool checkIfItemAdded(QString text);
    Graph makeGraph();

public slots:
    void placeSelected(double, double, QString);
    void searchButton_clicked();
    void suggestion_clicked(QListWidgetItem* item);
    void showZoom(int);
    void addPlace();
    void deletePlace();
    void hideListWithButtons();
    void showListWithButtons();
    void calculate();
    void place_clicked(QListWidgetItem*);
};

#endif // MAINWINDOW_H
