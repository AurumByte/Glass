#include "../include/Glass.h"
#include "../include/GetStr.h"
#include "../include/System.h"
#include "../include/Generic.h"
#include "../include/Collections.h"

using namespace std;

std::string DataTypeStr(const std::string lines)
{
    string repl = replace(lines, "string ", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\= ", "");
    string repl4 = replace(repl3, "\"", "");
    if (StrFind(repl2, "= "))
    {
        auto name = repl3.substr(0, repl3.find(' '));
        auto data = repl3.substr(name.size() + 1, name.find(' '));
        if (getString(data, "Console.Get(", ")"))
        {
            string Input = ConsoleGet(data);
            getline(cin, Input);

            string TitleVal = join(name, " ");
            string GetValue = join(TitleVal, Input);
            string repl5 = replace(GetValue, "\n", "");

            return repl5;
        }

        else if (StrFind(repl3, "\"")) return repl4;
        else return "None";
    }

    else return "None";
}

std::string DataTypeInt(const std::string lines)
{
    string repl = replace(lines, "int ", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\= ", "");
    if (StrFind(repl2, "= "))
    {
        auto name = repl3.substr(0, repl3.find(' '));
        auto data = repl3.substr(name.size() + 1, name.find(' '));
        if (getString(data, "Random.rand(", ")"))
        {
            string Num = RandomRange(data);

            string TitleVal = join(name, " ");
            string GetValue = join(TitleVal, Num);
            string repl5 = replace(GetValue, "\n", "");

            return repl5;
        }

        else if (StrFind(repl3, "\"") == false) return repl3;
        else return "None";
    }

    else return "None";
}
