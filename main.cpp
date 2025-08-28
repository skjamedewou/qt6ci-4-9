#include <QCoreApplication>
#include <QSharedPointer>
#include <vector>
#include "cat.h"
#include "toy.h"

void test()
{
    int max = 5;
    QSharedPointer<Toy> toy (new Toy());
    std::vector<QSharedPointer<Cat>> cats(max);

    for (int i = 0;  i < max; i++) {
        cats[i].reset(new Cat());
        cats[i]->play(toy);
    }
    qInfo() << "All cats are done";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.
    test();

    return a.exec();
}
