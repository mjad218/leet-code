#include <iostream> 
#include <vector>
#include <stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        vector<bool> exist;
        for (int i = 0; i < nums.size(); i++) {
            exist.push_back(false);
        }

        for (int i = 0; i < nums.size(); i++) {
            exist[nums[i] - 1] = true;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!exist[i]) {
                result.push_back(i + 1);
            }
        }
        return result;
    }

};

int main() {
    Solution sln;
    vector<int> v1 = {1 ,1};

    vector<int> result = sln.findDisappearedNumbers(v1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\t';
    }
}