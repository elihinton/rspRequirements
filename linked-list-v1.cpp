#include <iostream>

class Node {
    public:
        int value;
        Node* next;
};

void printLinkedList(Node* head){
    while(head != NULL){
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main(void){

    Node* head = new Node;
    Node* second= new Node;
    Node* third = new Node;
    Node* fourth = new Node;
    Node* fifth = new Node;

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = fourth;
    fourth->value = 4;
    fourth->next = fifth;
    fifth->value = 5;
    fifth->next = NULL;

    printLinkedList(head);

    return 0;
}
