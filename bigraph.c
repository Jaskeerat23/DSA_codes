#include<stdio.h>
#include<stdlib.h>
typedef struct Node_List{
    int data;
    int status;
    struct Node_List* next;
    struct Edge_List* Edge_Head;
}Nl;
typedef struct Edge_List{
    struct Node_List* Node_Address;
    struct Edge_List* next;
}El;
Nl* create_node(Nl*,int);
Nl* connecting_node(Nl*);
void display(Nl*);
void DFS(Nl*);
void BFS(Nl*);
int main()
{
    Nl* Graph_Start=NULL;
    int ch=1,val;
    while(ch){
        printf("Enter 1 to create node in a Graph\nEnter 2 to connect nodes\nEnter 3 display\nEnter 4 to compute DFS\nEnter 5 to compute BFS\nEnter 0 to Stop : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;
            case 1:printf("Enter node value : ");
                scanf("%d",&val);
                Graph_Start=create_node(Graph_Start,val); break;
            case 2:connecting_node(Graph_Start); break;
            case 3:display(Graph_Start); break;
            case 4:DFS(Graph_Start); break;
            case 5:BFS(Graph_Start); break;
        }
    }
}
Nl* create_node(Nl* Graph_Start,int val){
    Nl* temp=malloc(sizeof(Nl)),*ptr=Graph_Start;
    temp->data=val;
    temp->Edge_Head=NULL;
    temp->next=NULL;
    temp->status=0;
    if(Graph_Start==NULL)
        return temp;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=temp;
    return Graph_Start;
}
Nl* connecting_node(Nl* Graph_Start){
    int Node_src,Node_dest;
    printf("Enter the nodes you want to connect : ");
    scanf(" %d %d",&Node_src,&Node_dest);
    Nl* ptr_src=Graph_Start,*ptr_dest=Graph_Start;
    while(ptr_src->data!=Node_src)      //Traversing Till We find Source Node
        ptr_src=ptr_src->next;
    while(ptr_dest->data!=Node_dest)    //Traversing Till We find Destination Node
        ptr_dest=ptr_dest->next;
    El* temp_src=malloc(sizeof(El)),*temp_dest=malloc(sizeof(El));     //Storing the Source and Destination Node addresses
    temp_src->Node_Address=ptr_dest;     //Storing the address of destination into the edge_list that will connect to the node_list of source
    temp_dest->Node_Address=ptr_src;     //Storing the address of source into the edge_list that will connect to the node_list of destination
    temp_src->next=temp_dest->next=NULL; 
    El* ptr1=ptr_src->Edge_Head,*ptr2=ptr_dest->Edge_Head;
    if(ptr1==NULL)  //Handling the case where there exists no connection in Source Node
        ptr_src->Edge_Head=temp_src;
    else{
        while(ptr1->next!=NULL)  
            ptr1=ptr1->next;
        ptr1->next=temp_src;
    }
    if(ptr2==NULL)  //Handling the case where there exists no connection in Destination Node
        ptr_dest->Edge_Head=temp_dest;
    else{
        while(ptr2->next!=NULL)
            ptr2=ptr2->next;
        ptr2->next=temp_dest;
    }
    return Graph_Start;
}
void DFS(Nl* Graph_Start){
    if(Graph_Start==NULL){
        printf("Graph is NULL\n");
        return;
    }
    Nl* stack[100],*node_processed[100];
    Graph_Start->status=1;
    int top=0,idx=0;
    stack[top]=Graph_Start;
    while(top!=-1){
        printf("top is %d\n",top);
        printf("Stack top element is %d\n",stack[top]->data);
        Nl* node=stack[top];
        top-=1;
        if(node->status!=2){
            node_processed[idx]=node;
            idx++;
            node->status=2;
            El* edges=node->Edge_Head;
            while(edges!=NULL){
                if(edges->Node_Address->status!=2){
                    top++;
                    stack[top]=edges->Node_Address;
                    stack[top]->status=1;
                }
                edges=edges->next;
            }
        }
    }
    for(int i=0;i<idx;i++){
        printf("Node processed at %d is %d\n",i,node_processed[i]->data);
    }
}
void BFS(Nl* Graph_Start){
    Nl* stack[100],*node_processed[100],*queue[100];
    Graph_Start->status=1;
    int top=0,idx=0,r=0,f=-1;
    queue[r]=Graph_Start;
    while(f!=r){
        printf("top is %d\n",top);
        printf("Stack top element is %d\n",queue[r]->data);
        f+=1;
        Nl* node=queue[f];
        if(node->status!=2){
            node_processed[idx]=node;
            idx++;
            node->status=2;
            El* edges=node->Edge_Head;
            while(edges!=NULL){
                if(edges->Node_Address->status!=2){
                    r++;
                    queue[r]=edges->Node_Address;
                    queue[r]->status=1;
                }
                edges=edges->next;
            }
        }
    }
    for(int i=0;i<idx;i++){
        printf("Node processed at %d is %d\n",i,node_processed[i]->data);
    }
}
void display(Nl* Graph_Start){
    if(Graph_Start==NULL){
        printf("NO NODE EXIST IN A GRAPH!!\n");
        return;
    }
    for(Nl* ptr=Graph_Start;ptr!=NULL;ptr=ptr->next){
        printf("%d->",ptr->data);
        for(El* edges=ptr->Edge_Head;edges!=NULL;edges=edges->next)
            printf("%d->",edges->Node_Address->data);
        printf("NULL\n");
    }
}