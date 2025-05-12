#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node_list{
    int node;
    struct Edge_list* Edge_list_head;
}Nl;
typedef struct Edge_list{
    int weight;
    struct Node_list* Node_Address;
    struct Edge_list* Next_Link;
}El;
typedef struct Sort_list{
    int weight;
    struct Node_list* source;
    struct Node_list* dest;
    struct Sort_list* next;
}Sl;
Nl* create_node(int);
Nl* connecting_nodes(Nl*,Nl*,int);
void kruskal_Algorithm(Nl*[],int);
Sl* Sort_list(Sl*,Nl*,Nl*,int);
void display(Nl*[],int);
int main()
{
    Nl* graph[10],*graph2[10];
    int ch=1,val,source,dest,i=0,weight;
    while(ch){
        printf("Enter 1 to create node in a graph\nEnter 2 to connect nodes\nEnter 3 to display Graph\nEnter 4 to apply KRUSKAL ALGORITHM on existing graph\nEnter 0 to stop : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;
            case 1:printf("Enter the new node value : ");
                scanf("%d",&val);
                graph[i]=NULL;
                graph[i]=create_node(val); i++; break;
            case 2:printf("Enter the position of node you want to connect from : ");
                scanf("%d",&source);
                printf("Enter the posiiton of node you want to connect to : ");
                scanf("%d",&dest);
                printf("Enter the weight of this edge : ");
                scanf("%d",&weight);
                graph[source]=connecting_nodes(graph[source],graph[dest],weight); break;
            case 3:display(graph,i); break;
            case 4:kruskal_Algorithm(graph,i); break;
        }
    }
}
Nl* create_node(int val){
        Nl* temp=malloc(sizeof(Nl));
        temp->node=val;
        temp->Edge_list_head=NULL;
        return temp;
}
Nl* connecting_nodes(Nl* source,Nl* dest,int weight){
    El* edges=source->Edge_list_head,*temp=malloc(sizeof(El));
    temp->weight=weight;
    temp->Next_Link=NULL;
    temp->Node_Address=dest;
    if(edges==NULL){
        source->Edge_list_head=temp;
        return source;
    }
    while(edges->Next_Link!=NULL)
        edges=edges->Next_Link;
    edges->Next_Link=temp;
    return source;
}
void display(Nl* graph[],int n){
    for(int i=0;i<n;i++){
        El* edges=graph[i]->Edge_list_head;
        printf("%d",graph[i]->node);
        while(edges!=NULL){
            printf("-(w=%d)->%d",edges->weight,edges->Node_Address->node);
            edges=edges->Next_Link;
        }
        printf("->NULL\n");
    }
}
void kruskal_Algorithm(Nl* graph[],int n){
    printf("n is %d\n",n);
    Sl* sort_list_head=NULL,*ptr2=NULL;
    for(int i=0;i<n;i++){
        El* ptr=graph[i]->Edge_list_head;
        graph[i]->Edge_list_head=NULL;
        while(ptr!=NULL){
            sort_list_head=Sort_list(sort_list_head,graph[i],ptr->Node_Address,ptr->weight);
            ptr->Node_Address=NULL;
            El* temp=ptr->Next_Link;
            ptr->Next_Link=NULL;
            ptr=temp;
        }
    }
    printf("Sorted list:\n");
    ptr2=sort_list_head;
    while(ptr2!=NULL){
        printf("w=%d source=%d destination=%d\n",ptr2->weight,ptr2->source->node,ptr2->dest->node);
        ptr2=ptr2->next;
    }

}
Sl* Sort_list(Sl* head,Nl* source,Nl* dest,int weight){
    printf("Sorting List:\n");
    Sl* temp=malloc(sizeof(Sl)),*ptr=head;
    temp->source=source;
    temp->dest=dest;
    temp->weight=weight;
    temp->next=NULL;
    if(head==NULL)
        return temp;
    else if(temp->weight<head->weight){
        temp->next=head;
        return temp;
    }
    while(ptr->next!=NULL){
        if(temp->weight<ptr->next->weight){
            temp->next=ptr->next;
            ptr->next=temp;
            break;
        }
        ptr=ptr->next;
    }
    if(ptr->next==NULL && temp->weight>ptr->weight){
        temp->next=ptr->next;
        ptr->next=temp;
    }
    return head;
}