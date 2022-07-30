class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int size = nums.size();


        for (int i = 1; i < nums.size(); i++) {
             if(nums[k] != nums[i]) {
                nums[++k] = nums[i];
            }
        }
        k++;
        
        return k;
    }
};
