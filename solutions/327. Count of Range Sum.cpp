327. Count of Range Sum
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sums(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            
            sums[i+1] = sums[i]+nums[i];
        }
        return mergeSort(sums,1,sums.size()-1,lower,upper);
    }
    int mergeSort(vector<long long>&sum, int left, int right, int lower, int upper)
    {
        int mid, i, res, j, k;
        if(left>right) return 0;
        if(left==right) return ( (sum[left]>=lower) && (sum[left]<=upper) )?1:0;
        else
        {
            vector<long long> temp(right-left+1,0);
            mid = (left+right)/2;
            res = mergeSort(sum, left,mid, lower, upper) + mergeSort(sum, mid+1,right, lower, upper); // merge sort two halfs first, be careful about how to divide [left, mid] and [mid+1, right]
            for(i=left, j=k=mid+1; i<=mid; ++i)
            { // count the valid ranges [i,j], where i is in the first half and j is in the second half
                while(j<=right && sum[j]-sum[i]<lower)  ++j;
                while(k<=right && sum[k]-sum[i]<=upper) ++k;
                res +=k-j;
            }
            for(i=k=left, j=mid+1; k<=right; ++k) //merge the sorted two halfs
                temp[k-left] = (i<=mid) && (j>right || sum[i]<sum[j])?sum[i++]:sum[j++]; 
            for(k=left; k<=right; ++k) // copy the sorted results back to sum
                sum[k] = temp[k-left]; 
            return res;
        }
    }
};
