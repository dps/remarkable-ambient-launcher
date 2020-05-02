#include <QGuiApplication>
#include <QQmlApplicationEngine>
// Added for reMarkable support
#include <QtPlugin>
#ifdef __arm__
Q_IMPORT_PLUGIN(QsgEpaperPlugin)
#endif
// end reMarkable additions
#include <QtQml>

int main(int argc, char *argv[])
{
    //  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    // Added for reMarkable support
#ifdef __arm__
    qputenv("QMLSCENE_DEVICE", "epaper");
    qputenv("QT_QPA_PLATFORM", "epaper:enable_fonts");
    qputenv("QT_QPA_EVDEV_TOUCHSCREEN_PARAMETERS", "rotate=180");
    qputenv("QT_QPA_GENERIC_PLUGINS", "evdevtablet");
#endif
    // end reMarkable additions

    // battery capacity
    // /sys/class/power_supply/bq27441-0/capacity

    system("/usr/bin/button-capture &");

    system("/usr/sbin/wpa_supplicant -iwlan0 -c/home/root/wpa_supplicant.conf &");
    system("sleep 20");
    system("wget https://imgs.xkcd.com/comics/turtle_sandwich_standard_model.png -O fp.png");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
