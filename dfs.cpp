#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

// preorder dfs traversal

enum States { UNDISCOVERED , DISCOVERED , PROCESSED };

class Graph {
    public:
        std::unordered_map<int,std::vector<std::pair<int,int>>> graph;
        std::vector<States> vertexStates;
        void addEdge(int a, int b){
            int max = std::max(a,b);
            if (max > vertexStates.capacity()){
                vertexStates.resize(max+1);
            }
            graph[a].push_back(std::make_pair(a,b));
            graph[b].push_back(std::make_pair(b,a));
            vertexStates[a] = States::UNDISCOVERED;
            vertexStates[b] = States::UNDISCOVERED;
        }
        void printAdjacencyList(){
            for (const auto& list : graph){
                std::cout << list.first << ": ";
                for (const auto& el : list.second){
                    if (el != *(list.second.end()-1)){
                        std::cout << el.second << ","; 
                    } else {
                        std::cout << el.second << std::endl;
                    }
                }
            }
        }
        void dfs(int startVertex){
            if (vertexStates[startVertex] == States::UNDISCOVERED){
                std::cout << startVertex << " ";
                vertexStates[startVertex] = States::DISCOVERED;
                for (auto edge : graph[startVertex]){
                    if (vertexStates[edge.second] == States::UNDISCOVERED){
                        dfs(edge.second);
                    }
                }
                vertexStates[startVertex] = States::PROCESSED;
            }
        }
};

int main(void){

    Graph graph;
    graph.addEdge(3,4);
    graph.addEdge(1,2);
    graph.addEdge(3,2);
    graph.addEdge(5,6);
    graph.addEdge(1,7);
    graph.addEdge(2,8);

    graph.printAdjacencyList();

    graph.dfs(1);
    std::cout << std::endl;

    return 0;
}