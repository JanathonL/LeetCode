// 367. Valid Perfect Square
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        if(num==1) return true;
        while(left<right){
            // cout<<left<<" "<<right<<endl;
            int mid = (right+left)/2;
            int tmp = INT_MAX/mid;
            if(mid > tmp){
                // cout<<mid<<" "<<tmp<<" "<<right<<endl;
                right = mid;
                continue;
            }
            int square = mid*mid;
            
            if(square==num){
                // cout<<"true"<<endl;
                return true;
            } 
            if(square>num){
                // cout<<">"<<endl;
                right = mid;
            }
            else{
                // cout<<mid<<"<"<<endl;
                left = mid+1;
            }
        }
        // cout<<test<<" "<<left<<" "<<right<<endl;
        if(left*left==num) return true;
        return false;
    }
};
// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         if(num==1||num==4) return true;
//         for(int i=2;i<num/2&&i*i<=num;i++){
//             if(i*i==num){
//                 return true;
//             }
//         }
//         return false;
//     }
// };