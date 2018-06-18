// 385. Mini Parser
// 递归的思路
// recursive(s,from,to)
// 结束条件是if(s[from]!=’[‘ ) 说明是integer了，直接构造integer

// 否则就是s[from] 就是 [
// from++
// to –
// prev = from
// 这样做的目的是去除最外面的括号，创建一个nestedlist  res
// 接着去遍历s，记录一下括号数匹配，而且当前s[i]==’,’ 说明是 [int], 这种情况，直接递归 recursive（s, prev, i）,  prev = i + 1;
// 本质是一个去括号的过程

// 最后判断一下如果 prev!=to 说明还有括号  接着递归去括号



class Solution {
public:
     NestedInteger deserialize(string& s, int from, int to) {   
         // cout<<"from:"<<from<<" to:"<<to<<endl;
        if (s[from] != '[') {
            return NestedInteger(stoi(s.substr(from, to - from)));
        }
        
        NestedInteger res;
        from++;
        to--;
        int prev = from, opened = 0;
        for (int i = from; i < to; ++i) {
            if (s[i] == '[') {
                opened++;
            } else if (s[i] == ']') {
                opened--;
            } else if (s[i] == ',' && opened == 0) {
                res.add(deserialize(s, prev, i));
                prev = i + 1;
            }
        }
         
         // cout<<prev<<endl;
        if (prev < to) {
            res.add(deserialize(s, prev, to));
        }
        return res;
    }

    NestedInteger deserialize(string s) {
        return deserialize(s, 0, s.size());
    }
};