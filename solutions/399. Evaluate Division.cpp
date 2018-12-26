// 399. Evaluate Division
// Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

// Example:
// Given a / b = 2.0, b / c = 3.0. 
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
// return [6.0, 0.5, -1.0, 1.0, -1.0 ].

// The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

// According to the example above:

// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<vector<double>> matrix(26, vector<double>(26,INT_MAX));
        unordered_map<string, unordered_map<string, double>> m;
        for(int i=0;i<equations.size();i++){
            m[equations[i].first][equations[i].second] = values[i];
            if(values[i]!=0){
                m[equations[i].second][equations[i].first] = 1/values[i];
            }
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            unordered_map<string, bool> visited;
            double res = INT_MAX;
            if(m.find(queries[i].first)!=m.end())
                dfs(m,queries[i].first, queries[i].second, res, 1, visited);
            if(res==INT_MAX) res = -1;
            ans.push_back(res);
        }
        return ans;

    }
    void dfs(unordered_map<string, unordered_map<string, double>>& matrix, string b, string e, double& res, double cur, unordered_map<string, bool>& visited){
        if(b==e) {
            res = cur;
            return ;
        }
        visited[b] = true;
        for(auto it = matrix[b].begin();it!=matrix[b].end();it++){
            if(visited[it->first]!=true){
                string next = it->first;
                double val = it->second;
                dfs(matrix, next, e, res, cur*val, visited);
            }
        }
        visited[b] = false;
    }
};