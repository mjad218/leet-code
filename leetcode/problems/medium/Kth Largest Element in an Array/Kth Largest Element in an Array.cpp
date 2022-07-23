class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if(size - k >= 0) {
            return nums[size - k];
        }
        return -1;
    }
};
