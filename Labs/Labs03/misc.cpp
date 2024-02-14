#include <iostream>
#include <cstring>
using namespace std;

void reverse(char* p){

    int x ,i;
    char *begin_p, *end_p, ch;
    x = strlen(p);

    begin_p = p;

    end_p = p + x - 1;

    for (i = 0; i < (x- 1) / 2; i++) { 
 
    // swap character 
    ch = *end_p; 
    *end_p = *begin_p; 
    *begin_p = ch; 
 
    // update pointers positions 
    begin_p++; 
    end_p--; 

    }
}
