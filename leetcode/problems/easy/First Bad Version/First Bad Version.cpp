// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int start, int end) {
        if(start == end && isBadVersion(start)) {
            return start;
        }
        if(start == end){
            return 0;
        }
        
        unsigned int mid = ((unsigned)start + (unsigned)end) / 2;
        if (isBadVersion(mid)) {
            return firstBadVersion(start, mid);
        }
        return firstBadVersion(mid + 1, end);
    }
    
    int firstBadVersion(int n) {
        return firstBadVersion(1, n);
    }
};
