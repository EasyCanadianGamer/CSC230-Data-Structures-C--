
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    string ssn;
    string name;
    struct Node* next;
    struct Node* prev;
};

class LinkedList {
public:
    LinkedList() { head = NULL; }
    ~LinkedList() {}
    void append(string ssn, string name);
    void display();
    int findIndexBySSN(string ssn);
    void insert( string ssn, string name);
    Node* find(string ssn);

private:
    Node* head;
};


void LinkedList::insert(string ssn, string name)
{
    // Check if the element already exists in the list
    Node* existingNode = find(ssn);
    if (existingNode) {
        // The element already exists, do nothing
        return;
    }

    Node* newNode = new Node();
    newNode->ssn = ssn;
    newNode->name = name;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (!head) {
        // List is empty, insert as the first node
        head = newNode;
    } else {
        // Traverse to find the correct position
        Node* curr = head;
        while (curr && curr->ssn < ssn) {
            curr = curr->next;
        }

        if (!curr) {
            // Insert at the end
            Node* prevTail = head;
            while (prevTail->next) {
                prevTail = prevTail->next;
            }
            prevTail->next = newNode;
            newNode->prev = prevTail;
        } else {
            // Insert before curr
            if (curr->prev) {
                curr->prev->next = newNode;
                newNode->prev = curr->prev;
            } else {
                head = newNode; // Insert as new head
            }
            newNode->next = curr;
            curr->prev = newNode;
        }
    }
}

void LinkedList::display() {

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->ssn << " " << temp-> name<< endl;
        temp= temp->next;
    }
    cout << endl;
    }


Node* LinkedList::find(string ssn)
{
    Node* curr = head;
    while (curr) {
        if (curr->ssn == ssn) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
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
        list.insert(ssn, name += " " + last);
        if(!input){ 
            break;
        }
    }
    input.close();



    string userSSN;
    cout << "Input an SSN: ";
    cin >> userSSN;

    int index = list.findIndexBySSN(userSSN);
    if (index != -1) {
        cout << "Found at location " << index << endl;
    } else {
        cout << "SSN not found in the list." << endl;
    }
    list.display();


    return 0;
}   
