#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QObject>

class BankAccount : public QObject
{
    Q_OBJECT
    // TODO: declare QString holderName property that's represents account holder name
    //       this property must have getter and setter
    Q_PROPERTY(QString holderName READ holderName WRITE setHolderName)


    // TODO: declare long balance property
    //       this property should be read-only and associated with variable m_balance
    Q_PROPERTY(long balance MEMBER m_balance)
public:
    explicit BankAccount(QObject *parent = 0);

    void deposit(long amount);
    void withdraw(long amount);

    // TODO: declare and implement holderName getter/setter
    // TODO: decalre and implement balance getter
    QString holderName() const
    {
        return m_holderName;
    }

public slots:
    void setHolderName(QString holderName)
    {
        m_holderName = holderName;
    }

private:
    // TODO: declare holderName
    long m_balance;
    QString m_holderName;
};

#endif // BANKACCOUNT_H
