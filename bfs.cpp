#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <queue>

// assumption: undirected graph 

enum Status { UNVISITED , VISITED , PROCESSED };

typedef std::vector<std::pair<int,int>> vertexVector;

class Graph {
    public:
        std::unordered_map<int,vertexVector> graph;
        std::vector<Status> vectorStatus;
        void addEdge(int a, int b){
            // will segfault w/o as uninitialised vector -> undefined behaviour
            int max = std::max(a,b);
            if (max > vectorStatus.capacity()){
                vectorStatus.reserve(max+1);
            }
            graph[a].push_back(std::make_pair(a,b));
            graph[b].push_back(std::make_pair(b,a));
            vectorStatus[a] = Status::UNVISITED;
            vectorStatus[b] = Status::UNVISITED;
        }
        void printAdjacencyList(){
            for (auto list : this->graph){
                std::cout << list.first << ": ";
                for (auto item : list.second){
                    if (item != *(list.second.end()-1)){
                        std::cout << item.second << ",";
                    } else {
                        std::cout << item.second << std::endl;
                    }
                }
            }
        }
        void bfs(int startVertex){
            std::queue<vertexVector> queue;
            queue.push(graph[startVertex]);
            std::cout << "BFS order: ";
            while (!queue.empty()){
                vertexVector current = queue.front();
                queue.pop();
                if (vectorStatus[current[0].first] == Status::UNVISITED){
                    std::cout << current[0].first << " ";
                    vectorStatus[current[0].first] = Status::VISITED;
                    for (auto item : current){
                        if (vectorStatus[item.second] == Status::UNVISITED){
                            queue.push(graph[item.second]);
                        }
                    }
                    vectorStatus[current[0].first] = Status::PROCESSED;
                }
            }
            std::cout << std::endl;
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

    graph.bfs(1);

    return 0;
}