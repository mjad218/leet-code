class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int lastNonZero = 1;
        for (int i = 1; i < size; i++ ) {
            if (nums[i - 1] == 0 && nums[i ] != 0 ) {
                swapAll(nums, i);
            }
        }
    }
    
    void swapAll (vector<int>& nums, int i) {
        int iterations = 0;
      for (int j = i; j >= 1; j--) {
          if(nums[j - 1] == 0) {
              swap(nums, j ,j - 1);
             
          }
        }
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
