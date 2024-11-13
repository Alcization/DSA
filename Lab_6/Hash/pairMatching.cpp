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
int pairMatching(vector<int>& nums, int target) 
{
    map<int, int> my_map;
    for (int i : nums) my_map[i]++;
    int count = 0;
    for (int i : nums){
        if (i + i == target)
        {
            if (my_map[i] > 1)
            {
                count++;
                my_map[i] -= 2;
            }
        }
        else if (my_map[target - i] > 0 && my_map[i] > 0)
        {
            count++;
            my_map[i]--;
            my_map[target - i]--;
        } 
    }
    return count;
}

int main()
{    	
    int target = 120;
    vector<int>items{66,49,23,57,85,12,30,65,51,34,92,4,35,47,84,13,72,57,75,68,20,58,92,6,16,80,83,73,33,39,22,98,39,96,54,24,7,83,88,57,68,31,60,3,77,96,67,49,4,93,68,23,50,59,28,65,91,63,38,23,1,11,73,40,6,26,15,12,61,54,20,80,84,80,34,61,27,100,61,30,93,28,52,94,86,32,59,28,94,48,51,46,58,23,37,15,100,51,78,12};
    cout << pairMatching(items, target);
    return 0;
}