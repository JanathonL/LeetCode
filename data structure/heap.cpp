// heap
// 
// Sometimes during programming contests etc., 
// we need a simple working implementation of min priority queue with decrease-key to implement Dijkstra algorithm etc.. 
// I often use set< pair<key_value, ID> > 
// and an array (mapping ID-->key_value) together to achieve that.

// Adding an element to the set takes O(log(N)) time. 
// To build a priority queue out of N elements, 
// we simply add them one by one into the set. 
// This takes O(N log(N)) time in total.

// The element with min key_value is simply the first element of the set. 
// Probing the smallest element takes O(1) time. 
// Removing it takes O(log(N)) time.

// To test whether some ID=k is in the set, 
// we first look up its key_value=v_k in the array 
// and then search the element (v_k, k) in the set. This takes O(log(N)) time.

// To change the key_value of some ID=k from v_k to v_k', 
// we first look up its key_value=v_k in the array, 
// and then search the element (v_k, k) in the set. 
// Next we remove that element from the set and then insert the element (v_k', k) 
// into the set. We then update the array, too. This takes O(log(N)) time.