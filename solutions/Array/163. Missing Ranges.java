class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> res = new ArrayList<>();
        for(int num : nums){
            if(num>lower){
                res.add(""+lower+((lower<num-1)? "->"+(num-1):""));
            } 
            if(num==upper) return res;  // avoid overflow
            lower = num+1;
        }
        if(lower <= upper) res.add(lower + ((upper > lower)?"->"+(upper):""));
        return res;
    }
}