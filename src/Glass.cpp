// Glass programming language
// All these includes will be used in Glass
#include "../include/Glass.h"

using namespace std; // This will help us not to write std:: multiple times

// These are the Glass variable dictionaries
std::map<std::string, std::string> variables;
std::map<std::string, std::string> VarTypes;

// Package manager.
int Syspart;
int Cgrpart;
int Postpart;
int Webbrowser;
int FileIOpart;
int Genericpart;
int Collectionpart;

int Count; // This will make Count variable global which will be used by Error function.
int Comments; // This will make Comments variable global which will be used to check whether there is a multiline comment in the code.

std::string Arguments[7000]; // Change this in FUTURE.

// This is a global function which will help to make error messages more dynamic.
void Error(const std::string lines, const std::string num)
{
    setConsoleColor(04);
    cout << "Error.\nException Catched at Line: " << num << endl << "Exceptional Line: " << lines;
    setConsoleColor(7);
    exit(0);
}

int main(int argc, char** argv)
{
    // Global variables
    fstream in;
    string Line;
    string DirName;
    Count = 0;

    // Initializing Glass
    DirName = argv[1];
    if (endswith(DirName, ".glass")) in.open(DirName);
    else
    {
    	setConsoleColor(04);
    	cout << "Error.\nCannot read \"" << DirName << "\"" << endl;
        setConsoleColor(7);
    	exit(0);
    }

    // Package manager.
    Syspart = 0;
    Cgrpart = 0;
    Postpart = 0;
    FileIOpart = 0;
    Webbrowser = 0;
    Genericpart = 0;
    Collectionpart = 0;

    // Comments and Arguments manager.
    Comments = 0;
    for (int argus = 0; argus < argc; argus++) Arguments[argus] = argv[argus];

    // Main langauge
    while (in)
    {
        Count++;
        getline(in, Line);
        // These are not part of any Package.
        if (Line == "" || Line == " " || startswith(Line, "  ")) continue;
        else if (startswith(Line, "//")) continue;
        else if (getString(Line, "/*", "*/")) continue;
        else if (startswith(Line, "/*") && Comments == 0) Comments = 1;
        else if (endswith(Line, "*/") && Comments == 1) Comments = 0;

        // These are the Package caller.
        else if (Line == "using System;" && Comments == 0) Syspart = 1;
        else if (Line == "using FileIO;" && Comments == 0) FileIOpart = 1;
        else if (Line == "using Generic;" && Comments == 0) Genericpart = 1;
        else if (Line == "using PostThread;" && Comments == 0) Postpart = 1;
        else if (Line == "using Webbrowser;" && Comments == 0) Webbrowser = 1;
        else if (Line == "using Cgr.Graphics;" && Comments == 0) Cgrpart = 1;
        else if (Line == "using Collections.DataTypes;" && Comments == 0) Collectionpart = 1;

        // These are the part of the System Package.
        else if (Line == "System.Exit();" && Syspart == 1 && Comments == 0) exit(0);
        else if (getString(Line, "System.argv[", "];") && Syspart == 1 && Comments == 0)
        {
            string ARGV = SystemArgv(Line);
            Arguments[stoi(ARGV)];
        }

        else if (Line == "Console.Clear();" && Syspart == 1 && Comments == 0) ConsoleClear();
        else if (getString(Line, "Console.CMD(", ");") && Syspart == 1 && Comments == 0) ConsoleCMD(Line);
        else if (getString(Line, "Console.Title(", ");") && Syspart == 1 && Comments == 0) ConsoleTitle(Line);
        else if (getString(Line, "Console.Color(", ");") && Syspart == 1 && Comments == 0) ConsoleColor(Line);
        else if (getString(Line, "Shout(", ");") && Syspart == 1 && Comments == 0) ConsoleShout(Line);
        else if (getString(Line, "Shoutln(", ");") && Syspart == 1 && Comments == 0) ConsoleShoutln(Line);
        else if (getString(Line, "Get(", ");") && Syspart == 1 && Comments == 0)
        {
            string Input = ConsoleGet(Line);
            getline(cin, Input);
        }

        else if (getString(Line, "GetKey(", ");") && Syspart == 1 && Comments == 0)
        {
            ConsoleGetKey(Line);
            getch();
        }

        // These are the part of PostThread Package.
        else if (getString(Line, "Time.Sleep(", ");") && Postpart == 1 && Comments == 0) PostThreadSleep(Line);
        else if (Line == "Time.Now();" && Postpart == 1 && Comments == 0) PostThreadNow();

        // These are the part of the Generic Package.
        else if (getString(Line, "Random.range(", ");") && Genericpart == 1 && Comments == 0) RandomRange(Line);
        else if (getString(Line, "Random.Uniform(", ");") && Genericpart == 1 && Comments == 0) RandomUniform(Line);

        // These are the part of Collections Package.
        else if (getString(Line, "string ", ";") && Collectionpart == 1 && Comments == 0)
        {
            string Value = DataTypeStr(Line);
            string Type = "type<string>";

            auto Title = Value.substr(0, Value.find(' '));
            auto Content = Value.substr(Title.size() + 1, Title.find(' '));

            variables[Title] = Content;
            VarTypes[Title] = Type;
        }

        else if (getString(Line, "int ", ";") && Collectionpart == 1 && Comments == 0)
        {
            string Value = DataTypeInt(Line);
            string Type = "type<int>";

            auto Title = Value.substr(0, Value.find(' '));
            auto Content = Value.substr(Title.size() + 1, Title.find(' '));

            variables[Title] = Content;
            VarTypes[Title] = Type;
        }

        else if (getString(Line, "float ", ";") && Collectionpart == 1 && Comments == 0)
        {
            string Value = DataTypeFloat(Line);
            string Type = "type<float>";

            auto Title = Value.substr(0, Value.find(' '));
            auto Content = Value.substr(Title.size() + 1, Title.find(' '));

            variables[Title] = Content;
            VarTypes[Title] = Type;
        }

        else if (getString(Line, "bool ", ";") && Collectionpart == 1 && Comments == 0)
        {
            string Value = DataTypeBool(Line);
            string Type = "type<boolean>";

            auto Title = Value.substr(0, Value.find(' '));
            auto Content = Value.substr(Title.size() + 1, Title.find(' '));

            variables[Title] = Content;
            VarTypes[Title] = Type;
        }

        // This will Catch an Exceptional error.
        else
        {
            if (Comments == 0) Error(Line, to_string(Count));
            else continue;
        }
    }
    in.close();
    return 0;
}
