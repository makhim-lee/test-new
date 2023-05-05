#ifndef LIST_H
#define LIST_H
#include<string>
#include<iostream>

struct Node;
Node* createNode(int data, Node *next);

struct Node {
    int data;
    Node *next;
} ;

class List {
friend std::ostream& operator<<(std::ostream& out, const List& rhs);
private:
    Node *ptr_;

    std::ostream& printList(std::ostream& out, const std::string& delim = ", ")const;

    List(const List& );
    List& operator=(const List&);    
public:
    List();
    ~List();

    void insertFirstNode(int data);
    void insertNode(int prevData, int data);
    void deleteNode(int data);

    //static 
};


#endif