#pragma once

#include <sstream>
#include <string>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

namespace utils {
template <typename Iter>
string join(Iter begin, Iter end, char const separator)
{
    stringstream result;
    if (begin != end)
        result << *begin++;
    while (begin != end) {result << separator << *begin++;}
    return result.str();
}

list<string> tokenize(string_view s, char separator);

list<string> sanitize(string_view s, char separator);

inline std::string trim(const string_view &s)
{
   auto wsfront=std::find_if_not(s.begin(),s.end(),[](int c){return std::isspace(c);});
   auto wsback=std::find_if_not(s.rbegin(),s.rend(),[](int c){return std::isspace(c);}).base();
   return (wsback<=wsfront ? std::string() : std::string(wsfront,wsback));
}

}