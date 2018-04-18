// 167. Two Sum II - Input array is sorted
// 左右夹逼，定一个start，end, 一个从头，一个从尾遍历过来

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start,end;
        start = 0;
        end = numbers.size()-1;
        vector<int> res;
        while(start<end){
            if(numbers[start]+numbers[end]>target){
                end--;
            }
            else if(numbers[start]+numbers[end]<target){
                start++;
            }
            else{
                res={start+1,end+1};
                return res;
            }
        }
        return {};
    }
};