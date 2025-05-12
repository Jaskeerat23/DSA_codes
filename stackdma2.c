/*|| CODE TO IMPLEMENT STACK USING DMA FOR BOTH STACK POINTER AS WELL AS TOP*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push(int*, int*);
void pop(int*, int*);
void peek(int*, int*);
void display(int*, int*);
int main(){
    int *p=NULL,*top=NULL,ch=1;
    top=malloc(sizeof(int));
    p=malloc(10*sizeof(int));
    *top=-1;
    while(ch!=0){
        printf("Enter 1 to push\nEnter 2 to POP\nEnter 3 to PEEK\nEnter Enter 4 to DISPLAY\nEnter 0 to STOP:");
        scanf("%d",&ch);
        switch (ch)
        {
            case 0:break;
            case 1:push(p,top);
                break;
            case 2:pop(p,top);
                break;
            case 3:peek(p,top);
                break;
            case 4:display(p,top);
                break;
            default:printf("Invalid Choice\n");
                break;
        }
    }
}
void push(int *p,int *top){
    if(*top==9){
        printf("Stack is full!\n");
        return;
    }
    int x;
    (*top)++;
    printf("Enter value: ");
    scanf("%d",&p[*top]);
    // (*top)++;
    // *(p+*(top))=x;
}
void pop(int *p,int *top){
    if(*top==-1){
        printf("Stack is Empty1!!\n");
        return;
    }
    printf("The Top Element was %d\n",*(p+*(top)));
    int *x=p+*(top);;
    (*top)--;
    free(x);
}
void peek(int *p,int *top){
    if(*top==-1)
        printf("Stack Empty!!\n");
    else
        printf("The top element is %d\n",*(p+*(top)));
}
void display(int *p, int *top){
    if(*top==-1){
        printf("Stack is empty!!\n");
        return;
    }
    for(int i=*top;i>=0;i--)
        printf("Stack element is %d\n",*(p+i));
}