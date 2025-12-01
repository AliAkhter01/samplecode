#include<iostream>
using namespace std;

class Node{
public:
    Node *left;
    Node* right;
    int data;
    int height;
    Node(int val){
        left=right=NULL;
        data=val;
        height=1;
    }
    Node(){
        left=right=NULL;
        height=1;
    }
};

class AVLTREE{
    Node* root;
public:
    AVLTREE(){root=NULL;}

    int get_height(Node *node){
        if(node==NULL) return 0;
        return node->height;
    }

    int get_balance(Node *node){
        if(node==NULL) return 0;
        return get_height(node->left)-get_height(node->right);
    }

    Node* Rotate_right(Node *node){
        Node *x= node->left;
        Node *T2= x->right;
        x->right=node;
        node->left=T2;

        node->height=1+max(get_height(node->left),get_height(node->right));
        x->height=1+max(get_height(x->left),get_height(x->right));
        return x;
    }

    Node* Rotate_left(Node *node){
        Node *x=node->right;
        Node* T2=x->left;
        x->left=node;
        node->right=T2;
        node->height=1+max(get_height(node->left),get_height(node->right));
        x->height=1+max(get_height(x->left),get_height(x->right));
        return x;
    }

    Node* Check_Balance(Node *node){
        int balance=get_balance(node);
        // Left Left
        if(balance>1 && get_balance(node->left)>=0)
            return Rotate_right(node);
        // Left Right
        if(balance>1 && get_balance(node->left)<0){
            node->left=Rotate_left(node->left);
            return Rotate_right(node);
        }
        // Right Right
        if(balance<-1 && get_balance(node->right)<=0)
            return Rotate_left(node);
        // Right Left
        if(balance<-1 && get_balance(node->right)>0){
            node->right=Rotate_right(node->right);
            return Rotate_left(node);
        }
        return node;
    }

    Node* Insert(Node *root,int data){
        if(root==NULL) return new Node(data);

        if(data<root->data) root->left=Insert(root->left,data);
        else if(data>root->data) root->right=Insert(root->right,data);
        else return root;

        root->height=1+max(get_height(root->left),get_height(root->right));
        return Check_Balance(root);
    }

    void Insert(int data){
        root=Insert(root,data);
    }

    Node* find_successor(Node *root){
        if(root==NULL) return root;
        Node* temp=root;
        while(temp!=NULL && temp->left!=NULL) temp=temp->left;
        return temp;
    }

    Node* delete_node(Node* root,int data){
        if(root==NULL) return root;

        if(data<root->data) root->left=delete_node(root->left,data);
        else if(data>root->data) root->right=delete_node(root->right,data);
        else{
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            if(root->left==NULL){
                Node *temp=root->right;
                delete root;
                return temp;
            }
            if(root->right==NULL){
                Node* temp=root->left;
                delete root;
                return temp;
            }
            Node* temp=find_successor(root->right);
            root->data=temp->data;
            root->right=delete_node(root->right,temp->data);
        }

        if(root==NULL) return root;

        root->height=1+max(get_height(root->left),get_height(root->right));
        return Check_Balance(root);
    }

    void delete_node(int data){
        root=delete_node(root,data);
    }
    void inorder(Node* head){
        if(!head) return;
        inorder(head->left);
        cout<<head->data<<" ";
        inorder(head->right);
    }
    void inorder(){
        inorder(root);
        cout<<endl;
    }
    void preorder(Node* head){
        if(!head) return;
        cout<<head->data<<" ";
        preorder(head->left);
        preorder(head->right);
    }
    void preorder(){
        preorder(root);
        cout<<endl;
    }
};
int main(){
    AVLTREE tree;

    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(30);
    tree.Insert(40);
    tree.Insert(50);
    tree.Insert(25);

    cout<<"Inorder traversal after insertions: ";
    tree.inorder();  

    cout<<"Preorder traversal after insertions: ";
    tree.preorder(); 

    
    tree.delete_node(40);

    cout<<"Inorder traversal after deleting 40: ";
    tree.inorder();

    cout<<"Preorder traversal after deleting 40: ";
    tree.preorder();

    return 0;
}
