#include "../include/Glass.h"
#include "../include/GetStr.h"

using namespace std;

int main()
{
    fstream in;

    string Lst[] = {"Location> ", "File name> "};
    string DirName;
    string Line;
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
        getline(in, Line);
        if (getString(Line, "Console.Shout(", Line, ");"))
        {
            cout << "Hello world";
            // string repl = replace(Line, "Console.Shout(", "");
            // string repl2 = replace(Line, ");", "");
            // cout << repl2;
        }

        else if (getString(Line, "Console.Get(", Line, ");"))
        {
            string Input;
            getline(cin, Input);
        }
    }
    in.close();
    return 0;
}
