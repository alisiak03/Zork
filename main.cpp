#include "Treasure.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Treasure w;
    w.show();
    return a.exec();
}
