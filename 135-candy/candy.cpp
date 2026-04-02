class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;

        int i = 1;

        while(i < n) {
            if(ratings[i] == ratings[i-1]) {
                i++;
                continue;
            }

            //Increasing Slop - PEEK
            int peek = 0;
            while(ratings[i] > ratings[i-1]) {
                peek++;
                candy += peek;
                i++;
                
                if(i == n) {
                    return candy;
                }
            }

            //Deacrsing Slop
            int dip = 0;
            while(i < n && (ratings[i] < ratings[i-1])) {
                dip++;
                candy += dip;
                i++;
            }

            candy -= min(peek, dip);
        }

        return candy;
    }
};