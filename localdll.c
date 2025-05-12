#include<stdio.h>
#include<stdlib.h>
typedef struct Node_list{
    int info;
    struct Node_list* next;
    struct Node_list* prev;
}Nl;
Nl* create_node(Nl*);
Nl* insert_at_n(Nl*,int);
Nl* ins_n_last(Nl*,int);
Nl* reverse(Nl*);
Nl* del_even(Nl*);
void display(Nl*);
int main(){
    Nl* head=NULL;
    int ch=1,n=0;
    while(ch){
        printf("Enter 1 to crate node in the List\nEnter 2 to Display List\nEnter 3 to insert at nth from begining\nEnter 4 to insert from last\nEnter 7 to reverse Linked List without using reursion\nEnter 9 to delete nodes with even info\nEnter 0 to stop : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;
            case 1:head=create_node(head); break;
            case 2:display(head); break;
            case 3:printf("Enter nth from begining position : ");
                scanf("%d",&n);
                head=insert_at_n(head,n); break;
            case 4:printf("Enter nth from last position : ");
                scanf("%d",&n);
                head=ins_n_last(head,n); break;
            case 7:head=reverse(head); break;
            case 9:head=del_even(head); break;
            default:printf("InValid Choice!!\n"); break;
        }
    }
}
Nl* create_node(Nl* head){
    Nl* temp=malloc(sizeof(Nl));
    printf("Enter value : ");
    scanf("%d",&(temp->info));
    temp->next=temp->prev=NULL;
    if(head==NULL)
        return temp;
    Nl* ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=temp;
    temp->prev=ptr;
    return head;
}
void display(Nl* head){
    if(head==NULL){
        printf("Linked List is NULL\n");
        return;
    }
    for(Nl* ptr=head;ptr!=NULL;ptr=ptr->next)
        printf("The value at this node is %d\n",ptr->info);
}
Nl* insert_at_n(Nl* head,int n){
    Nl* temp=malloc(sizeof(Nl));
    printf("Enter value : ");
    scanf("%d",&(temp->info));
    temp->next=temp->prev=NULL;
    if(head==NULL)
        return NULL;
    else if(n==1){
        temp->next=head;
        head->prev=temp;
        return temp;
    }
    Nl* ptr=head;
    for(int i=1;i<n-1;i++)
        ptr=ptr->next;
    temp->next=ptr->next;
    ptr->next=(ptr->next==NULL)?temp:(ptr->next->prev=temp);
    temp->prev=ptr;
    return head;
}
Nl* ins_n_last(Nl* head,int n){
    Nl* fp=head,*sp=head,*temp=malloc(sizeof(Nl));
    printf("Enter value : ");
    scanf("%d",&(temp->info));
    temp->next=temp->prev=NULL;
    for(int i=n;i>0;i--){
        fp=fp->next;
        if(fp==NULL){
            temp->next=head;
            head->prev=temp;
            return temp;
        }
    }
    while(fp!=NULL){
        fp=fp->next;
        sp=sp->next;
    }
    temp->prev=sp;
    temp->next=sp->next;
    sp->next=(sp->next==NULL)?temp:(sp->next->prev=temp);
    return head;
}
Nl* reverse(Nl* head){
    Nl* new_head=NULL,*temp1=NULL;
    for(Nl* ptr=head;ptr!=NULL;ptr=temp1){
        temp1=ptr->next;
        Nl* temp2=ptr->next;
        ptr->next=ptr->prev;
        ptr->prev=temp2;
        new_head=ptr;
    }
    return new_head;
}
Nl* del_even(Nl* head){
    if(head==NULL){
        printf("Linked list is empty!!\n");
        return NULL;
    }
    Nl* ptr=head;                                
    while(ptr->next!=NULL){                     
        if(ptr->next->info%2==0){
            Nl* temp=ptr->next;
            ptr->next=ptr->next->next;
            free(temp);
        }
        else
            ptr=ptr->next;
    }
    if(head->info%2==0)
        return head->next;
    return head;
}