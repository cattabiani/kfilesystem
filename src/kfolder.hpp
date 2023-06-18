#pragma once

#include <unordered_map>
#include <variant>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "kfile.hpp"
#include "utils.hpp"

using namespace std;

class Kfolder {


public:

    string ls() const;

    template<class T>
    pair<unordered_map<string, shared_ptr<variant<Kfolder, Kfile>>>::iterator, bool> insert(const string_view s) {
        return children_.try_emplace(string(s), make_shared<variant<Kfolder, Kfile>>(T()));
    }

    size_t erase(const string_view s);


    unordered_map<string, shared_ptr<variant<Kfolder, Kfile>>> children_;
};