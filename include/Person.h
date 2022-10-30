#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iterator>
#include "Validation.h"
using namespace std;

class Person
{
public :
    int id ;
    string name, password ;
    Person()
    {
        this-> password = " ";
        this-> name = " ";
        this->id =0;
    }
    Person(int id, string name, string password)
    {
        this-> password = password;
        this-> name = name;
        this->id = id;
    }
    void setName(string name)
    {
        this-> name = Validation::enterName();
    }
    void setPassword(string password)
    {
        this-> password = Validation::enterPassword();
    }
    void setId(int id)
    {
        this-> id = id;
    }
    int getId()
    {
        return this->id;
    }
    string getName()
    {
        return this->name;
    }
    string getPassword()
    {
        return this->password;
    }
    void display()
    {
        cout<<"Name : "<<getName()<<endl;
        cout<<"Password : "<<getPassword()<<endl;
    }
};



#endif // PERSON_H
