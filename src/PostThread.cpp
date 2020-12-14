#include "../include/Glass.h"
#include "../include/GetStr.h"
#include "../include/PostThread.h"

using namespace std;

void PostThreadSleep(const std::string lines)
{
    string repl = replace(lines, "\\Time.Sleep", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");

    int SleepTime = stoi(repl4);
    sleep(SleepTime);
}
