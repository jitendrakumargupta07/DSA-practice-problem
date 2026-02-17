class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int hour = 0; hour <= 11; hour++){
            for(int min = 0; min <= 59; min++){
                if(__builtin_popcount(hour) + __builtin_popcount(min) == turnedOn){
                    res.push_back(to_string(hour) + ":" + ((min < 10) ? "0"+to_string(min) : to_string(min)));
                }
            }
        }
        return res;
    }
};
