#include "../include/Glass.h"
#include "../include/GetStr.h"

using namespace std;

int main()
{
    string DirName;
    string Line;

    fstream in;
    bool Instantiate;

    string Lst[] = {"Location> ", "File name> "};
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
    }
    cin.get();
    in.close();
    return 0;
}
