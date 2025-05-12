#include<stdio.h>
#include<string.h>
void MergeSort(int[],int,int);
void Merging(int[],int,int,int,int);
int main()
{
    int n,i,arr[10];
    printf("Enter the range of array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("The provided array is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    MergeSort(arr,0,n-1);
    printf("Sorted array:\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}
void MergeSort(int arr[],int i,int j){
    if(i==j)
        return;
    int mid;
    mid=i+(j-i)/2;
    MergeSort(arr,i,mid);
    MergeSort(arr,mid+1,j);
    Merging(arr,i,mid,mid+1,j);
}
void Merging(int arr[],int i,int mid,int j,int k){
    int p=i,temp[10],lower_bound=i;
    while(i<=mid && j<=k){
        if(arr[i]<arr[j]){
            temp[p]=arr[i];
            i++;
        }
        else{
            temp[p]=arr[j];
            j++;
        }
        p++;
    }
    while(j<=k){
        temp[p]=arr[j];
        p++,j++;
    }
    while(i<=mid){
        temp[p]=arr[i];
        p++,i++;
    }
    for(i=lower_bound;i<p;i++)
        arr[i]=temp[i];
}