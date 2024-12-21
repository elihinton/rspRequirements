#include <iostream>

class Node {
    public:
        int data;
        Node* next;
        Node(int val) : data(val), next(NULL) {};
};

void printList(Node* head){
    while (head->next != NULL){
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << head->data << std::endl;
}

void listInsertionEnd(Node* head, int value){
    if (head == NULL){
        head = new Node(value);
        return;
    }
    while (head->next != NULL){
        head = head->next;
    }
    Node* newNode = new Node(21);
    head->next = newNode;
    newNode->next = NULL;
}

Node* getNodeBefore(Node* head, Node* getNodeBeforeThis){
    if (head == NULL || getNodeBeforeThis == NULL){
        return NULL;
    }
    if (head->next == getNodeBeforeThis){
        return head;
    } else {
        return getNodeBefore(head->next,getNodeBeforeThis);
    }
}

void listDeletionByValue(Node* head, int val){
    // couldn't get this shit to work so i redid in v3
}

Node* searchByValue(Node* head, int val){
    while(head->data != val){
        head = head->next;
    }
    return head;
}

int main(void){

    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    printList(head);

    Node* result = searchByValue(head,4);
    std::cout << "Search result: " << result->data << std::endl;

    listInsertionEnd(head,21);
    printList(head);

    listDeletionByValue(head,5);
    printList(head);

    return 0;
}

// issue: deletion, will delete value but cannot link to rest of list