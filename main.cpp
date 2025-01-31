#include <iostream>
#include <fstream>
#include "Animal_struct.hpp"
#include "DoublyLinkedList_struct.hpp"

using namespace std;


int main() {
    DoublyLinkedList MyDoublyLinkedList;
    int do_edit;
    
    cout << "Двусвязный список." << endl;
    cout << "1 - Вставить элемент в начало" << endl;
    cout << "2 - Вставить элемент в конец" << endl;
    cout << "3 - Вывести список в консоль" << endl;
    cout << "4 - Вывести голову списка в консоль" << endl;
    cout << "5 - Вывести хвост списка в консоль" << endl;
    cout << "6 - Удалить первый по вхождению элемент" << endl;
    cout << "7 - Заполнить список данными из файла" << endl;
    cout << "8 - Заполнить файл данными из списка" << endl;
    cout << "9 - Просмотреть файл, в который записаны данные" << endl;
    cout << "10 - Изменить элемент списка" << endl;
    cout << "11 - Сортировать список по одному из двух ключей(вид, кличка)" << endl;
    cout << "12 - Очистить список" << endl;
    cout << "13 - Выйти из программы" << endl << endl;
    
    cout << "Выберите действие: ";
    cin >> do_edit;
    
    while(true) {
        switch(do_edit) {
            case 1: {
                Animal new_front_animal;
                
                cout << "Введите вид животного: ";
                cin >> new_front_animal.type;
                cout << "Введите пол животного: ";
                cin >> new_front_animal.gender;
                cout << "Введите вес животного: ";
                cin >> new_front_animal.weight;
                cout << "Введите кличку животного: ";
                cin >> new_front_animal.nickname;
                cout << "Введите возраст животного: ";
                cin >> new_front_animal.age;
                
                MyDoublyLinkedList.push_front(new_front_animal);
                cout << endl;
                break;
            }
                
            case 2: {
                Animal new_back_animal;
                
                cout << "Введите вид животного: ";
                cin >> new_back_animal.type;
                cout << "Введите пол животного: ";
                cin >> new_back_animal.gender;
                cout << "Введите вес животного: ";
                cin >> new_back_animal.weight;
                cout << "Введите кличку животного: ";
                cin >> new_back_animal.nickname;
                cout << "Введите возраст животного: ";
                cin >> new_back_animal.age;
                
                MyDoublyLinkedList.push_back(new_back_animal);
                cout << endl;
                break;
            }
                
            case 3: {
                MyDoublyLinkedList.print();
                break;
            }
            case 4: {
                MyDoublyLinkedList.print_head();
                break;
            }
            case 5: {
                MyDoublyLinkedList.print_tail();
                break;
            }
            case 6: {
                Animal removed_animal;
                
                cout << "Введите данные животного, которого вы хотите удалить." << endl;
                cout << "Введите вид животного: ";
                cin >> removed_animal.type;
                cout << "Введите пол животного: ";
                cin >> removed_animal.gender;
                cout << "Введите вес животного: ";
                cin >> removed_animal.weight;
                cout << "Введите кличку животного: ";
                cin >> removed_animal.nickname;
                cout << "Введите возраст животного: ";
                cin >> removed_animal.age;
                
                MyDoublyLinkedList.remove(removed_animal);
                cout << endl;
                break;
            }
            case 7: {
                MyDoublyLinkedList.fill_from_file("/Users/agolovanov/Desktop/pb_homework/pb_homework/file_for_fill_list.txt");
                cout << "Данные из файла записаны!" << endl << endl;
                break;
            }
            case 8: {
                MyDoublyLinkedList.record_to_file("/Users/agolovanov/Desktop/pb_homework/pb_homework/file_for_recording.txt");
                cout << "Данные записаны в файл!" << endl << endl;
                break;
            }
            case 9: {
                ifstream file("/Users/agolovanov/Desktop/pb_homework/pb_homework/file_for_recording.txt");
                cout << file.rdbuf() << endl;
                break;
            }
            case 10: {
                Animal selected_animal;
                
                cout << "Введите данные животного, которые вы хотите поменять:" << endl;
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
                
                MyDoublyLinkedList.edit(selected_animal);
                break;
            }
            case 11: {
                string key;
                cout << "Выберите ключ для сортировки списка(вид или кличка): ";
                cin >> key;
                
                MyDoublyLinkedList.sort(key);
                break;
            }
            case 12: {
                MyDoublyLinkedList.clear();
                cout << endl;
                break;
            }
            case 13: {
                return 0;
            }
        }
        
        cout << "Выберите действие: ";
        cin >> do_edit;
    }
    return 0;
}
