#include "../include/Glass.h"

using namespace std;

void ConsoleClear()
{
    system("cls");
}

void ConsoleColorReser()
{
    setConsoleColor(7);
}

void ConsoleCMD(const std::string lines)
{
    string repl = replace(lines, "\\Console.CMD", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    if (getString(repl4, "\"", "\"")) system(repl5.c_str());
    else if (getString(repl4, "\"", "\"") == false && VarTypes[repl4] == "type<string>") system(variables[repl4].c_str());
    else if (getString(repl4, "\'", "\'") || getString(repl4, "\"", "\'") || getString(repl4, "\'", "\"") || startswith(repl4, "\"") == false || endswith(repl4, "\"") == false) Error(lines, to_string(Count));
    else Error(lines, to_string(Count));
}

void ConsoleTitle(const std::string lines)
{
    string repl = replace(lines, "\\Console.Title", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    if (getString(repl4, "\"", "\"")) system(("title " + repl5).c_str());
    else if (getString(repl4, "\"", "\"") == false && VarTypes[repl4] == "type<string>") system(("title " + variables[repl4]).c_str());
    else if (getString(repl4, "\'", "\'") || getString(repl4, "\"", "\'") || getString(repl4, "\'", "\"") || startswith(repl4, "\"") == false || endswith(repl4, "\"") == false) Error(lines, to_string(Count));
    else Error(lines, to_string(Count));
}

void ConsoleColor(const std::string lines)
{
    string repl = replace(lines, "\\Console.Color", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    if (getString(repl4, "\"", "\"")) system(("color " + repl5).c_str());
    else if (getString(repl4, "\"", "\"") == false && VarTypes[repl4] == "type<string>") system(("color " + variables[repl4]).c_str());
    else if (getString(repl4, "\'", "\'") || getString(repl4, "\"", "\'") || getString(repl4, "\'", "\"") || startswith(repl4, "\"") == false || endswith(repl4, "\"") == false) Error(lines, to_string(Count));
    else Error(lines, to_string(Count));
}

void ConsoleShout(const std::string lines)
{
    string repl = replace(lines, "\\Shout", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    if (getString(repl4, "\"", "\"")) cout << repl5;
    else if (getString(repl4, "\"", "\"") == false) cout << variables[repl4];
    else if (getString(repl4, "\'", "\'") || getString(repl4, "\"", "\'") || getString(repl4, "\'", "\"") || startswith(repl4, "\"") == false || endswith(repl4, "\"") == false) Error(lines, to_string(Count));
    else Error(lines, to_string(Count));
}

void ConsoleShoutln(const std::string lines)
{
    string repl = replace(lines, "\\Shoutln", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    if (getString(repl4, "\"", "\"")) cout << repl5 << endl;
    else if (getString(repl4, "\"", "\"") == false) cout << variables[repl4] << endl;
    else if (getString(repl4, "\'", "\'") || getString(repl4, "\"", "\'") || getString(repl4, "\'", "\"") || startswith(repl4, "\"") == false || endswith(repl4, "\"") == false) Error(lines, to_string(Count));
    else Error(lines, to_string(Count));
}

void ConsoleGetKey(const std::string lines)
{
    string repl = replace(lines, "\\GetKey", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");

    if (getString(repl4, "\"", "\"")) cout << repl5;
    else if (getString(repl4, "\"", "\"") == false) cout << variables[repl4];
    else if (getString(repl4, "\'", "\'") || getString(repl4, "\"", "\'") || getString(repl4, "\'", "\"") || startswith(repl4, "\"") == false || endswith(repl4, "\"") == false)
    {
        Error(lines, to_string(Count));
    }

    else Error(lines, to_string(Count));
}

std::string ConsoleGet(const std::string lines)
{
    string repl = replace(lines, "\\Get", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");

    string return_val;
    if (getString(repl4, "\"", "\""))
    {
        cout << repl5;
        return_val = repl5;
    }

    else if (getString(repl4, "\"", "\"") == false)
    {
        cout << variables[repl4];
        return_val = variables[repl4];
    }

    else if (getString(repl4, "\'", "\'") || getString(repl4, "\"", "\'") || getString(repl4, "\'", "\"") || startswith(repl4, "\"") == false || endswith(repl4, "\"") == false)
    {
        return_val = "None";
        Error(lines, to_string(Count));
    }

    else
    {
        return_val = "None";
        Error(lines, to_string(Count));
    }
    return return_val;
}
