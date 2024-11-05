#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    node* next;
    node* prev;

    node(int value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

struct DoublyLinkedList {
    node* head;
    node* tail;

    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert(int value) {
        node* newnode = new node(value);

        if (head == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void delete_node(int value) {
        node* curr = head;

        if (head == nullptr) {
            return;
        }

        if (curr != nullptr && curr->value == value) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                head = curr->next;
                head->prev = nullptr;
                delete curr;
            }
            return;
        }

        while (curr != nullptr && curr->value != value) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout<<"node not found";
            return;
        }

        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        } else {
            tail = curr->prev;
        }

        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        }

        delete curr;
    }

    bool find_node(int value) {
        node* curr = head;

        while (curr != nullptr) {
            if (curr->value == value) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void print() {
        node* curr = head;
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void print_reverse() {
        node* curr = tail;
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr = curr->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        node* curr = head;
        while (curr != nullptr) {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.print();

    list.delete_node(20);
    list.print();

    list.delete_node(10);
    list.print();

    list.delete_node(40);
    list.print();

    list.delete_node(30);
    list.print();

    list.insert(50);
    list.insert(60);
    return 0;
}
