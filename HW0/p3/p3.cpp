#include<bits/stdc++.h>

using namespace std;
#define BUFFER_SIZE 100000

typedef struct _cell{
    int cost;
    int id;
    int layer;
    int layer_size;
    vector<int> neighbors;
}cell;

//create adjacency list to store the circular maze graph
void parser(char *filename, vector <cell> &cells, vector <int> &entrys){
    FILE *input = fopen(filename, "r");

    char buffer[BUFFER_SIZE];
    
    int cell_count = 0;
    int layer = 1;

    while(fscanf(input, "%[^\n]\n", buffer) != EOF){
        vector<int> state;
        char *token = strtok(buffer, " ");
        while(token != NULL){
            state.push_back(atoi(token));
            token = strtok(NULL, " ");
        }
        entrys.push_back(cell_count);

        for(size_t i = 0; i < state.size(); i++){
            cell temp;
            temp.layer = layer;
            temp.id = cell_count + i;
            temp.cost = state[i] == 0 ? INT_MAX : state[i];
            temp.layer_size = int(state.size());

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
    out << "cellID : " << c.id << ", cellCost : " << c.cost << ", cellLayer : " << c.layer << ", cellLayerSize : " << c.layer_size << endl;
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

void findVerticalNeighbor(vector <cell> &cells, vector <int> entrys){
    for(size_t i = 1; i < entrys.size(); i++){
        int layer1_index = entrys[i - 1];
        int layer2_index = entrys[i];

        int layer2_push_back_index = layer2_index;
        
        if(cells[layer1_index].layer_size != cells[layer2_index].layer_size){
            for(int j = layer1_index; j < layer2_index; j++){
                cells[j].neighbors.push_back(layer2_push_back_index++);
                cells[j].neighbors.push_back(layer2_push_back_index++);
            }
        }
        else{
            for(int j = layer1_index; j < layer2_index; j++){
                cells[j].neighbors.push_back(layer2_push_back_index++);
            }
        }
    }

    for(size_t i = entrys.size() - 1; i > 0; i--){
        int layer1_index = entrys[i];
        int layer2_index = entrys[i - 1];

        //cout << layer1_index << " " << layer2_index << endl;

        int layer2_push_back_index = layer2_index;

        cout << cells[layer1_index].layer_size << " " << cells[layer2_index].layer_size << endl;

        if(cells[layer1_index].layer_size != cells[layer2_index].layer_size){
            for(int j = layer1_index; j < cells[layer1_index].id + cells[layer1_index].layer_size; j = j + 2){
                cells[j].neighbors.push_back(layer2_push_back_index);
                cells[j + 1].neighbors.push_back(layer2_push_back_index++);
            }
        }
        else{
            for(int j = layer1_index; j < cells[layer1_index].id + cells[layer1_index].layer_size; j++){
                cells[j].neighbors.push_back(layer2_push_back_index++);
            }
        }
    }
}




int main(int argc, char *argv[]){
    vector <cell> cells;    //adjacency list
    vector <int> entrys;
    parser(argv[1], cells, entrys);
    //printCells(cells);

    findVerticalNeighbor(cells, entrys);
    printCells(cells);
    // findShortestPath();
    return 0;
}