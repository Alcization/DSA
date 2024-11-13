#include <iostream>
using namespace std;


string reverseSentence(string s) {
    if (s.empty()) {
        return "";
    }
    int spacePos = s.rfind(' ');
    if (spacePos == -1) {
        return s;
    } else {
        string restOfString = s.substr(0, spacePos);
        return s.substr(spacePos + 1) + " " + reverseSentence(restOfString);
    }
}
