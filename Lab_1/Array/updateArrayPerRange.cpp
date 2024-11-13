#include <iostream>
#include <vector>
using namespace std;
vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    int n = nums.size();
    vector<int> change(n, 0);
    for (const auto& operation : operations) {
        int L = operation[0]; int R = operation[1]; int X = operation[2];
        change[L] += X;
        if (R + 1 < n) {
            change[R + 1] -= X;
        }
    }
    int prefix_sum = 0;
    for (int i = 0; i < n; ++i) {
        prefix_sum += change[i];
        nums[i] += prefix_sum;
    }
    return nums;
}

int main() {
    vector<int> nums {13, 0, 6, 9, 14, 16};
    vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};  
    vector<int> result = updateArrayPerRange(nums, operations);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
