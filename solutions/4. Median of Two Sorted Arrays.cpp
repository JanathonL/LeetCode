4. Median of Two Sorted Arrays
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        return (findKth(nums1, nums2, (m + n + 1) / 2) + findKth(nums1, nums2, (m + n + 2) / 2)) / 2.0;
    }
    int findKth(vector<int> nums1, vector<int> nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findKth(nums2, nums1, k);
        if (m == 0) return nums2[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);
        int i = min(m, k / 2), j = min(n, k / 2);
        if (nums1[i - 1] > nums2[j - 1]) {
            return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k - j);
        } else {
            return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k - i);
        }
        return 0;
    }
};

// refined

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int first = findk(nums1,0,nums2,0,(n+m+1)/2);
        int second = findk(nums1,0,nums2,0,(n+m+2)/2);
        return (first+second)/2.0;
    }
    int findk(vector<int>& nums1, int begin1, vector<int>& nums2, int begin2, int k){
        int m = nums1.size()-begin1, n = nums2.size()-begin2;
        if(m>n) return findk(nums2,begin2,nums1,begin1,k);
        if(m==0) return nums2[begin2+k-1];
        if(k==1) return min(nums1[begin1],nums2[begin2]);
        int i = begin1 + min(m, k/2), j = begin2 + min(n, k/2);
        if(nums1[i-1]>nums2[j-1]) return findk(nums1,begin1,nums2,j,k-(j-begin2));
        else return findk(nums1, i, nums2, begin2, k-(i-begin1));
    }
};

// method 2
// beat 97%
// log(min(n,m))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if(n>m) return findMedianSortedArrays(b, a);
        int minI = 0, maxI = n;
        int i, j;
        int median=0;
        while(minI <= maxI){
            i = (minI+maxI)/2;
            j = (n+m+1)/2 - i;
            if(i>0 && j<m && a[i-1]>b[j])
                maxI = i-1;
            else if(i<n && j>0 && a[i]<b[j-1])
                minI = i+1;
            else{
                int maxleft = 0;
                if(i==0) { maxleft = b[j-1]; }
                else if(j==0) { maxleft = a[i-1]; }
                else { maxleft = max(a[i-1],b[j-1]); }
                if ((m+n)%2==1) { return maxleft; }
                
                int minright = 0;
                if(i==n) { minright = b[j]; }
                else if(j==m) {minright = a[i]; }
                else { minright = min(b[j],a[i]); }
                
                return (maxleft+minright)/2.0;
            }
        }
        return 0;
    }
};




