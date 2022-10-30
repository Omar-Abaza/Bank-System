#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H
#include "ClientManager.h"
#include "Admin.h"

Admin _Admin;
class EmployeeManager
{
private:
    static Client* edit(Client* client)
    {
        int choice, id;
        string name, password;
        double balance;
        Employee* employee;
        cout << "\n\t===============================\n";
        cout << "\t    What Do You Want To Edit \n";
        cout << "\t===============================\n\n"
             << " 1- All Data \n"
             << " 2- Name \n"
             << " 3- Password \n"
             << " 4- Balance \n"
             << " 5- Return\n\n";

        cout << " Enter Your Choice :\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            client->setName(name) ;
            client->setPassword(password) ;
            client->setBalance(balance);
            employee->editClient(client->getId(), name, password, balance);
            break;
        }
        case 2:
        {
            client->setName(name) ;
            password = client->getPassword();
            balance = client->getBalance();
            employee->editClient(client->getId(), name, password, balance);
            break;
        }
        case 3:
        {
            client->setPassword(password) ;
            name = client->getName();
            balance = client->getBalance();
            employee->editClient(client->getId(), name, password, balance);
            break;
        }
        case 4:
        {
            client->setBalance(balance);
            name = client->getName();
            password = client->getPassword();
            employee->editClient(client->getId(), name, password, balance);
            break;
        }
        case 5:
        {
            break;
        }
        default:
        {
            cout << "\n\n\t###################################\n\n";
            cout << "\t** Make Sure Of Your Choice ! **\n\n";
            cout << "\t###################################\n\n";
            edit(client);
            break;
        }
        }
    }
    static void Back(Employee* employee)
    {
        system("pause");
        printEmployeeMenu();
        employeeOptions(employee);
    }
public:
    static void printEmployeeMenu()
    {
        system("cls");
        cout << "\n\t\t\t\t===============================\n";
        cout <<"\t\t\t\t       Employee functions\n";
        cout << "\t\t\t\t===============================\n\n";
        cout << "1-Add New Client\n";
        cout << "2-List Of All Clients\n";
        cout << "3-Search For A Client\n";
        cout << "4-Edit Client\n";
        cout << "5-Display\n";
        cout << "6-Update Password\n";
        cout << "7-Logout\n\n";
    }
    static bool employeeOptions(Employee* employee)
    {
        int choice ;
        cout << "Enter your choice :  ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            newClient(employee);
            break;
        }
        case 2:

        {
            system("cls");
            listAllClients(employee);
            break;
        }
        case 3:

        {
            system("cls");
            searchForClient(employee);
            break;
        }
        case 4:

        {
            system("cls");
            editClientInfo(employee);
            break;
        }
        case 5:

        {
            system("cls");
            employee->display();
            break;
        }
        case 6:

        {
            system("cls");
            ClientManager::updatePassword(employee);
            break;
        }
        case 7:
        {
            _Filemanager.updateAllFiles();
            return true ;
        }
        default:
        {
            cout << "\n\n\t###################################\n\n";
            cout << "\t** Make Sure Of Your Choice ! **\n\n";
            cout << "\t###################################\n";
            employeeOptions(employee);
        }
        }
        Back(employee);
    }
    static void newClient(Employee* employee)
    {
        Client* client = new Client();
        string name, password;
        double balance;
        int id;
        cout<<"Enter New Client \n\n";
        client->setName(name) ;
        client->setPassword(password) ;
        client->setBalance(balance);
        id  = FilesHelper::getLast("ClientLastId.txt");
        client->setId(id+1);
        FilesHelper::saveLast("ClientLastId.txt", id+1);
        employee->addClient(*client);
        cout << "\n\n\t###################################\n\n";
        cout << "\t** Client Accepted **\n\n";
        cout << "\t###################################\n\n";
    }
    static void listAllClients(Employee* employee)
    {
        employee->listClient();
    }
    static void searchForClient(Employee* employee)
    {
        int id;
        cout<<"Client Id : ";
        cin>>id;
        Client* client = employee->searchClient(id);
        if(client == NULL)
        {
            cout << "\n\n\t###################################\n\n";
            cout << "\t** Client Not Found **\n\n";
            cout << "\t###################################\n\n";
        }
        else
        {
            client->display();
        }
    }
    static void editClientInfo(Employee* employee)
    {
        int choice, id;
        cout << " \n Enter Your Id \n ";
        cin >> id;
        Client* client = employee->searchClient(id);
        if (client != NULL)
        {
            EmployeeManager::edit(client);
        }
        else
        {
            cout << "\n\n\t###################################\n\n";
            cout << "\t** Client Not Found **\n\n";
            cout << "\t###################################\n\n";
            cout << " 1- Try Again \n";
            cout << " 2- Return \n";
            cout << " Enter Your Choice :\n";
            cin >> choice;
            system("cls");
            switch (choice)
            {
            case 1:
            {
                editClientInfo(employee);
                break;
            }
            case 2:
            {
                printEmployeeMenu();
                employeeOptions(employee);
                break;
            }
            default:
            {
                cout << "\n\n\t###################################\n\n";
                cout << "\t** Make Sure Of Your Choice ! **\n\n";
                cout << "\t###################################\n\n";
                system("pause");
                printEmployeeMenu();
                employeeOptions(employee);
                break;
            }
            }
            Back(employee);

        }
    }
    static Employee* login(int id, string password)
    {
        Employee* employee = _Admin.searchEmployee(id);
        if(employee == NULL)
        {
            cout << "\n\n\t###################################\n\n";
            cout << "\t   ** Invalid Id Or Password **\n\n";
            cout << "\t###################################\n\n";
            return NULL;
        }
        else
        {
            if(employee->getPassword() == password)
            {
                return employee;
            }
            else
            {
                cout << "\n\n\t###################################\n\n";
                cout << "\t   ** Invalid Id Or Password **\n\n";
                cout << "\t###################################\n\n";
                return NULL;
            }
        }
    }
};


#endif // EMPLOYEEMANAGER_H
