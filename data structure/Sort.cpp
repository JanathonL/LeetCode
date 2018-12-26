#include <iostream>
#include <vector>
using namespace std;
// Sort.cpp
// quicksort
// pseducode 
quickSort(arr[], low, high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
partition (arr[], low, high)
{
    // pivot (Element to be placed at right position)
    pivot = arr[high];  
 
    i = (low - 1)  // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap arr[i] and arr[j]
        }
    }
    swap arr[i + 1] and arr[high]
    return (i + 1)
}



int partition(vector<int>& array, int l, int h){
    int pivot = array[h];
    int i=l-1;
    for(int j=l;j<h;j++){
        if(array[j]<pivot){
            i++;
            swap(array[j],array[i]);
        }
    }
    swap(array[i+1],array[h]);
    return i+1;
}

void quicksort(vector<int>& array, int l, int h){
    if(l>=h) return;
    int p = partition(array, l, h);
    quicksort(array, l, p-1);
    quicksort(array, p+1, h);
}

void insertionSort(int arr[], int n)
{
   int i;
   for (i = 1; i < n; i++)
      insert(arr, i);
} 
void insert(int arr[], int i)
{
    int key = arr[i];
    int j;
    for(j=i-1;j>=0;j--){
        if(arr[j]>key){
            arr[j+1] = arr[j];
            
        }
        else{
            break;
        }
    }
    arr[j+1] = key;
}
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} 
// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int temp[r+1];
    int index = l;
    int i=l;
    int j=m+1;
     while(i<=m&&j<=r){
         if(arr[i]<arr[j]){
             temp[index++] = arr[i];
             i++;
         }
         else{
             temp[index++] = arr[j];
             j++;
         }
     }
     while(i<=m){
         temp[index++] = arr[i++];
     }
     while(j<=r){
         temp[index++] = arr[j++];
     }
     for(int k=l;k<=r;k++){
         arr[k] = temp[k];
     }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> array(n,0);
	    for(int i=0;i<n;i++){
	        cin>>array[i];
	    }
	    quicksort(array,0,n-1);
	    for(int item:array){
	        cout<<item<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}