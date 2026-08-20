#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* Getnode(int value) {
    node* p = new node;
    p->data = value;
    p->next = NULL;
    return p;
}

void EnQueue(node*& head, int value) {
    node* p = Getnode(value);

    if (head == NULL || value < head->data) {
        p->next = head;
        head = p;
        return;
    }

    node* temp = head;

    while (temp->next != NULL && temp->next->data <= value) {
        temp = temp->next;
    }

    p->next = temp->next;
    temp->next = p;
}

void DeQueue(node*& head) {
    if (head == NULL) {
        cout << "Priority Queue is Empty" << endl;
        return;
    }

    node* temp = head;
    head = head->next;

    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

void Traverse(node* head) {
    if (head == NULL) {
        cout << "Priority Queue is Empty" << endl;
        return;
    }

    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    node* pq = NULL;

    EnQueue(pq, 30);
    EnQueue(pq, 10);
    EnQueue(pq, 50);
    EnQueue(pq, 20);
    EnQueue(pq, 5);
    DeQueue(pq);

    cout << "Priority Queue: ";
    Traverse(pq);

    DeQueue(pq);

    cout << "After DeQueue: ";
    Traverse(pq);

    return 0;
}