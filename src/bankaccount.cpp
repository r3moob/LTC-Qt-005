#include "bankaccount.h"

BankAccount::BankAccount(Bank *parentBank) : QObject(parentBank)
{
    m_balance = 0;
    // TODO: connect Bank slots to BankAccount signals
    connect(this, &BankAccount::sigBalanceChanged, parentBank, &Bank::slotAccountBalanceChanged);
}

long BankAccount::balance() const
{
    return m_balance;
}

void BankAccount::setBalance(long newBalance)
{
    m_balance = newBalance;
    // TODO: add here signal emition
    emit sigBalanceChanged(m_balance);
}

void BankAccount::deposit(long amount)
{
    // TODO: implement this function
    setBalance(m_balance + amount);
}

void BankAccount::withdraw(long amount)
{
    // TODO: implement this function
    setBalance(m_balance - amount);
}
