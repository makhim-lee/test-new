#include<assert.h>
#include<iostream>
#include<cstring>
#include"list.h"
/*
Node* Node::createNode(int data, Node *next){
    Node *p = new Node[sizeof(Node)];   //default Node create
    assert(p );
    p->data = data;
    p->next = next;
    return p;
} 
*/
Node::Node(int data, const Node * next)
//: data_(data), next_((Node *)next)
: data_(data), next_(const_cast<Node *>(next))
{
}

std::ostream& operator<<(std::ostream& out, const List& rhs){
    //return rhs.printList(out, " > ");
    return rhs.printList(out); //default" ,"      
}

List::List(){
    //ptr_ = createNode(-1, NULL);
    ptr_= new Node(-1,NULL);
}

List::~List(){
    Node *ptr = ptr_;
    while (ptr){
        Node *tmp = ptr;
        ptr = ptr->next_;
        delete tmp;  //delete [] tmp;??
    }
}


void List::insertFirstNode(int data){
    //ptr_->next = createNode(data, ptr_->next);
    ptr_->next_= new Node(data, ptr_->next_);
}

void List::insertNode(int prevData, int data){
    Node *ptr = ptr_->next_;
    while(ptr){
        if(ptr->data_ == prevData) break;
        ptr = ptr->next_;
    }
    if(ptr) ptr->next_ = new Node(data , ptr->next_);//ptr->next = createNode(data, ptr->next); 
}

void List::deleteNode(int data)
{
    Node *ptr = ptr_->next_;
    Node *ptr2 = ptr_;
    while(ptr ){
        if(ptr->data_ == data) break;
        ptr = ptr->next_;
        ptr2 = ptr2->next_;   
    }
    if(ptr ){
        ptr2->next_ = ptr->next_;
        delete ptr;
    }
}

std::ostream& List::printList(std::ostream& out, const std::string& delim)const{
    Node *ptr = ptr_->next_;
    while(ptr){
        out<<ptr->data_;
        out<<((ptr->next_ )? delim : "");
        ptr = ptr->next_;
    }
    return out;
}