#include "../include/Glass.h"
#include "../include/GetStr.h"

using namespace std;

int main()
{
    fstream in;
    string Lst[] = {"Location> ", "File name> "};
    string DirName;
    string Line;
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
    system("cls");
    while (in)
    {
        Count++;
        getline(in, Line);
        if (Line == "" || Line == " " || startswith(Line, "  "))
        {
            continue;
        }

        else if (startswith(Line, "//"))
        {
            continue;
        }

        else if (getString(Line, "Console.Shout(", ");"))
        {
            string repl = replace(Line, "\\Console.Shout", "");
            string repl2 = replace(repl, "\\;", "");
            string repl3 = replace(repl2, "\\(", "");
            string repl4 = replace(repl3, "\\)", "");
            string repl5 = replace(repl4, "\"", "");
            cout << repl5;
        }

        else if (getString(Line, "Console.Get(", ");"))
        {
            string Input;
            getline(cin, Input);
        }

        else
        {
            system("cls");
            system("color 04");
            cout << "Error.\nProblem Catched at Line: " << Count;
            exit(0);
        }
    }
    in.close();
    return 0;
}
