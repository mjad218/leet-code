#include <string>

using namespace std;
class Solution {
public:
    bool isPal(string& s) {
        int size = s.length();
        for (int i = 0; i < size / 2; i++) {
            if (s[i] != s[size - i - 1]) {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            if (iswalnum(s[i])) {
                char c = s[i];
                if (isupper(c)) {
                    c = tolower(c);
                }
                str += c;
            }
        }
        return isPal(str);
    }
};