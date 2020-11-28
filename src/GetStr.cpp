#include "../include/Glass.h"
#include "../include/GetStr.h"

using namespace std;

bool startswith(const std::string& StartString, const std::string& SubStart)
{
    if (StartString.rfind(SubStart) == 0) return true;
    else return false;    
}

bool endswith(const std::string& EndString, const std::string& SubEnd)
{
    bool Ends = EndString.find(SubEnd, EndString.size() - SubEnd.size()) != string::npos;
    if (Ends) return true;
    else return false;
}

bool getString(const std::string& StartStr, const std::string& s1, const std::string& EndStr, const std::string& s2)
{
    bool Sw = startswith(StartStr, s1);
    bool Ew = endswith(EndStr, s2);
    if (Sw == true && Ew == true) return true;
    else return false;
}

string replace(const std::string& MainString, const std::string& ToRepl, const std::string& WithRepl)
{
    regex re("(" + ToRepl + ")(.*)");
    string repl = regex_replace(MainString, re, WithRepl);
    return repl;
}
