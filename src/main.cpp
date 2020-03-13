#include <QCoreApplication>
#include <QDebug>
#include <QStack>

#include <QListIterator>
#include <algorithm>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> names;
    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";


    // TODO: using Java-style iterators print the longest name from the list
    // use QString::arg to output message with this name
    QListIterator<QString> it(names);
    QString longestName = it.next();
    while (it.hasNext()) {
        QString tmp = it.next();
        if (tmp.size() > longestName.size()) longestName = tmp;
    }
    qDebug() << QString("Longest name from the list: %1").arg(longestName);

    // TODO: using STL-style iterators print the shortest name from the list
    // use QString::prepend and append to output message with this name
    QString shortestName = names.first();
    for (QList<QString>::const_iterator it = names.cbegin(); it < names.cend(); ++it) {
        if ((*it).size() < shortestName.size()) shortestName = *it;
    }
    QString msg("Shortest name from the list: ");
    qDebug() << shortestName.prepend(msg);

    // TODO: using foreach and QStringList show all names with "lynn" suffix
    // and print it separated by ',' as one string
    QStringList tmp;
    for (auto name : names) {
        if(name.endsWith("lynn")) {
            tmp.append(name);
        }
    }
    qDebug() << tmp.join(',');

    // print all names in reverse order
    // TODO: 1. Using QStack
    qDebug() << "TODO: 1. Using QStack";

    QStack<QString> stack;
    for (auto name : names) {
        stack.push(name);
    }
    while (!stack.isEmpty()) {
        qDebug() << stack.pop();
    }


    // TODO: 2. Using other QList
    qDebug() << "TODO: 2. Using other QList";

    QList<QString> copyNames;
    std::reverse_copy(names.begin(), names.end(), std::back_inserter(copyNames));
    qDebug() << copyNames;

    // TODO: 3. Without other containers
    qDebug() << "TODO: 3. Without other containers";

    for (QList<QString>::const_reverse_iterator it = names.crbegin(); it < names.crend(); ++it) {
        qDebug() << *it;
    }

    return a.exec();
}
