// 378. Kth Smallest Element in a Sorted Matrix
// O(n^2)  一列一列或者一行一行进行merge就好了，list有一个merge函数

class Solution {
public:
    void put_list(list<int> l, char *name)   
    {   
        list<int>::iterator plist;   

        cout << "The contents of " << name << " : ";   
        for(plist = l.begin(); plist != l.end(); plist++)   
            cout << *plist << " ";   
        cout<<endl;   
    }  
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        list<int> res, temp1, temp2;
        for(int i=0;i<matrix.size();i++){
            temp1.push_back(matrix[0][i]);
            
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                temp2.push_back(matrix[i][j]);
            }
            // put_list(temp2,"temp2");
            temp1.merge(temp2);
            // put_list(temp1,"temp1");
            temp2.clear();
        }
        int cnt = 0;
        for(auto it = temp1.begin();it!=temp1.end();it++){
            cnt++;
            // cout<<*it<<endl;
            if(cnt==k){
                return *it;
            }
        }
    }
};