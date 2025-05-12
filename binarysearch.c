#include<stdio.h>
#include<string.h>
int binarysearch(int[],int,int);
int binarysearch_rec(int [],int,int,int);
int main()
{
    int arr[10],n,val;
    printf("Enter range of array: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the value you want to search for: ");
    scanf("%d",&val);
    int res=binarysearch_rec(arr,val,0,(sizeof(arr))/sizeof(arr[0]));
    printf("The index is %d\n",res);
}
//ITERTIVE METHOD:
int binarysearch(int arr[],int n,int high){
    int low=0,mid;
    while(1){
        mid=(low+high)/2;
        if(arr[mid]==n)
            return mid;
        else if(arr[mid]<n)
            low=mid+1;
        else if(arr[mid]>n)
            high=mid;
    }
}
//RECURSIVE METHOD:
int binarysearch_rec(int arr[],int n,int low,int high){
    int mid=(low+high)/2;
    if(arr[mid]!=n){
        if(arr[mid]>n)
            mid=binarysearch_rec(arr,n,low,mid);
        else if(arr[mid]<n)
            mid=binarysearch_rec(arr,n,mid+1,high);
    }
    return mid;
}