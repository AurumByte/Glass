// Glass programming language
// All these includes will be used in Glass
#include "../include/Glass.h"
#include "../include/GetStr.h"
#include "../include/System.h"
#include "../include/Generic.h"
#include "../include/PostThread.h"
#include "../include/Collections.h"

using namespace std; // This will help us not to write std:: multiple times

// These are the Glass variable dictionaries
std::map<std::string, std::string> variables;
std::map<std::string, std::string> VarTypes;
int main()
{
    // Global variables
    fstream in;
    string Line;
    string DirName;
    int Count = 0;

    // Initializing Glass
    system("title Glass");
    cout << "File Path> ";
    getline(cin, DirName);
    in.open(DirName);

    // Package manager.
    int Syspart = 0;
    int Cgrpart = 0;
    int Postpart = 0;
    int FileIOpart = 0;
    int Genericpart = 0;
    int Collectionpart = 0;

    // Main langauge
    system("cls");
    while (in)
    {
        Count++;
        getline(in, Line);
        // These are not part of any Package.
        if (Line == "" || Line == " " || startswith(Line, "  ")) continue;
        else if (startswith(Line, "//")) continue;

        // These are the Package caller.
        else if (Line == "using System;") Syspart = 1;
        else if (Line == "using FileIO;") FileIOpart = 1;
        else if (Line == "using Generic;") Genericpart = 1;
        else if (Line == "using PostThread;") Postpart = 1;
        else if (Line == "using Cgr.Graphics;") Cgrpart = 1;
        else if (Line == "using Collections.DataTypes;") Collectionpart = 1;

        // These are the part of the System Package.
        else if (Line == "Console.Quit();" && Syspart == 1) exit(0);
        else if (Line == "Console.Clear();" && Syspart == 1) ConsoleClear();
        else if (getString(Line, "Console.CMD(", ");") && Syspart == 1) ConsoleCMD(Line);
        else if (getString(Line, "Console.Title(", ");") && Syspart == 1) ConsoleTitle(Line);
        else if (getString(Line, "Console.Color(", ");") && Syspart == 1) ConsoleColor(Line);
        else if (getString(Line, "Console.Shout(", ");") && Syspart == 1) ConsoleShout(Line);
        else if (getString(Line, "Console.Shoutln(", ");") && Syspart == 1) ConsoleShoutln(Line);
        else if (getString(Line, "Console.Get(", ");") && Syspart == 1)
        {
            string Input = ConsoleGet(Line);
            getline(cin, Input);
        }

        // These are the part of PostThread Package.
        else if (getString(Line, "Time.Sleep(", ");") && Postpart == 1) PostThreadSleep(Line);

        // These are the part of the Generic Package.
        else if (getString(Line, "Random.rand(", ");") && Genericpart == 1) RandomRange(Line);

        // These are the part of Collections Package.
        else if (getString(Line, "string ", ";") && Collectionpart == 1)
        {
            string Value = DataTypeStr(Line);
            string Type = "type<string>";

            auto Title = Value.substr(0, Value.find(' '));
            auto Content = Value.substr(Title.size() + 1, Title.find(' '));

            variables[Title] = Content;
            VarTypes[Title] = Type;
        }

        else if (getString(Line, "int ", ";") && Collectionpart == 1)
        {
            string Value = DataTypeInt(Line);
            string Type = "type<int>";

            auto Title = Value.substr(0, Value.find(' '));
            auto Content = Value.substr(Title.size() + 1, Title.find(' '));

            variables[Title] = Content;
            VarTypes[Title] = Type;
        }

        // This will Catch an Exceptional error.
        else
        {
            system("cls");
            system("color 04");
            cout << "Error.\nException Catched at Line: " << Count << endl << "Exceptional Line: " << Line;
            exit(0);
        }
    }
    in.close();
    return 0;
}
