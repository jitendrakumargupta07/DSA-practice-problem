class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    // Resize nums1 to accommodate both arrays
    nums1.resize(m + n);

    // Merge nums2 into nums1
    std::copy(nums2.begin(), nums2.end(), nums1.begin() + m);

    // Sort nums1 (since both arrays are already sorted, this merge is unnecessary)
    std::sort(nums1.begin(), nums1.end());
}
};