// 204. Count Primes
// 这题暴力做会超时，要使用Eratosthenes solution
// Input: an integer n > 1.
 
//  Let A be an array of Boolean values, indexed by integers 2 to n,
//  initially all set to true.
 
//  for i = 2, 3, 4, ..., not exceeding √n:
//    if A[i] is true:
//      for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n:
//        A[j] := false.
 
//  Output: all i such that A[i] is true.

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<int> pass(n,0);
        int upper = sqrt(n);
        int sum = 0;
        for(int i=2;i<n;i++){
            if(pass[i]==0){
                sum++;
                if(i>upper) continue; // avoid overflow
                for(int j = i*i;j<n;j+=i){
                    pass[j]=1;
                }
            }
        }
        return sum;
    }
    
};
