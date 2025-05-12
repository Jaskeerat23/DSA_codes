#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Binary_Tree{
    int info;
    struct Binary_Tree* left_child;
    struct Binary_Tree* right_child;
}tree;
int* DFS(tree*);
int height(tree*);
int max(int,int);
void create_node(tree**,int);
void inorder(tree*);
void preorder(tree*);
void postorder(tree*);
int main(){
    int ch=1,val;
    int* path=NULL;
    tree* root=NULL;
    while(ch){
        printf("Enter 1 to create node\nEnter 2 to view Inorder\nEnter 3 to view Pre-Order\nEnter 4 to view Post-Order\nEnter 5 to run DFS\nEnter 7 to find Height of the Tree\nEnter 0 to stop : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;
            case 1:printf("Enter value : ");
                scanf("%d",&val);
                create_node(&root,val); break;
            case 2:inorder(root); printf("\n"); break;
            case 3:preorder(root); printf("\n"); break;
            case 4:postorder(root); printf("\n"); break;
            case 5:path=DFS(root); break;
            case 7:printf("Height of the current BST is : %d\n",height(root));
            default:printf("Invalid Choice!!\n"); break;
        }
    }
}
void create_node(tree** root,int val){
    if(*root==NULL){
        *root=malloc(sizeof(tree));
        (*root)->info=val;
        (*root)->left_child=(*root)->right_child=NULL;
        return;
    }
    char ch;
    printf("Enter which child(L/R) of node %d you want to go : ",(*root)->info);
    scanf(" %c",&ch);
    if(ch=='L')
        create_node(&(*root)->left_child,val);
    else if(ch=='R')
        create_node(&(*root)->right_child,val);
    else{
        printf("Invalid choice\n");
        return;
    }
}
void inorder(tree* root){
    if(root!=NULL){
        inorder(root->left_child);
        printf("%d\t",root->info);
        inorder(root->right_child);
    }
}
void preorder(tree* root){
    if(root!=NULL){
        printf("%d\t",root->info);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}
void postorder(tree* root){
    if(root!=NULL){
        postorder(root->left_child);
        postorder(root->right_child);
        printf("%d\t",root->info);
    }
}
int* DFS(tree* root){
    tree* stack[100];
    int i=0,top=0,path[100];
    stack[top]=root;
    printf("value at top of stack is %d\n",stack[top]->info);
    while(top!=-1){
        tree* ptr=stack[top];
        path[i]=stack[top]->info;
        top--,i++;
        if(ptr->right_child!=NULL){
            top++;
            stack[top]=ptr->right_child;
        }
        if(ptr->left_child!=NULL){
            top++;
            stack[top]=ptr->left_child;
        }
    }
    for(int j=0;j<i;j++)
        printf("%d->",path[j]);
    printf("NULL\n");
    return path;
}
int height(tree* root){
    if(root==NULL)
        return 0;
    int lh=0,rh=0;
    lh=height(root->left_child);
    rh=height(root->right_child);
    return (1+max(lh,rh));
}
int max(int lh,int rh){
    if(lh<rh)
        return rh;
    return lh;
}