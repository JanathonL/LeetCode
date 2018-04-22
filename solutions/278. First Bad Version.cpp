// 278. First Bad Version
// 二分搜索，只要一定保证right是bad version。最后返回right就好了。
// 有一个坑点就是 (left+right)/2可能会溢出，要写成(left/2+right/2)
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1;
        int long right=n;
        while(left<right){
            int mid=(left/2+right/2);
            if(isBadVersion(mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return right;
    }
};