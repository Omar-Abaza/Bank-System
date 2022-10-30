#ifndef SCREENS_H
#define SCREENS_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
string name = " ";
class Screens
{
private:
    static void loginOptions()
    {
        cout << "\n\t\t\t\t===============================\n";
        cout <<"\t\t\t\t\t   Login As\n";
        cout << "\t\t\t\t===============================\n\n";
        cout<<"1 - Client\n\n";
        cout<<"2 - Employee\n\n";
        cout<<"3 - Admin\n\n";
        cout<<"4 - Exit\n\n";
    }
    static int loginAs()
    {
        int choice;
        cout<<"Login As : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            return 1;
            break;
        }
        case 2:
        {
            return 2;
            break;
        }
        case 3:
        {
            return 3;
            break;
        }
        case 4:
        {
            return 4;
            break;
        }
        default:
        {
            Invalid(choice);
            break;
        }
        }
    }
    static void Invalid(int c)
    {
        cout << "\n\n\t###################################\n\n";
        cout << "\t*** Make Sure Of Your Choice ! ***\n\n";
        cout << "\t###################################\n";
        loginAs();
    }
    static void LoginClient()
    {
        cout << "\n\t\t\t\t===============================\n";
        cout <<"\t\t\t\t       Login Client Page\n";
        cout << "\t\t\t\t===============================\n\n";
        int id;
        string password;
        cout << "Id : ";
        cin >> id;
        cout << "Password : ";
        cin >> password;
        Client* client = ClientManager::login(id,password);
        if(client != NULL)
        {
            name = client->getName();
            system("cls");
            cout << "\n\n\n\t\t\t\t===============================\n";
            cout <<"\t\t\t\t       Welccome, "<<name <<"\n";
            cout << "\t\t\t\t===============================\n\n";
            Sleep(1500);
            ClientManager::printClientMenu();
            if(ClientManager::clientOptions(client))
            {
                system("cls");
                cout << "\n\t\t\t\t===============================\n";
                cout <<"\t\t\t\t       Goodbye, "<<name <<"\n";
                cout <<"\t\t\t\t       Have a Nice Day !\n";
                cout << "\t\t\t\t===============================\n\n";
                Sleep(1500);
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
        }
        else
        {
            cout << "\n1 - Try Again\n";
            cout<< "2 - Return\n";
            int x;
            cout << "\nEnter Your Choice : ";
            cin >> x;
            system("cls");
            if(x == 1)
            {
                LoginClient();
            }
            else if(x == 2)
            {
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
            else
            {
                cout << "\n\n\t###################################\n\n";
                cout << "\t*** Make Sure Of Your Choice ! ***\n\n";
                cout << "\t###################################\n";
                system("pause");
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
        }
    }
    static void LoginEmployee()
    {
        cout << "\n\t\t\t\t===============================\n";
        cout <<"\t\t\t\t      Login Employee Page\n";
        cout << "\t\t\t\t===============================\n\n";
        int id;
        string password;
        cout << "Id : ";
        cin >> id;
        cout << "Password : ";
        cin >> password;
        Employee* employee = EmployeeManager::login(id, password);
        if(employee != NULL)
        {
            name = employee->getName();
            system("cls");
            cout << "\n\n\n\t\t\t\t===============================\n";
            cout <<"\t\t\t\t       Welccome, "<<name <<"\n";
            cout << "\t\t\t\t===============================\n\n";
            Sleep(1500);
            EmployeeManager::printEmployeeMenu();
            if(EmployeeManager::employeeOptions(employee))
            {
                system("cls");
                cout << "\n\n\n\t\t\t\t===============================\n";
                cout <<"\t\t\t\t       Goodbye, "<<name <<"\n";
                cout <<"\t\t\t\t       Have a Nice Day !\n";
                cout << "\t\t\t\t===============================\n\n";
                Sleep(1500);
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
        }
        else
        {
            cout << "\n1 - Try Again\n";
            cout<< "2 - Return\n";
            int x;
            cout << "\nEnter Your Choice : ";
            cin >> x;
            system("cls");
            if(x == 1)
            {
                LoginEmployee();
            }
            else if(x == 2)
            {
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
            else
            {
                cout << "\n\n\t###################################\n\n";
                cout << "\t*** Make Sure Of Your Choice ! ***\n\n";
                cout << "\t###################################\n";
                system("pause");
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
        }
    }
    static void LoginAdmin()
    {
        cout << "\n\t\t\t\t===============================\n";
        cout <<"\t\t\t\t\tLogin Admin Page\n";
        cout << "\t\t\t\t===============================\n\n";
        int id;
        string password;
        cout << "Id : ";
        cin >> id;
        cout << "Password : ";
        cin >> password;
        Admin* admin = AdminManager::login(id, password);
        if(admin != NULL)
        {
            name = admin->getName();
            system("cls");

            cout << "\n\n\n\t\t\t\t===============================\n";
            cout <<"\t\t\t\t       Welccome, "<<name <<"\n";
            cout << "\t\t\t\t===============================\n\n";
            Sleep(1500);
            AdminManager::printAdminMenu();
            if(AdminManager::adminOptions(admin))
            {
                system("cls");
                cout << "\n\n\n\t\t\t\t===============================\n";
                cout <<"\t\t\t\t       Goodbye, "<<name <<"\n";
                cout <<"\t\t\t\t       Have a Nice Day !\n";
                cout << "\t\t\t\t===============================\n\n";
                Sleep(1500);
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
        }
        else
        {
            cout << "\n1 - Try Again\n";
            cout<< "2 - Return\n";
            int x;
            cout << "\nEnter Your Choice : ";
            cin >> x;
            system("cls");
            if(x == 1)
            {
                LoginAdmin();
            }
            else if(x == 2)
            {
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
            else
            {
                cout << "\n\n\t###################################\n\n";
                cout << "\t*** Make Sure Of Your Choice ! ***\n\n";
                cout << "\t###################################\n";
                system("pause");
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
        }
    }
    static void loginScreen(int c)
    {
        switch(c)
        {
        case 1:
        {
            system("cls");
            LoginClient();
            break;
        }
        case 2:
        {
            system("cls");
            LoginEmployee();
            break;
        }
        case 3:
        {
            system("cls");
            LoginAdmin();
            break;
        }
        case 4:
        {
            Thanks();
            _Filemanager.updateAllFiles();
        }
        }
    }
    static void Thanks()
    {
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t###################################\n\n";
        cout << "\t\t\t\t *** THANK YOU ***\n\n";
        cout << "\t\t\t###################################\n";
        Sleep(2500);
        system("cls");
    }
    static void BankName()
    {
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t###################################\n\n";
        cout << "\t\t\t\t*** CIB BANK ***\n\n";
        cout << "\t\t\t###################################\n";
        Sleep(2500);
    }
    static void Welcome()
    {
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t###################################\n\n";
        cout << "\t\t\t\t*** WELCOME ***\n\n";
        cout << "\t\t\t###################################\n";
        Sleep(2500);
    }
public:
    static void runApp()
    {
        BankName();
        system("cls");
        Welcome();
        system("cls");
        _Filemanager.getAllData();
        loginOptions();
        loginScreen(loginAs());
    }
};

#endif // SCREENS_H
