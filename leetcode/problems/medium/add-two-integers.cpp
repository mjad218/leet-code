class Binary {
    public:
    Binary(int s,int c) : sum(s), carry(c) 
    {
        
    }
    int sum;
    int carry;
};
class Solution {
public:
    vector<int> convertToBinary(int a) {
        vector<int> nums;
        while(a > 0){
            if (a % 2 == 0) {
                nums.push_back(0);
            } else {
                nums.push_back(1);
            }
            a = a/2;
        }
        return nums;
    }
    Binary addTwoBinary(int a, int b, int c) {
        // return the sum and the carry
        if (c == 0) {
            if( a == 1 && b == 1 ) {
               return Binary(0, 1); 
            }
            if( a == 0 && b == 0 ) {
               return Binary(0, 0); 
            }
            return Binary(1, 0); 
        }
        if( a == 1 && b == 1 ) {
           return Binary(1, 1); 
        }
        if( a == 0 && b == 0 ) {
           return Binary(1, 0); 
        }
        return Binary(0, 1); 
    }
    int convertToDecimal(vector<int>& nums) { 
        int result = 0;
        for(unsigned int i = 0; i < nums.size(); i++ ) {
            if(nums[i] == 1) {
                result += pow(2, i);
            }
        }
        return result;
    }
    void addBinary(vector<int>& a,vector<int>& b,unsigned int index, vector<int>& result, int carry) {
        int aSize = a.size();
        int bSize = b.size();
        if(index >= bSize && index >= aSize) {
            result.push_back(carry);
            return;
        }
        if(index >= bSize && index < aSize) {
            Binary binary = addTwoBinary(a[index], 0, carry);
            cout << binary.sum;
            result.push_back(binary.sum);
            carry = binary.carry;
            addBinary(a, b, index + 1, result, carry);
            return;
        }
        if(index >= aSize && index < bSize) {
            Binary binary = addTwoBinary(0, b[index], carry);
            cout << binary.sum;
            result.push_back(binary.sum);
            carry = binary.carry;
            addBinary(a, b, index + 1, result, carry);
            return;
        }
        Binary binary = addTwoBinary(a[index], b[index], carry);
        cout << binary.sum;
        result.push_back(binary.sum);
        carry = binary.carry;
        addBinary(a, b, index + 1, result, carry);
        return;
    }
    int getSum(int a, int b) {
        vector<int> result;
        vector<int> aVect = convertToBinary(a);
        vector<int> bVect = convertToBinary(b);
        addBinary( aVect,bVect, 0, result, 0);
        return convertToDecimal(result);
    }
};
