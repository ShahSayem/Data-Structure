#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *left, *right;
} Node;

Node *root;

Node* creatNode();
void insertNode(Node *root, Node *temp);
void insertNew(Node *root, int key);
void display_inOrder(Node *vertex);
void display_preOrder(Node *vertex);
void display_postOrder(Node *vertex);
Node* search(Node *root, int key);
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

    cout<<"\nPre order: ";
    display_preOrder(root);
    cout<<"\nIn order: ";
    display_inOrder(root);
    cout<<"\nPost order: ";
    display_postOrder(root);


    int value;
    cout<<"\n\nEnter a value to search: ";
    cin>>value;
    Node *found =  search(root, value);

    if (found)
        cout<<"Found data: "<<found->data;
    else    
        cout<<"Data not found";


    int ins;
    cout<<"\n\nEnter a value to insert: ";
    cin>>ins;
    insertNew(root, ins);

    cout<<"\nPre order: ";
    display_preOrder(root);
    cout<<"\nIn order: ";
    display_inOrder(root);
    cout<<"\nPost order: ";
    display_postOrder(root);


    int dl;
    cout<<"\nEnter a data to delete: ";
    cin>>dl;
    delete_node(root, dl);
    
    cout<<"\nPre order: ";
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

void insertNew(Node *root, int key)
{
    Node *prev = NULL;
    while (root != NULL){
        prev = root;
        if (key == root->data)
            return;
        else if (key < root->data)
            root= root->left;
        else    
            root = root->right;
    }
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = key;
    temp->right = temp->left = NULL;

    if (key < prev->data)
        prev->left = temp;
    else
        prev->right = temp;
}

void display_preOrder(Node *vertex)
{
    if (vertex != NULL){
        cout<<vertex->data<<" ";
        display_preOrder(vertex->left);
        display_preOrder(vertex->right);
    }  
}

void display_inOrder(Node *vertex)
{
    if (vertex != NULL){
        display_inOrder(vertex->left);
        cout<<vertex->data<<" ";
        display_inOrder(vertex->right);
    }        
}

void display_postOrder(Node *vertex)
{
    if (vertex != NULL){
        display_postOrder(vertex->left);
        display_postOrder(vertex->right); 
        cout<<vertex->data<<" "; 
    } 
}

Node* search(Node *root, int key)
{
    while (root != NULL){
        if (root->data == key)
            return root;
    
        else if (root->data > key)
            root = root->left;
        else    
            root = root->right;
    }

    return NULL;   
}

Node* leftRightMost(Node *lroot)
{
    if (lroot->left == NULL)
        return lroot->right;

    lroot = lroot->left;
    while (lroot->right != NULL)
        lroot = lroot->right;

    return lroot;    
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
        root->left = delete_node(root->left, data);

    else if (data > root->data)
        root->right = delete_node(root->right, data);

    else {
        l_r_most = leftRightMost(root);
        root->data = l_r_most->data;
        root->left = delete_node(root->left, l_r_most->data);
    }

    return root;
}

