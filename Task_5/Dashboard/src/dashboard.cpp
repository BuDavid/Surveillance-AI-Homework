#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    network_manager = new QNetworkAccessManager(this);

    QStringList category_list;
    category_list.append("Opening");
    category_list.append("Highest");
    category_list.append("Lowest");
    category_list.append("closing");

    line_series = new QLineSeries(this);
    bar_series = new QBarSeries(this);

    chart_line = new QChart();
    chart_bar = new QChart();

    chart_line->legend()->hide();
    chart_line->setTitle("Time/Volume Line Chart");

    chart_bar->legend()->hide();
    chart_bar->setTitle("Price Bar Chart");

    chart_bar->setAnimationOptions(QChart::SeriesAnimations);

    x_axis = new QBarCategoryAxis();
    x_axis->append(category_list);
    chart_bar->addAxis(x_axis, Qt::AlignBottom);

    y_axis = new QBarCategoryAxis();
    y_axis->setRange("0", "100");
    chart_bar->addAxis(x_axis, Qt::AlignLeft);

    chart_bar->legend()->setVisible(true);
    chart_bar->legend()->setAlignment(Qt::AlignBottom);

    chart_view_line = new QChartView();
    chart_view_bar = new QChartView();

    chart_view_line->setRenderHint(QPainter::Antialiasing);
    chart_view_bar->setRenderHint(QPainter::Antialiasing);

    chart_view_line->setParent(ui->line_frame);
    chart_view_bar->setParent(ui->bar_frame);

    QVBoxLayout *layout_line = new QVBoxLayout(ui->line_frame);
    layout_line->addWidget(chart_view_line);

    QVBoxLayout *layout_bar = new QVBoxLayout(ui->bar_frame);
    layout_bar->addWidget(chart_view_bar);

    timer = new QTimer(this);

    int one_min = 60000;
    timer->setInterval(one_min * 5);

    QObject::connect(timer, &QTimer::timeout, this, &Dashboard::send_request);
    connect(network_manager, &QNetworkAccessManager::finished, this, &Dashboard::display_data);

    timer->start();
    QTimer::singleShot(0, this, &Dashboard::send_request);

}

void Dashboard::send_request()
{
    QNetworkRequest request(QUrl("https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=AAPL&interval=60min&apikey=3IKEMJCIAYQPTBV3"));
    network_manager->get(request);
}

void Dashboard::display_data(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument json_doc = QJsonDocument::fromJson(data);
        QJsonObject json_obj = json_doc.object();

        QString file_path = QCoreApplication::applicationDirPath() + "/../Dashboard/data/latest_data.txt";

        if (json_obj.contains("Time Series (60min)")) {
            write_json_to_file(json_obj, file_path);
        } else {
            json_obj = read_json_from_file(file_path);
        }
        QJsonObject time_series = json_obj.value("Time Series (60min)").toObject();

        QVector<double> time_stamps;
        QVector<double> open_prices;
        QVector<double> high_prices;
        QVector<double> low_prices;
        QVector<double> close_prices;
        QVector<double> volumes;

        QBarSet *open_price_set= new QBarSet("open");
        QBarSet *high_price_set= new QBarSet("high");
        QBarSet *low_price_set= new QBarSet("low");
        QBarSet *close_price_set= new QBarSet("close");

        for (auto it = time_series.begin(); it != time_series.end(); ++it) {
            QString time_stamp = it.key();
            QJsonObject dataPoint = it.value().toObject();

            QDateTime date_time = QDateTime::fromString(time_stamp, "yyyy-MM-dd hh:mm:ss");
            time_stamps.append(date_time.toSecsSinceEpoch());

            open_prices.append(dataPoint.value("1. open").toString().toDouble());
            high_prices.append(dataPoint.value("2. high").toString().toDouble());
            low_prices.append(dataPoint.value("3. low").toString().toDouble());
            close_prices.append(dataPoint.value("4. close").toString().toDouble());
            volumes.append(dataPoint.value("5. volume").toString().toDouble());
        }

        ui->closing_price->display(close_prices.back());
        ui->high_price->display(high_prices.back());
        ui->low_price->display(low_prices.back());

        line_series->clear();
        bar_series->clear();

        for (int i = 0; i < time_stamps.size(); i++) {
            line_series->append(time_stamps[i], volumes[i]);
            *open_price_set << open_prices[i];
            *high_price_set << high_prices[i];
            *low_price_set << low_prices[i];
            *close_price_set << close_prices[i];
        }

        bar_series->append(open_price_set);
        bar_series->append(high_price_set);
        bar_series->append(low_price_set);
        bar_series->append(close_price_set);

        chart_bar->removeAllSeries();
        chart_bar->addSeries(bar_series);
        bar_series->attachAxis(x_axis);
        bar_series->attachAxis(y_axis);

        chart_line->removeAllSeries();
        chart_line->addSeries(line_series);
        chart_line->createDefaultAxes();

        chart_view_line->setChart(chart_line);
        chart_view_bar->setChart(chart_bar);

    } else {
        qDebug() << "Error";
    }
    reply->deleteLater();
}

void Dashboard::write_json_to_file(const QJsonObject& jsonObject, const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to open file for writing:" << file.errorString();
        return;
    }

    QJsonDocument jsonDoc(jsonObject);
    file.write(jsonDoc.toJson());
    file.close();
}

QJsonObject Dashboard::read_json_from_file(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open file for reading:" << file.errorString();
        return QJsonObject();
    }

    QByteArray jsonData = file.readAll();
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &error);
    if (error.error != QJsonParseError::NoError) {
        qWarning() << "Failed to parse JSON:" << error.errorString();
        return QJsonObject();
    }

    return jsonDoc.object();
}

Dashboard::~Dashboard()
{
    delete ui;
    delete network_manager;
    delete x_axis;
    delete y_axis;
    delete line_series;
    delete bar_series;
    delete timer;
    delete chart_line;
    delete chart_bar;
    delete chart_view_line;
    delete chart_view_bar;
}

void Dashboard::on_radioButton_pressed()
{
    timer->setInterval(60000 * 5);
}


void Dashboard::on_radioButton_4_pressed()
{
    timer->setInterval(60000 * 15);
}


void Dashboard::on_radioButton_3_pressed()
{
    timer->setInterval(60000 * 30);
}


void Dashboard::on_radioButton_2_pressed()
{
    timer->setInterval(60000 * 60);
}

