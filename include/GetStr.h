#pragma once

#include "Glass.h"

bool startswith(const std::string& StartString, const std::string& SubStart);
bool endswith(const std::string& EndString, const std::string& SubEnd);
bool getString(const std::string& StartStr, const std::string& s1, const std::string& s2);
std::string replace(const std::string MainString, const std::string& ToRepl, const std::string& WithRepl);
std::string join(std::string& JoinString, const std::string& JoinWith);
