#ifndef FILESHELPER_H
#define FILESHELPER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Parser.h"
#include "Admin.h"
#include "Client.h"
#include "Employee.h"
using namespace std;
class FilesHelper
{
public:
    static void saveLast(string fileName, int id)
    {
        ofstream file;
        file.open(fileName);
        file << id;
        file.close();
    }
    static int getLast(string fileName)
    {
        ifstream file;
        file.open(fileName);
        int id;
        file >> id;
        file.close();
        return id;
    }
    static void saveClient(Client c)
    {
        int id = getLast("ClientLastId.txt");
        fstream file("Clients.txt", ios::app);
        file << id +1 << '|' << c.getName() << '|' << c.getPassword() << '|' << c.getBalance() <<  '|' << endl;
        file.close();
        saveLast("ClientLastId.txt", id + 1);
    }
    static void saveEmployee(string fileName, string lastIdFile, Employee e)
    {
        int id = getLast(lastIdFile);
        fstream file(fileName, ios::app);
        file << id + 1 << '|' << e.getName() << '|' << e.getPassword() << '|' << e.getSalary() <<  '|' << endl;
        file.close();
        saveLast(lastIdFile, id + 1);
    }
    static void getClients()
    {
        fstream file("Clients.txt", ios::in);
        string line;
        while (getline(file, line))
        {
            Client c = Parser::parseToClient(line);
            allClients.push_back(c);
        }
        file.close();
    }
    static void getEmployees()
    {
        fstream file("Employees.txt", ios::in);
        string line;
        while (getline(file, line))
        {
            Employee e = Parser::parseToEmployee(line);
            allEmployees.push_back(e);
        }
        file.close();
    }
    static void getAdmins()
    {
        fstream file("Admins.txt", ios::in);
        string line;
        while (getline(file, line))
        {
            Admin a = Parser::parseToAdmin(line);
            allAdmins.push_back(a);
        }
        file.close();
    }
    static void clearFile(string fileName, string lastIdFile)
    {
        fstream file1, file2;
        file1.open(fileName, ios::out | ios::trunc);
        file1.close();
        file2.open(lastIdFile, ios::out);
        file2 << 0;
        file2.close();
    }
};

#endif // FILESHELPER_H
