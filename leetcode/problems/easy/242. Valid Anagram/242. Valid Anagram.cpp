class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        map<char, int> smap = calcFreq(s);
        map<char, int> tmap = calcFreq(t);

    
        
        for (auto const & [key, val] : smap) {
            auto iterator = tmap.find(key);
            if(iterator == tmap.end()) {
                return false;
            }
            
            if (iterator->second != val) {
                return false;
            }
        }
        
        return true;
    }
    map<char, int> calcFreq (string& s) {
        map<char, int> smap;
        for (int i = 0; i < s.length(); i++) {
            auto iterator = smap.find(s[i]);
            if(iterator == smap.end()) {
                smap.insert({s[i], 1});
            } else {
                iterator->second++;
            }
       }
        return smap;
    }
};
