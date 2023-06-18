#include <iostream>
#include <memory>
#include <string>

#include "src/utils.hpp"
#include "src/kfile.hpp"
#include "src/kfolder.hpp"
#include "src/kfilesystem.hpp"

using namespace std;

int main() {

    string raw_cmd;
    KfileSystem fs;

    while (raw_cmd != "quit") {
        cout << fs.intro();
        cin >> raw_cmd;

        cout << "in call" << endl;

        fs.call(raw_cmd);
        
    }

    return 0;
}
