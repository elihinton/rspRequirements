#include <iostream>
#include <stdexcept>

// doubly linked list with search, insert, delete
// fully fucked it -- redo

class Node {
    public:
        int value;
        Node* next;
        Node* prev;
        Node(int val) : value(val), next(NULL), prev(NULL) {};
};

void printLinkedList(Node* head){
    while (head->next != NULL){
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << head->value << std::endl;
}

Node* searchDoublyLinkedList(Node* head, const int& value){
    if (head == NULL){
        throw std::runtime_error("unable to search as head node is null");
        return NULL;
    }
    while(head->value != value && head != NULL){
        head = head->next;
    }
    if (head == NULL){
        throw std::runtime_error("value was not found in list");
        return NULL;
    }
    return head;
}

void insertValueHead(Node** head, const int& value){
    if (head == NULL){
        throw std::runtime_error("head node is null, value cannot be inserted at head");
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = *(head);
    newNode->prev = NULL;
    (*head)->prev = newNode;
}

void insertValueTail(Node* head, const int& value){
    if (head == NULL){
        throw std::runtime_error("head node is null, value cannot be inserted at tail");
        return;
    }
    while(head->next != NULL){
        head = head->next;
    }
    Node* newNode = new Node(value);
    head->next = newNode;
    newNode->prev = head;
}

void deleteNode(Node** head, Node* toDelete){
    if (toDelete == NULL || head == NULL){
        throw std::runtime_error("unable to delete node");
        return;
    }
    if (*head == toDelete){
        Node* newHead = (*head)->next;
        newHead->prev = NULL;
        delete head;
        return;
    }
    while((*head)->next != toDelete){
        *head = (*head)->next;
    }
    if ((*head)->next == NULL){
        Node* previous = (*head)->prev;
        previous->next = NULL;
        return;
    }
    Node* previous = (*head)->prev;
    previous->next = previous->next->next;
    previous->next->next->prev = previous;
    delete head;
}

int main(void){

    Node* head = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    head->next = b;
    b->next = c;
    b->prev = head;
    c->next = d;
    c->prev = b;
    d->next = e;
    d->prev = c;
    e->next = f;
    e->prev = d;
    f->next = g;
    f->prev = e;
    g->prev = f;

    printLinkedList(head);

    try {
        Node* result = searchDoublyLinkedList(head,5);
        std::cout << "Search Result (expected: 5): " << result->value << std::endl;
        searchDoublyLinkedList(head,88);
    } catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try {
        insertValueHead(&head,21);
        insertValueTail(head,12);
        printLinkedList(head->prev);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Node* newHead = head->prev;
        deleteNode(&newHead,head); // deletes 1 
        deleteNode(&newHead,g); // deletes 7
        deleteNode(&newHead,e); // deletes 5
        // deletes 4 and 6 instead of 5 and 7
        printLinkedList(b);
    } catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}