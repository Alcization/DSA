#include <iostream>
#include <vector>
using namespace std;


bool consecutiveOnes(vector<int>& nums) {
    bool found = false;  
    bool flag = false;
    for (int num : nums) {
        if (num == 1) {
            if (found == false) {
                found = true;  
            }
            if (flag) return false;
        } else {
            if (found) {
                flag = true;
            }
        }
    }
    return true;
}
int main()
{
    vector <int> nums {0, 1, 1, 1, 9, 8};
    cout << consecutiveOnes(nums);
}