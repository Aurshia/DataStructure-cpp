#include<iostream>
using namespace std;
class Node{
public:    
    int info;
    Node *left;
    Node *right;
    Node(int val){
        info = val;
        left = right = nullptr;
    }
}; 
Node *insert(Node *n , int val){ //insertting and also preventing duplicates to enter
    if(n == NULL){
        return new Node(val);
    }
    if(n->info == val){
        cout<<"duplicate found";
        return n;
    }
    if(val < n->info){
        n->left = insert(n->left , val);
        return n;
    }
    else{
        n->right = insert(n->right , val);
        return n;
    }
}
void preorder(Node *curr){
    if(curr == NULL){
        return ;
    }
    else{
        cout<<curr->info<<" ";
        preorder(curr->left);
        preorder(curr->right);
    }
}

void inorder(Node* curr){
    if(curr == NULL){
        return ;
    }
    else{
        preorder(curr->left);
        cout<<curr->info<<" ";
        preorder(curr->right);
    }
}

bool isBST(Node *curr , Node *min , Node *max){ //if the binary tree is binary search tree or not
    if(curr == NULL){
        return true;
    }
    if(min != NULL && curr->info <= min->info){
        return false;
    }
    if(max != NULL && curr->info >= max->info){
        return false;
    }
    return isBST(curr->left , min , curr) && isBST(curr->right , curr , max);
}
// checking if teh bst is avl or not

int checkHeight(Node* curr) {
    if (curr == NULL)
        return 0;

    int leftHeight = checkHeight(curr->left);
    if (leftHeight == -1)
        return -1;

    int rightHeight = checkHeight(curr->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isAVL(Node* root) {
    return checkHeight(root) != -1;
}


bool search(Node *curr , int val){
    if(curr == NULL){
        return false;
    }
    if(curr->info == val){
        return true;
    }
    else if(val < curr->info){
        return search(curr->left , val);
    }
    else{
        return search(curr->right , val);
    }
}

Node* GetInorderPredecessor(Node* root){
    while(root && root->right != NULL){
        root = root->right;
    }
    return root;
}

Node* GetInorderSuccessor(Node* root){
    while(root && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root , int key){
    if(root == NULL){
        return NULL;
    }
    else if(key < root->info){
        root->left = delNode(root->left , key);
    }
    else if(key > root->info){
        root->right = delNode(root->right , key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;            
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;            
        }
        else{ // sucessor is replaced by node
            Node* IS = GetInorderSuccessor(root->right);
            root->info = IS->info;
            root->right = delNode(root->right , IS->info);



            //using predecessor
            Node* PD = GetInorderPredecessor(root->left);
            root->info = PD->info;
            root->left = delNode(root->left , PD->info);

        }
    } 
    return root;
}

int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty\n";
        return -1;
    }

    Node* temp = root;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp->info;
}

int findMax(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty\n";
        return -1;
    }

    Node* temp = root;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp->info;
}



int main(){
    Node * root = nullptr;
    //int arr[] = {14 , 15 , 4 , 9 , 7 , 18 , 3 , 5 , 16 , 4 , 20 , 17 , 9 , 4 , 5};
    root = insert(root , 14); 
    root = insert(root , 15);
    root = insert(root , 4);
    root = insert(root , 9);
    root = insert(root , 7);
    root = insert(root , 18);
    root = insert(root , 3);
    root = insert(root , 5);
    root = insert(root , 16);
    root = insert(root , 4);
    root = insert(root , 20);
    root = insert(root , 17);
    root = insert(root , 9);
    root = insert(root , 4);
    root = insert(root , 5);                
    
    preorder(root);
    cout<<endl;
    int n = isBST(root ,NULL , NULL);
    cout<<"the tree is bst or not: "<<n;
    cout<<endl;
    int srch = search(root , 100);
    cout<<"teh searching value is: "<<srch;
    cout<<endl;

    inorder(root);
    cout<<endl;

    delNode(root , 5);
    inorder(root);

}