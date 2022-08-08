class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       vector<int> result;
        result = plus(digits,  digits.size() - 1,  1, result);
        reverse(result.begin(), result.end());
        return result;
    }
    
    
    vector<int> plus (vector<int>& digits, int index, int carry, vector<int>& result) {
        if (index < 0 && carry == 0) {
            return result;
        }
        if (index < 0 && carry == 1) {
            result.push_back(1);
            return result;

        }
        int el = digits[index] + carry;
        if (el <= 9) {
            result.push_back(el);
            index--;
            return plus(digits,  index,  0, result);
        } 
        
        if (el == 10) {
            result.push_back(0);
            index--;
            return plus(digits,  index,  1, result);
        }
        return result;
    }
    
};
