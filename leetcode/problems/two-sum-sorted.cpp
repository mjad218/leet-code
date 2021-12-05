#include <vector> 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int j = arr.size() - 1, i = 0;
        vector<int> result;
        while (i < j) {
            if (arr[i] + arr[j] == target) {
                result.push_back(i + 1);
                result.push_back(j + 1);
                return result;
            }
            else if (arr[i] + arr[j] > target) j--;
            else i++;
        }
        return result;
    }
};

int main() {
    return 0;
}
