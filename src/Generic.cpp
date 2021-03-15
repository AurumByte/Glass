// All these includes will be used in Glass
#include "../include/Glass.h"

using namespace std; // This will help us not to write std:: multiple times

// This function will be used to generate a random whole number.
std::string RandomRange(const std::string num)
{
    // Create some variable which will replace all the syntax words.
    string repl = replace(num, "\\Random.range", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5;

    // Check whether if space is there in "," or not.
    if (StrFind(repl4, ", ")) repl5 = replace(repl4, ", ", " ");
    else if (StrFind(repl4, ",")) repl5 = replace(repl4, ",", " ");

    // Split the string and create "Comma" and "Comma2" variable.
    auto Comma = repl5.substr(0, repl5.find(' '));
    auto Comma2 = repl5.substr(Comma.size() + 1, Comma.find(' '));

    srand(time(0)); // Set the Seed of time to 0 (Process with PC time).

    // Convert string to int, generate a random whole number and return the value.
    int min = stoi(Comma);
    int max = stoi(Comma2);
    int Number = (rand() % max) + min;
    return to_string(Number);
}

// This function will be used to generate a random decimal number.
std::string RandomUniform(const std::string num)
{
    // Create some variable which will replace all the syntax words.
    string repl = replace(num, "\\Random.Uniform", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\(", "");
    string repl4 = replace(repl3, "\\)", "");
    string repl5;

    // Check whether if space is there in "," or not.
    if (StrFind(repl4, ", ")) repl5 = replace(repl4, ", ", " ");
    else if (StrFind(repl4, ",")) repl5 = replace(repl4, ",", " ");

    // Split the string and create "Comma" and "Comma2" variable.
    auto Comma = repl5.substr(0, repl5.find(' '));
    auto Comma2 = repl5.substr(Comma.size() + 1, Comma.find(' '));

    srand(time(0)); // Set the Seed of time to 0 (Process with PC time).

    // Convert string to int, generate a random decimal number and return the value.
    int min = stoi(Comma);
    int max = stoi(Comma2);
    int ZeroToOne = (rand() % 1000);
    int Number = (rand() % max) + min;

    string Decimal = "0." + to_string(ZeroToOne);
    float UniformNum = stof(Decimal) * Number;
    return to_string(UniformNum);
}
