#include <vector> 
using namespace std; 

class Solution {
public:

    vector<int> twoSum(vector<int>& arr, int givenNum) {
        vector<int> result;
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if(arr[i] + arr[j] == givenNum) {
                result.push_back(i);
                result.push_back(j);
                return result;
                }
            }
        }
    return result;
    }
};

int main() {
    return 0; 
}