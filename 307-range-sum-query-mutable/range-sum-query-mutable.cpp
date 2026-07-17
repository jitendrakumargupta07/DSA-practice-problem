class NumArray {
public:
    vector<int> st;
    int n;

    void bt(int i, int l, int r, vector<int>& nums){
        if(l == r){
            st[i] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        bt(2*i+1, l, mid, nums);
        bt(2*i+2, mid+1, r, nums);
        st[i] = st[2*i+1] + st[2*i+2];
    }

    void fun(long long i, int l, int r, int& s , int& e, int& sum){
        if((l < s && r < s) || (l > e && r > e)) return;
        if(l >= s && r <= e){
            sum += st[i];
            return;
        }
        int mid = (l+r)/2;
        fun(2*i+1, l, mid, s, e, sum);
        fun(2*i+2, mid+1, r, s, e, sum);
    }

    void update(int i, int l, int r, int& idx, int& val){
        if(l == r){
            st[i] = val;
            return;
        }
        int mid = (l+r)/2;
        if(idx <= mid){
            update(2*i+1, l, mid, idx, val);
        }else{
            update(2*i+2, mid+1, r, idx, val);
        }
        st[i] = st[2*i+1] + st[2*i+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n, 0);
        bt(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        update(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        fun(0, 0, n-1, left, right, sum);
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */