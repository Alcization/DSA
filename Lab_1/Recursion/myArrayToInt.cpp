#include <iostream>
using namespace std;


int myArrayToInt(char *str, int n) {
    if (n == 0) {
        return 0;
    }
    int lastDigit = str[n - 1] - '0';
    int result = myArrayToInt(str, n - 1) * 10 + lastDigit;
    return result;
}
