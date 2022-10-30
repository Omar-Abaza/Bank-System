#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <cstring>
#include "Person.h"
using namespace std;

class Client : public Person
{
private:
    double balance;
public:
    Client():Person()
    {
        this->balance = 0.0;
    }
    Client(int id, string name, string password, double balance):Person(id, name, password)
    {
        this->balance = balance;
    }
    void setBalance(double balance)
    {
        this->balance = Validation::enterBalance();
    }
    double getBalance()
    {
        return this->balance;
    }
    void deposit(double amount)
    {
        this->balance += amount;
    }
    void withdraw(double amount)
    {
        if(amount <= this->balance)
        {
            this->balance -= amount;
        }
        else
        {
                cout << "\n\n\t#######################################################\n\n";
                cout << "\t** Sorry you don't have enough money in your account **\n\n";
                cout << "\t#######################################################\n\n";
        }
    }
    void checkBalance()
    {
        cout<<"Balance : $"<<getBalance()<<endl;
    }
    void transferTo(double amount, Client& recipient )
    {
        if(amount <= this->balance)
        {
            this->balance -= amount;
            recipient.balance += amount;
        }
        else
        {
                cout << "\n\n\t#######################################################\n\n";
                cout << "\t** Sorry you don't have enough money in your account **\n\n";
                cout << "\t#######################################################\n\n";
        }
    }
    void display()
    {
        cout<<"\nClient INFO : \n"<<endl;
        cout<<"ID : C100-"<<getId()<<endl;
        Person::display();
        this->checkBalance();
        cout<<"\n================================\n"<<endl;
    }
};

static vector<Client> allClients;
static vector<Client>::iterator cli_Iterator;
#endif // CLIENT_H
