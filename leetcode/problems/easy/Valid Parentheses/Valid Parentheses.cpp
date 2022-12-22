class Solution {
public:
    bool matchInput(char top, char input) {
        if(input == '}' && top == '{') {
            return true;
        }
         if(input == ']' && top == '[') {
            return true;
        }
         if(input == ')' && top == '(') {
            return true;
        }
        
        return false;
    }
    bool isValid(string s) {
        stack<char> stack;
        
        for(unsigned int i = 0; i < s.length() ; i++) {
            if(stack.empty()) {
                stack.push(s[i]);
                continue;
            }
            char top = stack.top();
            
            if(!this->matchInput(top, s[i])) {
                stack.push(s[i]);
                continue;
            }
            stack.pop();
            
        }
        
        return stack.empty();

    }
};
