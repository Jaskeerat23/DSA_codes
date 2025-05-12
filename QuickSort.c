#include<stdio.h>
#include<string.h>
int find_pivot_index(int [],int ,int);
void QuickSort(int [],int,int);
void Merging(int [],int,int,int,int);
int main()
{
    int n,arr[20];
    printf("Enter range of array : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("The provided array is : ");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    QuickSort(arr,0,n-1);
    printf("Modified array is : ");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
}
void QuickSort(int arr[],int i,int j){
    if(i==j)
        return;
    int mid;
    mid=find_pivot_index(arr,i,j);
    printf("Pivot index is %d\n",mid);
    QuickSort(arr,i,mid);
    if(mid!=j)
        QuickSort(arr,mid+1,j);
}
int find_pivot_index(int arr[],int i,int j){
    int right_trav=0,left_trav=1,k=j,pivot_index=i;
    while(right_trav!=left_trav){
        printf("Main while loop\n");
        if(left_trav==1){
            while(k>pivot_index){
                printf("k is %d and pivot index is %d\n",k,pivot_index);
                if(arr[k]<arr[pivot_index]){
                    int temp=arr[k];
                    arr[k]=arr[pivot_index];
                    arr[pivot_index]=temp;
                    left_trav=0,right_trav=1;
                    break;
                }
                k--;
            }
            if(pivot_index==k){
                break;
            }
            pivot_index=k;
            k=i;
        }
        if(right_trav==1){
            while(k<pivot_index){
                printf("k is %d and pivot index is %d\n",k,pivot_index);
                if(arr[k]>arr[pivot_index]){
                    int temp=arr[k];
                    arr[k]=arr[pivot_index];
                    arr[pivot_index]=temp;
                    left_trav=1,right_trav=0;
                    break;
                }
                k++;
            }
            if(pivot_index==k){
                break;
            }
            pivot_index=k;
            k=j;
        }
    }
    return pivot_index;
}