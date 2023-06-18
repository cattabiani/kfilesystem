#include "utils.hpp"

#include <sstream>
#include <string>
#include <list>
#include <iostream>

using namespace std;

namespace utils {

list<string> tokenize(string_view s, char separator) {
    stringstream ss;
    ss << s;
    string token;
    list<string> ans;
    while (getline(ss, token, separator)) { ans.push_back(token); }

    return ans;
}

list<string> sanitize(string_view s, char separator) {
    auto temp = tokenize(s, separator);

    list<string> ans;
    int n = 0;
    for (auto i = temp.rbegin(); i != temp.rend(); ++i) {
        auto s = trim(*i);
        if (s == "") { continue; }
        if (s == ".") { continue; }
        if (s == "..") { ++n; continue; }
        if (n > 0) { --n; continue; }
        ans.push_front(s);
    }

    return ans;
}

}