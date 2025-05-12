#define max 10
#include<stdio.h>
#include<stdlib.h>
void enq(int [],int*,int*);
void deq(int[],int*,int*);
void display(int[],int*,int*);
int main()
{
    int q[max],*r=malloc(sizeof(int)),*f=malloc(sizeof(int)),ch=1;
    *f=*r=-1;
    while(ch!=0){
        printf("Enter 1 to Enque\nEnter 2 to Deque\nEnter 3 to Display\nEnter 0 to Stop: ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;
            case 1:enq(q,r,f);
                if(*f==-1)
                    *f=0;
                break;
            case 2:deq(q,r,f);
                if(*f==-1)
                    *r=-1;
                break;
            case 3:display(q,r,f);
                break;
        }
    }
}
void enq(int q[],int *r,int*f){
    if(*f==(*r+1)%max){
        printf("Que Overflow!!!\n");
        return;
    }
    *r=(*r+1)%max;
    printf("Enter value: ");
    scanf("%d",&q[*r]);
}
void deq(int q[],int* r,int* f){
    if(*r==-1){
        printf("Que Underflow!\n");
        return;
    }
    printf("The Front Element is %d\n",q[*f]);
    if(*f==*r)
        *f=*r=-1;
    else
        *f=(*f+1)%max;
}
void display(int q[],int *r,int* f){
    if(*r==-1){
        printf("Que Underflow!!\n");
        return;
    }
    int i=*f;
    printf("%d\n%d\n",*f,*r);
    for(i=*f;i<=*r;i=(i+1)%max)
        printf("the que element is %d\n",q[i]);
}