68. Text Justification
/*
check num (num_word) of words can be put in this string -> sum(word.size()+1) <= len_line+1
cal the space num_space = len_line - sum(word.size());
space_for_word = num_space/(num_word-1);
extra_space = num_space%(num_word-1);
fill the line with word and space and extra_space; each time extra_space --

when i reach the end, 
fill words with only one space
44min
cannot finish


15 min 
2 wrong
time: O(N)
space: O(1)
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // check empty
        if(words.size()==0){
            return vector<string>();
        }
        int n = words.size();
        int num_word = 0;
        vector<string> res;
        for(int i=0;i<n;i+=num_word){
            int sum = 0;
            num_word = 0;
            for(num_word=0;i+num_word<n && sum+words[i+num_word].size() <= maxWidth-num_word; num_word++){
                sum += words[i+num_word].size();
            }
            
            int space_for_word = (num_word-1)>1 ? (maxWidth-sum)/(num_word-1) :  (maxWidth-sum);
            int extra_space = (num_word-1)>1 ?(maxWidth-sum)%(num_word-1): 0;
            // cout<<space_for_word<<" "<<extra_space<<endl;
            string temp = words[i];
            for(int j=i+1;j<i+num_word;j++){
                if(i+num_word<n){
                    temp += string(space_for_word, ' ');
                    if(extra_space>0){
                        temp += " ";
                        extra_space--;
                    }
                } else {
                    temp += ' ';
                }
                
                temp += words[j];
                
            }
            temp += string(maxWidth-temp.size(), ' ');
            // cout<<temp<<endl;
            res.push_back(temp);
            
        }
        return res;
    }
};