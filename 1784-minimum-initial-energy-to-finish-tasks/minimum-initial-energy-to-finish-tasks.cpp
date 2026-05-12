class Solution {
public:
    bool istrue(int mid,vector<vector<int>>&tasks){
        for(int i = 0; i<tasks.size(); i++){
            if(mid>= tasks[i][1]){
                mid -= tasks[i][0];
            }else return false;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]); // descending order
        });
        int low = 0,high = 0;
        for(auto &a : tasks){
            low += a[0];
            high += a[1];
        }
        int ans = 0;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(istrue(mid,tasks)){
                ans = mid;
                high = mid-1; 
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    
        
    }
};