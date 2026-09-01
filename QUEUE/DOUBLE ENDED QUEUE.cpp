#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *prev;
    node *next;
};

node *front = NULL, *rear = NULL;

node* GetNode() {
    node *p;
    p = new node;
    return p;
}

void InsFront(node *&front, node *&rear, int x) {
    node *p;
    p = GetNode();

    p->data = x;
    p->prev = NULL;
    p->next = front;

    if (front != NULL) {
        front->prev = p;
    } 
    else {
        rear = p;
    }

    front = p;
}

void InsRear(node *&front, node *&rear, int x) {
    node *p;
    p = GetNode();

    p->data = x;
    p->prev = rear;
    p->next = NULL;

    if (rear != NULL) {
        rear->next = p;
    } 
    else {
        front = p;
    }

    rear = p;
}

int DelFront(node *&front, node *&rear) {
    if (front == NULL) {
        cout << "Deque is empty\n";
        return -1;
    }

    node *p;
    int x;

    p = front;
    x = p->data;

    front = front->next;

    if (front != NULL) {
        front->prev = NULL;
    } 
    else {
        rear = NULL;
    }

    delete p;

    return x;
}

int DelRear(node *&front, node *&rear) {
    if (rear == NULL) {
        cout << "Deque is empty\n";
        return -1;
    }

    node *p;
    int x;

    p = rear;
    x = p->data;

    rear = rear->prev;

    if (rear != NULL) {
        rear->next = NULL;
    } 
    else {
        front = NULL;
    }

    delete p;

    return x;
}

int main() {

    InsFront(front, rear, 10);
    InsFront(front, rear, 20);
    InsRear(front, rear, 30);
    InsRear(front, rear, 40);

    cout << "Deleted from front: " << DelFront(front, rear) << endl;
    cout << "Deleted from rear: " << DelRear(front, rear) << endl;

    return 0;
}E