// class Solution {
// public:
//     /*
//     12345
//     40 min
//     7 wrongs
//     time: O(1)
//     space: O(1)
//     */
//     vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
//     vector<string> twenty = {"Zero", "One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
//     string helper(int num){
//         if(num>=1000000000) {
//             return helper(num/1000000000) + " Billion" + helper(num%1000000000);  // 注意空格可以放前面
//         } else if(num>=1000000){
//             return helper(num/1000000) + " Million" + helper(num%1000000);
//         } else if(num>=1000){
//             return helper(num/1000) + " Thousand" + helper(num%1000);
//         } else if(num>=100){
//             return helper(num/100) + " Hundred" + helper(num%100);
//         } else if(num>=20){
//             return " "+ tens[num/10] + helper(num%10);  // 注意空格可以放前面
//         } else if(num>0){
//             return " "+twenty[num];  // 注意空格可以放前面
//         } else {
//             return "";
//         }
//     }
//     string numberToWords(int num) {
//         if(num==0){
//             return "Zero";
//         }
//         string str = helper(num);
        
//         return str.substr(1);
//     }
// };

vector<string> less_than_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> thousands = {"", "Thousand", "Million", "Billion"};
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        int i = 0;
        string words = "";

        while (num > 0) {
            if (num % 1000 != 0)
                words = helper(num % 1000) +" "+ thousands[i] + words;
            num /= 1000;
            i++;
        }
        if(words[0]==' '){
            words = words.substr(1);
        }
        if(words.back()==' '){
            words.pop_back();
        }
        return words;
    }

    string helper(int num) {
        if (num == 0)
            return "";
        else if (num < 20)
            return " " + less_than_20[num];
        else if (num < 100)
            return " "+tens[num / 10] + helper(num % 10);
        else
            return " "+less_than_20[num / 100] + " Hundred" + helper(num % 100);
    }
};