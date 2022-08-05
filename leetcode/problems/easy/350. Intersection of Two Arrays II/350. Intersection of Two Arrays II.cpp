class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end() );
        sort(nums2.begin(), nums2.end() );
        
        vector<int> result;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            cout << i << " : " << j << endl;
            if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                j++;
                i++;
                continue;
            }
            if(nums1[i] > nums2[j]) {
                j++;
                continue;
            }
            if(nums1[i ] < nums2[j]) {
                i++;
                continue;

            }
        }
        cout << "end " << i << " : " << j << endl;

        return result;
    }
};
