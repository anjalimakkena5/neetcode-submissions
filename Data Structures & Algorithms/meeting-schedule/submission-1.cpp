/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool static myfunc(Interval &a,Interval &b){
        return a.start<b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),myfunc);
        int start=intervals[0].start;
        int end=intervals[0].end;
        for(int i=1;i<n;i++){
            if(intervals[i].start<end) return false;
            end=intervals[i].end;
        }
        return true;
    }
};
