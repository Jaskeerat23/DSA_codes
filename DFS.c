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
    int status;
    struct Edge_list* edge;
}Nl;
typedef struct Stack{
    struct Node_list* nodes;
}Stack;
typedef struct node_process{
    struct Node_list* node_information;
}np;

Nl* create_node(Nl*,int);
Nl* connecting_nodes(Nl*[],int,int);
Nl* connection(Nl*,Nl*);
void display_status(Nl*[],int);
void DFS(Nl*[],Stack[],int);
void display(Nl* [],int);
int main()
{
    Nl* start_node[100];
    Stack stack[100];
    int ch=1,val,i=0,source,dest;
    while(ch){
        printf("Enter 1 to create node\nEnter 2 to connect node\nEnter 3 to display\nEnter 4 to View Status of Each Node\nEnter 5 to Run DFS algorithm\nEnter 0 to stop : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter value : ");
                scanf("%d",&val);
                start_node[i]=NULL;
                start_node[i]=create_node(start_node[i],val); i++; break;
            case 2:printf("Enter node you want to connect : ");
                scanf("%d",&source);
                printf("Enter node you want to connect to : ");
                scanf("%d",&dest);
                start_node[source]=connection(start_node[source],start_node[dest]); break;
            case 3:display(start_node,i); break;
            case 4:display_status(start_node,i); break;
            case 5:DFS(start_node,stack,i); break;
        }
    }
}
Nl* create_node(Nl* start_node,int val){
    Nl* temp=malloc(sizeof(Nl));
    temp->val=val;
    temp->status=0;
    temp->edge=NULL;
    return temp;
}
Nl* connection(Nl* source_node,Nl*dest_node){
    El* ptr1=source_node->edge,*ptr2=dest_node->edge,*temp1=malloc(sizeof(El)),*temp2=malloc(sizeof(El));
    temp1->node_Address=dest_node;
    temp2->node_Address=source_node;
    temp1->next_Link=temp2->next_Link=NULL;
    if(ptr1==NULL && ptr2==NULL){
        source_node->edge=temp1;
        dest_node->edge=temp2;
        return source_node;
    }
    else if(ptr1==NULL){
        source_node->edge=temp1;
        while(ptr2->next_Link!=NULL)
            ptr2=ptr2->next_Link;
        ptr2->next_Link=temp2;
        return source_node;
    }
    else if(ptr2==NULL){
        dest_node->edge=temp2;
        while(ptr1->next_Link!=NULL)
            ptr1=ptr1->next_Link;
        ptr1->next_Link=temp1;
        return source_node;
    }
    while(ptr1->next_Link!=NULL)
        ptr1=ptr1->next_Link;
    while(ptr2->next_Link!=NULL)
        ptr2=ptr2->next_Link;
    ptr1->next_Link=temp1;
    ptr2->next_Link=temp2;
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
void DFS(Nl*graph[],Stack stack[],int n){
    graph[0]->status=1;
    stack[0].nodes=graph[0];
    int Top=0,idx=0;
    np node_processed[100]; 
    while(Top!=-1){
        Nl* node_info=stack[Top].nodes;
        printf("Stack top is %d\n",stack[Top].nodes->val);
        printf("Top is %d\n",Top);
        Top--;
        if(node_info->status!=2){
            node_info->status=2;
            node_processed[idx].node_information=node_info;
            printf("Nodeproceesed is %d\n",node_processed[idx].node_information->val);
            idx++;  
            El* edges=node_info->edge;
            while(edges!=NULL){
                printf("Status of edge %d is %d\n",edges->node_Address->val,edges->node_Address->status);
                if(edges->node_Address->status!=2){
                    Top++;
                    edges->node_Address->status=1;
                    stack[Top].nodes=edges->node_Address;
                }
                edges=edges->next_Link;
            }
        }
    }
    printf("Node processed array : \n");
    for(int i=0;i<idx;i++){
        printf("%d->",node_processed[i].node_information->val);
    }
    printf("\n");
}
void display_status(Nl* graph[],int n){
    for(int i=0;i<n;i++){
        printf("The status of node %d is %d\n",graph[i]->val,graph[i]->status);
    }
}