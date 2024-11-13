#include <iostream>
#include <algorithm>
using namespace std;


int buyCar(int* nums, int length, int k) {
    sort(nums, nums + length);
    int cars = 0;
    int spend = 0;
    for (int i = 0; i < length; i++)
    {
        if (spend + nums[i] <= k)
        {
            spend += nums[i];
            cars++;
        } else break;
    }
    return cars;
}