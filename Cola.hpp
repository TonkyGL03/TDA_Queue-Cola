#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED

#include<iostream>

template<class T, int ARRAYSIZE = 1024>
class Queue{
private:
    T data[ARRAYSIZE];
    int frontPos;
    int endPos;

    void copyAll(const Queue<T, ARRAYSIZE>&);

public:
    Queue();
    Queue(const Queue<T, ARRAYSIZE>&);

    bool isEmpty();
    bool isFull();

    void enqueue(const T&);

    T dequeue();

    T getFront();

    void showQueue();

    Queue<T, ARRAYSIZE>& operator = (const Queue<T, ARRAYSIZE>&);

};

using namespace std;

template<class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::copyAll(const Queue<T, ARRAYSIZE>& q){


}

template<class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue() : frontPos( 0 ), endPos(ARRAYSIZE - 1){}

template<class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isEmpty(){
    return frontPos == endPos + 1 or (frontPos == 0 and endPos == ARRAYSIZE - 1);
}

template<class T, int ARRAYSIZE>
 bool Queue<T, ARRAYSIZE>::isFull(){
return frontPos == endPos + 2
            or ( frontPos == 0 and endPos == ARRAYSIZE - 2)
            or ( frontPos == 1 and endPos == ARRAYSIZE - 1);
}

template<class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::enqueue(const T& e){
    if(isFull()){ cout<<"Desbordamiento de datos"<<endl; abort();  }

    if(++endPos == ARRAYSIZE){
        endPos = 0;
    }
    data[endPos] = e;
}

template<class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::dequeue(){
    if(isEmpty()){
        cout<<"Insuficiencia de datos, dequeue"<<endl; abort();
    }

    T result( data[ frontPos ] );
    if(++frontPos == ARRAYSIZE){
        frontPos = 0;
    }
    return result;
}

template<class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::getFront(){
    if(isEmpty()){
        cout<<"Insuficiencia de datos, getFront"<<endl; abort();
    }

    return data[ frontPos ];
}

template<class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>& Queue<T, ARRAYSIZE>:: operator= (const Queue<T, ARRAYSIZE>& q){
    copyAll(q);
    return *this;
}

template<class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue(const Queue<T, ARRAYSIZE>& q){
    copyAll(q);
}

template<class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::showQueue(){
    for(int i(0); i <= endPos; i++){

        cout<<data[i]<<endl;
    }
}
#endif // COLA_HPP_INCLUDED
