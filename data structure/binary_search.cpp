#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;
bool cmp(int a, int b){
	return a>b;
}
void print(list<int> l){
	for(int it: l){
		cout<<it<<" ";
	}
	cout<<endl;
}
int upper(vector<int> nums, int target){
    int l = -1;
    int r = nums.size();
    while(l<r){
        int m = l + (r-l)/2;
        if(nums[m]>target){
            r = m;
        }
        else{
            l = m+1;
        }
    }
    return r;
}

int lower(vector<int> nums, int target){
    int l = -1;
    int r = nums.size();
    while(l<r){
        int m = l + (r-l+1)/2;   // make sure ceiling
        if(nums[m]>=target){
            r = m-1;
        }
        else{
            l = m;
        }
    }
    return r;
}
int main(){
	list<int> l;
	for (int i = 0; i < 10; ++i)
	{
		l.push_back(i);
	}

	l.sort(cmp);
	print(l);
	auto it = l.begin();
	it++;
	cout<<*it<<endl;
	l.splice(l.begin(),l,it);
	cout<<*it<<endl;
	print(l);
}