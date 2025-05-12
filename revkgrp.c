#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
    int val;
    struct ListNode* next;
}ln;
ln* reverseKGroup(ln*,int);
int main()
{
    ln* head=NULL,*r=NULL,*ptr=NULL;
    int k=0,ch=1;
    while(ch){
        ptr=malloc(sizeof(ln));
        printf("Enter Node value: ");
        scanf("%d",&(ptr->val));
        if(head==NULL && r==NULL)
            head=r=ptr;
        else{
            r->next=ptr;
            r=ptr;
        }
        printf("Do you want to continue(0/1): ");
        scanf("%d",&ch);
    }
    r->next=NULL;
    printf("Enter range of Groups: ");
    scanf("%d",&k);
    head=reverseKGroup(head,k);
    printf("Returned: ");
    while(head!=NULL){
        printf("The element is %d\n",head->val);
        head=head->next;
    }
}
int l_copy=0,l=0,k_copy=0,check=0,check_grps=0;
ln *temp=NULL,*rem_nodes=NULL,*new_head=NULL;
ln* reverseKGroup(ln* head,int k){
    new_head=temp=rem_nodes=NULL;
    if(head==NULL && l==0)
        return head;
    k_copy=k;
    // l_copy=l+1;
    if(head!=NULL && check!=1){
        l++;
        l_copy=l;
        check_grps=(l%k);
        printf("recured\n");
        new_head=reverseKGroup(head->next,k);
    }
    else
        return new_head;
    printf("%d\n",head->val);
    check=1;
    l_copy--;
    if(check_grps!=0 && l%k!=0){
        rem_nodes=head;
        check_grps--;
        return head;
    }
    if(k_copy==k){
        k_copy--;
        temp=rem_nodes;
        rem_nodes=head;
        printf("k=%d\tk_copy=%d\n",k,k_copy);
        return head;
    }
    head->next->next=head;
    head->next=NULL;
    k_copy--;
    printf("k=%d\tk_copy=%d\n",k,k_copy);
    printf("l=%d\n",l);
    if(k_copy==0){
        k_copy=k;
        // rem_nodes=head->next;
        head->next=temp;
        printf("rem_nodes->val=%d\n",rem_nodes->val);
        // new_head=head;
    }
    if(l_copy==0)
        temp=rem_nodes=NULL;
    return new_head;
}