#include "DLL.h"
#include <iostream>
#include <string>
using namespace std;

// default constructor is already implemented
// do not modify the default constructor
DLL::DLL(){
    headPtr = nullptr;
    itemCount=0;
}

// return the head pointer of the list
// it is already implemented, do not modify it
Node* DLL::getHeadPtr(){
    return headPtr;
}

// copy construct, which copies an existing list n
// the new list is a different object from n
// the new list and object n have the same contents
// Please implement it
DLL::DLL(DLL& n){

    // if( headPtr != nullptr)
    // {
    //     headPtr = nullptr;
    // }
    headPtr = nullptr;
    
    Node* curr = n.getHeadPtr();


    
    if( curr == nullptr)
    {
        return;
    }
    //Node* curr_next = curr-> next;

    Node* tempNode = new Node;
    tempNode -> ssn = curr -> ssn;
    tempNode -> name = curr -> name;
    tempNode -> pred = nullptr;
    curr = curr-> succ;
    // while( curr != nullptr)
    // {
    //     tempNode -> succ = new Node;
    //     tempNode -> succ -> ssn = curr -> ssn;
    //     tempNode -> succ -> name = curr -> name;
    //     tempNode -> succ -> pred = tempNode;
    //     tempNode = temp // while( curr != nullptr)
    // {
    //     tempNode -> succ = new Node;
    //     tempNode -> succ -> ssn = curr -> ssn;
    //     tempNode -> succ -> name = curr -> name;
    //     tempNode -> succ -> pred = tempNode;
    //     tempNode = tempNode -> succ;

    //     curr = curr ->succ;
    // }

    // tempNode-> succ =  nullptr;
}

// destructor
// release every node of the list
// Please implement it
DLL::~DLL(){

    Node* current = headPtr;
    while( current != nullptr)
    {
        Node* nextNode = current -> succ;
        delete current;
        current = nextNode;
    }
    
}

// if some node has SSN matcthes string ss
// return the index value of the node
// the index value of the first node is 0, the second node is 1, etc.
// if there is node matching ss, return -1
int DLL::search(string ss)const{

    return -1;
}


// insert (ss, name) to the existing list
// the SSN values are each node are organized in INCREASING order
// if there is a node matching ss value, return false; otherwise true
// else create a node with (ss, name), insert the node to the proper position
// parameter count is the counter of number of valid insertion
// when you implement this method, consider the following situations:
// 1. list is empty
// 2. node should be inserted to the beginning of the list
// 3. node should be inserted to the middle of the list
// 4. node should be inserted to the end of the list
bool DLL::insert(string ss, string name, int & count){
    
    return false;
}


// remove node containing ss value
// if there is no node containing ss, return false; otherwise true
// consider the following situations:
// 1. list is empty
// 2. node containing ss value is the first node
// 3. node containing ss value is in the middle of the list
// 4. node containing ss value is the last node of the list
bool DLL::remove(string ss, int & count){
    return false;
}

// return the number of the nodes
// it is already implemented, do not modify it
int DLL::size(){
    
    return itemCount;
}

// iterate through each node
// print out SSN and memory address of each node
// do not modify this method
void DLL::display(){
    Node* temp;
    temp = headPtr;
    while (temp!= nullptr) {
        cout << temp->ssn << "\t" << temp << endl;
        temp = temp->succ;
    }
}
