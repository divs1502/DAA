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

    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int j=i-1;
        count1++;
        while (arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
            count2++;
        }
        arr[j+1]=current;
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