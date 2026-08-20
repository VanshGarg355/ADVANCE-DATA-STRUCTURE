#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

// Create a new node
node *GetNode() {
    node *p;
    p = (struct node*)malloc(sizeof(struct node));
    return p;
}

// Insert at Beginning
node *InsBeg(node *head, int x) {
    node *p;

    p = GetNode();
    p->data = x;
    p->next = head;
    head = p;

    return head;
}

// Insert at End
node *InsEnd(node *head, int x) {
    node *p, *q;

    p = GetNode();
    p->data = x;
    p->next = NULL;

    if (head == NULL) {
        head = p;
        return head;
    }

    q = head;

    while (q->next != NULL) {
        q = q->next;
    }

    q->next = p;

    return head;
}

// Insert after a given node
node *InsAft(node *head, int key, int x) {
    node *p, *q;

    q = head;

    while (q != NULL && q->data != key) {
        q = q->next;
    }

    if (q == NULL) {
        cout << "Node " << key << " not found." << endl;
        return head;
    }

    p = GetNode();
    p->data = x;

    p->next = q->next;
    q->next = p;

    return head;
}

// Delete from Beginning
node *DelBeg(node *head) {

    if (head == NULL) {
        cout << "List is empty." << endl;
        return head;
    }

    node *p;
    p = head;

    head = head->next;

    cout << "Deleted node is : " << p->data << endl;

    free(p);

    return head;
}

// Delete after a given node
node *DelAft(node *head, int key) {

    if (head == NULL) {
        cout << "List is empty." << endl;
        return head;
    }

    node *p, *q;

    q = head;

    while (q != NULL && q->data != key) {
        q = q->next;
    }

    if (q == NULL) {
        cout << "Node " << key << " not found." << endl;
        return head;
    }

    if (q->next == NULL) {
        cout << "No node exists after " << key << endl;
        return head;
    }

    p = q->next;
    q->next = p->next;

    cout << "Deleted node is : " << p->data << endl;

    free(p);

    return head;
}

// Delete from End
node *DelEnd(node *head) {

    if (head == NULL) {
        cout << "List is empty." << endl;
        return head;
    }

    // Only one node
    if (head->next == NULL) {
        cout << "Deleted node is : " << head->data << endl;
        free(head);
        return NULL;
    }

    node *p, *q;

    p = head;

    // Find second-last node
    while (p->next->next != NULL) {
        p = p->next;
    }

    q = p->next;

    cout << "Deleted node is : " << q->data << endl;

    p->next = NULL;

    free(q);

    return head;
}

// Traverse / Display
void Treverse(node *head) {

    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    node *p = head;

    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }

    cout << "NULL" << endl;
}

// Free all nodes
node *FreeNode(node *head) {

    node *p;

    while (head != NULL) {
        p = head;
        head = head->next;

        free(p);
    }

    return head;
}

int main() {

    node *head = NULL;

    // Insert at Beginning
    head = InsBeg(head, 10);
    head = InsBeg(head, 20);
    head = InsBeg(head, 30);

    cout << "After InsBeg:" << endl;
    Treverse(head);

    // Insert at End
    head = InsEnd(head, 40);
    head = InsEnd(head, 50);

    cout << "\nAfter InsEnd:" << endl;
    Treverse(head);

    // Insert after 20
    head = InsAft(head, 20, 25);

    cout << "\nAfter InsAft(20, 25):" << endl;
    Treverse(head);

    // Delete Beginning
    head = DelBeg(head);

    cout << "\nAfter DelBeg:" << endl;
    Treverse(head);

    // Delete after 20
    head = DelAft(head, 20);

    cout << "\nAfter DelAft(20):" << endl;
    Treverse(head);

    // Delete End
    head = DelEnd(head);

    cout << "\nAfter DelEnd:" << endl;
    Treverse(head);

    // Free complete linked list
    head = FreeNode(head);

    cout << "\nAfter FreeNode:" << endl;
    Treverse(head);

    return 0;
}