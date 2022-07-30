class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        
        if(nums.size() == 0) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int targetPos = searchRange( nums,  target,  0,  nums.size() - 1);
        if (targetPos == -1) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        cout<< targetPos;
        
        int startIndex = targetPos;
        while(startIndex - 1 >= 0 && nums[startIndex - 1 ] == target) {
            startIndex--;
        }
        
        int endIndex = targetPos;
        while(endIndex + 1 < nums.size() && nums[endIndex + 1] == target) {
            endIndex++;
        }
        
        res.push_back(startIndex);
        res.push_back(endIndex);
        return res;

    }
    
    int searchRange(vector<int>& nums, int target, int start, int end) {
        if (start >= end) {
            return nums[start] == target ? start : -1;
        }
        int mid = (start + end ) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] > target) {
            return searchRange( nums,  target,  start,  mid - 1);
        }
        if(nums[mid] < target) {
            return searchRange( nums,  target,  mid + 1,end);
        }
        return -1;
    }
};
