#ifndef CLIENTMANGER_H
#define CLIENTMANGER_H


class ClientManger
{
public:
    static void updatePassword(Person* person)
    {
        string password;
        cout << "/n enter the new password /n";
        person->setPassword(password);
        cout << "/n Your Password updated" << endl;
    }
    static Client* login(int id, string password)
    {
        Client *clientptr = Employee.searchClient(id);
        if(clientptr == NULL)
        {
            return NULL;
        }
        else
        {
            if(clientptr->getPassword() == password)
            {
                return clientptr
            }
            else
            {
            }
            return NULL;
        }

    }
};

#endif // CLIENTMANGER_H
