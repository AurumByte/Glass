#include "../include/Glass.h"

using namespace std;

bool StrFind(const std::string& MainStr, const std::string& SubString)
{
    if (MainStr.find(SubString) != std::string::npos) return true;
    else return false;
}

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

bool getString(const std::string& StartStr, const std::string& s1, const std::string& s2)
{
    bool Sw = startswith(StartStr, s1);
    bool Ew = endswith(StartStr, s2);
    if (Sw == true && Ew == true) return true;
    else return false;
}

std::string replace(const std::string MainString, const std::string& ToRepl, const std::string& WithRepl)
{
    string repl = regex_replace(MainString, regex(ToRepl), WithRepl);
    return repl;
}

std::string join(std::string& JoinString, const std::string& JoinWith)
{
    string Join = JoinString.append(JoinWith);
    return Join;
}
