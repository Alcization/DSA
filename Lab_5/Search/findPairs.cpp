#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>

using namespace std;

bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
    // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
    // first for sum and second for pair
    map<int, pair<int,int> > hash;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (hash.find(sum) == hash.end()) hash[sum] = make_pair(i, j);
            else
            {
                pair<int, int> pp = hash[sum];
                pair1 = {arr[pp.first], arr[pp.second]};
                pair2 = {arr[i], arr[j]};
                return true;
            }
        }
    }
    return false;
}

bool findPairs (int arr[], int n, pair<int, int>& pair1, pair<int, int>& pair2)
{
    map<int, pair<int, int>> hash;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (hash.find(sum) == hash.end()) hash[sum] = make_pair(i, j);
            else
            {
                pair<int, int> pp = hash[sum];
                pair1 = {arr[pp.first], arr[pp.second]};
                pair2 = {arr[i], arr[j]};
                return true;
            }
        }
    }
    return false;
}

int main()
{
    return 0;
}

