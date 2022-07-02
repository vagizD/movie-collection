#include <string>

using namespace std;

void capitalize(string &str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i  < str.size(); i++) {
        if (str[i-1] == ' ') str[i] = toupper(str[i]);
        else str[i] = tolower(str[i]);
    }
}