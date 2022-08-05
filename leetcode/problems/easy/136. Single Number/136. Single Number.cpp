class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp; 
        
        for (int i = 0; i < nums.size(); i++) {
            auto iterator = mp.find(nums[i]);
            if(iterator != mp.end()) {
                iterator->second += iterator->second;
            } else {
                mp.insert({nums[i], 1});
            }
        }
        
          for (auto const& [key, val] : mp) {
            if(val == 1) {
                cout << val << endl << key << endl;
                return key;
            }
          }
        return -1;
    }
};
