#include<bits/stdc++.h>

using namespace std;

struct item{
	int w, v;
	float r;
};

float fractional_knapsack(int n, int w, struct item items[]){
	int i=n-1;
	float max=0, curr=0;
	while(i>=0 && curr<w){
		if(items[i].w+curr<=w){
			max+=items[i].v;
			curr+=items[i].w;
		}
		else{
			max+=(((w-curr)/items[i].w)*items[i].v);
			curr+=(((w-curr)/items[i].w)*items[i].w);
		}
		i--;
	}
	return max;
}

void insertion(int n, struct item items[]){
	int i, j;
	struct item key;
	for(i=0; i<n; i++){
		key=items[i];
		j=i-1;
		while(j>=0 && items[j].r>key.r){
			items[j+1]=items[j];
			j--;
		}
		items[j+1]=key;
	}
}

int main(){

	int n, i, w;

	cout<<"Enter No of Items :: ";
	cin>>n;

	cout<<"Enter Maximum Weight :: ";
	cin>>w;

	struct item items[n];

	for(i=0; i<n; i++){
		cout<<"Enter Weight & Value of "<<i+1<<" item :: ";
		cin>>items[i].w>>items[i].v;
		items[i].r=items[i].v/items[i].w;
	}

	insertion(n, items);

	cout<<"Sorted Items Are :: \n";
	for(i=0; i<n; i++){
		cout<<"\nItem "<<i+1<<" is (W, V, R) :: ";
		cout<<items[i].w<<" "<<items[i].v<<" "<<items[i].r;
	}
	cout<<"\nMax Profit is :: "<<fractional_knapsack(n, w, items);

	return 0;
}