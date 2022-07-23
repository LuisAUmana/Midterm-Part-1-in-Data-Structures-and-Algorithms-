// Implement the push_front method
// by Luis Umana

#include <string>
#include "q2.h"

using namespace std;

// Node class implemenation

template <typename T>
Node<T>::Node(T element) { // Constructor 
	data = element;
	previous = nullptr;
	next = nullptr;
}

// List implementation

template <typename T>
List<T>::List() { 
	head = nullptr;
	tail = nullptr;
}


template <typename T>
List<T>::~List() { // Destructor
	for(Node<T>* n = head; n != nullptr; n = n->next) {
    
		delete n; //Deconstructor create an error evertime i ran it.
	}

}

template <typename T>
void List<T>::push_front(T element) {  
	// Your code here
	// frontmethod is my temporary variable
	Node<T> *frontmethod = new Node<T>(element); // new node
    frontmethod->next=head; // makes the new node point to the head 
    head=frontmethod; //Temporay variable becomes the head

}



template <typename T>
Iterator<T> List<T>::begin() {  
	Iterator<T> iter;
	iter.position = head;
	iter.container = this;
	return iter;
}

template <typename T>
Iterator<T> List<T>::end() {  
	Iterator<T> iter;
	iter.position = nullptr;
	iter.container = this;
	return iter;
}

// Iterator implementation

template <typename T>
Iterator<T>::Iterator() {
	position = nullptr;
	container = nullptr;
}


template <typename T>
T Iterator<T>::get() const {  
	return position->data;
}

template <typename T>
void Iterator<T>::next() {  
	position = position->next;
}

template <typename T>
void Iterator<T>::previous() {  
	if (position == nullptr) {
		position = container->tail;
	} else {
		position = position->previous;
	}
}

template <typename T>
bool Iterator<T>::equals(Iterator<T> other) const {  
   return position == other.position;
}
