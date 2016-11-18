#include "qmainwindowwidget.h"
#include <QApplication>


#include "View/MainView.h"
#include "View/SubVideoSwitchView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QMainWindowWidget w;
//    w.show();

    MainView w;
    w.show();
//    SubVideoSwitchView subw;
//    subw.show();
    return a.exec();
}
