class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        deque<int> result;
        result = plus(digits,  digits.size() - 1,  1, result);
        vector<int>  finals(result.begin(), result.end());
        return finals;
    }
    
    
    deque<int> plus(vector<int>& digits, int index, int carry, deque<int>& result) {
        if (index < 0 && carry == 0) {
            return result;
        }
        if (index < 0 && carry == 1) {
            result.push_front(1);
            return result;

        }
        int el = digits[index] + carry;
        if (el <= 9) {
            result.push_front(el);
            index--;
            return plus(digits,  index,  0, result);
        } 
        
        if (el == 10) {
            result.push_front(0);
            index--;
            return plus(digits,  index,  1, result);
        }
        return result;
    }
    
};
