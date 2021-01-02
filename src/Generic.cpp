#include "../include/Glass.h"
#include "../include/GetStr.h"
#include "../include/Generic.h"

using namespace std;

std::string RandomRange(const std::string num)
{
    string repl = replace(num, "\\Random.rand", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");

    srand(time(0));

    int RangeNUM = stoi(repl4);
    int Number = rand() % RangeNUM;
    return to_string(Number);
}
