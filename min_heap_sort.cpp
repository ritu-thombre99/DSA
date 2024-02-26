# include<iostream>
# include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n,int i)
{
    int smallest = i;
    int left = 2*smallest + 1;
    int right = left + 1;
    if(left < n && arr[smallest] > arr[left])
        smallest = left;
    if(right < n && arr[smallest] > arr[right])
        smallest = right;
    if(smallest != i)
    {
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        heapify(arr,n,smallest);
    }

}
int main()
{
    vector<int> arr;
    for(int i=0;i<10;i++)
        arr.push_back(i);
    cout<<"Before sorting:\n";
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    int n = arr.size();
    for(int i=n -1;i>=0;i--)
        heapify(arr,n,i);
    for(int i=n-1;i>=0;i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
    }
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}