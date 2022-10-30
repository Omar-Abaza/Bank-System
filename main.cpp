#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "Person.h"
#include "Validation.h"
#include "FileManager.h"
#include "FilesHelper.h"
#include "Screens.h"
using namespace std;

int main()
{
//    Employee* e1 = new Employee(1,"AliOsama","AliOsama12!@",6000);
//    Admin* a1 = new Admin(1,"Raamy","Raamy12!@",7000);
//    Client* c1 = new Client(1,"Khaled","Khaled12!@",5000);
//    FileManager* f1 = new FileManager();
//    f1->addAdmin(*a1);
//    f1->addEmployee(*e1);
//    f1->addClient(*c1);

    Screens::runApp();
}

