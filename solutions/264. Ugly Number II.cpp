// 264. Ugly Number II
// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

// Example:

// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note:  

// 1 is typically treated as an ugly number.
// n does not exceed 1690.
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        int p1,p2,p3;
        p1=p2=p3=0;
        vector<int> res;
        res.push_back(1);
        int cnt = 1;
        while(cnt<n){
            int times2 = res[p1]*2;
            int times3 = res[p2]*3;
            int times5 = res[p3]*5;
            int minv = min(min(times2,times3),times5);
            
            if(times2==minv){
                p1++;
                if(minv<=res.back()) {
                    continue;
                }
                else{
                    res.push_back(times2);
                }
                
                
            }
            else if(times3==minv){
                p2++;
                if(minv>res.back()){
                    res.push_back(times3);
                }
                else{
                    continue;
                }
                
                
            }
            else{
                p3++;
                if(minv>res.back()){
                    res.push_back(times5);
                }
                else{
                    continue;
                }
                
            }
            cnt++;
            // cout<<minv<<endl;
        }
        // cout<<p1<<" "<<p2<<" "<<p3<<endl;
        return res.back();
        
    }
};