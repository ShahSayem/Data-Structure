#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *left, *right;
} Node;

Node *root;

Node* creatNode();
void insertNode(Node *root, Node *temp);
void display_inOrder(Node *vertex);
void display_preOrder(Node *vertex);
void display_postOrder(Node *vertex);
Node* delete_node(Node *root, int data);
Node* leftRightMost(Node *lroot);

int main()
{
    int n;
    cout<<"Mention number of data: ";
    cin>>n;

    Node *child, *temp;
    root = child = temp = NULL;

    int x = n;
    cout<<"Enter node data: ";
    while (x--){
        temp = creatNode();
        if (root == NULL)
            root = temp;
        else
            insertNode(root, temp);
    }

    cout<<"Pre order: ";
    display_preOrder(root);
    cout<<"\nIn order: ";
    display_inOrder(root);
    cout<<"\nPost order: ";
    display_postOrder(root);

    int dl;
    cout<<"Enter a data to delete: ";
    cin>>dl;
    delete_node(root, dl);
    
    cout<<"Pre order: ";
    display_preOrder(root);
    cout<<"\nIn order: ";
    display_inOrder(root);
    cout<<"\nPost order: ";
    display_postOrder(root);

    return 0;
}

Node *creatNode()
{
    Node *temp;
    temp = (Node *) malloc(sizeof(Node));
    cin>>temp->data;
    temp->right = temp->left = NULL;

    return temp;
}

void insertNode(Node *root, Node *temp)
{
    if (root->data < temp->data){
        if (root->right == NULL)
            root->right = temp;
        else
            insertNode(root->right, temp);
    }  

    else if (root->data > temp->data){
        if (root->left == NULL)
            root->left = temp;
        else
            insertNode(root->left, temp);
    }
}

void display_preOrder(Node *vertex)
{
    if (vertex == NULL)
        return;

    if (vertex->right == NULL && vertex->left == NULL){
        cout<<vertex->data;
        return;
    }

    cout<<" "<<vertex->data<<" ";
    display_preOrder(vertex->left);
    display_preOrder(vertex->right);   
}

void display_inOrder(Node *vertex)
{
    if (vertex == NULL)
        return;

    if (vertex->right == NULL && vertex->left == NULL){
        cout<<vertex->data;
        return;
    }

    display_inOrder(vertex->left);
    cout<<" "<<vertex->data<<" ";
    display_inOrder(vertex->right);   
}

void display_postOrder(Node *vertex)
{
    if (vertex == NULL)
        return;

    if (vertex->right == NULL && vertex->left == NULL){
        cout<<vertex->data;
        return;
    }

    display_preOrder(vertex->left);
    display_preOrder(vertex->right); 
    cout<<" "<<vertex->data<<" ";  
}

Node* delete_node(Node *root, int data)
{
    Node* l_r_most;
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if (data < root->data)
        delete_node(root->left, data);

    else if (data > root->data)
        delete_node(root->right, data);

    else {
        l_r_most = leftRightMost(root);
        root->data = l_r_most->data;
        delete_node(l_r_most, data);
    }
}

Node* leftRightMost(Node *lroot)
{
    if (lroot->left == NULL)
        return lroot->right;

    lroot = lroot->left;
    while (root->right != NULL)
        lroot = lroot->right;

    return lroot;    
}