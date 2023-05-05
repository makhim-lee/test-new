#include<assert.h>
#include<iostream>
#include<cstring>
#include"list.h"

std::ostream& operator<<(std::ostream& out, const List& rhs){
    //return rhs.printList(out, " > ");
    return rhs.printList(out); //default" ,"      
}

Node* createNode(int d, Node *n){
    Node *p = new Node[sizeof(Node)];   //default Node create
    assert(p );
    p->next = n;
    p->data = d;
    return p;
}

List::List(){
    ptr_ = new Node;   //Node의 디폴트 생성자
    assert(ptr_);
    //ptr->data = ??
    ptr_->next = NULL;
}

List::~List(){
    Node *ptr = ptr_;
    while (ptr){
        Node *tmp = ptr;
        ptr = ptr->next;
        delete tmp;  //delete [] tmp;??
    }
    
}


void List::insertFirstNode(int data){
    ptr_->next = createNode(data, ptr_->next);
}

void List::insertNode(int prevData, int data){
    Node *ptr = ptr_->next;
    while(ptr){
        if(ptr->data == prevData) break;
        ptr = ptr->next;
    }
    if(ptr) ptr->next = createNode(data, ptr->next); 
}

void List::deleteNode(int data)
{
    Node *ptr = ptr_->next;
    Node *ptr2 = ptr_;
    while(ptr ){
        if(ptr->data == data) break;
        ptr = ptr->next;
        ptr2 = ptr2->next;   
    }
    if(ptr ){
        ptr2->next = ptr->next;
        delete ptr;
    }
}

std::ostream& List::printList(std::ostream& out, const std::string& delim)const{
    Node *ptr = ptr_->next;
    while(ptr){
        out<<ptr->data;
        out<<((ptr->next )? delim : "");
        ptr = ptr->next;
    }
    return out;
}