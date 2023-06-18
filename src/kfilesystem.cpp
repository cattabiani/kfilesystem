#include "kfilesystem.hpp"
#include "utils.hpp"

list<string> KfileSystem::to_abs_path(string_view s) const {

    if (s.size() && s[0] == '/') {
        return utils::sanitize(s, '/');
    }

    string ans = pwd_;
    if (s.empty()) {
        return utils::sanitize(ans, '/');
    }

    ans.push_back('/');
    ans += s;

    return utils::sanitize(ans, '/');
}

void KfileSystem::call(string_view s) {
    auto args = utils::tokenize(s, ' ');
    if (args.empty()) { return; }

    auto cmd = args.front();
    args.pop_front();

    if (cmd == "ls") {
        ls(args);
        return;
    }
}

void KfileSystem::ls(list<string>& l) const {

    auto p = l.empty() ? to_abs_path("") : to_abs_path(l.front());

    auto node = root_;
    while (!p.empty()) {
        const auto& key = p.front();
        auto ptr = node.children_.find(key);
        if (ptr == node.children_.end()) {
            cout << "ls: cannot access '" << key << "': No such file or directory\n";
            return;
        }

        try
        {
            node = std::get<Kfolder>(*ptr->second);
        }
        catch (std::bad_variant_access const& ex)
        {
            cout << "ls: cannot access '" << key << "': Not a directory\n";
        }


        p.pop_front();
    }


}