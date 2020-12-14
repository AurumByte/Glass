#include "../include/Glass.h"
#include "../include/GetStr.h"
#include "../include/System.h"
#include "../include/Generic.h"
#include "../include/PostThread.h"
#include "../include/Collections.h"

using namespace std;

int main()
{
    fstream in;
    string Line;
    string DirName;
    string Lst[] = {"Location> ", "File name> "};

    int Count = 0;
    for (int i = 0; i < 2; i++)
    {
        cout << Lst[i];
        getline(cin, DirName);
        if (i == 0)
        {
            chdir(DirName.c_str());
        }

        else if (i == 1)
        {
            in.open(DirName);
        }
    }

    // Package manager.
    int Syspart = 0;
    int Cgrpart = 0;
    int Postpart = 0;
    int Genericpart = 0;
    int Collectionpart = 0;

    system("cls");
    while (in)
    {
        Count++;
        getline(in, Line);
        // These are not part of any Package.
        if (Line == "" || Line == " " || startswith(Line, "  ")) continue;
        else if (startswith(Line, "//")) continue;
        else if (Line == "Quit();") exit(0);

        // These are the Package caller.
        else if (Line == "using System;") Syspart = 1;
        else if (Line == "using PostThread;") Postpart = 1;
        else if (Line == "using Generic;") Genericpart = 1;
        else if (Line == "using Collections.DataTypes;") Collectionpart = 1;
        else if (Line == "using Cgr.Graphics;") Cgrpart = 1;

        // These are the part of the System Package.
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
        else if (getString(Line, "string ", ";") && Collectionpart == 1) DataTypeStr(Line);

        // This is the error finder.
        else
        {
            system("cls");
            system("color 04");
            cout << "Error.\nException Catched at Line: " << Count;
            exit(0);
        }
    }
    in.close();
    return 0;
}
