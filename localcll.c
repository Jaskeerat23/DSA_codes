#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
    int val;
    struct ListNode* next;
}ln;
ln* create_node(ln*);
ln* insert_at_beg(ln*);
ln* del_at_beg(ln*);
ln* insert_at_nth(ln*,int);
ln* del_at_nth(ln*,int);
void display(ln*);
int check_empty(ln*);
int main(){
    ln* head=NULL;
    int ch=1,pos=0;
    while(ch!=0){
        printf("Enter 1 to Insert\nEnter 2 to Display\nEnter 3 to Insert at begining\nEnter 4 to delete at begining\nEnter 5 to insert at nth\nEnter 6 to delete at nth\nEnter 0 to Stop: ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;;
            case 1:head=create_node(head); break;
            case 2:display(head); break;
            case 3:head=insert_at_beg(head); break;
            case 4:head=del_at_beg(head); break;
            case 5:printf("Enter positions: ");
                scanf("%d",&pos);
                head=insert_at_nth(head,pos); break;
            case 6:printf("Enter positions: ");
                scanf("%d",&pos);
                head=del_at_nth(head,pos); break;
            default:printf("Invalid Choice!!\n"); break;
        }
    }
}
ln* create_node(ln* head){
    ln* temp=malloc(sizeof(ln));
    printf("Enter value: ");
    scanf("%d",&(temp->val));
    temp->next=head;
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    ln* ptr=head;
    while(ptr->next!=head)
        ptr=ptr->next;
    ptr->next=temp;
    return head;
}
void display(ln* head){
    if(check_empty(head))
        return;
    ln* ptr=head->next;
    printf("The value at this node is %d\n",head->val);
    while(ptr!=head){
        printf("The value at this node is %d\n",ptr->val);
        ptr=ptr->next;
    }
}
ln* insert_at_beg(ln* head){
    ln* temp=malloc(sizeof(ln));
    printf("Enter value: ");
    scanf("%d",&(temp->val));
    temp->next=head;
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    ln* ptr=head->next;
    while(ptr->next!=head)
        ptr=ptr->next;
    ptr->next=temp;
    return temp;
}
ln* del_at_beg(ln* head){
    if(check_empty(head) || head->next==head)
        return NULL;
    ln* temp=head,*ptr=head->next;
    while(ptr->next!=head)
        ptr=ptr->next;
    ptr->next=head->next;
    head=head->next;
    free(temp);
    return head;
}
ln* insert_at_nth(ln* head,int pos){
    pos--;
    if(pos==0)
        return insert_at_beg(head);
    ln* ptr=head,*temp=malloc(sizeof(ln));
    printf("Enter Value: ");
    scanf("%d",&(temp->val));
    temp->next=NULL;
    while(pos>1){
        ptr=ptr->next;
        pos-=1;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    return head;
}
ln* del_at_nth(ln* head,int pos){
    if(check_empty(head))
        return head;
    pos--;  
    if(pos==0)
        return del_at_beg(head);
    ln* ptr=head,*temp=NULL;
    while(pos>1){
        ptr=ptr->next;
        pos-=1;
    }
    temp=ptr->next;
    ptr->next=ptr->next->next;
    free(temp);
    return head;
}
//Helps for checking if List is Empty or not
int check_empty(ln* head){
    if(head==NULL){
        printf("Linked list rempty!!\n");
        return 1;
    }
    return 0;
}