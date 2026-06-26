class Solution {
public:

    long long merge(vector<int>& pre_sum, int l, int mid, int r) {
        long long cross_count = 0;
    
        int left_ptr = l;
        for(int right_ptr = mid + 1; right_ptr <= r; right_ptr++) {
            while(left_ptr <= mid && pre_sum[left_ptr] < pre_sum[right_ptr]) {
                left_ptr++;
            }
            cross_count += (left_ptr - l);
        }

        vector<int> temp;
        int i = l;        
        int j = mid + 1;  


        while(i <= mid && j <= r) {
            if(pre_sum[i] <= pre_sum[j]) {
                temp.push_back(pre_sum[i]);
                i++;
            } else {
                temp.push_back(pre_sum[j]);
                j++;
            }
        }

        while(i <= mid) {
            temp.push_back(pre_sum[i]);
            i++;
        }

        while(j <= r) {
            temp.push_back(pre_sum[j]);
            j++;
        }

        for(int k = 0; k < temp.size(); k++) {
            pre_sum[l + k] = temp[k];
        }

        return cross_count;
    }

    long long divide(vector<int>& pre_sum, int l, int r) {
        if( l == r) {
            return 0;
        }
        int mid = (l+r) / 2;
        long long left_count = divide(pre_sum, l, mid); 
        long long right_count = divide(pre_sum, mid+1, r);
        long long count = 0;

        count = merge(pre_sum , l, mid, r);

        return left_count + right_count + count;
    }


    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre_sum(n + 1, 0);

        for( int i = 0; i < n; i++ ) {
            if( nums[i] == target ) {
                pre_sum[i+1] = pre_sum[i] + 1;
            } else {
                pre_sum[i+1] = pre_sum[i] - 1;
            }
        }

        long long res = divide(pre_sum, 0, n);
        return res;
    }
};
