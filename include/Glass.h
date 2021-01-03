#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <regex>
#include <ctime>
#include <map>

#include <windows.h>
#include <string.h>
#include <unistd.h>

extern std::map<std::string, std::string> variables;
extern std::map<std::string, std::string> VarTypes;

extern int Syspart;
extern int Cgrpart;
extern int Postpart;
extern int FileIOpart;
extern int Genericpart;
extern int Collectionpart;
