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
ln* del_alt(ln*);
ln* reverse(ln*);
ln* reverse_non_rec(ln*);
void check_palindrone(ln*);
ln* middle_node(ln*);
void display(ln*);
void print_rev(ln*);
void length(ln*);
int check_empty(ln*);
int main(){
    ln* head=NULL;
    int ch=1,pos;
    while(ch!=0){
        printf("Enter 1 to Insert\nEnter 2 to Display\nEnter 3 to insert at begining\nEnter 4 to delete from begining\nEnter 5 to insert at nth\nEnter 6 to delete at nth\nEnter 7 to delete at alternate positions\nEnter 8 to PRINT Linked List in reverse Order\nEnter 9 to reverse Linked List\nEnter 10 to find middle node\nEnter 11 to Check if Linked List is Palindrone\nEnter 12 to check the length of Linked List\nEnter 13 to reverse Linked List using Iterative Method\nEnter 0 to Stop: ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;
            case 1:head=create_node(head); break;
            case 2:display(head); break;
            case 3:head=insert_at_beg(head); break;
            case 4:head=del_at_beg(head); break;
            case 5:printf("Enter position: ");
                    scanf("%d",&pos);
                    head=insert_at_nth(head,pos);
                    break;
            case 6:printf("Enter position: ");
                    scanf("%d",&pos);
                    head=del_at_nth(head,pos);
                    break;
            case 7:head=del_alt(head); break;
            case 8:print_rev(head); break;
            case 9:head=reverse(head); break;
            case 10:middle_node(head); break;
            case 11:check_palindrone(head); break;
            case 12:length(head); break;
            case 13:head=reverse_non_rec(head); break;
            default:printf("Invalid Choice\n"); break;
        }
    }
}
ln* create_node(ln* head){
    ln *ptr=head,*temp=NULL;
    temp=malloc(sizeof(ln));
    printf("Enter a value: ");
    scanf("%d",&(temp->val));
    temp->next=NULL;
    if(head==NULL)
        return temp;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=temp;
    return head;
}
void display(ln* ptr){
    if(check_empty(ptr))
        return;
    while(ptr!=NULL){
        printf("The value at this node (%d->info) is %d\n",ptr,ptr->val);
        printf("The value at this node (%d->next) is %d\n",ptr,ptr->next);
        ptr=ptr->next;
    }
    printf("%d\n",ptr);
    printf("%d\n",&ptr);
}
ln* insert_at_beg(ln* head){
    ln* temp=malloc(sizeof(ln));
    printf("Enter value: ");
    scanf("%d",&(temp->val));
    temp->next=head;
    return temp;
}
ln* del_at_beg(ln* head){
    if(check_empty(head))
        return head;
    ln* temp=head;
    printf("Node with val %d DELETED successfully\n",head->val);
    head=head->next;
    free(temp);
    return head;
}
ln* insert_at_nth(ln* head,int pos){
    pos--;
    ln *ptr=head,*temp=malloc(sizeof(ln));
    printf("Enter value: ");
    scanf("%d",&(temp->val));
    if(pos==0){
        temp->next=head;
        return temp;
    }
    while(pos>1){
        ptr=ptr->next;
        pos--;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    return head;
}
ln* del_at_nth(ln* head,int pos){
    pos--;
    if(pos==0)
        return del_at_beg(head);
    ln* ptr=head;
    while(pos>1){
        ptr=ptr->next;
        pos--;
    }
    ptr->next=ptr->next->next;
    return head;
}
ln* del_alt(ln* ptr){   
    if(ptr!=NULL && ptr->next!=NULL){
        ln* temp=ptr->next;
        ptr->next=ptr->next->next;
        free(temp);
        del_alt(ptr->next);
    }
    return ptr;
}
void print_rev(ln* ptr){
    (ptr->next!=NULL) ? print_rev(ptr->next) : 0;
    printf("The Node Value is %d\n",ptr->val);
}
ln* reverse(ln* ptr){
    if(ptr->next==NULL || ptr==NULL)
        return ptr;
    ln* new_head=NULL;
    if(ptr->next->next!=NULL)
        new_head=reverse(ptr->next);
    else    
        new_head=ptr->next;
    ptr->next->next=ptr;
    ptr->next=NULL;
    return new_head;
}
ln* middle_node(ln* head){
    if(check_empty(head))
        return;
    ln *fp=head->next,*sp=head;
    while(fp!=NULL && fp->next!=NULL){
        printf("Im inside");
        fp=fp->next->next;
        sp=sp->next;
    }
    printf("The middle node is %d\n",sp->val);
}
void check_palindrone(ln* head){
    if(check_empty(head))
        return;
    ln *new_head=NULL,*fp=head->next,*sp=head,*temp=NULL;
    while(fp!=NULL && fp->next!=NULL){
        fp=fp->next->next;
        sp=sp->next;
    }
    temp=sp->next;
    sp->next=NULL;
    sp=new_head=reverse(temp);
    fp=head;
    while(fp!=NULL && sp!=NULL){
        if(fp->val!=sp->val){
            printf("NOT PALINDRONE\n");
            return;
        }
        fp=fp->next;
        sp=sp->next;
    }
    printf("Linked List Palindrone\n");
}
void length(ln* head){
    int i=1;
    if(check_empty(head))
        return;
    for(i=1;head->next!=NULL;i++)
        head=head->next;
    printf("The length is %d\n",i);
}
ln* reverse_non_rec(ln* head){
    if(head==NULL || head->next==NULL)
        return head;
    ln* fp=head,*sp=head->next,*tp=sp->next;
    while(sp!=NULL){
        sp->next=fp;
        fp=sp;
        sp=tp;
        if(tp!=NULL)
            tp=tp->next;
    }
    head->next=NULL;
    return fp;
}
/*HELPS IN REDUCING LINES OF CODE*/
int check_empty(ln* head){
    if(head==NULL){
        printf("Linked List Empty\n");
        return 1;
    }
    return 0;
}