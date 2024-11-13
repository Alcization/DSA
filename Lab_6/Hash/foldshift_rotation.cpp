#include <iostream>
#include <string>
#include <math.h>
#include <string.h>
using namespace std;



long int to_int (string s)
{
    long int loop = 1;
    long int result = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        result += (s[i] - 48) * loop;
        loop *= 10;
    }
    return result;
}

int foldShift(long long key, int addressSize)
{
    string s;
    string num = to_string(key);
    long int sum = 0;
    for (int i = 0; i < int(num.size()); i += addressSize)
    {
        s = "";
        for (int j = 0; j < addressSize && (i + j) < int(num.size()); j++) s += num[i + j];
        sum += to_int(s);
    }
    int mod = 1;
    for (int i = 0; i < addressSize; i++) mod *= 10;
    sum = sum % mod;
    return sum;
}

int rotation(long long key, int addressSize)
{
    string num = to_string(key);
    string s1 = num.substr(0, num.size() - 1);
    num = num[num.size() - 1] + s1;
    long long n = to_int(num);
    return foldShift(n, addressSize);
    return 0;
}




int main()
{   
    cout << rotation(600101, 2);
    return 0;
}

