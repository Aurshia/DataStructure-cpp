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
Node *parent(Node *curr , Node *p , Node *par ){
        if(curr == NULL){
            return NULL;
        }
        if(curr == p){
            return par;
        }
        Node *t = NULL;
        t = parent(curr->left , p , curr);
        if(t != NULL){
            return t;
        }
        else{
            t = parent(curr->right , p , curr);
            return t;
        }
}
Node *sibling(Node *curr , Node *p){
    Node *par = parent(curr , p , NULL);
        if(p = par->right){
            return par->left;
        }
        else{
            return par->right;
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
void inorder(Node *curr){
    if(curr == NULL){
        return ;
    }
    else{
        
        inorder(curr->left);
        cout<<curr->info<<" ";
        inorder(curr->right);
    }
}
void postorder(Node *curr){
    if(curr == NULL){
        return ;
    }
    else{
        
        postorder(curr->left);
        postorder(curr->right);
        cout<<curr->info<<" ";
    }
}
int getlevel(Node *curr ,int val , int level){
    if(curr == NULL){
        return -1;
    }
    if(curr->info == val){
        return level;
    }
    else{
        int left = getlevel(curr->left , val , level+1);
        int right = getlevel(curr->right , val , level+1);
        if(left>right){
            return left;
        }
        else{
            return right;
        }
    }
}
int dept(Node *curr){
    if(curr == NULL){
        return -1;
    }
    else{
        int ldept = dept(curr->left);
        int rdpe = dept(curr->right);
        if(ldept > rdpe){
            return ldept+1;
        }
        else{
            return rdpe+1;
        }
    }
}
int addAllNodes(Node *curr) {
    if (curr == NULL) {
        return 0;               // stopping condition
    }

    int left = addAllNodes(curr->left);
    int right = addAllNodes(curr->right);

    return curr->info + left + right;
}
bool isOdd(int x) {
    return x % 2 != 0;
}

void odd(Node* curr) {
    if (curr == NULL) return;

    if (isOdd(curr->info)) {
        cout << curr->info << " ";
    }

    odd(curr->left);
    odd(curr->right);
}

bool isEven(int x) {
    return x % 2 == 0;
}
void even(Node* curr) {
    if (curr == NULL) return;

    if (isEven(curr->info)) {
        cout << curr->info << " ";
    }

    even(curr->left);
    even(curr->right);
}

// Recursive function to calculate sum of even numbers
int sumEven(Node* root) {
    if (root == nullptr)
        return 0; // Base case: empty tree
    
    int sum = 0;
    
    // Check if current node is even
    if (root->data % 2 == 0)
        sum += root->data;
    
    // Add sum of left and right subtrees
    sum += sumEven(root->left);
    sum += sumEven(root->right);
    
    return sum;
}

int sumOdd(Node* root) {
    if (root == nullptr)
        return 0; // Base case: empty tree

    int sum = 0;

    // Check if current node is odd
    if (root->data % 2 != 0)
        sum += root->data;

    // Recursively add sum of odd numbers in left and right subtrees
    sum += sumOdd(root->left);
    sum += sumOdd(root->right);

    return sum;
}

int insert(Node *curr , int val , Node *p){
    if(curr == NULL){
       return val;
    }
    if(curr->info == val){
        return p->info;
    }
    int left = insert(curr->left , val , curr);
    int right = insert(curr->right , val , curr);
    return val;
}
int count(Node* curr) {
    if (curr == NULL) {
        return 0; // base case: empty tree has 0 nodes
    }

    // count current node + count left subtree + count right subtree
    return 1 + count(curr->left) + count(curr->right);
}
   

int main(){
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->right->left = new Node(3);
    root->right->right = new Node(9);
    root->left->left = new Node(6);
    root->left->left->right = new Node(1);
    Node *n =parent(root,root->right->right,NULL);
    cout<<"Parent is: "<<n->info<<endl;
    Node *sib=sibling(root , root->right->right);
    cout<<"sibling is: "<<sib->info;
    cout<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    int depth = dept(root);
    cout<<"the depth is: "<<depth;
    cout<<endl;
    int lev = getlevel(root , 9 , 0);
    cout<<"the level is: "<<lev;
    cout<<endl;
    int add = addAllNodes(root);
    cout<<"the sum of all nodes is: "<<add;
    cout<<endl;
    
    cout<<endl;
    even(root);
    int c = count(root);
    cout<<endl;
    cout<<"the number f nodes are: "<<c;
    return 0;
}