#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>


struct Node {
    Animal data;
    Node* prev;
    Node* next;


    Node(Animal value) : data(value), prev(nullptr), next(nullptr) {}
};


struct DoublyLinkedList {
    Node* head;
    Node* tail;
    
    
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    
    void push_back(Animal value);
    void push_front(Animal value);
    void fill_from_file(std::string filename);
    void record_to_file(std::string filename);
    void edit(Animal selected_animal);
    void sort(std::string key);
    void remove(Animal value);
    void print();
    void print_head();
    void print_tail();
    void clear();
    ~DoublyLinkedList();
};

#endif
