// 303. Range Sum Query – Immutable
// 令状态f[i]为0到i元素之间的和，则状态转移方程为 f[i] = f[i-1] + nums[i]。
// f[i]本质上是累加和，有了f[i]，则范围[i,j]之间的和等于f[j] - f[i-1]。

class NumArray {
public:
    NumArray(vector<int> nums) {
        sum = vector<int>(nums.size()+1,0);
        sum[0]=0;
        for(int i =1;i<=nums.size();i++){
            sum[i]= nums[i-1]+sum[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */