#include <string>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, string> mp;

        sort(nums.begin(), nums.end());
        int size = nums.size() - 1;

        for (int i = 0; i < size + 1; i++) {
            int freq = 1;
            while(i < size && nums[i] == nums[i + 1]) {
                freq++;
                i++;
            }
            auto iterator = mp.find(freq);

            if(iterator != mp.end()) {
                string last = iterator->second;
                iterator->second = last + ':' + to_string(nums[i]);
                cout << "second end "<< iterator->second; 
            } else {
                string str = std::to_string(nums[i]);
                mp.insert({freq,str });

            }
            
        }
        vector<int> ans;

        for(int i = size + 1; i > -1; i--) {
            if(ans.size() >= k){
                return ans;
            }
            auto iterator = mp.find(i);
            if(iterator != mp.end()){
                string indices = iterator->second;
                cout << "indices " << indices << endl;
                vector<int> n = convertToInt(indices);
                
                for(int j = 0; j < n.size(); j++) {
                        ans.push_back(n[j]);
                }
            }
        }

        if(k == 1 && nums.size() == 1) {
            return nums;
        }
        return ans;
    }
    vector<int> convertToInt(string& str) {
        vector<int> ans;
        cout << "str " <<  str << endl ;
        for (int i = 0; i < str.length(); i++) {
            // if(str[i] == ':') {
            //     continue;
            // }
            string st = "";
            while(i < str.length() && str[i] != ':') {
                st += str[i];
                i++;
            }
            if(st.length() > 0) {
                int num = stoi(st);
                cout << "num "<< num << endl;
                ans.push_back(num);
            }
        }
        return ans;
    }
};
