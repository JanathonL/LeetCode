medium_add_get_remove
维护一个中位数。先要支持add和get。做完后要支持remove。remove真的难想，就一直靠面试官提示。
// 我看过一个解答 两个int 存两个PQ的实际size multiset存应该被删除的数字 hashmap存被删除的数字不行吗
// 以后每次从PQ取数字时候先看看set里面有么有 若有就跳过。其实更好的办法是可以用hashheap 带删除的PQ。
/**
 * use two priority_queues and hashmap
 * cnt_for_max_heap
 * cnt_for_min_heap
 * max_heap for the small one and min_heap for the bigger one
 * the max_heap size is >= min_heap size 
 * if max_heap size > min_heap size:
 * 		cnt_for_min_heap++
 * 		if item > getTop(max_heap, hashmap):
 * 			min_heap.push(item)
 * 			
 * 		else 
 * 			put the item to max_heap 
 * 		 	min_heap.push(max_heap.top())
 * 		  	max_heap.pop
 * 		  	
 *  else:
 *  	cnt_for_max_heap++
 *  	if item > getTop(max_heap, hashmap):
 *  		min_heap.push(item)
 *  		max_heap.push(min_heap.top())
 *  		min_heap.pop
 *  	else:
 *  		max_heap.push(item)
 *
 *
 * 	get: 
 * 		if cnt_for_min_heap == cnt_for_max_heap:
 * 			return (getTop(min_heap, hashmap) + getTop(max_heap, hashmap)) /2.0
 * 		else
 * 			return getTop(min_heap, hashmap) 
 *
 * 	remove:
 * 		hashmap[item]++
 * 		if(item >= min_heap.top()){
 * 			cnt_for_min_heap--;
 * 			
 * 		} else {
 * 			cnt_for_max_heap--;
 * 		}
 * 		adjust(max_heap, min_heap);
 * 		
 * 	int getTop(max_heap, hashmap):
 * 		while(max_heap.top() is in hashmap){
 * 			hashmap[max_heap.top()]--
 * 			if(hashmap[max_heap.top()]==0){
 * 				hashmap.erase(max_heap.top())
 * 			}
 * 			max_heap.pop()
 * 		}
 * 		return max_heap.top();
 *  void adjust(max_heap, min_heap, hashmap):
 *  	if(cnt_for_min_heap > cnt_for_max_heap){
 *  		top = getTop(min_heap, hashmap);
 *  		max_heap.push(top)
 *  		min_heap.pop()
 *  		cnt_for_min_heap --;
 *  		cnt_for_max_heap ++;
 *  	} else if(cnt_for_max_heap > cnt_for_min_heap+1){
 *  		cnt_for_min_heap ++;
 *  		cnt_for_max_heap --;
 *  		top = getTop(max_heap, hashmap);
 *  		min_heap.push(top);
 *  		max_heap.pop();
 *  	}
 * 		
 *  
 */
