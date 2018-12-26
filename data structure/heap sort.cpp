// heap sort.cpp
#include <iostream>
 
using namespace std;
 
// A function to heapify the array.
// void MaxHeapify(int a[], int i, int n)
// {
// 	int child, cur_parent;
// 	cur_parent = a[i];
// 	child = 2*i;
 
//  	while (child <= n)
// 	{
// 		if (child < n && a[child+1] > a[child]){
// 			child = child+1;
// 		}
		
// 		// Break if parent value is already greater than child value.
// 		if (cur_parent > a[child])
// 			break;
// 		// Switching value with the parent node if cur_parent < a[child].
// 		else if (cur_parent <= a[child])
// 		{
// 			a[child/2] = a[child];
// 			child = 2*child;
// 		}
// 	}
// 	a[child/2] = cur_parent;
// 	return;
// }
void MaxHeapify(int a[], int i, int n){
	int child = i*2;
	int parent = a[i];
	while(child <= n){
		if(child+1<=n && a[child+1] > a[child]){
			child++;
		}
		if (parent<=a[child])
		{
			a[child/2] = a[child];
			child = child*2;
		} else {
			break;
		}
	}
	a[child/2] = parent;
}
void HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		// Storing maximum value at the end.
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		// Building max heap of remaining element.
		MaxHeapify(a, 1, i - 1);
	}
}
void Build_MaxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		MaxHeapify(a, i, n);
}
int main()
{
	int n, i;
	
	int arr[] = {1,3,4,2,5,7,10};
	n = sizeof(arr)/sizeof(int);
	
	// Building max heap.
	Build_MaxHeap(arr, n-1);
	HeapSort(arr, n-1);
 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
 
	for (i = 1; i < n; i++)
		cout<<"->"<<arr[i];
 
	return 0;
}
// Program Explanation
// 1. Take input of data.
// 2. Call Build_MaxHeap() function with ‘arr’ the array of data and ‘n-1’ the number of values, in the argument list.
// 3. After building the max heap call HeapSort().
// 4. Switch the root value of heap with the last index value of array since root value is highest among all.
// 5. Decrement the last index value.
// 6. Repeat it for all the element.
// 7. Return to main and display the result.
// 8. Exit.