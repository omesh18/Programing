/* C++ program to sort the array using quick sort algorithm. */

#include <iostream>
using namespace std;

/* 
  function to swap the array elements
*/
void swap(int arr[],int left,int right){
	int temp = arr[left];
	arr[left]=arr[right];
	arr[right]=temp;
}

/*
  function to find the pivot in the given range of the array. 
  The selection of the pivot point here is the array's
  right most element and then compared the elements with it.
*/
int partition(int arr[],int left,int right){
 
	int pivot = arr[right];
 
	int i = left-1;
 
	for(int j=left;j<right;j++){
		if(arr[j] <= pivot){
			i++;
			swap(arr,i,j);
		}
	}
 
	swap(arr,i+1,right);
	return i+1;
}

/* 
  quicksort function to recursively call it for the given range 
*/
void quicksort(int arr[],int left,int right){
	if(left < right){
		int pivot = partition(arr,left,right);
		quicksort(arr,left,pivot-1);
		quicksort(arr,pivot+1,right);
	}
}
 
 
int main() {

	int arr[] = {1,5,3,8,6,9};
	int size = sizeof(arr)/sizeof(arr[0]);
 
	quicksort(arr,0,size-1);
 
	cout<<"sorted array :"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
 
	return 0;
}
