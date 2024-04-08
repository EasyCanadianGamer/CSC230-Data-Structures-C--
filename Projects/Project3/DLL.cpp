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

    //cout<< curr->ssn<< endl;
    
    if( curr == nullptr)
    {
        return;
    }
    // Node* curr_next = curr-> next;

    Node* tempNode = new Node;
    tempNode -> ssn = curr -> ssn;
    tempNode -> name = curr -> name;
    tempNode -> pred = nullptr;
    headPtr = tempNode;
    curr = curr-> succ;
    while( curr != nullptr)
    {
        tempNode -> succ = new Node;
        tempNode -> succ -> ssn = curr -> ssn;
        tempNode -> succ -> name = curr -> name;
        tempNode -> succ -> pred = tempNode;
        tempNode = tempNode -> succ;

        curr = curr ->succ;
    }

    tempNode-> succ =  nullptr;
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
        Node* curr = headPtr;
        int curr_index =0;
        while(curr != nullptr)
        {
            if(curr -> ssn == ss)
            {
                return curr_index;
            }
            if(curr-> succ==nullptr)
            {
                return -1;
            }
            curr_index++;
            curr = curr->succ;
        }
        
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
 // Create a new node
    Node* newNode = new Node;
    newNode->ssn = ss;
    newNode->name = name;
    newNode->succ = nullptr;
    newNode->pred = nullptr;
    if(headPtr == nullptr)
    {
        headPtr = newNode;
        count++;
        itemCount++;
        return true;
    }

    // Traverse the list to find the correct position
    Node* current = headPtr;
    while (current -> succ != nullptr && current -> succ->ssn < ss) {
        current = current->succ;
    }
    if( current->succ == nullptr)
    {
        //insert at the end
        current-> succ = newNode;
        newNode->pred = current;
        count++;
        itemCount++;
        return true;

    }
    if( current == headPtr)
    {
        if( newNode->ssn == current->ssn)
        {
            delete newNode;
            return false;
        }
        if( newNode->ssn < current->ssn)
        {
            //insert at the beginning
            headPtr = newNode;
            newNode->succ = current;
            current->pred= nullptr;
            count++;
            itemCount++;
            return true;
        }
    }

    if( newNode->ssn == current->succ->ssn && newNode->ssn < current->ssn)
    {
        delete newNode;
        return false;
    }
    else{
        //instert in the middle
        newNode->succ = current->succ;
        newNode->pred=current;
        current->succ->pred= newNode;
        current->succ = newNode;
        count++;
        itemCount++;
        return true;
        }

}
// remove node containing ss value
// if there is no node containing ss, return false; otherwise true
// consider the following situations:
// 1. list is empty
// 2. node containing ss value is the first node
// 3. node containing ss value is in the middle of the list
// 4. node containing ss value is the last node of the list
bool DLL::remove(string ss, int & count){
        Node* current = headPtr;
    Node* prev = nullptr;

    // Search for the node to remove
    while (current && current->ssn != ss) {
        prev = current;
        current = current->succ;
    }

    if (current) {
        // Node with the specified SSN found
        if (prev) {
            // Update pointers for nodes other than head
            prev->succ = current->succ;
            if (current->succ) {
                current->succ->pred = prev;
            }
        } else {
            // Removing the head node
            headPtr = current->succ;
            if (headPtr) {
                headPtr->pred = nullptr;
            }
        }

        // Delete the node
        delete current;
        count++; // Decrement itemCount
        return true;
    } else {
        // Node with the specified SSN not found
        return false;
    }
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
