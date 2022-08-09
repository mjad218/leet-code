class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int size = nums.size() - 1; 
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp.insert({nums[i], i});
        }
        for(int i = 0; i < nums.size(); i++) {
            int sub = target - nums[i];
            auto index = mp.find(sub);
            if (index != mp.end() && index->second != i) {
                result.push_back(i);
                result.push_back(index->second);
                return result;
            }
        }
        return result;
    }
    
    int search(vector<int>& nums, int target, int start, int end) {
       if (nums[start] == target) {
            return start;
        }
        if (start >= end) {
            return -1;
        }
        int mid = (start + end) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            return search(nums,  target,  start, mid - 1 ) ;
        }
        if (nums[mid] < target) {
            return search(nums,  target, mid + 1, end) ;
        }
        
        return -1;
    }
};
