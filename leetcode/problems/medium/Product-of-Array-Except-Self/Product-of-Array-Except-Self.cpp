class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        map<int, int> forwardProduct;
        map<int, int> backwardProduct;
        int end = nums.size() - 1;
        for(unsigned int i = 0; i < nums.size(); i++){
            if(i == 0) {
                forwardProduct.insert({i, nums[i]});
                continue;
            }
            int product = forwardProduct.find(i - 1)->second * nums[i];
            forwardProduct.insert({i, product});
        }
        
        for( int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1) {
                backwardProduct.insert({i, nums[i]});
                continue;
            }
            int product = backwardProduct.find(i + 1)->second * nums[i];
            backwardProduct.insert({i, product});
        }
        
        vector<int> ans;
        
        for(unsigned int i = 0; i < nums.size(); i++ ) {
            int forward; 
            int backward; 
            if(i == 0) {
                forward = 1;
            } else {
                forward = forwardProduct.find(i - 1)->second;
            }
            
            
            if(i == nums.size() - 1) {
                backward = 1;
            } else {
                backward = backwardProduct.find(i + 1)->second;

            }
            
            ans.push_back(forward * backward);
        }
        
        return ans;
    }
};
