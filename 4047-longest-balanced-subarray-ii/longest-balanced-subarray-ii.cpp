class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        SegmentTree seg(nums.size());
        unordered_map<int,int> prev_idx;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i] % 2 ? 1 : -1;
            if (prev_idx.contains(nums[i])) {
                seg.update(0, 0, prev_idx[nums[i]], -val);
            }
            seg.update(0, 0, i, val);
            int left_idx = seg.find_left_most_idx(0);
            prev_idx[nums[i]] = i;
            if (left_idx != -1) {
                res = max(res, i - left_idx + 1);
            }
        }
        return res;
    }
private:
    class SegmentTree {
        public:
            SegmentTree(uint32_t size) : _size(size), _min_tree(size * 4), _max_tree(size * 4), _lazy(size * 4) {

            }
            void update(int node, int left_idx, int right_idx, int val, int seg_left = -1, int seg_right = -1) {
                push(node, seg_left, seg_right);
                if (seg_right == -1) {
                    seg_left = 0, seg_right = _size - 1;
                }
                if (left_idx > seg_right || right_idx < seg_left) {
                    return;
                }
                if (seg_left >= left_idx && seg_right <= right_idx) {
                    _lazy[node] += val;
                    push(node, seg_left, seg_right);
                    return;
                }
                int mid = seg_left + (seg_right - seg_left) / 2;
                update(node * 2 + 1, left_idx, right_idx, val, seg_left, mid);
                update(node * 2 + 2, left_idx, right_idx, val, mid + 1, seg_right);
                _min_tree[node] = min(_min_tree[node * 2 + 1], _min_tree[node * 2 + 2]);
                _max_tree[node] = max(_max_tree[node * 2 + 1], _max_tree[node * 2 + 2]);
            }
            int find_left_most_idx(int node, int seg_left = -1, int seg_right = -1) {
                if (seg_left == -1) {
                    seg_left = 0, seg_right = _size - 1;
                }
                push(node, seg_left, seg_right);
                if (_min_tree[node] > 0 || _max_tree[node] < 0) {
                    return -1;
                }
                if (seg_left == seg_right) {
                    return _max_tree[node] == 0 ? seg_left : -1;
                }
                int mid = seg_left + (seg_right - seg_left) / 2;
                if (int idx = find_left_most_idx(node * 2 + 1, seg_left, mid); idx != -1) {
                    return idx;
                }
                return find_left_most_idx(node * 2 + 2, mid + 1, seg_right);
            }
        private:
            int _size;
            vector<int> _min_tree, _max_tree, _lazy;
            void push(int node, int seg_left, int seg_right) {
                if (_lazy[node] == 0)
                    return;
                _min_tree[node] += _lazy[node]; 
                _max_tree[node] += _lazy[node]; 
                if (seg_left != seg_right) {
                    _lazy[node * 2 + 1] += _lazy[node];
                    _lazy[node * 2 + 2] += _lazy[node];
                }
                _lazy[node] = 0;
            }
    };
};