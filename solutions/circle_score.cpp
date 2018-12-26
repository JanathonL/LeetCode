// circle_score
// 给一堆(x, y)的二维坐标，每一个坐标对应一个整形的score。以原点为圆心的，会有很多圆存在。
// 需要找出一个圆，使得这个圆内的（包括圆上）所有score的和最大。
// "给一堆(x, y)的二维坐标，每一个坐标对应一个整形的score。以原点为圆心的，会有很多圆存在。需要找出一个圆，使得这个圆内的（包括圆上）所有score的和最大。不用返回半，只需要返回最大的和即可。

// 有几种不容易想到的corner case：
// 1. 如果原点本身存在点，这些点肯定会被选中。
// 2. 如果所有score都是负数，并且原点本身没有点，那最好的答案就是0。因为可以任何点都不选。
// 3. 如果在一个圆上有好几个点，那这些点要么全都不选，要么全选。"

use hashmap <distance, sum_score>
vector<double> dists
sort(dist)
sum = hashmap[0]
max_sum = hashmap[0]
for(dist : dists){
	if(0==dist){
		continue;
	} else {
		sum += hashmap[dist];
		max_sum = max(max_sum, sum);
	}
}
return max_sum;
