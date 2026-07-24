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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int>mpp;
        for(auto it:intervals){
            mpp[it.start]++;
            mpp[it.end]--;
        }
        int overlap=0;
        int maxi=0;
        for(auto it:mpp){
            overlap+=it.second;
            maxi=max(maxi,overlap);
        }
        return maxi;
    }
};
