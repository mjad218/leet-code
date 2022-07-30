class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        set<int> st;
        for (int i = 0; i < intervals.size(); i++ ) {
            int posOfInterval = needsToBeMerged(intervals ,intervals[i] , st, i);
            cout << posOfInterval << endl;
            vector<int> res1 = intervals[i];
            while(posOfInterval != -1) {
                st.insert(posOfInterval);
                res1 = mergeTwoIntervals(res1, intervals[posOfInterval]);
                posOfInterval = needsToBeMerged(intervals ,res1 , st, i);
            }
            if(st.find(i) == st.end() ) {
                result.push_back(res1);            
            }

        }
        return result;
    }
    
    int needsToBeMerged(vector<vector<int>>& intervals, vector<int>& interval, set<int>& st, int itself) {
        
        int greatestNum = interval[1];
        int smallestNum = interval[0];
        for (int i = 0; i < intervals.size(); i++ ) {
            if(greatestNum >= intervals[i][0] && smallestNum <= intervals[i][1]) {
                if (st.find(i) == st.end() && i != itself) {
                    return i;                
                }
            }
        }
        
        return -1;
    }
    
    vector<int> mergeTwoIntervals(vector<int>& inter1,vector<int>& inter2) {
        vector<int> result; 
        cout << "inter1[0] "<< inter1[0] << endl << "inter2[0] " << inter2[0];
        inter1[0] >= inter2[0] ? result.push_back(inter2[0]) :  result.push_back(inter1[0]);
        inter1[1] >= inter2[1] ? result.push_back(inter1[1]) :  result.push_back(inter2[1]);
        return result;
    }
};
