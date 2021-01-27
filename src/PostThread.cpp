#include "../include/Glass.h"

using namespace std;

void PostThreadSleep(const std::string lines)
{
    string repl = replace(lines, "\\Time.Sleep", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");

    int SleepTime;
    if (StrFind(repl4, "\"") == false && VarTypes[repl4] == "type<int>" or StrFind(repl4, "\"") == false && VarTypes[repl4] == "type<float>") SleepTime = stoi(variables[repl4]);
    else if (StrFind(repl4, "\"") == false) SleepTime = stoi(repl4);
    else SleepTime = 0;

    sleep(SleepTime);
}

std::string PostThreadNow()
{
	time_t now = time(0);
	std::string date_time = ctime(&now);
	return date_time;
}
