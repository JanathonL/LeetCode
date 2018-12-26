484. Find Permutation
class Solution {
public:
    vector<int> findPermutation(string s) {
        int n=s.length();
        vector<int> arr(n+1, 0);
        for (int i=0; i<arr.size(); i++)
            arr[i] = i+1;
        for (int h = 0; h < n; h++) {
            if (s[h] == 'D') {
                int l = h;
                while (h < n && s[h] == 'D') h++;
                reverse(arr, l, h); 
            }
        }
        return arr;
    }
    void reverse(vector<int>& arr, int l, int h) {
        while (l < h) {
            swap(arr[l],arr[h]);
            l++; h--;
        }   
    }
};