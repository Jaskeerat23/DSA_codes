/*CODE  FOR BINARY-SEARCH-TREE*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Tree{
    struct Tree* left_child;
    int val;
    struct Tree* right_child;
}t;
t* create_node(t*);
t* create_node_rec(t*,int);
int total_nodes(t*,int);
int null_nodes(t*,int);
void deletion(t**,int);
void insert(t**,int);
void helper(t**,t*);
void preorder(t*);
void postorder(t*);
void inorder(t*);
void print_root(t*);
int main(){
    t* root=NULL;
    int ch=1,val,n,n_leaf,n_one_child;
    while(ch!=0){
        printf("Enter 1 to Enter Elements\nEnter 2 to Delete particular node\nEnter 3 to Display Tree in PREORDER\nEnter 4 to Display tree in POSTORDER\nEnter 5 to Display tree in INORDER\nEnter 6 to Print value of root\nEnter 7 to count total no. of nodes\nEnter 8 to count Leaf Nodes\nEnter 0 to Stop: ");
        scanf("%d",&ch);
        switch(ch){
            case 0:break;
            case 1:printf("Enter value: ");
                scanf("%d",&val);
                insert(&root,val); break;
            case 2:printf("Enter value you want to delete: ");
                scanf("%d",&val);
                // root=deleteion(root,val); break;
            case 3:preorder(root); break;
            case 4:postorder(root); break;
            case 5:inorder(root); break;
            case 6:print_root(root); break;
            case 7:n=total_nodes(root,0); 
                printf("Total No of Nodes in tree is %d\n",n); break;
            case 8:n=null_nodes(root,0); 
                printf("Total No of Leaf Nodes in tree is %d\n",n); break;
            default:printf("Invalid Choice!!\n");
        }
    }
}
t* create_node(t* root){
    t* temp=malloc(sizeof(t)),*ptr=root;
    printf("Enter Value: ");
    scanf("%d",&(temp->val));
    temp->right_child=temp->left_child=NULL;
    if(root==NULL)
        return temp;
    while(1){
        if(ptr->val>temp->val){
            if(ptr->left_child==NULL){
                ptr->left_child=temp;
                break;
            }
            ptr=ptr->left_child;
        }
        else if(ptr->val<temp->val){
            if(ptr->right_child==NULL){
                ptr->right_child=temp;
                break;
            }
            ptr=ptr->right_child;
        }
    }
    return root;
}
t* create_node_rec(t* root,int val){
    if(root==NULL){
        t* temp=malloc(sizeof(t));
        temp->val=val;
        temp->right_child=temp->left_child=NULL;
        return temp;
    }
    if(root->val<val)
        root->right_child=create_node_rec(root->right_child,val);
    else
        root->left_child=create_node_rec(root->left_child,val);
    return root;
}
void insert(t** root,int val){
    if((*root)==NULL){
        *root=malloc(sizeof(t));
        (*root)->val=val;
        (*root)->left_child=(*root)->right_child=NULL;
        return;
    }
    if((*root)->val<val){
        insert(&((*root)->right_child),val);
    }
    else{
        insert(&((*root)->left_child),val);
    }
}
int total_nodes(t* root,int n){
    if(root!=NULL){
        n++;
        n=total_nodes(root->left_child,n);
        n=total_nodes(root->right_child,n);
    }
    return n;
}
int null_nodes(t* root,int n){
    if(root==NULL)
        return n;
    if(root->left_child==NULL && root->right_child==NULL){
        n++;
        return n;
    }
    n=null_nodes(root->left_child,n);
    n=null_nodes(root->right_child,n);
    return n;
}
void preorder(t* root){
    if(root!=NULL){
        printf("%d\t",root->val);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}
void postorder(t* root){
    if(root!=NULL){
        postorder(root->left_child);
        postorder(root->right_child);
        printf("%d\t",root->val);
    }
}
void inorder(t* root){
    if(root!=NULL){
        inorder(root->left_child);
        printf("%d\t",root->val);
        inorder(root->right_child);
    }
}
void print_root(t* root){
    if(root==NULL){
        printf("Tree is empty\n");
        return;
    }
    printf("The Root Node is %d\n",root->val);
}