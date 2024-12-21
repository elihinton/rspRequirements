#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {};
        Node() : Node(0) {}; 
};

class AdjacencyList {
    public:
        Node*** verticeLists;
        int verticesNum;
        AdjacencyList(int numVertices) : verticesNum(numVertices) {
            verticeLists = new Node**[numVertices-1];
        }
        void addEdge(pair<int,int> edge){
            for (int i = 0; i < verticesNum; i++){
                if (edge.first == verticeLists[i][0]->value){
                    for (int j = 0; j < verticesNum; j++){
                        if (verticeLists[i][j]->next == nullptr){
                            Node* newNode = new Node(edge.second);
                            verticeLists[i][j]->next = newNode;
                        }
                    }
                }
            }
        }
        void viewEdges(){
            for (int i = 0; i < verticesNum; i++){
                cout << verticeLists[i] << ": ";
                for (int j = 0; i < verticesNum; i++){
                    cout << verticeLists[j] << ",";
                }
            }
        }
};


int main(void){

    AdjacencyList graph(4);

    graph.addEdge(make_pair(1,2));
    graph.addEdge(make_pair(2,1));
    graph.addEdge(make_pair(3,2));
    graph.addEdge(make_pair(4,3));
    graph.addEdge(make_pair(3,4));

    graph.viewEdges();
    
    return 0;
}