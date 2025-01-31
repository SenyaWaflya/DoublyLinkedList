#include <iostream>
#include <fstream>
#include <sstream>
#include "Animal_struct.hpp"
#include "DoublyLinkedList_struct.hpp"

using namespace std;


void DoublyLinkedList::push_back(Animal value) {
    Node* newNode = new Node(value);
    if(!head) {
        head = tail = newNode;
    } else {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}


void DoublyLinkedList::push_front(Animal value) {
    Node* newNode = new Node(value);
    if(!head) {
        head = tail = newNode;
    } else {
        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
    }
}


void DoublyLinkedList::fill_from_file(string filename) {
    ifstream file(filename);
    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string type, gender, nickname;
        int weight, age;
        ss >> type >> gender >> weight >> nickname >> age;
        Animal line_animal;
        line_animal.type = type;
        line_animal.gender = gender;
        line_animal.weight = weight;
        line_animal.nickname = nickname;
        line_animal.age = age;
        
        Node* newNode = new Node(line_animal);
        if(!head) {
            head = tail = newNode;
        } else {
            head -> prev = newNode;
            newNode -> next = head;
            head = newNode;
        }
    }
}


void DoublyLinkedList::record_to_file(string filename) {
    ofstream file(filename);
    Node* current = head;
    while(current) {
        file << current -> data.type << " " << current -> data.gender << " " << current -> data.weight << " " << current -> data.nickname << " " << current -> data.age << " " << endl;
        current = current -> next;
    }
}


void DoublyLinkedList::edit(Animal selected_animal) {
    Node* current = head;
    while(current) {
        if(current -> data.type == selected_animal.type and current -> data.gender == selected_animal.gender and current -> data.weight == selected_animal.weight and current -> data.nickname == selected_animal.nickname and current -> data.age == selected_animal.age) {
            cout << "Введите новые данные животного:" << endl;
            cout << "Введите вид животного: ";
            cin >> selected_animal.type;
            cout << "Введите пол животного: ";
            cin >> selected_animal.gender;
            cout << "Введите вес животного: ";
            cin >> selected_animal.weight;
            cout << "Введите кличку животного: ";
            cin >> selected_animal.nickname;
            cout << "Введите возраст животного: ";
            cin >> selected_animal.age;
            
            current -> data.type = selected_animal.type;
            current -> data.gender = selected_animal.gender;
            current -> data.weight = selected_animal.weight;
            current -> data.nickname = selected_animal.nickname;
            current -> data.age = selected_animal.age;
            return;
        }
        current = current -> next;
    }
}


void DoublyLinkedList::sort(string key) {
    if(key == "вид") {
        if(!head or !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node* current = head;

            while(current -> next) {
                if(current -> data.type > current -> next -> data.type) {
                    swap(current -> data, current -> next -> data);
                    swapped = true;
                }
                current = current -> next;
            }
        } while(swapped);
    } else if(key == "кличка") {
        if(!head or !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node* current = head;

            while(current -> next) {
                if(current -> data.nickname > current -> next -> data.nickname) {
                    swap(current -> data, current -> next -> data);
                    swapped = true;
                }
                current = current -> next;
            }
        } while(swapped);
    } else {
        cout << "Такого ключа нет!" << endl;
    }
}


void DoublyLinkedList::remove(Animal value) {
    Node* current = head;
    while(current) {
        if(current -> data.type == value.type and current -> data.gender == value.gender and current -> data.weight == value.weight and current -> data.nickname == value.nickname and current -> data.age == value.age) {
            if(current -> prev) {
                current -> prev -> next = current -> next;
            } else {
                head = current -> next;
            }
            if(current -> next) {
                current -> next -> prev = current -> prev;
            } else {
                tail = current -> prev;
            }
            delete current;
            return;
        }
        current = current -> next;
    }
}


void DoublyLinkedList::print() {
    Node* current = head;
    while(current) {
        cout << current -> data.type << " " << current -> data.gender << " " << current -> data.weight << " " << current -> data.nickname << " " << current -> data.age << endl;
        current = current -> next;
    }
    cout << endl;
}


void DoublyLinkedList::print_head() {
    Node* current = head;
    cout << current -> data.type << " " << current -> data.gender << " " << current -> data.weight << " " << current -> data.nickname << " " << current -> data.age << endl << endl;
}


void DoublyLinkedList::print_tail() {
    Node* current = tail;
    cout << current -> data.type << " " << current -> data.gender << " " << current -> data.weight << " " << current -> data.nickname << " " << current -> data.age << endl << endl;
}


void DoublyLinkedList::clear() {
    Node* current = head;
    while(current) {
        Node* next = current -> next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}


DoublyLinkedList::~DoublyLinkedList() {
    clear();
}
