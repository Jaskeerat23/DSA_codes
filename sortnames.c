#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node_List{
    char *name;
    int roll_no;
    struct Node_List* next;
}Nl;
Nl* create_node(Nl*,Nl**);
Nl* middle_node(Nl*,Nl*);
void display(Nl*);
void MergeSort(Nl*,Nl*);
void Merging(Nl*,Nl*,Nl*,Nl*);
int main()
{
    Nl* head=NULL,*r=NULL;
    int ch=1;
    while(ch){
        printf("Enter 1 to make an entry in the list\nEnter 2 to display the list\nEnter 3 to sort names\nEnter 4 to find middle node\nEnter 0 to stop : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;
            case 1:head=create_node(head,&r); printf("Last node added is %s\n",r->name); break;
            case 2:display(head); break;
            case 3:MergeSort(head,r); break;
            case 4:printf("Middle Node : Student Name = %s | Roll No. = %d\n",(middle_node(head,NULL))->name,(middle_node(head,NULL))->roll_no); break;
        }
    }
}
Nl* create_node(Nl* head,Nl** r){
    Nl* temp=malloc(sizeof(Nl));
    char* s=malloc(100*sizeof(char));
    getchar();
    printf("Enter name of the student : ");
    fgets(s,100,stdin);
    printf("Enter the roll no. of student : ");
    scanf("%d",&(temp->roll_no));
    s[strlen(s)-1]='\0';
    temp->name=malloc(100*sizeof(char));
    temp->name=s;
    temp->next=NULL;
    *r=temp;
    if(head==NULL)
        return temp;
    Nl* ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=temp;
    return head;
}
void display(Nl* head){
    if(head==NULL){
        printf("Linked List Empty!!\n");
        return;
    }
    for(Nl* ptr=head;ptr!=NULL;ptr=ptr->next)
        printf("Student Name : %s | Student Roll no. : %d\n",ptr->name,ptr->roll_no);
}
void MergeSort(Nl* head,Nl* end){
    if(head==end)
        return;
    Nl* mid_node=middle_node(head,end->next);
    printf("Middle node is %s\n",mid_node->name);
    MergeSort(head,mid_node);
    MergeSort(mid_node->next,end);
    printf("head=%d mid_node->info=%d mid_node->next->info=%d end->info=%d\n",head->roll_no,mid_node->roll_no,mid_node->next->roll_no,end->roll_no);
    Merging(head,mid_node,mid_node->next,end);
    printf("Returned\n");
}
void Merging(Nl* left,Nl* left_end,Nl* right,Nl* right_end){
    Nl* lower_bound=left,*ptr1=left,*ptr2=right,*r=NULL,*new_head=NULL,*ptr=NULL;
    printf("Enterig the function\n");
    printf("left=%d left_end=%d right=%d right_end=%d\n",left->roll_no,left_end->roll_no,right->roll_no,right_end->roll_no);
    while(ptr1!=left_end->next && ptr2!=right_end->next){
        printf("1st while\n");
        ptr=malloc(sizeof(Nl));
        ptr->name=malloc(100*sizeof(char));
        if(ptr1->name[0]<ptr2->name[0]){
            ptr->roll_no=ptr1->roll_no;
            ptr->name=ptr1->name;
            printf("ptr1->name = %s | ptr1->roll no. = %d\n",ptr1->name,ptr1->roll_no);
            ptr1=ptr1->next;
        }
        else{
            ptr->roll_no=ptr2->roll_no;
            ptr->name=ptr2->name;
            printf("ptr2->name = %s | ptr2->roll no. = %d\n",ptr2->name,ptr2->roll_no);
            ptr2=ptr2->next;
        }
        printf("Running\n");
        if(new_head==NULL && r==NULL)
            new_head=r=ptr;
        else{
            r->next=ptr;
            r=ptr;
        }
    }
    // ptr=r->next=NULL;
    while(ptr1!=left_end->next){
        printf("Second while\n");
        ptr=malloc(sizeof(Nl));
        ptr->roll_no=ptr1->roll_no;
        ptr->name=ptr1->name;
        printf("ptr1->name = %s | ptr1->roll no. = %d\n",ptr1->name,ptr1->roll_no);
        ptr1=ptr1->next;
        r->next=ptr;
        r=ptr;
    }
    while(ptr2!=right_end->next){
        printf("third while\n");
        ptr=malloc(sizeof(Nl));
        ptr->roll_no=ptr2->roll_no;
        ptr->name=ptr2->name;
        printf("ptr2->name = %s | ptr2->roll no. = %d\n",ptr2->name,ptr2->roll_no);
        ptr2=ptr2->next;
        r->next=ptr;
        r=ptr;
    }
    r->next=NULL;
    for(ptr=new_head;ptr!=NULL;ptr=ptr->next){
        lower_bound->roll_no=ptr->roll_no;
        lower_bound->name=ptr->name;
        printf("ptr->name = %s | ptr->roll no. = %d\n",ptr->name,ptr->roll_no);
        lower_bound=lower_bound->next;
    }
    printf("Ending\n");
}
Nl* middle_node(Nl* head,Nl* end){
    Nl* fp=head->next,*sp=head;
    while(fp!=end && fp->next!=end){
        sp=sp->next;
        fp=fp->next->next;
    }
    return sp;
}