#include <iostream>
using namespace std;

long int midSquare(long int seed)
{
    seed = seed * seed;
    seed /= 100;
    return seed % 10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}
long int digitExtraction(long int seed, int* extractDigits, int size)
{
    int temp[1000];
    for (int i = 0;i < 1000; i++) temp[i] = -1;
    int i = 0;
    while (seed > 0)
    {
        temp[i] = seed % 10;
        seed /= 10;
        i++;
    }
    long int result = 0;
    int j = 0;
    while (size)
    {
        result = result * 10 + temp[i - extractDigits[j] - 1];
        j += 1;
        size--;   
    }
    return result;
}

int main()
{
    int a[]={1, 2, 5};
    cout << digitExtraction(122443, a, 3);
    cout << endl;
    cout <<midSquare(9452);
    return 0;
}