class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        // to store the digits
        vector<int> v;
        //accessing all elements from back
        short int i;
        for(i=nums.size()-1;i>=0;i--)
        {
            //storing the elements
            int temp=nums[i];

            //extracting each digit from the number
            while(temp)
            {
                //inserting digit at begenning
                //v.insert(v.begin(),temp%10);

                //storing the digits in order they are removed
                v.push_back(temp%10);

                //deleting that digit from the temp
                temp=temp/10;
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};