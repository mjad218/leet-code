class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i  < matrix.size() ; i++) {
            int index = search(matrix[i], target, 0, matrix[i].size() - 1);
            if(index != -1) {
                return true;
            }
        }
        return false;
    }
    
    int search(vector<int>& nums, int target, int start, int end) {
        if(nums[start] == target) {
            return start;
        }
        if(start >= end) {
            return -1;
        }        
        int mid = (start + end) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] > target) {
            return search(nums, target,0, mid - 1);
        }
        
        if(nums[mid] < target) {
            return search(nums, target, mid + 1, end);
        }
        return -1;
    
    } 
};
