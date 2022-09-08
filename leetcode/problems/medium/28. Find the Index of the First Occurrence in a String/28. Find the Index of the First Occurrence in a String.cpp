class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.length(); i++) {
            string str = "";
            for (int j = i; j < haystack.length(); j++) {
                str += haystack[j];
                if (str == needle) {
                    return i;
                }
            }
        }
        return -1;
    }
};
