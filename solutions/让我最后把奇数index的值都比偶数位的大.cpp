让我最后把奇数index的值都比偶数位的大
[1,2,3,5,6,7,9]

// no duplicate
// O(n)
[1,3,2,6,5,9,7]
for (int i = 0; i < nums.size()-1; ++i)
{
	if (i%2==0)
	{
		if (nums[i]>nums[i+1]){
			swap(nums[i], nums[i+1]);
		}	
	} else {
		if (nums[i]<nums[i+1]){
			swap(nums[i],nums[i+1]);
		}
	}
}

//has duplicate, no guarantee an answer
