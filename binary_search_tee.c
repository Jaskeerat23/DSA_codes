#include<stdio.h>
#include<stdlib.h>
typedef struct binary_search_tree{
    int info;
    struct binary_search_tree* left_child;
    struct binary_search_tree* right_child;
}tree;
int height(tree*);
int max(int,int);
int leaf_nodes(tree*);
int internal_nodes(tree*);
void create_node(tree**,int);
tree* delete_node(tree*,int);
tree* inorder_successor(tree*);
void inorder(tree*);
int main()
{
    printf("changed code\n");
    tree* root=NULL;
    int ch=1,val;
    while(ch){
        printf("Enter 1 to insert node in BST\nEnter 2 to view in-order of current BST\nEnter 3 to view pre-order of current BST\nEnter 4 to view post-order of current BST\nEnter 5 to change root with it's inorder successor\nEnter 6 to delete node in BST\nEnter 7 to find Height of the Tree\nEnter 8 to Know the no.s of Leaf Nodes\nEnter 9 to find the no. of internal nodes\nEnter 0 to stop : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter value you want to insert : ");
                scanf("%d",&val);
                create_node(&root,val); break;
            case 2:inorder(root); break;
            // case 5:val=inorder_successor(root->right_child); printf("Inorder succesor of %d is %d\n",root->info,val); break;
            case 6:printf("Enter target : ");
                scanf("%d",&val);
                root=delete_node(root,val); break;
            case 7:printf("Height of the current BST is : %d\n",height(root)); break;
            case 8:printf("No. of Leaf Nodes are %d\n",leaf_nodes(root)); break;
            case 9:printf("No. of Leaf Nodes are %d\n",internal_nodes(root)); break;
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
    if(val<(*root)->info)
        create_node(&(*root)->left_child,val);
    else if(val>(*root)->info)
        create_node(&(*root)->right_child,val);
    else
        printf("Value Invalid\n");
}
void inorder(tree* ptr){
    if(ptr!=NULL){
        inorder(ptr->left_child);
        printf("%d\t",ptr->info);
        inorder(ptr->right_child);
    }
}
tree* delete_node(tree* root,int target){
    if(root->info==target){
        if(root->left_child==NULL && root->right_child==NULL)
            return NULL;
        else if(root->left_child==NULL || root->right_child==NULL){
            if(root->left_child==NULL)
                return root->right_child;
            return root->left_child;
        }
        tree* address=inorder_successor(root->right_child);
        int val=address->info;
        root=delete_node(root,address->info);
        root->info=val;
        return root;
    }
    else if(root->info>target)
        root->left_child=delete_node(root->left_child,target);
    else
        root->right_child=delete_node(root->right_child,target);

}
tree* inorder_successor(tree* ptr){
    if(ptr->left_child==NULL)
        return ptr;
    tree* ans=inorder_successor(ptr->left_child);
    return ans;
}
int height(tree* root){
    if(root==NULL || (root->left_child==NULL && root->right_child==NULL))
        return 0;
    int lh=0,rh=0;
    lh=height(root->left_child);
    rh=height(root->right_child);
    return 1+(max(lh,rh));
}
int max(int lh,int rh){
    if(lh<rh)
        return rh;
    return lh;
}
int leaf_nodes(tree* root){
    if(root==NULL)
        return 0;
    if(root->left_child==NULL && root->right_child==NULL)
        return 1;
    return (leaf_nodes(root->left_child)+leaf_nodes(root->right_child));
}
int internal_nodes(tree* root){
    if(root==NULL)
        return 0;
    int c=0;
    if(root->left_child!=NULL || root->right_child!=NULL)
        c=1;
    return c+internal_nodes(root->left_child)+internal_nodes(root->right_child);
}