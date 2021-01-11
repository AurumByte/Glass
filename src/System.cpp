#include "../include/Glass.h"

using namespace std;

void ConsoleClear()
{
    system("cls");
}

void ConsoleCMD(const std::string lines)
{
    string repl = replace(lines, "\\Console.CMD", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    if (StrFind(repl4, "\"") == false && VarTypes[repl4] == "type<string>") system(variables[repl4].c_str());
    else if (StrFind(repl4, "\"")) system(repl5.c_str());
    else cout << "None" << endl;
}

void ConsoleTitle(const std::string lines)
{
    string repl = replace(lines, "\\Console.Title", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    if (StrFind(repl4, "\"") == false && VarTypes[repl4] == "type<string>") system(("title " + variables[repl4]).c_str());
    else if (StrFind(repl4, "\"")) system(("title " + repl5).c_str());
    else cout << "None" << endl;
}

void ConsoleColor(const std::string lines)
{
    string repl = replace(lines, "\\Console.Color", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    if (StrFind(repl4, "\"") == false && VarTypes[repl4] == "type<string>") system(("color " + variables[repl4]).c_str());
    else if (StrFind(repl4, "\"")) system(("color " + repl5).c_str());
    else cout << "None" << endl;
}

void ConsoleShout(const std::string lines)
{
    string repl = replace(lines, "\\Console.Shout", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    if (StrFind(repl4, "\"") == false) cout << variables[repl4];
    else if (StrFind(repl4, "\"")) cout << repl5;
    else cout << "None" << endl;
}

void ConsoleShoutln(const std::string lines)
{
    string repl = replace(lines, "\\Console.Shoutln", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    if (StrFind(repl4, "\"") == false) cout << variables[repl4] << endl;
    else if (StrFind(repl4, "\"")) cout << repl5 << endl;
    else cout << "None" << endl;
}

std::string ConsoleGet(const std::string lines)
{
    string repl = replace(lines, "\\Console.Get", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");

    string return_val;
    if (StrFind(repl4, "\"") == false)
    {
        cout << variables[repl4];
        return_val = variables[repl4];
    }

    else if (StrFind(repl4, "\""))
    {
        cout << repl5;
        return_val = repl5;
    }

    else return_val = "None";
    return return_val;
}
