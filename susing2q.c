#include<stdio.h>
#include<stdlib.h>
#define max 10
void push(int [],int [],int*,int*,int*,int*);
void pop(int [],int [],int*,int*,int*,int*);
void enqueue(int[],int[],int*,int*,int*,int*,int);
void dequeue(int [],int[],int*,int*,int*,int*,int);
void display(int [],int*,int*);
int main()
{
    int q1[max],q2[max],*r1=NULL,*f1=NULL,*r2=NULL,*f2=NULL,ch=1;
    r1=malloc(sizeof(int));
    f1=malloc(sizeof(int));
    r2=malloc(sizeof(int));
    f2=malloc(sizeof(int));
    *r1=*r2=*f1=*f2=-1;
    printf("%d %d %d %d\n",*r1,*r2,*f1,*f2);
    while(ch){
        printf("Enter 1 to Push Value in the STACK\nEnter 2 to POP a value from the STACK\nEnter 3 to Display the STACK\nEnter 0 to STOP : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;
            case 1:
                push(q1,q2,r1,r2,f1,f2); printf("r1=%d\n",*r1); break;
            case 2:pop(q1,q2,r1,r2,f1,f2); break;
            case 3:display(q1,r1,f1); break;
        }
    }
}
void push(int q1[],int q2[],int* r1,int* r2,int* f1,int* f2){
    if(*r1==max-1){
        printf("Stack Overflow\n");
        return;
    }
    int val;
    printf("Enter a value : ");
    scanf("%d",&val);
    if(*r1==-1){
        (*r1)++;
        q1[*r1]=val;
        return;
    }
    for(int i=0;i<=*r1;i++)
        dequeue(q1,q2,r1,r2,f1,f2,0);
    enqueue(q1,q2,r1,r2,f1,f2,val);
    for(int i=0;i<=*r2;i++)
        dequeue(q1,q2,r1,r2,f1,f2,1);
}
void pop(int q1[],int q2[],int* r1,int* r2,int* f1,int* f2){
    for(int i=0;i<=*r1;i++)
        dequeue(q1,q2,r1,r2,f1,f2,0);
    for(int i=1;i<=*r2;i++){
        (*r1)++;
        q1[*r1]=q2[i];
    }
    *r2=*f2=*f1=-1;
}
void enqueue(int q1[],int q2[],int* r1,int* r2,int* f1,int* f2,int val){
    (*r1)++;
    q1[*r1]=val;
}
void dequeue(int q1[],int q2[],int* r1,int* r2,int* f1,int* f2,int flag){
    if(flag==0){
        printf("While dequeuing q1\n");
        (*r2)++;
        (*f1)++;
        q2[*r2]=q1[*f1];
        printf("q1[%d]=%d | q2[%d]=%d\n",*f1,q1[*f1],*r2,q2[*r2]);
        if(*r2==*r1)
            *f1=*r1=-1;
    }
    else{
        printf("While dequeuing q2\n");
        (*r1)++;
        (*f2)++;
        q1[*r1]=q2[*f2];
        printf("q1[%d]=%d | q2[%d]=%d\n",*r1,q1[*r1],*f2,q2[*f2]);
        if((*r2+1)==*r1)
            *f2=*r2=-1;
    }
}
void display(int q[],int* r,int* f){
    for(int i=0;i<=*r;i++){
        // printf("%d\n",i);
        printf("%d\n",q[i]);
    }
}