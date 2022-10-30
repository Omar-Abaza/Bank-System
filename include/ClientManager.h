#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H
#include "Client.h"
#include "Employee.h"
#include "FileManager.h"
#include "FileManager.h"
FileManager _Filemanager;

Employee _Employee;
class ClientManager
{
private:
    static void Back(Client* client)
    {
        system("pause");
        printClientMenu();
        clientOptions(client);
    }
public:
    static void printClientMenu()
    {
        system("cls");
        cout << "\n\t\t\t\t===============================\n";
        cout <<"\t\t\t\t       Client functions\n";
        cout << "\t\t\t\t===============================\n\n";
        cout << "1-deposit\n";
        cout << "2-withdraw\n";
        cout << "3-transfer to\n";
        cout << "4-checkBalance\n";
        cout << "5-Display\n";
        cout << "6-Update password\n";
        cout << "7-logout\n\n";

    }
    static void updatePassword(Person* person)
    {
        string password;
        cout << "\n Enter The New Password \n";
        person->setPassword(password);

        cout << "\n\n\t###################################\n\n";
        cout << "\t** Your Password Updated **\n\n";
        cout << "\t###################################\n";
    }
    static Client* login(int id, string password)
    {
        Client *client = _Employee.searchClient(id);
        if(client == NULL)
        {
            cout << "\n\n\t###################################\n\n";
            cout << "\t   ** Invalid Id Or Password **\n\n";
            cout << "\t###################################\n\n";
            return NULL;
        }
        else
        {
            if(client->getPassword() == password)
            {

                return client;
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
    static bool clientOptions(Client* client)
    {
        int choice, id;
        double amount;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            client->deposit(amount);
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Enter Amount to Withdraw : ";
            cin >> amount;
            client->withdraw(amount);
            break;
        }
        case 3:
        {
            system("cls");
            Client* otherClinet;
            cout << "Enter client id to want to transfer to : ";
            cin >> id;
            otherClinet = _Employee.searchClient(id);
            if (otherClinet != NULL)
            {
                cout << "Enter amount To transfer to :";
                cin >> amount;
                client->transferTo(amount, *otherClinet);
            }
            else
            {
                cout << "\n\n\t###################################\n\n";
                cout << "\t** The Other client Not Found In System **\n\n";
                cout << "\t###################################\n\n";
            }
            break;

        }
        case 4:
        {
            system("cls");
            client->checkBalance();
            break;
        }
        case 5:
        {
            system("cls");
            client->display();
            break;

        }
        case 6:
        {
            system("cls");
            updatePassword(client);
            break;
        }
        case 7:
        {
            _Filemanager.updateAllFiles();
            return true;
        }
        default:
        {
            cout << "\n\n\t###################################\n\n";
            cout << "\t** Make Sure Of Your Choice ! **\n\n";
            cout << "\t###################################\n\n";
            clientOptions(client);


        }
        }
        Back(client);
    }
};

#endif // CLIENTMANAGER_H
