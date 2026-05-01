#include<iostream>
using namespace std;
class node{
public:    
    int data ;
    node * next;
    node(int val){
        data = val;
        next =  nullptr;
    }
};
class sll{
public:
    node * head ;
    node * tail;
    sll(){
        head = tail = nullptr;
    }
    
};