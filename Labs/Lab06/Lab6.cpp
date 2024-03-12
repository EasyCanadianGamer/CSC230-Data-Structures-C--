
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    string ssn;
    string name;
    struct Node* next;
};

class LinkedList {
public:
    LinkedList() { head = NULL; }
    ~LinkedList() {}
    void append(string ssn, string name);
    void display();
    int findIndexBySSN(string ssn);

private:
    Node* head;
};

void LinkedList::append(string ssn, string name) {
    Node* newNode = new Node();
    newNode->ssn = ssn;
    newNode->name = name;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
    }
    else{
        Node* temp = head;
        while ( temp -> next != NULL)
        {
            temp = temp-> next;
        }
            temp -> next = newNode;

    }
}

void LinkedList::display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->ssn << " " << temp->name << endl;
        temp = temp->next;
    }
}

int LinkedList::findIndexBySSN(string ssn) {
    Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->ssn == ssn) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1; // SSN not found
}

int main(int argc, char* argv[]) {
    LinkedList list;
    string ssn, name, last;
    fstream input(argv[1]);
    char c; 

    while (!input.eof()) {


        input >> c; // Reads the i in the beginning

        input >> ssn; // Reads the SSN listed in the file

        input >> name; // Reads the first name in the file

        input >> last; // Reads the last name in the file
        list.append(ssn, name += " " + last);
        if(!input){ 
            break;
        }
    }
    input.close();


    //list.display();

    string userSSN;
    cout << "Input an SSN: ";
    cin >> userSSN;

    int index = list.findIndexBySSN(userSSN);
    if (index != -1) {
        cout << "Found at location " << index << endl;
    } else {
        cout << "SSN not found in the list." << endl;
    }

    return 0;
}   
