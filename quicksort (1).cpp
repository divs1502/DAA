#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int l, int h, int ar[]){
	int pivot=ar[l], i=l, j=h;

	while(i<j){
		do{
			i++;
		}while(ar[i]<=pivot);

		do{
			j--;
		}while(ar[j]>pivot);

		if(i<j){
			swap(&ar[i], &ar[j]);
		}
	}
	swap(&ar[l], &ar[j]);
	return j;
}

void quicksort(int l, int h, int ar[]){
	if(l<h){
		int j=partition(l, h, ar);
		quicksort(l, j, ar);
		quicksort(j+1, h, ar);
	}
}


int main(){

	int n, i;

	cout<<"Enter Number of Elements :: ";
	cin>>n;

	int ar[n];
	
	cout<<"Enter (Space Separated) Elements :: ";
	for(i=0; i<n; i++){
		cin>>ar[i];
	}

	quicksort(0, n, ar);

	cout<<"Sorted Elements :: ";
	for(i=0; i<n; i++){
		cout<<ar[i]<<" ";
	}




	return 0;
}