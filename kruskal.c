#include<stdio.h>
#include<stdlib.h>
typedef struct Node_list{
    int node;
    struct Node_list* next_node;
    struct Edge_list* edge_head;
}Nl;
typedef struct Edge_list{
    int weight;
    int node_idx;
    struct Edge_list* next;
}El;
typedef struct Sorted_list{
    int source_idx,dest_idx,weight;
}Sl;
typedef struct Origin_list{
    int node_val;
    int org;
}Ol;
Nl* create_node(int);
Nl* connecting_nodes(Nl*,int,int,int);
Sl* sort_list(Sl*,int,int,int);
void display_origin(Ol[],int);
void kruskal(Nl* graph[],Ol origin[],int n);
void MergeSort(Sl[],int,int);
void Merging(Sl[],int,int,int,int);
void display(Nl*[],int);
int main()
{
    Nl* graph[10];
    Ol origin[10];
    int weight,val,source,dest,ch=1,i=0;
    while(ch){
        while(ch){
            printf("Enter 1 to create node in a graph\nEnter 2 to connect nodes\nEnter 3 to display Graph\nEnter 4 to apply KRUSKAL ALGORITHM on existing graph\nEnter 5 to see origin matrix\nEnter 0 to stop : ");
            scanf("%d",&ch);
            switch(ch){
                case 0:break;
                case 1:printf("Enter the new node value : ");
                    scanf("%d",&val);
                    graph[i]=NULL;
                    origin[i].node_val=val;
                    origin[i].org=i;
                    graph[i]=create_node(val); i++; break;
                case 2:printf("Enter the position of node you want to connect from : ");
                    scanf("%d",&source);
                    printf("Enter the posiiton of node you want to connect to : ");
                    scanf("%d",&dest);
                    printf("Enter the weight of this edge : ");
                    scanf("%d",&weight);
                    graph[source-1]=connecting_nodes(graph[source-1],source-1,dest-1,weight); break;
                case 3:display(graph,i); break;
                case 4:kruskal(graph,origin,i); break;
                case 5:display_origin(origin,i);
            }
        }
    }
}
Nl* create_node(int val){
    Nl* temp=malloc(sizeof(Nl));
    temp->node=val;
    temp->edge_head=NULL;
    temp->next_node=NULL;
    return temp;
}
Nl* connecting_nodes(Nl*graph,int source,int dest,int weight){
    El* temp=malloc(sizeof(El)),*ptr=graph->edge_head;
    printf("Source index is %d and destination index is %d\n",source,dest);
    temp->weight=weight;
    temp->node_idx=dest;
    temp->next=NULL;
    if(ptr==NULL){
        graph->edge_head=temp;
        return graph;
    }
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=temp;
    return graph;
}
void kruskal(Nl* graph[],Ol origin[],int n){
    Sl sorted_array[100];
    int idx=0;
    for(int i=0;i<n;i++){
        El* ptr=graph[i]->edge_head;
        while(ptr!=NULL){
            sorted_array[idx].source_idx=i;
            sorted_array[idx].dest_idx=ptr->node_idx;
            sorted_array[idx].weight=ptr->weight;
            idx++;
            ptr=ptr->next;
        }
    }
    printf("INITIALLY SORTED ARRAY IS : \n");
    for(int i=0;i<idx;i++){
        printf("Source index : %d | Destination index : %d | weight : %d\n",sorted_array[i].source_idx,sorted_array[i].dest_idx,sorted_array[i].weight);
    }
    MergeSort(sorted_array,0,idx-1);
    printf("SORTED ARRAY : \n");
    for(int i=0;i<idx;i++){
        printf("Source index : %d | Destination index : %d | weight : %d\n",sorted_array[i].source_idx,sorted_array[i].dest_idx,sorted_array[i].weight);
    }
    int mstWeight=0,j=0;
    for(int i=1;i<n;i++){
        int dest=origin[sorted_array[j].dest_idx].org,source=origin[sorted_array[j].source_idx].org;
        if(dest!=source){
            mstWeight+=sorted_array[j].weight;
            origin[sorted_array[j].dest_idx].org=origin[sorted_array[j].source_idx].org;
        }else
            i--;
        j++;
    }
    printf("MST weight = %d\n",mstWeight);
}
void MergeSort(Sl sorted_array[],int i,int j){
    if(i==j)
        return;
    int mid=i+(j-i)/2;
    MergeSort(sorted_array,i,mid);
    MergeSort(sorted_array,mid+1,j);
    Merging(sorted_array,i,mid,mid+1,j);
}
void Merging(Sl sorted_array[],int i,int i_high,int j,int j_high){
    int p=i,lower_bound=i;
    Sl temp[100];
    while(i<=i_high && j<=j_high){
        if(sorted_array[i].weight<sorted_array[j].weight){
            temp[p]=sorted_array[i];
            p++,i++;
        }
        else{
            temp[p]=sorted_array[j];
            p++,j++;
        }
    }
    while(i<=i_high){
        temp[p]=sorted_array[i];
        i++,p++;
    }
    while(j<=j_high){
        temp[p]=sorted_array[j];
        p++,j++;
    }
    for(i=lower_bound;i<p;i++){
        sorted_array[i]=temp[i];
    }
}
void display(Nl* graph[],int n){
    for(int i=0;i<n;i++){
        printf("%d-",graph[i]->node);
        El* ptr=graph[i]->edge_head;
        while(ptr!=NULL){
            printf("(w=%d)->%d-",ptr->weight,graph[ptr->node_idx]->node);
            ptr=ptr->next;
        }
        printf(">Null\n");
    }
}
void display_origin(Ol origin[],int n){
    for(int i=0;i<n;i++)
        printf("node = %d | origin = %d\n",origin[i].node_val,origin[i].org);
}