class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        for(int i = 0; i < s.length(); i++) {
            auto iterator = mp.find(s[i]);
            if(iterator == mp.end()) {
                mp.insert({s[i], 1});
            } else {
                iterator->second += 1; 
            }
        }
        
       for(int i = 0; i < s.length(); i++) {
           
            auto iterator = mp.find(s[i]);
            int val = iterator->second;
            if (val == 1) {
               char uniqChar = iterator->first;
                return this->uniqCharIndex(uniqChar, s);
            }
        }
        return -1;
    }
    
    int uniqCharIndex(char val, string& s) {
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == val) {
                return i;
            }
        }
        return -1;
    }
};
