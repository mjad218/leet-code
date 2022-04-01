#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void swap(int index, vector<int>& nums) {
        for (int i = index; i < nums.size() - 1; i++) {
            int temp = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = temp;
        }
    }
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();

        for (int i = 0; i < k - 1; i++) {
            if (i == k - 1) continue;

            int m = i;
            while (m < k - 1 && k > 0 && nums[m] == nums[m + 1]) {
                swap(m + 1, nums);
                k--;
            }
        }
        return k;
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                nums[k++] = nums[i + 1];
            }
        }
        return k;
    }
};
int main() {
    Solution s;

    vector<int> nums = {};
    vector<int> expectedNums = { 1 };

    int k = s.removeDuplicates(nums); 
    cout << k;
    //k == expectedNums.size() ? cout << "right" : cout << "wrong";
    for (int i = 0; i < k; i++) {
        cout << nums[i];
        //nums[i] != expectedNums[i] && cout << "wrong";
    }

    return 0;
}