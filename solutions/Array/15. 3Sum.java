class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if(nums.length<3){
            return new ArrayList<>();
        }
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for(int i = 0;i<nums.length-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int fix = nums[i], start = i+1, end = nums.length-1, target = 0;
            while(start<end){
                int sum = fix + nums[start] + nums[end];
                if(sum>target){
                    end--;
                } else if (sum<target){
                    start++;
                } else {
                    res.add(Arrays.asList(fix,nums[start],nums[end]));
                    end--;
                    start++;
                    while(start<end && nums[start]==nums[start-1]) start++;
                    while(start<end && nums[end]==nums[end+1]) end--;
                }
            }
        }
        return res;
    }
}