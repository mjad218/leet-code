bool sortCol(const vector<int>& v1, const vector<int>& v2) {
       if(v1[0] == v2[0])    return v1[1] < v2[1];
        return v1[0] < v2[0];

}
class Solution {
public:
    

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), sortCol);
        int index = 0;
        vector<int> res1;
        for (int i = 0; i < intervals.size(); i++ ) {
            bool needsMerge = needsToBeMerged( intervals[index] ,intervals[i]);
            if(needsMerge) {
                res1 = mergeTwoIntervals(intervals[index], intervals[i]);
                intervals[index] = res1;
            } else {
                index++;
                intervals[index] = intervals[i];
            }

        }
        intervals.resize(index+1);
        return intervals;
    }
    
    bool needsToBeMerged(vector<int>& interval1, vector<int>& interval2) {
        int greatestNum = interval1[1];
        int smallestNum = interval1[0];
        if(greatestNum >= interval2[0] && smallestNum <= interval2[1]) {
                return true;                
        }
        return false;
    }
    
    vector<int> mergeTwoIntervals(vector<int>& inter1,vector<int>& inter2) {
        vector<int> result; 
        cout << "inter1[0] "<< inter1[0] << endl << "inter2[0] " << inter2[0];
        inter1[0] >= inter2[0] ? result.push_back(inter2[0]) :  result.push_back(inter1[0]);
        inter1[1] >= inter2[1] ? result.push_back(inter1[1]) :  result.push_back(inter2[1]);
        return result;
    }
};
