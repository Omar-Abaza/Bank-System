#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
private:
    void removeAllClients()
    {
        FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
    }
    void removeAllEmployees()
    {
        FilesHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
    }
    void removeAllAdmins()
    {
        FilesHelper::clearFile("Admins.txt", "AdminLastId.txt");
    }
    void addClient(Client c)
    {
        FilesHelper::saveClient(c);
    }
    void addEmployee(Employee e)
    {
        FilesHelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", e);
    }
    void addAdmin(Admin a)
    {
        FilesHelper::saveEmployee("Admins.txt", "AdminLastId.txt", a);
    }
    void updateClients()
    {
        removeAllClients();
        for (cli_Iterator = allClients.begin(); cli_Iterator != allClients.end(); cli_Iterator++)
        {
            addClient(*cli_Iterator);
        }
    }
    void updateEmployees()
    {
        removeAllEmployees();
        for (emp_Iterator = allEmployees.begin(); emp_Iterator != allEmployees.end(); emp_Iterator++)
            addEmployee(*emp_Iterator);
    }
    void updateAdmins()
    {
        removeAllAdmins();
        for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++)
            addAdmin(*aIt);
    }
public:
    vector<Client> getAllClients()
    {
        FilesHelper::getClients();
        return allClients;
    }
    vector<Employee> getAllEmployees()
    {
        FilesHelper::getEmployees();
        return allEmployees;
    }
    vector<Admin> getAllAdmins()
    {
        FilesHelper::getAdmins();
        return allAdmins;
    }
    void getAllData()
    {
        getAllClients();
        getAllEmployees();
        getAllAdmins();
    }
    void updateAllFiles()
    {
        updateClients();
        updateEmployees();
        updateAdmins();
    }
};
#endif // FILEMANAGER_H
