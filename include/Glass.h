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

#include "../include/GetStr.h"
#include "../include/System.h"
#include "../include/Generic.h"
#include "../include/PostThread.h"
#include "../include/Collections.h"

extern std::map<std::string, std::string> variables;
extern std::map<std::string, std::string> VarTypes;

extern int Syspart;
extern int Cgrpart;
extern int Postpart;
extern int FileIOpart;
extern int Genericpart;
extern int Collectionpart;

extern int Count;

void Error(const std::string lines, const std::string num);
