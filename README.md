# Doubly_Linked_List

a implementation of templated circular doubly linked list
It is a homework from Data structure

# Feature

        DL_List()
          constructor
          
        DL_List(DL_List<T> const &another)
          overloaded copy constructor
          
        ~DL_List()
          destructor
          
        void operator=(DL_List<T> const &another)
          overloaded operator = which does a deep copy from old list to new list
          
        void delete_element(T)
          delete elements from the list
          
        void search_element(T)
          search elements from the list
          
        void empty()
          empty all elements on the list
          
        int is_empty()
          determine if the list is empty
          
        int get_length()
          return length of list by int
          
        void insert_front(T)
          insert element at the front
          
        void insert_back(T)
          insert element from the back
          
        void print()
          print in normal order
          
        void reverseprint()
          print backward
