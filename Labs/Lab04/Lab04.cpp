#include <iostream>
#include <fstream>
using namespace std;


struct info{

    string ssn;
    string name;

};


int main(int argc, char* argv[]){
    

    char op;
    string ssn;
    string last;
    int c = 0; // Indexes through the array of structures

    static info list[1000];

    fstream input(argv[1]);

    while(!input.eof()){
        
        input >> op; // Reads the i in the beginning

        input >> list[c].ssn; // Reads the SSN listed in the file

        input >> list[c].name; // Reads the first name in the file

        input >> last; // Reads the last name in the file

        list[c].name += " " + last; // Combines the first and last name
        c++; // Indexes through the structure array.
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