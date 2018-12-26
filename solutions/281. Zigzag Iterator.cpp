281. Zigzag Iterator
class ZigzagIterator {
public:
    
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */
    ZigzagIterator(vector<int>& v1, vector<int>& v2){
        // do intialization if necessary
        if(v1.size()!=0) q.push(make_pair(v1.begin(),v1.end()));
        if(v2.size()!=0) q.push(make_pair(v2.begin(),v2.end()));
    }

    /*
     * @return: An integer
     */
    int next() {
        vector<int>::iterator it1 = q.front().first;
        vector<int>::iterator it2 = q.front().second;
        if(it1+1!=it2) q.push(make_pair(it1+1,it2));
        q.pop();
        return *it1;
        // write your code here
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        return !q.empty();
        // write your code here
    }
private:
    queue<pair<vector<int>::iterator,vector<int>::iterator>> q;
};