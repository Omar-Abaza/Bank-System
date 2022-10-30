#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class Parser
{
public:
    static vector<string> split(string line)
    {
        stringstream s(line);
        vector<string> info;
        string data;
        while(getline(s,data,'|'))
        {
            info.push_back(data);
        }
        return info;
    }
    static Client parseToClient(string line)
    {
        vector<string> info = split(line);
        Client c(stoi(info[0]),info[1],info[2],stod(info[3]));
        return c;
    }
    static Employee parseToEmployee(string line)
    {
        vector<string> info = split(line);
        Employee e(stoi(info[0]),info[1],info[2],stod(info[3]));
        return e;
    }
    static Admin parseToAdmin(string line)
    {
        vector<string> info = split(line);
        Admin a(stoi(info[0]),info[1],info[2],stod(info[3]));
        return a;
    }
};

#endif // PARSER_H
