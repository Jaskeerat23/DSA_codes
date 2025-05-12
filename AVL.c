#include<stdio.h>
#include<stdlib.h>
typedef struct AVL_tree{
    int info;
    int balance_factor;
    struct AVL_tree* left_child;
    struct AVL_tree* right_child;
}AVL;
void create_node(AVL**,int);
void inorder(AVL*);
int height(AVL*);
int max(int,int);
int balance_fact(AVL*);
int main()
{
    AVL* root=NULL;
    int ch=1,val=0;
    while(ch){
        printf("Enter 1 to create node\nEnter 2 to view inorder of the tree\nEnter 3 to view balance factor of the nodes\nEnter 4 to calculate height of the current tree\nEnter 0 to STOP : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;
            case 1:printf("Enter the value : ");
                scanf("%d",&val);
                create_node(&root,val); break;
            case 2:inorder(root); break;
            case 4:printf("Height of the tree is %d\n",height(root)); break;
        }
    }
}
void create_node(AVL** root,int val){
    if((*root)==NULL){
        *root=malloc(sizeof(AVL));
        (*root)->info=val;
        (*root)->balance_factor=0;
        (*root)->left_child=(*root)->right_child=NULL;
        return;
    }
    if(val<((*root)->info)){
        create_node((&(*root)->left_child),val);
        // (*root)->balance_factor=balance_fact((*root));
    }
    else if(val>((*root)->info)){
        create_node((&(*root)->right_child),val);
        // (*root)->balance_factor=balance_fact((*root));
    }
    else{
        printf("Invalid Value Entered or Key Already Exists\n");
        return;
    }
}
void inorder(AVL* root){
    if(root!=NULL){
        inorder(root->left_child);
        printf("%d\t",root->info);
        inorder(root->right_child);
    }
}
int height(AVL* root){
    if(root==NULL || (root->right_child==NULL && root->left_child==NULL))
        return 0;
    int lh=0,rh=0;
    lh=height(root->left_child);
    rh=height(root->right_child);
    return 1+max(lh,rh);
}
int max(int lh,int rh){
    if(lh>rh)
        return lh;
    return rh;
}