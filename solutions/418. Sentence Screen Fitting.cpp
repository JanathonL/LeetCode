418. Sentence Screen Fitting
class Solution {
public:
    /**
     * @param sentence: a list of string
     * @param rows: an integer
     * @param cols: an integer
     * @return: return an integer, denote times the given sentence can be fitted on the screen
     */
    int wordsTyping(vector<string> &sentence, int rows, int cols) {
        int col_start = 0;
        int row_start = 0;
        int cnt = 0;
        int repeat_rows = 0;
        int repeat_cnt = 0;
        int res = 0;
        int total_len = 0;
        
        for(int i=0;i<sentence.size();i++){
            total_len+=sentence[i].size()+1;
        }
        // std::cout << total_len << std::endl;
        while(1){
            int i;
            // std::cout << "col_start:"<<col_start << std::endl;
            if(col_start+total_len<cols){
                cnt+= (cols - col_start)/total_len;
                col_start = cols - (cols - col_start)%total_len;
                if(col_start+total_len-1 == cols ){
                    cnt++;
                    col_start = cols;
                }
            }
            // std::cout << "cnt:"<<cnt << std::endl;
            // std::cout << "col_start:"<<col_start << std::endl;
            for(i=0;i<sentence.size();i++){
                if(sentence[i].size()+col_start>cols){
                    col_start = 0;
                    row_start ++;
                    // cout<<"i:"<<i<<endl;
                    if(i == 0){
                        repeat_cnt = cnt;
                        repeat_rows = row_start;
                        res += rows/repeat_rows * repeat_cnt;
                        row_start = rows - rows%repeat_rows;
                        cnt = res;
                        // std::cout << "repeat_cnt:"<<repeat_cnt << std::endl;
                        // std::cout << "repeat_rows:"<<repeat_rows << std::endl;
                    }
                    if(row_start<rows){
                        col_start += sentence[i].size()+1;
                    }
                    else{
                        break;
                    }
                }
                else{
                    col_start += sentence[i].size()+1;
                }
            }
            if(i==sentence.size()){
                cnt++;
            }
            else{
                return cnt;
            }
        }
    }
};