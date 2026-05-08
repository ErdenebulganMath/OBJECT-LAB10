#include<iostream>
#include<string>
#include<cmath>
using namespace std ; 

template <typename T>
class Node { 
    private : 
        T data ; 
        Node<T> *next ; 
    public : 
        void setData(T data){
            this->data = data ; 
        }

        T getData(){
            return data ; 
        }

        void setNext(Node<T>* next){
            this->next = next ; 
        }

        Node<T>* getNext(){
            return next ; 
        }

} ; 

int main(){
    Node<string> node1 ; 
    node1.setData("Hello") ; 
    cout << node1.getData() << endl ; 

    Node<string> node2 ; 
    node2.setData("World") ; 
    cout << node2.getData() << endl ; 

    node1.setNext(&node2) ; 
    cout << node1.getNext()->getData() << endl ; 

    return 0 ; 

}