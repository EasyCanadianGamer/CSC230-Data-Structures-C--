#include <iostream>
#include <stack>
using namespace std;

template <class T>
class MyQueue {
    // these two stck are instance variables
    // by default, the access is private
    stack<T> first;
    stack<T> second;
    
    public:

    // return the value of the oldest member
   T front() {
    if (first.empty()) {
       throw underflow_error("Queue is empty");
     }
     return first.top();

}


    // add value val to MyQueue
void push(T val) {
    while(!first.empty())
    {
        second.push(first.top());
        first.pop();
    }
    first.push(val);
    while(!second.empty())
    {
        first.push(second.top());
        second.pop();
    }
}



    // remove the oldest member from MyQueue
void pop() {
    first.pop();
}

};
