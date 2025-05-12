#include<stdio.h>
#include<stdlib.h>
typedef struct List_Node{
    int info;
    struct List_Node* next;
}ln;
ln* middle_node(ln*,ln*);
void MergeSort(ln*,ln*);
void Merging(ln*,ln*,ln*,ln*);
int main()
{
    ln* list1=NULL,*r1=NULL,*ptr=NULL;
    int ch=1;
    printf("Enter nodes of First list : \n");
    while(ch){
        ptr=malloc(sizeof(ln));
        printf("Enter the node value : ");
        scanf("%d",&(ptr->info));
        if(r1==NULL && list1==NULL)
            r1=list1=ptr;
        else{
            r1->next=ptr;
            r1=ptr;
        }
        printf("Do you want to continue : ");
        scanf("%d",&ch);
    }
    r1->next=NULL;
    ptr=NULL;
    printf("Provided List is %d\n");
    ptr=list1;
    while (ptr!=NULL){
        printf("Node value is %d\n",ptr->info);
        ptr=ptr->next;
    }
    printf("Calling Merge Sort:\n");
    MergeSort(list1,r1);
    printf("Returned from MergeSort:\n");
    ptr=list1;
    while (ptr!=NULL){
        printf("Node value is %d\n",ptr->info);
        ptr=ptr->next;
    }
    
}
void MergeSort(ln* head,ln* end){
    if(head==end)
        return;
    ln* mid=middle_node(head,end->next);
    // printf("Middle node is %d\n",mid->info);
    MergeSort(head,mid);
    MergeSort(mid->next,end);
    // printf("head=%d | mid=%d | mid->next=%d | end=%d\n",head->info,mid->info,mid->next->info,end->info);
    Merging(head,mid,mid->next,end);
}
void Merging(ln* head,ln* mid,ln* j,ln*end){
    ln* ptr=NULL,*ptr1=head,*ptr2=j;
    ln* r=NULL,*new_head=NULL;
    ln* copy=head;
    while(ptr1!=mid->next && ptr2!=end->next){
        ptr=malloc(sizeof(ln));
        if(ptr1->info < ptr2->info){
            ptr->info=ptr1->info;
            ptr1=ptr1->next;
        }
        else{
            ptr->info=ptr2->info;
            ptr2=ptr2->next;
        }
        if(new_head==NULL && r==NULL)
            new_head=r=ptr;
        else{
            r->next=ptr;
            r=ptr;
        }
    }
    while(ptr1!=mid->next){
        ptr=malloc(sizeof(ln));
        ptr->info=ptr1->info;
        ptr1=ptr1->next;
        r->next=ptr;
        r=ptr;
    }
    while(ptr2!=end->next){
        ptr=malloc(sizeof(ln));
        ptr->info=ptr2->info;
        ptr2=ptr2->next;
        r->next=ptr;
        r=ptr;
    }
    r->next=NULL;
    for(ptr=new_head;ptr!=NULL;ptr=ptr->next){
        // printf("node value %d\n",ptr->info);
        copy->info=ptr->info;
        copy=copy->next;
    }
}
ln* middle_node(ln* head,ln* end){
    ln* fp=head->next,*sp=head;
    while(fp!=end && fp->next!=end){
        sp=sp->next;
        fp=fp->next->next;
    }
    return sp;
}