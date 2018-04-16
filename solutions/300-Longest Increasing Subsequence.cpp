// 300. Longest Increasing Subsequence
// (1)	DFS: Time: O(n^2),  Space: O(1)
// 直接dfs做，注意剪枝，不然超时
// 我加了一个nums.size()- i>maxlen-cnt的剪枝，也就是如果后续数字总的长度加上当前序列长度小于maxlen，那就不要搜了。
// (2)	DP: Time: O(n^2),  Space: O(n)
// f[i]表示以nums[i]结尾的最大递增序列长度
// 状态转移方程就是
// f[j]=max(f[j],f[i]+1) if(i<j&&nums[i]<nums[j])
// (3)	二分查找，维护一个递增数组list。 Time: O(n log n),  Space: O(n)
// 如果这个数比数组里所有的元素都大，list.push_back(nums[i]), 否则 list[pos] = nums[i]更新对应位置。


