373. Find K Pairs with Smallest Sums
class CMP{
    public:
    bool operator()(tuple<int,int,int> a, tuple<int,int,int> b){
        int c1=get<0>(a);
        int c2=get<0>(b);
        if(c1!=c2) return c1 > c2;
        else if(get<1>(a)!=get<1>(b)) return get<1>(a) > get<1>(b);
        else return get<2>(a) > get<2>(b);
    }
};
class Solution {
    
public:
    int getmin(int a, int b){
        return a>b? b:a;
    }
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        priority_queue< tuple<int,int,int>,
            vector< tuple<int,int,int> >,
            CMP> q;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1==0 || len2 == 0 || k==0) return vector<pair<int,int>>();
        int cnt = getmin(len1,k);
        for(int i=0;i<cnt;i++){
            q.push(make_tuple(nums1[i]+nums2[0],i,0));
        }
        for(int i=0;i<k && !q.empty();i++){
            int cost,a,b;
            tie(cost,a,b)=q.top();
            q.pop();
            res.push_back(make_pair(nums1[a],nums2[b]));
            if(b<len2-1){
                q.push(make_tuple(nums1[a]+nums2[b+1],a,b+1));
            }
        }
        return res;
        
        
    }
};