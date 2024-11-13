#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int minSum(vector<long long int> arr, long long int k)
{
    sort(arr.begin(), arr.end());
    long long int remove_sum = 0;
    for (auto num : arr) 
    {
        if (num < k)
        {
            k++;
            remove_sum += num;
        }
        else break;  
    }
    return k*(k+1)/2 - remove_sum;
}

int main()
{
    vector<long long int> n = {1, 4, 25, 10, 25};
    long long int k = 2;
    cout << minSum(n, k);
    return 0;
}