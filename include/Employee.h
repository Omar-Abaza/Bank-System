#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <cstring>
#include <iterator>
#include "Person.h"
#include "Client.h"
using namespace std;

class Employee :public Person
{
protected:
    double salary;
public:
    Employee():Person()
    {
        this->salary = 0.0;
    }
    Employee(int id, string name, string password, double salary) :Person(id, name, password)
    {
        this->salary = salary;
    }
    double getSalary()
    {
        return this->salary;
    }
    void setSalary(double salary)
    {
        this->salary = Validation::enterSalary();
    }
    void addClient(Client& c)
    {
        allClients.push_back(c);
    }
    Client* searchClient(int id)
    {
        for(int i=0; i<allClients.size(); i++)
        {
            if(allClients[i].getId()==id)
            {
                Client* c = &allClients[i];
                return c;
            }
        }
        return nullptr;
    }
    void listClient ()
    {
        for (cli_Iterator = allClients.begin(); cli_Iterator != allClients.end(); cli_Iterator++)
        {
            cli_Iterator->display();
        }
    }
    Client* editClient (int id, string name, string password, double balance )
    {
        Client *c = searchClient(id);
        c->getName();
        c->getPassword();
        c->getBalance();
        return c;
    }
    void display()
    {
        cout<<"\nEmployee INFO : \n"<<endl;
        cout<<"ID : E200-"<<getId()<<endl;
        Person::display();
        cout<<"Salary : $"<<getSalary()<<endl;
        cout<<"\n================================\n"<<endl;
    }
};

static vector<Employee> allEmployees;
static vector<Employee>::iterator emp_Iterator;
#endif // EMPLOYEE_H
