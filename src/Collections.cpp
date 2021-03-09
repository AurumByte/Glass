#include "../include/Glass.h"

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
        if (getString(data, "\"", "\""))
        {
            string repl5 = replace(repl4, "\n", "");
            return repl5;
        }

        else if (getString(data, "Get(", ")") && Syspart == 1)
        {
            string Input = ConsoleGet(data);
            getline(cin, Input);

            string TitleVal = join(name, " ");
            string GetValue = join(TitleVal, Input);
            string repl5 = replace(GetValue, "\n", "");

            return repl5;
        }

        else if (data == "Time.Now()" && Postpart == 1)
        {
            string Currenttime = PostThreadNow();

            string TitleVal = join(name, " ");
            string GetValue = join(TitleVal, Currenttime);
            string repl4 = replace(GetValue, "\n", "");

            return repl4;
        }

        else if (getString(data, "System.argv[", "];") && Syspart == 1 && getString(data, "\'", "\'") == false || getString(data, "\"", "\'") == false || getString(data, "\'", "\"") == false || startswith(data, "\"") == false || endswith(data, "\"") == false)
        {
            string ARGV = SystemArgv(data);

            string TitleVal = join(name, " ");
            string argvValue = join(TitleVal, Arguments[stoi(ARGV)]);
            string repl5 = replace(argvValue, "\n", "");

            return repl5;
        }

        else if (getString(data, "\'", "\'") || getString(data, "\"", "\'") || getString(data, "\'", "\"") || startswith(data, "\"") == false || endswith(data, "\"") == false)
        {
            Error(lines, to_string(Count));
            return "None";
        }

        else
        {
            Error(lines, to_string(Count));
            return "None";
        }
    }

    else
    {
        Error(lines, to_string(Count));
        return "None";
    }
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
        if (getString(data, "Random.range(", ")") && Genericpart == 1)
        {
            string Num = RandomRange(data);

            string TitleVal = join(name, " ");
            string GetValue = join(TitleVal, Num);
            string repl4 = replace(GetValue, "\n", "");

            return repl4;
        }

        else if (getString(data, "\"", "\"") == false)
        {
            string repl4 = replace(repl3, "\n", "");
            return repl4;
        }

        else if (getString(data, "\'", "\'") || getString(data, "\"", "\'") || getString(data, "\'", "\"") || startswith(data, "\"") == false || endswith(data, "\"") == false)
        {
            Error(lines, to_string(Count));
            return "None";
        }

        else
        {
            Error(lines, to_string(Count));
            return "None";
        }
    }

    else
    {
        Error(lines, to_string(Count));
        return "None";
    }
}

std::string DataTypeFloat(const std::string lines)
{
    string repl = replace(lines, "float ", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\= ", "");
    if (StrFind(repl2, "= "))
    {
        auto name = repl3.substr(0, repl3.find(' '));
        auto data = repl3.substr(name.size() + 1, name.find(' '));
        if (getString(data, "Random.Uniform(", ")") && Genericpart == 1)
        {
            string Num = RandomUniform(data);

            string TitleVal = join(name, " ");
            string GetValue = join(TitleVal, Num);
            string repl4 = replace(GetValue, "\n", "");

            return repl4;
        }

        else if (getString(data, "Random.range(", ")") && Genericpart == 1)
        {
            string Num = RandomRange(data);

            string TitleVal = join(name, " ");
            string GetValue = join(TitleVal, Num);
            string repl4 = replace(GetValue, "\n", "");

            return repl4;
        }

        else if (getString(data, "\"", "\"") == false)
        {
            string repl4 = replace(repl3, "\n", "");
            return repl4;
        }

        else if (getString(data, "\'", "\'") || getString(data, "\"", "\'") || getString(data, "\'", "\"") || startswith(data, "\"") == false || endswith(data, "\"") == false)
        {
            Error(lines, to_string(Count));
            return "None";
        }

        else
        {
            Error(lines, to_string(Count));
            return "None";
        }
    }

    else
    {
        Error(lines, to_string(Count));
        return "None";
    }
}

std::string DataTypeBool(const std::string lines)
{
    string repl = replace(lines, "bool ", "");
    string repl2 = replace(repl, "\\;", "");
    string repl3 = replace(repl2, "\\= ", "");
    if (StrFind(repl2, "= "))
    {
        auto name = repl3.substr(0, repl3.find(' '));
        auto data = repl3.substr(name.size() + 1, name.find(' '));
        if (getString(repl3, "\"", "\"") == false && data == "True")
        {
            string GetValue = join(name, " True");
            string repl4 = replace(GetValue, "\n", "");

            return repl4;
        }

        else if (getString(repl3, "\"", "\"") == false && data == "False")
        {
            string GetValue = join(name, " False");
            string repl4 = replace(GetValue, "\n", "");

            return repl4;
        }

        else if (getString(data, "\'", "\'") || getString(data, "\"", "\'") || getString(data, "\'", "\""))
        {
            Error(lines, to_string(Count));
            return "None";
        }

        else
        {
            Error(lines, to_string(Count));
            return "None";
        }
    }

    else
    {
        Error(lines, to_string(Count));
        return "None";
    }
}
