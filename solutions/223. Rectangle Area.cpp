223. Rectangle Area
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int leftx = max(A,E), lefty = max(B,F), rightx = min(C,G), righty = min(D,H);
        // cout<<leftx<<" "<<lefty<<" "<<rightx<<" "<<righty<<endl;
        if(leftx<=rightx && lefty<=righty){
            return (C-A)*(D-B)+(G-E)*(H-F)-(rightx-leftx)*(righty-lefty);
        }
        else{
            return (C-A)*(D-B)+(G-E)*(H-F);
        }
    }
    
};