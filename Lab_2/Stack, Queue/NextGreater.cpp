#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreater(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);  
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[j] > arr[i]) {
                result[i] = arr[j];
                break;
            }
        }
    }
    return result;
}


