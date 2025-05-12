/*||CODE TO IMPLEMENT STACK USING DMA ONLY FOR **TOP**||*/

#define max 10
#include<stdio.h>
#include<stdlib.h>
void push(int [],int*);
void pop(int [],int*);
void peek(int [],int*);
void display(int [],int*);
int FIFO_SUM(int [],int*);
int main(){
    int stack[max],*top=NULL,ch=1,s;
    top=malloc(sizeof(int));
    *top=-1;
    while(ch!=0){
        printf("Enter 1 to push\nEnter 2 to POP\nEnter 3 to PEEK\nEnter Enter 4 to DISPLAY\nEnter 5 to print in FIFO order and calculate sum\nEnter 0 to STOP:");
        scanf("%d",&ch);
        switch (ch)
        {
            case 0:break;
            case 1:push(stack,top);
                break;
            case 2:pop(stack,top);
                break;
            case 3:peek(stack,top);
                break;
            case 4:display(stack,top);
                break;
            case 5:s=FIFO_SUM(stack,top);
                printf("%d is sum\n",s);
                break;
            default:printf("Invalid Choice\n");
                break;
        }
    }
}
void push(int stack[],int* top){
    if(*top==max-1){
        printf("Stack Full\n");
        return;
    }
    int x;
    (*top)++;
    printf("Enter value: ");
    scanf("%d",&stack[*top]);
    // stack[*top]=x;
    
}
void pop(int stack[],int* top){
    if(*top==-1){
        printf("Stack Empty\n");
        return;
    }
    printf("The Top Value is %d\n",stack[*top]);
    (*top)--;
}
void peek(int stack[],int* top){
    if(*top==-1)
        printf("Stack Empty\n");
    else
        printf("The Top Element is %d\n",stack[*top]);
}
void display(int stack[],int* top){
    if(*top==-1){
        printf("Stack Empty\n");
        return;
    }
    for(int i=*top;i>=0;i--)
        printf("Stack Element is %d\n",stack[i]);
}
int FIFO_SUM(int stack[],int *top){
    int s=0;
    int i=*top; 
    (*top)--;
    if(*top>=0)
        s=FIFO_SUM(stack,(*top-1));
    printf("The Element is %d\n",stack[i]);
    *top=i;
    return s+stack[i]; 
}