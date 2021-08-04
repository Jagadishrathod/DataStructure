#include<iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high){
	int i=low,j=mid+1,k,index=low;
	int temp[20];
	while(i<=mid && j<=high){
		if(arr[i]<arr[j]){
			temp[index]=arr[i];
			i = i+1;
		}
		else{
			temp[index]=arr[j];
			j = j+1;
		}
		index++;
	}
	if(i>mid){
		while(j<=high){
			temp[index]=arr[j];
			index++;
			j++;
		}
	}
	else{
		while(i<=mid){
			temp[index]=arr[i];
			index++;
			i++;
		}
	}
	k = low;
	while(k<index){
		arr[k]=temp[k];
		k++;
	}
}

void MergeSort(int arr[], int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid+1, high);
		Merge(arr, low, mid, high);
	}
}

int main(){
	int size,i,arr[20];
	cout<<"Enter total number of elements: ";
	cin>>size;
	
	cout<<"Enter the "<<size<<" elements: ";
	for(i=0;i<size;i++){
		cin>>arr[i];
	}
	MergeSort(arr, 0, size-1);
	
	cout<<"After Sorting: ";
	for(i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
