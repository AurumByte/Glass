#include "../include/Glass.h"
#include "../include/GetStr.h"

using namespace std;

bool startswith(string MainString, string SubString)
{
    if (MainString.rfind(SubString) == 0) return true;
    else return false;    
}

bool endswith(string MainString, string SubString)
{
    bool Ends = MainString.find(SubString, MainString.size() - SubString.size()) != string::npos;
    if (Ends) return true;
    else return false;
}

bool getString(string StartString, string s1, string EndString, string s2)
{
    bool Sw = startswith(StartString, s1);
    bool Ew =endswith(EndString, s2);
    if (Sw == true && Ew == true) return true;
    else return false;
}

string replace(string MainString, string ToRepl, string WithRepl)
{
    string Replace = regex_replace(MainString, regex(ToRepl), WithRepl);
    return Replace;
}
