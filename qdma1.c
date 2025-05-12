/*||CODE TO IMPLEMENT QUE USING DMA ONLY FOR FRONT AND REAR||*/

#define max 10
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void enq(int [],int*);
void deq(int [],int*,int*);
void look_rear(int [],int*);
void look_front(int [],int*);
void display(int [],int*,int*);
int main(){
    int q[max],*r=NULL,*f=NULL,ch=1;
    r=malloc(sizeof(int)); 
    f=malloc(sizeof(int)); 
    *f=*r=-1;
    while(ch!=0){
        printf("Enter 1 to to Enque\nEnter 2 to to Deque\nEnter 3 to to Look rear element\nEnter 4 to to look front element\nEnter 5 to display\nEnter 0 to stop: ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;
            case 1:enq(q,r);
                if(*f==-1)
                    *f=0;
                break;
            case 2:deq(q,r,f);
                if(*f==-1)
                    *r=-1;
                break;
            case 3:look_rear(q,r); break;
            case 4:look_front(q,f); break;
            case 5:display(q,f,r); break;
        }
    }
}
void enq(int q[],int *r){
    if(*r==max-1){
        printf("Que is Full\n");
        return;
    }
    int x;
    printf("Enter the value: ");
    scanf("%d",&x);
    (*r)++;
    q[*r]=x;
}
void deq(int q[],int *r,int* f){
    if(*r==-1){
        printf("Que is Empty\n");
        return;
    }
    printf("The top element is %d\n",q[*f]);
    if(*f==*r)
        *f=-1;
    else 
        (*f)++;
}
void look_rear(int q[],int* r){
    if(*r==-1)
        printf("Que is Empty!\n");
    else
        printf("The rear element is %d\n",q[*r]);
}
void look_front(int q[],int* f){
    if(*f==-1)
        printf("Que is Empty!\n");
    else
        printf("The rear element is %d\n",q[*f]);
}
void display(int q[],int *f,int *r){
    if(*f==-1){
        printf("Que Empty!\n");
        return;
    }
    printf("%d\t%d\n",*f,*r);
    for(int i=*f;i<=*r;i++)
        printf("Que Element is %d\n",q[i]);
}