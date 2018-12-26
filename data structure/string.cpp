#include <string>
#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string s, char delimiter);
int main(int argc, char const *argv[])
{
	// string s = "asdf asdf qwerwer sadfasfd";
	// std::vector<string> v = split(s, ' ');
	// cout<<"string:"<<s<<endl;
	// cout<<"word count:"<<v.size()<<endl;
	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	cout<<v[i]<<endl;
	// }
	string num1 = "1234";
	string num2 = "4566";
	int n = num1.size();
    int m = num2.size();
    vector<int> ans(m+n,0);
    for(int i=num1.size()-1;i>=0;i--){
        for(int j=num2.size()-1;j>=0;j--){
            ans[i+j-1]=(num1[i]-'0')*(num2[j]-'0');
            cout<<ans[i+j-1]<<endl;
        }
    }
	return 0;
}
vector<string> split(string s, char delimiter){
	int pos;
	vector<string> res;
	int i;
	for(i=0;i<s.size();i++){
		pos = s.find(delimiter, i);
		cout<<pos<<endl;
		if(pos==string::npos){
			break;
		}
		else{
			string temp = s.substr(i, pos-i);
			i = pos;
			res.push_back(temp);

		}
	}
	res.push_back(s.substr(i));
	return res;
}