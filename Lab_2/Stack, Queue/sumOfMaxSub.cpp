int sumOfMaxSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> maxIndices;
    int result = 0;
    for (int i = 0; i < n; ++i) 
    {
        while (!maxIndices.empty() && maxIndices.front() < i - k + 1) maxIndices.pop_front(); 
        while (!maxIndices.empty() && nums[maxIndices.back()] < nums[i]) maxIndices.pop_back();
        maxIndices.push_back(i);
        if (i >= k - 1) result += nums[maxIndices.front()];
    }
    return result;
}