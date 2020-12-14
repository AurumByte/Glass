#include "../include/Glass.h"
#include "../include/GetStr.h"
#include "../include/System.h"

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
    system(repl5.c_str());
}

void ConsoleTitle(const std::string lines)
{
    string repl = replace(lines, "\\Console.Title", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    system(("title " + repl5).c_str());
}

void ConsoleColor(const std::string lines)
{
    string repl = replace(lines, "\\Console.Color", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    system(("color " + repl5).c_str());
}

void ConsoleShout(const std::string lines)
{
    string repl = replace(lines, "\\Console.Shout", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    cout << repl5;
}

void ConsoleShoutln(const std::string lines)
{
    string repl = replace(lines, "\\Console.Shoutln", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    cout << repl5 << endl;
}

std::string ConsoleGet(const std::string lines)
{
    string repl = replace(lines, "\\Console.Get", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5 = replace(repl4, "\"", "");
    cout << repl5;
    return repl5;
}
