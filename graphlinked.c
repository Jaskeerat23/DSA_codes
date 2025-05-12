//Code for Pure Linked Representation of GRAPHS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Edge_list{
    struct Node_list* Node_Address;
    struct Edge_list* next_Link;
}El;
typedef struct Node_list{
    int Node;
    struct Node_list* next;
    struct Edge_list* next_Edge;
}Nl;
Nl* create_node(Nl*,int);
Nl* connecting_Nodes(Nl*);
void display(Nl*);
int main()
{
    Nl* start_node=NULL;
    int ch=1,val;
    while(ch){
        printf("Enter 1 to insert a new node\nEnter 2 to Connect Nodes\nEnter 3 to display graph\nEnter 0 to stop: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter node value: ");
                scanf("%d",&val);
                start_node=create_node(start_node,val); break;
            case 2:start_node=connecting_Nodes(start_node); break;
            case 3:display(start_node); break;
        }
    }
}

Nl* create_node(Nl* start_node,int val){
    Nl* ptr=start_node,*temp=malloc(sizeof(Nl));
    temp->Node=val;
    temp->next=NULL;
    temp->next_Edge=NULL;
    if(start_node==NULL)
        return temp;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=temp;
    return start_node;
}
Nl* connecting_Nodes(Nl* start_node){
    int node_A,node_B,n;
    printf("Enter the no. of nodes you want to connect : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the node you want to connect : ");
        scanf("%d",&node_A);
        printf("Enter the node you want to connect from : ");
        scanf("%d",&node_B);
        Nl* ptr1=start_node,*ptr2=start_node;
        while(ptr1->Node!=node_A)
            ptr1=ptr1->next;
        while(ptr2->Node!=node_B)
            ptr2=ptr2->next;
        El *ptr3=ptr1->next_Edge,*temp=malloc(sizeof(El));
        temp->next_Link=NULL;
        temp->Node_Address=ptr2;
        if(ptr3==NULL){
            ptr1->next_Edge=temp;
            continue;
        }
        while(ptr3->next_Link!=NULL)
            ptr3=ptr3->next_Link;
        ptr3->next_Link=temp;
    }
    return start_node;
}
void display(Nl* start_node){
    Nl* Nodes=start_node;
    while(Nodes!=NULL){
        printf("%d->",Nodes->Node);
        El* Edges=Nodes->next_Edge;
        while(Edges!=NULL){
            printf("%d->",Edges->Node_Address->Node);
            Edges=Edges->next_Link;
        }
        printf("NULL\n");
        Nodes=Nodes->next;
    }
}   