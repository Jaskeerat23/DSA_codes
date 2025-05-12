//Code for HYBRID representation of GRAPHS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Edge_list{
    struct Node_list* node_Address;
    struct Edge_list* next_Link;
}El;
typedef struct Node_list{
    int val;
    struct Edge_list* edge;
}Nl;
Nl* create_node(Nl*,int);
Nl* connecting_nodes(Nl*[],int,int);
Nl* connection(Nl*,Nl*);
void display(Nl* [],int);
int main()
{
    Nl* start_node[100];
    int ch=1,val,i=0,source,dest;
    while(ch){
        printf("Enter 1 to create node\nEnter 2 to connect node\nEnter 3 to display\nEnter 0 to stop : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter value : ");
                scanf("%d",&val);
                start_node[i]=NULL;
                start_node[i]=create_node(start_node[i],val); i++; break;
            case 2:printf("Enter position you want to connect : ");
                scanf("%d",&source);
                printf("Enter postion you want to connect to : ");
                scanf("%d",&dest);
                start_node[source]=connection(start_node[source],start_node[dest]); break;
            case 3:display(start_node,i);
        }
    }
}
Nl* create_node(Nl* start_node,int val){
    Nl* temp=malloc(sizeof(Nl));
    temp->val=val;
    temp->edge=NULL;
    return temp;
}
Nl* connection(Nl* source_node,Nl*dest_node){
    El* ptr=source_node->edge,*temp=malloc(sizeof(El));
    temp->node_Address=dest_node;
    temp->next_Link=NULL;
    if(ptr==NULL){
        source_node->edge=temp;
        return source_node;
    }
    while(ptr->next_Link!=NULL)
        ptr=ptr->next_Link;
    ptr->next_Link=temp;
    return source_node;
}
void display(Nl* start_node[],int n){
    if(start_node[0]==NULL){
        printf("Empty graph\n");
        return;
    }
    for(int i=0;i<n;i++){
        Nl* ptr1=start_node[i];
        printf("%d->",ptr1->val);
        El* ptr2=ptr1->edge;
        while(ptr2!=NULL){
            printf("%d->",ptr2->node_Address->val);
            ptr2=ptr2->next_Link;
        }
        printf("NULL\n");
    }
}