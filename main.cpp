#include "widget.h"
#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString lang;
    QFile file("lang");
    file.open(QIODevice::ReadOnly);
    QTextStream s(&file);
    lang = s.readLine();
    if(lang == "")
    {
        lang = QLocale::system().name();
        qDebug() << "Can't load language preference, using system locale";
    }
    file.close();
    qDebug() << "lang" << lang;

    QTranslator translator;
    translator.load("qvknotify_" + lang);
    if (a.installTranslator(&translator)==true)
        qDebug() << lang << "localization loaded";

    MainWindow w;
    w.show();

    return a.exec();
}
////TODO:
//              совмещать сообщения, если отправитель один
//DONE          сохранение и загрузка ключа автоматически
//              шифрование ключа
//DONE          автовход
//FIXME?        аватара рядом с полем сообщения
//              статус отправителя (онлайн/оффлайн)
//DONE          пусть все добавленные кнопки меню работают
//DONE          заменить поля Status и User ID на статус-строку внизу
//DONE          автообновление и/или кнопка "обновить"
//FIXME         перевод
//              поддержка чатов
//              обнаружение вложений
//              быстрый ответ
//              error handling
//DONE          tray icon
//WONTFIX       поддержка libnotify и/или его аналог на windows
