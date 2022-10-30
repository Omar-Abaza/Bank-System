#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include <cstring>
#include <iterator>
#include "Employee.h"
using namespace std;

class Admin :public Employee
{
private:
    double salary;
public:

    Admin():Employee() {}
    Admin(int id, string name, string password, double salary) :Employee(id, name, password, salary) {}
    void addEmployee(Employee& e)
    {
        allEmployees.push_back(e);
    }
    Employee* searchEmployee(int id)
    {
        for(int i=0; i<allEmployees.size(); i++)
        {
            if(allEmployees[i].getId()==id)
            {
                Employee* e = &allEmployees[i];
                return e;
            }
        }
        return nullptr;
    }
    void listEmployee ()
    {
        for (emp_Iterator = allEmployees.begin(); emp_Iterator != allEmployees.end(); emp_Iterator++)
        {
            emp_Iterator->display();
        }
    }
    Employee* editEmployee (int id, string name, string password, double salary )
    {
        Employee *e = searchEmployee(id);
        e->getName();
        e->getPassword();
        e->getSalary();
        return e;
    }
    void display()
    {
        cout<<"\nAdmin INFO : \n"<<endl;
        cout<<"ID : A300-"<<getId()<<endl;
        Person::display();
        cout<<"Salary : $"<<getSalary()<<endl;
        cout<<"\n================================\n"<<endl;
    }
};
static vector<Admin> allAdmins;
static vector<Admin>::iterator aIt;



#endif // ADMIN_H
