#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ListNode{
    int coeff;
    int pow;
    struct ListNode* next;
}ln;
void display(ln*,ln*);
ln* add(ln*,ln*);
int main()
{
    ln *head1=NULL,*head2=NULL,*r1=NULL,*r2=NULL,*ptr=NULL,*res=NULL;
    int ch=1;
    while(ch!=0){
        ptr=malloc(sizeof(ln));
        printf("Enter coefficient: ");
        scanf("%d",&(ptr->coeff));
        printf("Enter power: ");
        scanf("%d",&(ptr->pow));
        if(r1==NULL && head1==NULL)
            head1=r1=ptr;
        else{
            r1->next=ptr;
            r1=ptr;
        }
        printf("Do you want to continue(0/1): ");
        scanf("%d",&ch);
    }
    r1->next=NULL;
    ch=1;
    while(ch!=0){
        ptr=malloc(sizeof(ln));
        printf("Enter coefficient: ");
        scanf("%d",&(ptr->coeff));
        printf("Enter power: ");
        scanf("%d",&(ptr->pow));
        if(r2==NULL && head2==NULL)
            head2=r2=ptr;
        else{
            r2->next=ptr;
            r2=ptr;
        }
        printf("Do you want to continue(0/1): ");
        scanf("%d",&ch);
    }
    r2->next=NULL;
    display(head1,head2);
    res=add(head1,head2);
    printf("The new added list is:\n");
    ptr=res;
    while(ptr->next!=NULL){
        printf("%dx^%d+",ptr->coeff,ptr->pow);
        ptr=ptr->next;
    }
    printf("%dx^%d\n",ptr->coeff,ptr->pow);
}
void display(ln* head1,ln* head2){
    ln *ptr=head1;
    printf("Eq1:-");
    while(ptr->next!=NULL){
        printf("%dx^%d+",ptr->coeff,ptr->pow);
        ptr=ptr->next;
    }
    printf("%dx^%d\n",ptr->coeff,ptr->pow);
    ptr=head2;
    printf("Eq2:-");
    while(ptr->next!=NULL){
        printf("%dx^%d+",ptr->coeff,ptr->pow);
        ptr=ptr->next;
    }
    printf("%dx^%d\n",ptr->coeff,ptr->pow);
}
ln* add(ln* head1,ln* head2){
    ln *new_head=NULL,*ptr1=head1,*ptr2=head2,*ptr3=NULL,*r=NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        ptr3=malloc(sizeof(ln));
        if(ptr1->pow==ptr2->pow){
            ptr3->coeff=ptr1->coeff+ptr2->coeff;
            ptr3->pow=ptr1->pow;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->pow>ptr2->pow){
            ptr3->coeff=ptr1->coeff;
            ptr3->pow=ptr1->pow;
            ptr1=ptr1->next;
        }
        else{
            ptr3->coeff=ptr2->coeff;
            ptr3->pow=ptr2->pow;
            ptr2=ptr2->next;
        }
        if(new_head==NULL && r==NULL)
            new_head=r=ptr3;
        else{
            r->next=ptr3;
            r=ptr3;
        }
    }
    if(ptr1==NULL)
        r->next=ptr2;
    else if(ptr2==NULL)
        r->next=ptr1;
    else
        r->next=NULL;
    return new_head;
}