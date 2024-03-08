#include <iostream>
#include <fstream>
using namespace std;


struct info{

    string ssn;
    string name;

};


struct Node
{
  string data;
  struct Node *next;
};

struct Node *head;
struct Node *one = NULL;
struct Node *two = NULL;
struct Node *three = NULL;


class List{
public:
    List() { // constructor
        head = NULL;
    }
    ~List() {}; // destructor
    void addNode(string val);
    void reverseList();
    void display();
private:
    Node* head;
};


void List::addNode(string val) {
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    }
    else {
        Node* temp = head; // head is not NULL
        while (temp->next != NULL) { 
            temp = temp->next; // go to end of list
        }
        temp->next = newnode; // linking to newnode
    }
}



void List::display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]){
    

    char op;
    string ssn;
    string last;
    string name;
    int c = 0; // Indexes through the array of structures

    List* list = new LinkedList();

    fstream input(argv[1]);

    while(!input.eof()){
        
        input >> op; // Reads the i in the beginning

        input >> ssn; // Reads the SSN listed in the file

        input >> name; // Reads the first name in the file

        input >> last; // Reads the last name in the file


        list->addNode(name += " " + last);
        if(!input){ 
            break;
        }

    }
    input.close();

    string user;

    cout << "Input an SSN:" << endl;
    cin >> user;

    //cout << c;

    for(int i = 0; i < c; i++){

        if(user == list[i].ssn){
            cout << "Found at location: " << i;
            break;
        }

    }

    

}

// cin >> ssn >> first >> last
    // ignore i