#include <iostream>


void printParents(int parents[], int x, int y){
    if (x == y || x < 0){
        std::cout << y << std::endl;
        return;
    }
    std::cout << y << " ";
    y = parents[y];
    printParents(parents,x,y);
}

int main(void){
    int parents[] = {};
    int nodes[] = {1,2,3,4};
    for (int i = 0; i < 4; i++){
        parents[nodes[i]] = i;
    }
    printParents(parents,1,4);
}