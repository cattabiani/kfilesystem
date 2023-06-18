#include "kfolder.hpp"

using namespace std;

string Kfolder::ls() const {
    vector<string> v;
    v.reserve(children_.size());
    for (auto i : children_) {
        v.push_back(i.first);
    }

    sort(v.begin(), v.end());
    
    return utils::join(v.begin(), v.end(), ' ');
}


size_t Kfolder::erase(const string_view s) {
    return children_.erase(string(s));
}

