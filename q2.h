// Doubly linked list
#ifndef Q2_H
#define Q2_H

template<typename T> class List;
template<typename T> class Iterator;

template <typename T>
class Node {
	public:
		Node(T element);
	private:
		T data; 
		Node* previous;
		Node* next;
	friend class List<T>;
	friend class Iterator<T>;
};

template <typename T>
class List {
	public:
		List(); // Constructor
		~List(); // Destructor
		void push_front(T element); // Inserts to front of list
		Iterator<T> begin(); // Point to beginning of list
		Iterator<T> end(); // Point to past end of list
	private:
		Node<T>* head;
		Node<T>* tail;
	friend class Iterator<T>;
};


template <typename T>
class Iterator {
	public:
		Iterator();
		T get() const; // Get value pointed to by iterator
		void next(); // Advance iterator forward
		void previous(); // Advance iterator backward
		bool equals(Iterator<T> other) const; // Compare values pointed to by two iterators
	private:
		Node<T>* position; // Node pointed to by iterator
		List<T>* container; // List the iterator is used to iterattoe
	friend class List<T>;
};

#endif
