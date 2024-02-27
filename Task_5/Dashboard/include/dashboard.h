#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QtCharts/QtCharts>
#include <QLineSeries>
#include <QBarSeries>
#include <QBarSet>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dashboard;
}
QT_END_NAMESPACE

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    Dashboard(QWidget *parent = nullptr);
    void send_request();
    void display_data(QNetworkReply *reply);
    void write_json_to_file(const QJsonObject& jsonObject, const QString& filePath);
    QJsonObject read_json_from_file(const QString& filePath);
    ~Dashboard();

private slots:
    void on_radioButton_pressed();

    void on_radioButton_4_pressed();

    void on_radioButton_3_pressed();

    void on_radioButton_2_pressed();

private:
    Ui::Dashboard *ui;
    QNetworkAccessManager *network_manager;
    QBarCategoryAxis *x_axis;
    QBarCategoryAxis *y_axis;
    QLineSeries *line_series;
    QBarSeries *bar_series;
    QTimer *timer;
    QChart *chart_line;
    QChart *chart_bar;
    QChartView *chart_view_line;
    QChartView *chart_view_bar;
};
#endif // DASHBOARD_H
