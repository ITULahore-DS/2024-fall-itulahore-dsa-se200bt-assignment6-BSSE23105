#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node *next;
public:
    Node(){
        data = 0;
        next = nullptr;
    }
    ~Node(){

    }
    Node(int value) {
        this->data = value;
        this->next = nullptr;
    }
    void setNext(Node *node){     //setter
        next = node;
    }
    Node *getNext(){
        return next;                 //getter
    }
    void setData(int data){
        this->data=data;           //setter
    }

    int getData(){
        return data;             //getter
    }
};




class Stack {
    Node *top;
    int count;

public:

    Stack() {
        top=nullptr;
        count=0;
    }
    ~Stack() {
        //destructor
        while(count!=0) {
            pop();
        }
    }

    void push(int inputData) {
        if(top==nullptr) {
            top=new Node();
            top->setData(inputData);               //if linked list is empty then set the top
            top->setNext(nullptr);
            count++;
        }
        else {
            Node* pushedNode = new Node();
            pushedNode->setData(inputData);              //unpdating top node because of stack algorithm
            pushedNode->setNext(top);
            top = pushedNode;
            count++;

        }
    }

    void pop() {
        if(count==0){
            cout<<"Stack is already empty"<<endl;
            return;
        }
        else {
            Node* deleteNode = top;
            top = top->getNext();
            delete deleteNode;                //deleting the top
            count--;
        }
    }


    bool isEmpty() {
        if(count == 0) {
            return true;
        }else {                                   //check to se if our stack is empty or not
            return false;
        }
    }
    int peek() {
        if (count==0) {
            cout << "Stack is empty"<<endl;
            return -1;                 // Sentinel value as instructed in word file
        }
        return top->getData();         //returning data on the top
    }

        int size() const {
        return count;              //getter
    }

    void printStack() {
                  if (count==0) {
                      cout << "Stack is empty"<<endl;
                      return;
                  }
                  //initialising                           condition                      incrementing
                  for(Node* iteratoringNode = top ;iteratoringNode != nullptr;iteratoringNode = iteratoringNode->getNext()) {
                      cout<< iteratoringNode->getData()<<endl;
                  }
              }

    void clear() {
        while(count!=0){
            pop();               //popping untill the linked list ends
        }
    }

};



class Queue {
   Node *top;
    int count;

    public:
    Queue() {
        top=nullptr;
        count = 0;
    }

    ~Queue() {
        while(count!=0) {
            dequeue();
        }
    }

    bool isEmpty() {
        if (count == 0) {        //check to see if our linked list is empty or not
            return true;
        }
        else {
            return false;
        }
    }

    int size() {
        return count;                   //getter
    }


    void printQueue() {
        if (count==0) {
            cout << "Queue is empty" << endl;
            return;
        }
        //initialising                           condition                      incrementing
        for(Node* iteratoringNode = top ;iteratoringNode != nullptr;iteratoringNode = iteratoringNode->getNext()) {
            cout<< iteratoringNode->getData()<<endl;
        }
    }


    void enqueue(int inputData) {
        if(top==nullptr) {
            top=new Node();
            top->setData(inputData);               //if linked list is empty then set the top
            top->setNext(nullptr);
            count++;
        }
        else {

            Node *iterator= top;
            while (iterator->getNext() != nullptr) {             //finding the second last element
                iterator = iterator->getNext();
            }
            Node *enqueuedNode= new Node();
            enqueuedNode->setData(inputData);
            enqueuedNode->setNext(nullptr);
            iterator->setNext(enqueuedNode);              // adding the new node at the end as it is Queue
            count++;
        }
        }

    void dequeue() {
        if(count==0){
            cout<<"Queue is already empty"<<endl;         //checking if it is already empty
            return;
        }
        else {
            Node* deleteNode = top;
            top = top->getNext();
            delete deleteNode;                //deleting the top
            count--;
        }
    }
    int peek() {
        if (count==0) {
            cout << "Queue is empty"<<endl;
            return -1;                 // Sentinel value as instructed in word file
        }
        return top->getData();
    }

    void clear() {
        while(count!=0){
            dequeue();               //dequeing untill the linked list ends
        }
    }


};

#endif
