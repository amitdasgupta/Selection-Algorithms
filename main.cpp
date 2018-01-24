#include <iostream>
#include<string>
using namespace std;
/*********************tournament method to find minimum and maximum element in an array
struct value{
int min;
int max;
};

value returnMinMax(int *arr,int start,int last)
{
    value v;
    cout<<start<< " "<<last<<endl;
    if(start==last)
    {
        v.max=arr[start];
        v.min=v.max;
        return v;
    }
    else
        if(last==start+1)
    {
        if(arr[start]>arr[last])
        {
            v.max=arr[start];
            v.min=arr[last];
        }
        else
            {
            v.max=arr[last];
            v.min=arr[start];
        }
         return v;
    }
    else
    {    int mid=(last+start)/2;
        value left=returnMinMax(arr,start,mid);
        value right=returnMinMax(arr,mid+1,last);
        if(left.min<right.min)
            v.min=left.min;
        else
            v.min=right.min;
        if(left.max<right.max)
            v.max=right.max;
        else
            v.max=left.max;
            return v;
    }
}
*//////////
/*********problem to find the kth smallest element in an array*//////
void swapValues(int * &arr,int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int main()
{

    int *arr,n,k;
    cin>>n>>k;
    arr=new int[n]();
    for(int i=0;i<n;i++)
        cin>>arr[i];
     int min;
    for(int i=0;i<k;i++)
     {
         min=i;
         for(int j=i+1;j<n;j++)
         {
             if(arr[j]<arr[min])
                min=j;
            cout<<min<<endl;
         }
         if(min!=i)
         {
             swapValues(arr,i,min);
         }
     }
     cout<<arr[k-1];
     return 0;
}













