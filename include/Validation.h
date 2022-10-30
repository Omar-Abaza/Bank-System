#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Validation
{
private:
    static bool validateName(string name)
    {

        int nameLength = name.length();
        char nameOne[nameLength];
        strcpy(nameOne,name.c_str());
        if(strlen(nameOne)<5 || strlen(nameOne)>20)
        {
            return false;
        }
        for(int i=0; i<strlen(nameOne); i++)
        {
            while(!isalpha(nameOne[i]))
            {
                return false;
            }
        }
        return true;

    }
    static bool validatePassword(string password)
    {
        bool hasLower = false, hasUpper = false, hasDigit = false, specialChar = false;
        string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
        int passwordLength = password.length();
        char passwordOne[passwordLength];
        strcpy(passwordOne,password.c_str());
        if(strlen(passwordOne)<8 || strlen(passwordOne)>20)
        {
            return false;
        }
        for(int i=0; i<strlen(passwordOne); i++)
        {
            if (islower(passwordOne[i]))
                hasLower = true;
            if (isupper(passwordOne[i]))
                hasUpper = true;
            if (isdigit(passwordOne[i]))
                hasDigit = true;
            size_t special = password.find_first_not_of(normalChars);
            if (special != string::npos)
                specialChar = true;
        }
        if(!hasLower || !hasUpper || !hasDigit || !specialChar)
        {
            return false;
        }
        return true;

    }
    static bool validateBalance(double balance)
    {
        if(balance>=1500 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    static bool validateSalary(double salary)
    {
        if(salary>=5000)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    static string enterName()
    {
        string name;
        cout<< "Enter Name: ";
        cin>>name;
        while(!validateName(name))
        {
            cout<< "Invalid name!\n";
            cout<<"*Name size should be between (5-20) chars and Characters Only \n\n";
            cout<< "Enter Name: ";
            cin>>name;
        }
        return name;
    }
    static string enterPassword()
    {
        string password;
        cout<< "Enter password: ";
        cin>>password;
        while(!validatePassword(password))
        {
            cout<< "Invalid password!\n";
            cout<<"*Password size should be between (8-20) chars.\n";
            cout<<"*Your password should have (lower, upper, digit and special Chars).\n\n";
            cout<< "Enter password: ";
            cin>>password;
        }
        return password;
    }
    static double enterBalance()
    {
        double balance;
        cout<< "Enter balance: ";
        cin>>balance;
        while(!validateBalance(balance))
        {
            cout<< "Invalid balance!\n";
            cout<<"*The Min balance is 1500.\n\n";
            cout<< "Enter balance: ";
            cin>>balance;
        }
        return balance;
    }
    static double enterSalary()
    {
        double salary;
        cout<< "Enter salary: ";
        cin>>salary;
        while(!validateSalary(salary))
        {
            cout<< "Invalid salary!\n";
            cout<<"*The Min salary is 5000.\n\n";
            cout<< "Enter salary: ";
            cin>>salary;
        }
        return salary;
    }

};

#endif // VALIDATION_H
