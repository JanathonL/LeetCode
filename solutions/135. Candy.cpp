135. Candy
class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> res(n,0);
        for(int i =1;i<n;i++){

            if(ratings[i-1]<ratings[i]&&!(res[i-1]<res[i])){
                res[i]=res[i-1]+1;
                // cout<<res[i]<<endl;
            }
        }
        cout<<endl;
        for(int i=n-2;i>=0;i--){

            if(ratings[i+1]<ratings[i]&&!(res[i+1]<res[i])){
                res[i]=res[i+1]+1;
                // cout<<"later:"<<res[i]<<endl;
            }
            
        }
        // cout<<endl;

        int sum = 0;
        for(int i =0;i<n;i++){
            // cout<<res[i]<<" ";
            sum += res[i]+1;
        }
        // cout<<endl;
        return sum;
    }
};