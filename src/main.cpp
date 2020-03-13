#include <QCoreApplication>
#include "bankaccount.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // don't change type of account, use it as QObject*
    QObject *account = new BankAccount;

    // TODO: set holder name
    account->setProperty("holderName", "Bill Gates");
    // TODO: print it to qDebug()
    qDebug() << account->property("holderName");

    // TODO: get balance from property to qDebug()
    qDebug() << account->property("balance");
    return a.exec();
}
