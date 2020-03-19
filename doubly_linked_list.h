/*
 *  CSC331H-170L Project one part one
 *  doubly linked list header file
 *  Last Updated 2020/02/26
 *  By Yan Chen
 */

/*
 *  Directive
 */
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <iostream>
using namespace std;

/*
 *  Class Header Declaration
 */

//Templated Node Struct contains two Node pointers
template <class T> struct Node{
    T info;
    Node<T> *pre;
    Node<T> *next;
};

//A template doubly linked list
template <class T> class DL_List{
    private:
        Node<T> *first; //a node pointer which points to the first node of list
    public:
        DL_List(); //constructor
        DL_List(DL_List<T> const &another); //overloaded copy constructor
        ~DL_List(); //destructor
        void operator=(DL_List<T> const &another); //overloaded operator = which does a deep copy from old list to new list

        void delete_element(T); //delete elements from the list
        void search_element(T); //search elements from the list
        void empty(); //empty all elements on the list
        int is_empty();//determine if the list is empty
        int get_length();//return length of list by int
        void insert_front(T);//insert element at the front
        void insert_back(T);//insert element from the back
        void print(); //print in normal order
        void reverseprint();//print backward
};

/*
 *  Class Function Implimentation
 */
	//constructor
	template <class T> 
	DL_List<T>::DL_List(){
        first = nullptr;
	};

	//copy constructor
	template <class T> 
	DL_List<T>::DL_List(const DL_List<T> &another){
        if (another.first == nullptr){
            first = nullptr;
        }
        else{
            Node<T> *ptr = another.first;
            do {
                insert_back(ptr->info);
                ptr = ptr->next;
            } while (ptr != another.first);
        }
	};

	//destructor which release dymatic allocated memory
	template <class T> 
	DL_List<T>::~DL_List(){
		empty();
	};

	//void overloaded operator= function which does deep copy
	template <class T> 
	void DL_List<T>:: operator=(const DL_List<T> &another){
            empty();
        if (another.first != nullptr){
            Node<T> *ptr = another.first;
            do {
                this->insert_back(ptr->info);
                ptr = ptr->next;
            }while (ptr != another.first);
            ptr = nullptr;
        }
	};

	//void function which deletes T elements from the list
	template <class T> 
	void DL_List<T>::delete_element(T element){
		if (first == nullptr){
			cout <<"List is empty."<<endl;
		}
		else if (first->next == first && first->pre == first){
			if (first->info == element){
				delete first;
				first = nullptr;
			}
		}
		else {
            while (first->info == element && !(first->next == first && first->pre == first)){
                Node<T> *temp = first;
                first->pre->next = first->next;
                first->next->pre = first->pre;
                first = first->next;
                delete temp;
                temp = nullptr;
            }
            if (first->info == element && (first->next == first && first->pre == first)){
                delete first;
                first = nullptr;
        }
            else if (first->next == first && first->pre == first){
                if (first->info == element){
                    delete first;
                    first = nullptr;
                }
            }
            else {
                Node<T> *ptr = first->next;
                while (ptr != first){
                    Node<T> *temp = ptr;
                    ptr = ptr->next;
                    if (temp->info == element){
                        temp->pre->next = ptr;
                        ptr->pre = temp->pre;
                        delete temp;
                        temp = nullptr;
                    }
                }
                }
            }
	};

	//a void function which search an element in the list
	template <class T> 
	void DL_List<T>::search_element(T element){
		if (first == nullptr){
			cout <<"The list is empty."<<endl;
		}
		else if (first->next == first && first->pre == first){
			if (first->info == element){
				cout <<"Item is the only one on the list"<<endl;
			}
		}
		else {
			int count = 0;
			int position = 0;
			Node<T> *ptr = first;
			while (ptr != first->pre){
				if (ptr->info == element){
					cout <<"Item found on the "<<position<<"th position of list"<<endl;
					count++;
				}
				position++;
				ptr = ptr->next;
			}
			if (ptr->info == element){
				count++;
				cout <<"Item found on the "<<position<<"th position of list"<<endl;
			}
			cout <<"There are "<<count<<" items founded on the list"<<endl;
			ptr = nullptr;
		}
	};

	//void function which emptis the list
	template <class T> 
	void DL_List<T>::empty(){
		if (first == nullptr){
			cout <<"List is already empty."<<endl;
		}
		else if (first->next == first && first->pre == first){
			delete first;
			first = nullptr;
			cout <<"Successfully empty the list."<<endl;
		}
		else {
			Node<T> *ptr = first->next;
            do{
				Node<T> *temp = ptr;
				ptr = ptr->next;
				delete temp;
				temp = nullptr;
            }while (ptr != first);
			ptr = nullptr;
            delete first;
			first = nullptr;
			cout <<"Successfully empty the list."<<endl;
		}
	};
	
	//boolean function which determines if the list is empty
	template <class T> 
	int DL_List<T>::is_empty(){return first==nullptr;};

	//returns the length of list
	template <class T>
	int DL_List<T>::get_length(){
		int length = 0;
		if (first == nullptr){
			length = 0;
		}
		else if (first->next == first && first->pre == first){
			length = 1;
		}
		else {
			Node<T> *ptr = first;
			do {
				length++;
				ptr = ptr->next;
			}while (ptr != first);
			ptr = nullptr;
		}
		return length;
	};

	//function which inserts a given element to the front of first element(back of the list)
	template <class T>
	void DL_List<T>::insert_back(T element){
		if (first == nullptr){
			first = new Node<T>;
			first->info = element;
			first->next = first;
			first->pre = first;
		}
         else {
             Node<T> *ptr = new Node<T>;
             ptr->info = element;
             ptr->next = first;
             ptr->pre = first->pre;
             first->pre->next = ptr;
             first->pre = ptr;
             ptr = nullptr;
		}
	};

	//void function which inserts a given element to the front of the list
	template <class T> 
	void DL_List<T>::insert_front(T element){
		if (first == nullptr){
			first = new Node<T>;
			first->info = element;
			first->next = first;
			first->pre = first;
		}
		else {
			this->insert_back(element);
			first = first->pre;
		}
	};

	//void function which prints the list in normal order
	template <class T>
	void DL_List<T>::print(){
		if (first == nullptr){
			cout<<"{}"<<endl;
		}
		else {
			Node<T> *ptr = first;
			cout <<"{";
			do {
				cout <<ptr->info<<" ";
				ptr = ptr->next;
			}
			while (ptr != first);
			cout <<"}"<<endl;
            ptr = nullptr;
		}
	};

	//void function which prints the list backward
	template <class T>
	void DL_List<T>::reverseprint(){
		if (first == nullptr){
			cout <<"{}"<<endl;
		}
		else {
			Node<T> *ptr = first->pre;
			cout <<"{";
                        do {
                                cout <<ptr->info<<" ";
                                ptr = ptr->pre;
                        }
                        while (ptr != first->pre);
			cout <<"}"<<endl;
            ptr = nullptr;
		}
	};
#endif
