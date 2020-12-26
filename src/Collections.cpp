#include "../include/Glass.h"
#include "../include/GetStr.h"
#include "../include/Collections.h"

using namespace std;

std::string DataTypeStr(const std::string lines)
{
    string repl = replace(lines, "string ", "");
    string repl2 = replace(repl, "\\;", "");
    if (StrFind(repl2, "= "))
    {
        string repl3 = replace(repl2, "\\= ", "");
        if (StrFind(repl3, "\""))
        {
            string repl4 = replace(repl3, "\"", "");
            return repl4;
        }
        else return "None";
    }

    else return "None";
}
