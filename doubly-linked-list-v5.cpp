#include <iostream>

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int value) : data(value), next(nullptr), prev(nullptr) {};
        Node() : Node(0) {};
};

class LinkedList{
    public:
        Node* head = nullptr;
        void printLinkedList(){
            Node* current = head;
            while (current != nullptr){
                std::cout << current->data << " ";
                current = current->next;
            } 
            std::cout << std::endl;
        }
        void insertHead(int value){
            if (head == nullptr){
                throw std::runtime_error("unable to insert new node at head");
                return;
            }
            Node* newNode = new Node(value);
            head->prev = newNode;
            newNode->next = head;
            newNode->prev = nullptr;
            head = head->prev;
        }
        void insertTail(int value){
            if (head == nullptr || !value){
                throw std::runtime_error("unable to insert new node at tail");
                return;
            }
            Node* current = head;
            while (current->next != nullptr){
                current = current->next;
            }
            Node* newNode = new Node(value);
            current->next = newNode;
            newNode->prev = current;
        }

        Node* searchListByValue(int value){
            if (head == nullptr){
                throw std::runtime_error("search could not operate as head is null");
                return nullptr;
            }
            Node* current = head;
            while (current->data != value && current != nullptr){
                current = current->next;
            }
            if (current == nullptr){
                throw std::runtime_error("value was not found in list");
                return nullptr;
            }
            return current;
        }
        void deleteNode(Node* toDelete){
            if (head == toDelete){
                head = head->next;
                delete toDelete;
                return;
            } 
            toDelete->prev->next = toDelete->next;
            delete toDelete;
        }

};

int main(void){

    Node* head = new Node(1);
    Node* a = new Node(2);
    Node* b = new Node(3);
    Node* c = new Node(4);
    Node* d = new Node(5);
    Node* e = new Node(6);

    head->next = a;
    a->next = b;
    a->prev = head;
    b->next = c;
    b->prev = a;
    c->next = d;
    c->prev = b;
    d->next = e;
    d->prev = c;
    e->prev = d;

    LinkedList list;

    list.head = head;
    list.printLinkedList();

    try {
        Node* result = list.searchListByValue(5);
        std::cout << "expected result: 5 \t actual result: " << result->data << std::endl;
    } catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    try {
        list.insertHead(21);
        list.insertTail(12);
        list.printLinkedList();
    } catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    try {
        list.deleteNode(b);
        std::cout << "3 deleted: ";
        list.printLinkedList();
        list.deleteNode(list.head);
        std::cout << "head deleted: ";
        list.printLinkedList();
        list.deleteNode(e->next);
        std::cout << "tail deleted: ";
        list.printLinkedList();
    } catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
