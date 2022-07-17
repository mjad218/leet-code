class Solution {
map<int, int> fibs;

public:
    int fib(int n) {
        if(n <= 1) {
            return n;
        }
        if(this->fibs.find(n) != this->fibs.end()) {
            return this->fibs.find(n)->second;
        }
        int res = fib(n - 1) + fib(n - 2);
        this->fibs.insert({n, res});
        return res;
    }
};
