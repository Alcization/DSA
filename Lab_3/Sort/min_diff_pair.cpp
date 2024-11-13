#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

string minDiffPairs(int* arr, int n)
{   
    string result;
    sort(arr, arr+n);
    int minDiff = arr[1] - arr[0];
    for (int i = 2 ; i < n ; i++)
        minDiff = min(minDiff, arr[i] - arr[i-1]);
    for (int i = 1; i < n; i++){
        if ((arr[i] - arr[i-1]) == minDiff)
        {
            if (!result.empty())
            {
                result += ", ";
                result += "(";
                result += to_string(arr[i-1]);
                result += ", ";
                result += to_string(arr[i]);
                result += ")";
            }
            else 
            {
                result += "(";
                result += to_string(arr[i-1]);
                result += ", ";
                result += to_string(arr[i]);
                result += ")";
            }
        }
    }    
    return result;     
}


int main()
{
    int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << minDiffPairs(arr, 10);
    return 0;
}