#include <QCoreApplication>
#include <QDebug>
#include "game.h"
#include <iostream>

int main(int argc, char *argv[]) {
    //QCoreApplication a(argc, argv);
    game instance(15, 15);
    instance.wyswietlenie();
    instance.giveField(12,7)->bombSetup();
    std::cout << std::endl;
    instance.giveField(13, 8)->serialReveal(instance.giveBoard());
    instance.wyswietlenie();
    //return QCoreApplication::exec();
    return 0;
}
