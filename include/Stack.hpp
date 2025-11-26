#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Nodes{
    T value;
    //current Node;
    int nodepos;
    int linepos;
    Nodes* next;
    Nodes(){
        linepos=nodepos=0;
        next=nullptr;
    };
    Nodes(T value, Nodes* next = nullptr, int NodePos=0, int LinePos=0):value(value), next(next), nodepos(NodePos), linepos(LinePos) {}
};

template <typename T>
class Stack {
    private:
        Nodes<T>* top;
        int size;
    public:
        Stack(){
            top = nullptr;
            size = 0;
        }

        ~Stack(){
            Nodes<T>* cur = top;
            while(cur != nullptr){
                Nodes<T>* temp = cur;
                cur = cur->next;
                delete temp;
            }
        }  
        
        void push(T value, int NodeIndex, int LineIndex){
            Nodes<T>* newNode = new Nodes<T>(value, top, NodeIndex, LineIndex);
            top = newNode;
            size++;
        }

        Nodes<T>* pop(){
            if(isEmpty()){
                return new Nodes<char>();
            }
            Nodes<T>* temp = top;
            T value = top->value;
            top = top->next;
            //delete temp;
            size--;
            return temp;
        }

        T peek(){
            if(isEmpty()){
                throw out_of_range("Stack is empty");
            }
            return top->value;
        }

        bool isEmpty(){return top == nullptr;}
        int getSize(){return size;}
};