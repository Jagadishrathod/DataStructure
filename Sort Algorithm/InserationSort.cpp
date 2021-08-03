#include<iostream>
using namespace std;

int InserationSort(int size, int arr[]){
	for(int i=1;i<size;i++){
		int current = arr[i];
		int j=i-1;
		while(arr[j]>current && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=current;
	}
}

int main(){
	int size,i,arr[20];
	cout<<"Enter total number of elements: ";
	cin>>size;
	
	cout<<"Enter the "<<size<<" elements: \n";
	for(i=0;i<size;i++){
		cin>>arr[i];
	}
	InserationSort(size, arr);
	
	cout<<"After Sorting: ";
	for(i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
