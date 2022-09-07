class Solution {
public:
    bool isPalindrome(string s) {
        string str = adjustString(s);
        int n = str.length();
        for (int i = 0; i < str.length(); i++) {
            if(str[i] != str[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    string adjustString(string& s) {
        string result = "";
        for (int i = 0;i < s.length(); i++) {
            if (iswalnum(s[i]) ) {
                char c = tolower(s[i]);
                result += c;
            } 
        }
        return result;
    } 
};
