#include <iostream>
#include <queue>
using namespace std;

template <class T>
class MyStack {

  // define two instance variables
  // by default, they are private
  queue <T> first; 
  queue <T> second;

 public:

  // return the latest value of MyStack
  T top(){

    if( first.empty() )
    {
      throw underflow_error("Stack is empty");
    }
    return first.back();

    // please implement this method
  }

  // add value val to MyStack
  void push(T val){

    first.push(val);

    // please implement this method
  }

  // remove the oldest value from MyStack
  void pop(){
        if (first.empty()) {
            throw underflow_error("Stack is empty");
        }
        // Move all elements except the last one to the second queue
        while (first.size() > 1) {
            second.push(first.front());
            first.pop();
        }
        // Remove the last element from the first queue
        first.pop();
        // Swap the queues so that the second queue becomes the first
        swap(first, second);
    // please implement this method
  }

  
};
