/*||CODE TO IMPLEMENT QUE USING DMA FOR QUE VARIABLE AS WELL AS FRONT & REAR||*/

#define max 10
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void enq(int*,int*);
void deq(int*,int*,int*);
void look_rear(int*,int*);
void look_front(int*,int*);
void display(int*,int*,int*);
int main(){
    int *q=NULL,*r=NULL,*f=NULL,ch=1;
    q=malloc(max*sizeof(int));
    r=malloc(sizeof(int));
    f=malloc(sizeof(int));
    *r=-1;
    *f=-1;
    while(ch!=0){
        printf("Enter 1 to Enque\nEnter 2 for Deque\nEnter 3 for look rear\nEnter 4 to look front\nEnter 5 to display\nEnter 0 to stop: ");
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
            case 5:display(q,r,f); break;
            default:printf("Invalid Choice!\n"); break;
        }
    }
    free(r);
    free(f);
    free(q);
}
void enq(int *q,int *r){
    if(*r==max-1){
        printf("Que is Full!!\n");
        return;
    }
    int x;
    printf("Enter Value: ");
    scanf("%d",&x);
    (*r)++;
    *(q+(*r))=x;
}
void deq(int *q,int *r,int *f){
    if(*r==-1){
        printf("Que is Empty!!\n");
        return;
    }
    int *x=(q+(*f));
    printf("The Element to be Dequed is %d\n",*(q+(*f)));
    free(x);
    if(*f==*r)
        *f=-1;
    else
        (*f)++;
}
void look_rear(int *q,int *r){
    if(*r==-1)
        printf("Que is Empty!\n");
    else    
        printf("The rear element is %d\n",*(q+(*r)));
}
void look_front(int *q,int *f){
    if(*f==-1)
        printf("Que is Empty!\n");
    else    
        printf("The rear element is %d\n",*(q+(*f)));
}
void display(int *q,int *r,int *f){
    if(*r==-1){
        printf("Que Empty!!\n");
        return;
    }
    for(int i=*f;i<=*r;i++)
        printf("Que Element is %d\n",*(q+i));
}