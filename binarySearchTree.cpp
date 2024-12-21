#include <iostream>

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {};
};

Node* searchNodeValue(Node* head, const int& value){
    if (head == nullptr){
        throw std::runtime_error("Head node is null and value cannot be found");
        return nullptr;
    }
    while(head != nullptr){
        if (head->data == value) {
            return head;
        } else if (head->data > value){
            head = head->left;
        } else if (head->data < value){
            head = head->right;
        }
    }
    if (head == nullptr){
        throw std::runtime_error("Could not find value in binary search tree");
        return nullptr;
    }
}

int main(void){
    Node* head = new Node(10);
    Node* a = new Node(8);
    Node* b = new Node(6);
    Node* c = new Node(4);
    Node* d = new Node(12);
    Node* e = new Node(11);
    head->left = a;
    head->right = e;
    a->left = b;
    a->right = e;
    b->left = c;
    b->right = a;
    e->left = head;
    e->right = d;

    try {
        Node* result = searchNodeValue(head,12);
        std::cout << "result: " << result->data << std::endl;
    } catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }

}
