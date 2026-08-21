#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

node *front = NULL;
node *rear = NULL;

node* GetNode(int value) {
    node *p = new node;
    p->data = value;
    p->next = NULL;
    return p;
}

bool IsEmpty() {
    if(front == NULL) {
        return true;
    }
    else {
        return false;
    }
}

int EnQueue(int x) {
    node *temp;
    temp = GetNode(x);

    if(front == NULL) {
        front = temp;
        rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }

    return x;
}

int DeQueue() {

    if(front == NULL) {
        cout << "Queue is underflow";
        exit(1);
    }

    node *temp;
    temp = front;

    front = front->next;

    int x = temp->data;

    delete temp;

    if(front == NULL) {
        rear = NULL;
    }

    return x;
}

void Traverse() {

    if(front == NULL) {
        cout << "Queue is Empty";
        return;
    }

    node *temp;
    temp = front;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    EnQueue(10);
    EnQueue(20);
    EnQueue(30);

    cout << "Queue: ";
    Traverse();

    cout << "Deleted element: " << DeQueue() << endl;

    cout << "After DeQueue: ";
    Traverse();

    return 0;
}