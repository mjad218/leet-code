#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);
        int size = str.length();
        for (int i = 0; i < size / 2; i++) {
            if (str[i] != str[size - i - 1]) {
                return false;
            }
        }
        return true;
    }
};