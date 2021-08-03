#include<iostream>
//#include<algorithm>
using namespace std;

int Bubblesort(int size, int array[]){
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-i-1;j++){
			if(array[j]>array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	return 1;
}

int main(){
	int size,i,array[20];
	cout<<"Enter total number of elements: ";
	cin>>size;
	
	cout<<"Enter the "<<size<<" elements: \n";
	for(i=0;i<size;i++){
		cin>>array[i];
	}
	Bubblesort(size, array);
	
	cout<<"After Sorting: ";
	for(i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
