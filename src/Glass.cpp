#include "Glass.h"

using namespace std;

bool startswith(string MainString, string SubString)
{
    if (MainString.rfind(SubString) == 0) return true;
    else return false;    
}

bool endswith(string MainString, string SubString)
{
    bool Ends = MainString.find(SubString, MainString.size() - SubString.size()) != string::npos;
    if (Ends) return true;
    else return false;
}

bool getString(string StartString, string s1, string EndString, string s2)
{
    bool Sw = startswith(StartString, s1);
    bool Ew =endswith(EndString, s2);
    if (Sw == true && Ew == true) return true;
    else return false;
}

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
    in.close();
    return 0;
}
