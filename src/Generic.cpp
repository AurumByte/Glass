#include "../include/Glass.h"

using namespace std;

std::string RandomRange(const std::string num)
{
    string repl = replace(num, "\\Random.range", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5;

    if (StrFind(repl4, ", ")) repl5 = replace(repl4, ", ", " ");
    else if (StrFind(repl4, ",")) repl5 = replace(repl4, ",", " ");

    auto Comma = repl5.substr(0, repl5.find(' '));
    auto Comma2 = repl5.substr(Comma.size() + 1, Comma.find(' '));

    srand(time(0));

    int min = stoi(Comma);
    int max = stoi(Comma2);
    int Number = (rand() % max) + min;
    return to_string(Number);
}

std::string RandomUniform(const std::string num)
{
    string repl = replace(num, "\\Random.Uniform", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5;

    if (StrFind(repl4, ", ")) repl5 = replace(repl4, ", ", " ");
    else if (StrFind(repl4, ",")) repl5 = replace(repl4, ",", " ");

    auto Comma = repl5.substr(0, repl5.find(' '));
    auto Comma2 = repl5.substr(Comma.size() + 1, Comma.find(' '));

    srand(time(0));

    int min = stoi(Comma);
    int max = stoi(Comma2);
    double Number = (double)((rand() % max) + min) * .1;
    return to_string(Number);
}
