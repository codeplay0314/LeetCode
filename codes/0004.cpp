class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int inf = 1e6 + 1;
        if (nums1.size() == 0) nums1.push_back(-inf), nums1.push_back(inf);
        if (nums2.size() == 0) nums2.push_back(-inf), nums2.push_back(inf);
        
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> &svec = n <= m ? nums1 : nums2;
        vector<int> &lvec = n <= m ? nums2 : nums1;
        if (n > m) swap(n, m);
        
        int lmed, rmed;
        int res = (n + m) / 2 - n;
        if (svec[n - 1] <= lvec[res]) {
            lmed = svec[n - 1];
            if (res > 0) lmed = max(lmed, lvec[res - 1]);
            rmed = lvec[res];
        } else {
            int l = 1, r = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (svec[n - mid] >= lvec[res + mid - 1]) l = mid + 1;
                else r = mid - 1;
            }
            lmed = lvec[res + r -1];
            if (r < n) lmed = max(lmed, svec[n - r - 1]);
            rmed = svec[n - r];
            if (res + r < m) rmed = min(rmed, lvec[res + r]);
        }
        if ((n + m) % 2) lmed = rmed;
        
        return ((double)lmed + rmed) / 2;
    }
};