#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H
#include "ClientManager.h"
#include "EmployeeManager.h"

class AdminManager : public EmployeeManager
{
private:
    static Employee* edit(Employee* employee)
    {
        int choice, id;
        string name, password;
        double salary;
        Admin* admin;
        cout << "\n\t===============================\n";
        cout << "\t    What Do You Want To Edit \n";
        cout << "\t===============================\n\n"
                << " 1- All Data \n"
                << " 2- Name \n"
                << " 3- Password \n"
                << " 4- Salary \n"
                << " 5- Return\n\n";

        cout << " Enter Your Choice :\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            employee->setName(name) ;
            employee->setPassword(password) ;
            employee->setSalary(salary);
            admin->editEmployee(employee->getId(), name, password, salary);
            break;
        }
        case 2:
        {
            employee->setName(name) ;
            password = employee->getPassword();
            salary = employee->getSalary();
            admin->editEmployee(employee->getId(), name, password, salary);
            break;
        }
        case 3:
        {
            employee->setPassword(password) ;
            name = employee->getName();
            salary = employee->getSalary();
            admin->editEmployee(employee->getId(), name, password, salary);
            break;
        }
        case 4:
        {
            employee->setSalary(salary);
            name = employee->getName();
            password = employee->getPassword();
            admin->editEmployee(employee->getId(), name, password, salary);
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
            edit(employee);
            break;
        }
        }
    }
    static Admin* searchAdmin(int id)
    {
        for(int i=0; i<allAdmins.size(); i++)
        {
            if(allAdmins[i].getId()==id)
            {
                Admin* a = &allAdmins[i];
                return a;
            }
        }
        return nullptr;
    }
    static void Back(Admin* admin)
    {
        system("pause");
        printAdminMenu();
        adminOptions(admin);
    }
public:
    static void printAdminMenu()
    {
        system("cls");
        cout << "\n\t\t\t\t===============================\n";
        cout <<"\t\t\t\t       Admin functions\n";
        cout << "\t\t\t\t===============================\n\n";
        cout << "1-Add New Client\n";
        cout << "2-List Of All Clients\n";
        cout << "3-Search For A Client\n";
        cout << "4-Edit Client\n";
        cout << "5-Add New Employee\n";
        cout << "6-List Of All Employees\n";
        cout << "7-Search For A Employee\n";
        cout << "8-Edit Employee\n";
        cout << "9-Display\n";
        cout << "10-Update Password\n";
        cout << "11-Logout\n\n";
    }
    static bool adminOptions(Admin* admin)
    {
        int choice ;
        cout << "Enter your choice :  ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            newClient(admin);
            break;
        }
        case 2:

        {
            system("cls");
            listAllClients(admin);
            break;
        }
        case 3:

        {
            system("cls");
            searchForClient(admin);
            break;
        }
        case 4:

        {
            system("cls");
            editClientInfo(admin);
            break;
        }
        case 5:

        {
            system("cls");
            newEmployee(admin);
            break;
        }
        case 6:
        {
            system("cls");
            listAllEmployee(admin);
            break;
        }
        case 7:
        {
            system("cls");
            searchForEmployee(admin);
            break;
        }
        case 8:
        {
            system("cls");
            editEmployeeInfo(admin);
            break;
        }

        case 9:
        {
            system("cls");
            admin->display();
            break;
        }
        case 10:
        {
            system("cls");
            ClientManager::updatePassword(admin);
            break;
        }
        case 11:
        {
            _Filemanager.updateAllFiles();
            return true;
        }

        default:
        {
            cout << "\n\n\t###################################\n\n";
            cout << "\t** Make Sure Of Your Choice ! **\n\n";
            cout << "\t###################################\n";
            printAdminMenu();
            adminOptions(admin);
        }
        }
        Back(admin);
    }
    static void newEmployee(Admin* admin)
    {
        Employee* employee = new Employee();
        string name, password;
        double salary;
        int id;
        cout<<"Enter New Employee \n\n";
        employee->setName(name) ;
        employee->setPassword(password);
        employee->setSalary(salary);
        id  = FilesHelper::getLast("EmployeeLastId.txt");
        employee->setId(id+1);
        FilesHelper::saveLast("EmployeeLastId.txt", id+1);
        admin->addEmployee(*employee);
        cout << "\n\n\t###################################\n\n";
        cout << "\t** Employee Accepted **\n\n";
        cout << "\t###################################\n\n";
    }
    static void listAllEmployee(Admin* admin)
    {
        admin->listEmployee();
    }
    static void searchForEmployee(Admin* admin)
    {
        int id;
        cout<<"Employee Id : ";
        cin>>id;
        Employee* employee = admin->searchEmployee(id);
        if(employee == NULL)
        {
            cout << "\n\n\t###################################\n\n";
            cout << "\t** Employee Not Found **\n\n";
            cout << "\t###################################\n\n";
        }
        else
        {
            employee->display();
        }
    }
    static void editEmployeeInfo(Admin* admin)
    {
        int choice, id;
        string name, password;
        double salary;
        cout << " \n Enter Your Id \n ";
        cin >> id;
        Employee* employee = admin->searchEmployee(id);
        if (employee != NULL)
        {
            AdminManager::edit(employee);
        }
        else
        {
            cout << "\n\n\t###################################\n\n";
            cout << "\t** Employee Not Found **\n\n";
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
                editEmployeeInfo(admin);
                break;
            }
            case 2:
            {
                printAdminMenu();
                adminOptions(admin);
                break;
            }
            default:
            {
                cout << "\n\n\t###################################\n\n";
                cout << "\t** Make Sure Of Your Choice ! **\n\n";
                cout << "\t###################################\n\n";
                system("pause");
                printAdminMenu();
                adminOptions(admin);
                break;
            }
            }
            Back(admin);
        }
    }
    static Admin* login(int id, string password)
    {
        Admin *admin = AdminManager::searchAdmin(id);
        if(admin == NULL)
        {
            cout << "\n\n\t###################################\n\n";
            cout << "\t   ** Invalid Id Or Password **\n\n";
            cout << "\t###################################\n\n";
            return NULL;
        }
        else
        {
            if(admin->getPassword() == password)
            {
                return admin;
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

#endif // ADMINMANAGER_H
