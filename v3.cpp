#include <iostream>

// unsorted singly linked list with insert, delete, search and print all values

class Node {
    public:
        int value;
        Node* next;
        Node(int val) : value(val), next(NULL) {};
};

void printLinkedList(Node* head){
    if (head == NULL){
        std::cout << "List is empty" << std::endl;
        return;
    }
    while(head->next != NULL){
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << head->value << std::endl;
}

Node* searchByValue(Node* head, int val){
    if (head == NULL){
        std::cout << "List is empty" << std::endl;
        return NULL;
    }
    while(head->value != val && head->next != NULL){
        head = head->next;
    }
    if (head->next == NULL && head->value != val){
        std::cout << "Value " << val << " was not found " << std::endl;
        return NULL;
    }
    return head;
}

void insertNodeByValue(Node* head, int val){
    Node* node = new Node(val);
    if (head == NULL){
        head = node;
        return;
    }
    while(head->next != NULL){
        head = head->next;
    }
    head->next = node;
}

void deleteNode(Node* head, Node* toDelete){
    if (head == NULL){
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (head == toDelete){
        delete head;
        return;
    }
    while(head->next != toDelete){
        head = head->next;
    }
    toDelete = head->next;
    head->next = head->next->next;
    delete toDelete;
}

int main(void){

    Node* head = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);

    head->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;

    printLinkedList(head);

    Node* result = searchByValue(head,4);
    std::cout << "Search result (expected 4): " << result->value << std::endl;

    insertNodeByValue(head,21);
    printLinkedList(head);
    insertNodeByValue(head,11);
    printLinkedList(head);
    insertNodeByValue(head,-11);
    printLinkedList(head);

    deleteNode(head,c);
    printLinkedList(head);

    deleteNode(head,head);
    printLinkedList(b);

    return 0;
}