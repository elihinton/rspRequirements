#include <iostream>
#include <unordered_map>
#include <utility>

// assumes undirected

template <typename T>
class Graph {
    public:
        Graph(){};
        std::unordered_map<T,std::vector<T>> adjacencyList;
        void addEdge(std::pair<T,T> edge){
            adjacencyList[edge.first].push_back(edge.second);
            adjacencyList[edge.second].push_back(edge.first);
        }
        void printEdges(){
            for (auto edge : adjacencyList){
                std::cout << edge.first << ": ";
                for (auto vertex : edge.second){
                    if (*(edge.second.end()-1) != vertex){
                        std::cout << vertex << ",";
                    } else {
                        std::cout << vertex << std::endl;
                    }
                }
            }
        }
};

int main(void){

    Graph<int> g;

    g.addEdge(std::make_pair(1,2));
    g.addEdge(std::make_pair(3,2));
    g.addEdge(std::make_pair(3,1));
    g.addEdge(std::make_pair(4,1));

    g.printEdges();

    return 0;
}