class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> mp;
        for (int i=0; i< nums.size(); i++)
            mp.insert({nums[i], i});
        for (int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            auto foundIndex = mp.find(num);
            if (foundIndex != mp.end()) {
                if (foundIndex->second != i) {
                    result.push_back(foundIndex->second);
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};
