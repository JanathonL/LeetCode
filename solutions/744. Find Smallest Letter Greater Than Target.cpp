// 744. Find Smallest Letter Greater Than Target
// Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

// Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

// Examples:
// Input:
// letters = ["c", "f", "j"]
// target = "a"
// Output: "c"

// Input:
// letters = ["c", "f", "j"]
// target = "c"
// Output: "f"

// Input:
// letters = ["c", "f", "j"]
// target = "d"
// Output: "f"

// Input:
// letters = ["c", "f", "j"]
// target = "g"
// Output: "j"

// Input:
// letters = ["c", "f", "j"]
// target = "j"
// Output: "c"

// Input:
// letters = ["c", "f", "j"]
// target = "k"
// Output: "c"
// Note:
// letters has a length in range [2, 10000].
// letters consists of lowercase letters, and contains at least 2 unique letters.
// target is a lowercase letter.
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int pos = upper(letters,target);
        if(pos==letters.size()){
            pos = 0;
        }
        return letters[pos];
    }
    int upper(vector<char> letter, char target){
        int l = 0;
        int r = letter.size();
        while(l<r){
            int mid = l+(r-l)/2;
            if(letter[mid]>target){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return r;
    }
};