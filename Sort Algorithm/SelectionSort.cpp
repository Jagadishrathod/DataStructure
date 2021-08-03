#include<iostream>
using namespace std;

/*void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}*/

int SelectionSort(int size, int array[]){
	for(int i=0;i<size-1;i++){
		int index=i;
		for(int j=i+1;j<size;j++){
			if(array[j]<array[index]){
				index = j;
			}
		}
		//swap(array[index],array[i]);
		int temp = array[i];
		array[i] = array[index];
		array[index] = temp;
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
	SelectionSort(size, array);
	
	cout<<"After Sorting: ";
	for(i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
