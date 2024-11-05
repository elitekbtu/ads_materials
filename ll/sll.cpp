#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    void insert(int value)
    {
        node *newnode = new node(value);
        if (this->next == nullptr)
        {
            this->next = newnode;
        }
        else
        {
            node *curr = this->next;
            while (curr->next != nullptr) 
            {
                curr = curr->next;
            }
            curr->next = newnode;
        }
    }
    void delnode()
    {
        if (this->next == nullptr)
        {
            return;
        }

        node *curr = this;
        while (curr->next && curr->next->next)
        {
            curr = curr->next;
        }
        node *lastNode = curr->next;
        curr->next = nullptr; 
        delete lastNode;
    }
    bool find(int value)
    {
        node *curr = this->next;

        while (curr != nullptr)
        {
            if (curr->data == value)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    void reverse()
    {
        node *prev = nullptr;
        node *curr = this->next;
        node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = next; 
        }
        this->next = prev;
    }
    void print()
    {
        node *curr = this->next; 
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    node* head = new node(0); 
    head->insert(10);
    head->insert(20);
    head->insert(30);
    head->print();
    head->find(10);
    head->reverse();
    head->print();
    head->delnode();
    head->print();

    return 0;
}
