#include <iostream>

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* searchNodeValue(Node* head, const int& value) {
    if (head == nullptr) {
        return nullptr;
    }
    while (head != nullptr) {
        if (head->data == value) {
            return head;
        } else if (head->data > value) {
            head = head->left;
        } else if (head->data < value) {
            head = head->right;
        }
    }
    return nullptr;
}


Node* insertNode(Node* head, const int& value) {
    if (head == nullptr) {
        return new Node(value);
    }
    if (value < head->data) {
        head->left = insertNode(head->left, value);
    } else if (value > head->data) {
        head->right = insertNode(head->right, value);
    }
    return head;
}


int main() {

    Node* head = nullptr;
    head = insertNode(head, 10);
    head = insertNode(head, 8);
    head = insertNode(head, 12);
    head = insertNode(head, 6);
    head = insertNode(head, 11);
    head = insertNode(head, 4);

    Node* result1 = searchNodeValue(head, 12);
    std::cout << ((result1 != nullptr)? "Found node with value: " : "Not found brotha") << result1->data << std::endl;

    Node* result2 = searchNodeValue(head, 8);
    std::cout << ((result2 != nullptr)? "Found node with value: " : "Not found brotha") << result2->data << std::endl;

    Node* result3 = searchNodeValue(head, 13);
    std::cout << ((result3 != nullptr)? "Found node with value: " : "Not found brotha") << std::endl;


    return 0;
}
