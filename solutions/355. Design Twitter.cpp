// 355. Design Twitter
// OO design,没什么好说的，完全模拟，好多边界都炸了
// 用一个timestamp记录每个tweet的时间
// unfollow 清除所有followee的tweet
// follow 加上followee的tweet

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        time=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        time++;
        vector<int> neighbor= neighbors[userId];
        for(int i=0;i<neighbor.size();i++){
            // cout<<neighbor[i]<<endl;
            // cout<<tweetId<<" "<<time<<" "<<userId<<endl;
            m[neighbor[i]].push_back({tweetId,time,userId});
        }
        m[userId].push_back({tweetId,time,userId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        // cout<<m[userId].size()<<endl;
        for(int i=m[userId].size()-1;i>=0;i--){
            
            ans.push_back(m[userId][i][0]);
            if(ans.size()==10) return ans;
        }
        return ans;
    }
    static bool cmp(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(find(neighbors[followeeId].begin(),neighbors[followeeId].end(),followerId)!=neighbors[followeeId].end()) return ;
        if(followerId==followeeId) return;
        neighbors[followeeId].push_back(followerId);
        vector<vector<int>> fe = getUnique(followeeId,followeeId,10);
        for(int i=0;i<fe.size();i++){
            m[followerId].push_back(fe[i]);
            // cout<<fe[i][0]<<" "<<fe[i][1]<<" "<<fe[i][2]<<endl;
        }
        sort(m[followerId].begin(),m[followerId].end(),cmp);
    }
    vector<vector<int>> getUnique(int user1, int user2, int k){
        vector<vector<int>> ans;
        for(int i=m[user1].size()-1;i>=0;i--){
            if(m[user1][i][2]==user2){
                ans.push_back(m[user1][i]);
            }
            if(ans.size()==k){
                return ans;
            }
        }
        return ans;
    }
    vector<vector<int>> getNotUnique(int user1, int user2){
        vector<vector<int>> ans;
        for(int i=0;i<m[user1].size();i++){
            if(m[user1][i][2]!=user2){
                ans.push_back(m[user1][i]);
            }
        }
        return ans;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(find(neighbors[followeeId].begin(),neighbors[followeeId].end(),followerId)==neighbors[followeeId].end()) return ;
        vector<vector<int>> fe = getNotUnique(followerId,followeeId);
        m[followerId] = fe;
        sort(m[followerId].begin(),m[followerId].end(),cmp);
        neighbors[followeeId].erase(find(neighbors[followeeId].begin(),neighbors[followeeId].end(),followerId));
    }
private:
    int time;
    unordered_map<int,vector<vector<int>>> m;
    unordered_map<int,vector<int>> neighbors;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */