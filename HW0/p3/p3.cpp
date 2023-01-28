#include<bits/stdc++.h>

using namespace std;
#define BUFFER_SIZE 100000

typedef struct _cell{
    int cost;
    int id;
    int layer;
    vector<int> neighbors;
}cell;

//create adjacency list to store the circular maze graph
void parser(char *filename, vector <cell> &cells){
    FILE *input = fopen(filename, "r");

    char buffer[BUFFER_SIZE];
    
    int cell_count = 0;
    int layer = 0;

    while(fscanf(input, "%[^\n]\n", buffer) != EOF){
        vector<int> state;
        char *token = strtok(buffer, " ");
        while(token != NULL){
            state.push_back(atoi(token));
            token = strtok(NULL, " ");
        }

        for(size_t i = 0; i < state.size(); i++){
            cell temp;
            temp.layer = layer;
            temp.id = cell_count + i;
            temp.cost = state[i] == 0 ? INT_MAX : state[i];

            if(i == 0){
                temp.neighbors.push_back(temp.id + 1);
                temp.neighbors.push_back(temp.id + state.size() - 1);
            }

            else if(i == state.size() - 1){
                temp.neighbors.push_back(temp.id - state.size() + 1);
                temp.neighbors.push_back(temp.id - 1);
            }

            else{
                temp.neighbors.push_back(temp.id - 1);
                temp.neighbors.push_back(temp.id + 1);
            }
            cells.push_back(temp);
        }
        cell_count += state.size();
        layer++;
    }

    fclose(input);
}

ostream& operator<<(ostream& out, cell& c){
    out << "cellID : " << c.id << " cellCost : " << c.cost << " cellLayer : " << c.layer << endl;
    out << "neighbors : ";
    for(size_t i = 0; i < c.neighbors.size(); i++){
        out << c.neighbors[i] << " ";
    }
    out << endl;
    return out;
}

void printCells(vector <cell> cells){
    for(size_t i = 0; i < cells.size(); i++){
        cout << cells[i] << endl;
    }
}

int main(int argc, char *argv[]){
    vector <cell> cells;    //adjacency list
    parser(argv[1], cells);
    printCells(cells);
    findVerticalNeighbor();
    findShortestPath();
    return 0;
}