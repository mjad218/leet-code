class Solution {
    
public:
    void swap(vector<int>& arr,int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    void sortColors(vector<int>& nums) {
        int noOfZeros = 0;
        int noOfOnes = 0;
        int noOfTwos = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0){
                noOfZeros++;
                continue;
            }
            if(nums[i] == 1){
                noOfOnes++;
                continue;

            }
            if(nums[i] == 2){
                noOfTwos++;
                continue;
            }
        }
        int index = 0;
        for(int i = 0; i < noOfZeros; i++) {
            nums[index] = 0;
            index++;
        }
        for(int i = 0; i < noOfOnes; i++) {
            nums[index] = 1;
            index++;
        }
        for(int i = 0 ; i < noOfTwos; i++) {
            nums[index] = 2;
            index++;
        }
    }
};
