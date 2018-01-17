#include <iostream>

using namespace std;
/*********************tournament method to find minimum and maximum element in an array*//////////
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

int main()
{
    int *arr,n;
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
     value v=returnMinMax(arr,0,n-1);
     cout<<v.min<<" "<<v.max;
    return 0;
}
