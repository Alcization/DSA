#include <iostream>
#include <vector>
using namespace std;

int equalSumIndex(vector<int>& nums) {
    int totalSum = 0;
    int leftSum = 0;
    for (int num : nums) {
        totalSum += num;
    }
    for (int i = 0; i < nums.size(); ++i) {
        int rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum) {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}
int main()
{
    vector<int> nums {3, 5, 2, 7, 6, 4};
    cout << equalSumIndex(nums);
}