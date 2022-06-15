#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    int arr[n];
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    
    for (int i = 0; i < n-1; i++)
    {
       for (int j = i+1; j < n; j++)
       {
           count1++;
           if (arr[j]<arr[i])
           {
              int temp = arr[j];
              arr[j]=arr[i];
              arr[i]=temp;
              count2++;  
           }
           
       }
       
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<count1<<" "<<count2<<endl;
    cout<<count1 + count2<<endl;
    return 0;
}