#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <utility>
#include <list>
#include <functional>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int leastAfter(vector<int>& nums, int k) 
{
    priority_queue<int, vector<int>, greater<int>> min_q(nums.begin(), nums.end());
    while (k)
    {
        int n = min_q.top();
        min_q.pop();
        min_q.push(n*2);
        k--;
    }
    return min_q.top();
}  

 