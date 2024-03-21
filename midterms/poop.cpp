#include <iostream>
using namespace std;
struct Node{
 char val;
 Node* next;
};
class SLL{
private:
 Node* headPtr = NULL;
public:
 void display() {

    Node* temp = headPtr;
    while (temp != nullptr) {
        cout << temp->val << endl;
        temp= temp->next;
    }
 }
 void append(char val) {
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = NULL;
    if(headPtr == NULL)
    {
        headPtr = newNode;
    }
    else{
        Node* temp = headPtr;
        while ( temp -> next != NULL)
        {
            temp = temp-> next;
        }
            temp -> next = newNode;

    }
}
 Node* getHeadPtr(){
 return headPtr;
 }
 void merge(SLL x){
    Node* curr_into = this -> headPtr;
    Node* curr_from = x.getHeadPtr();
    Node* curr_into_prev = NULL;
    while( curr_into != nullptr)
    {
        if( curr_from == nullptr)
        {
            return;
        }

        Node* temp = new Node { curr_from -> val, curr_into -> next};

        curr_into -> next =  temp; 
        curr_into_prev = curr_into->next;
        curr_into = curr_into ->next->next;
        curr_from = curr_from -> next;
    }
    curr_into_prev-> next = curr_from;

 }







};


int main()
{



    SLL list, list2;
    list.append('a');
    list.append('b');
    list.append('c');

    // list.display();

    list2.append('w');
    list2.append('x');
    list2.append('y');
    list2.append('z');

    // list2.display();

    list.merge(list2);

    list.display();

    return 0;
}