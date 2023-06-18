#pragma once

#include "kfolder.hpp"

class KfileSystem {
public:
    inline string intro() const {
        return pwd_ + "$ ";
    }

    list<string> to_abs_path(string_view s) const;

    void ls(list<string>& l) const;

    void call(string_view s);

    string pwd_ = "/";
    Kfolder root_;
};