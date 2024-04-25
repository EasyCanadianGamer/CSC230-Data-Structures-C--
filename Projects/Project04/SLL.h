#include <iostream>
#include "Node.h"
using  namespace  std;

template <class U>
class SLL {
    
    Node<U> * headPtr;
    int size;
    
    public:
    // default constructor
    SLL(){
      //implement this method
      size = 0;
      headPtr = nullptr;
    }

    // destructor    
    ~SLL(){
      // implement this method
      Node<U>* temp;
      temp = headPtr;
      while (temp!= nullptr) {
          temp = temp->next;
          delete temp;
      }
    }
    
    Node<U>* getHeadPtr(){
        return headPtr;
    }
    
    // insert (item1, item2) to the list
    void insert(U item1, U item2){
      //implement this method
      Node<U>* newNode = new Node<U>;
      newNode->SSN = item1;
      newNode->name = item2;
      newNode->next = headPtr;
      headPtr = newNode;
      size++;

    }
    
    // if find the item1 value, return the pointer to the node
    // otherwise, return nullptr
    Node<U>* search(U item1){
      //implement this method
      Node<U>* temp;
      temp = headPtr;
      while (temp!= nullptr) {
          if (temp->SSN == item1) {
              return temp;
          }
          temp = temp->next;
      }
      return nullptr;

    }
    
    // remove the node with key value: item1
    bool remove(U item1){
      //implement this method
      Node<U>* temp;
      temp = headPtr;
      if (temp->SSN == item1) {
          headPtr = temp->next;
          delete temp;
          size--;
          return true;
      }
      else {
          while (temp->next!= nullptr) {
              if (temp->next->SSN == item1) {
                  Node<U>* temp2;
                  temp2 = temp->next;
                  temp->next = temp2->next;
                  delete temp2;
                  size--;
                  return true;
              }
              temp = temp->next;
          }
      }
      return false;
    }
    
    int getSize(){
        
        return size;
    }
    
    // display the SSN values of each node in the linked list
    void display(){
        Node<U>* temp;
        temp = headPtr;
        while (temp!= nullptr) {
            cout << temp->SSN << endl;
            temp = temp->next;
        }
    }
};


