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
        int layer2_push_back_index = layer2_index;

        if(cells[layer1_index].layer_size != cells[layer2_index].layer_size){
            for(int j = layer1_index; layer2_push_back_index != layer1_index; j = j + 2){
                cells[j].neighbors.push_back(layer2_push_back_index);
                cells[j + 1].neighbors.push_back(layer2_push_back_index++);
            }
        }
        else{
            for(int j = layer1_index; layer2_push_back_index != layer1_index; j++){
                cells[j].neighbors.push_back(layer2_push_back_index++);
            }
        }
    }
}

void Dijkstra(vector <cell> cells, vector <int> &distance, vector <int> &parent, int start){
    
    vector <bool> visited(cells.size(), false);
    
    int curr = start;
    distance[start] = cells[start].cost;
    
    while(!visited[curr]){
        visited[curr] = true;
        vector<int> currNeighbors = cells[curr].neighbors;
        for(size_t i = 0; i < currNeighbors.size(); i++){
            unsigned long long int new_cost = distance[curr] + cells[currNeighbors[i]].cost;
            unsigned long long int old_cost = distance[currNeighbors[i]];
            if(new_cost <= old_cost){
                distance[currNeighbors[i]] = distance[curr] + cells[currNeighbors[i]].cost;
                parent[currNeighbors[i]] = curr;
            }
        }

        int min_dist = INT_MAX;
        for(size_t i = 0; i < cells.size(); i++){
            if(!visited[i] && (distance[i] < min_dist)){
                curr = i;
                min_dist = distance[i];
            }
        }
    }

}

int findExit(vector <cell> cells, vector <int> entrys){
    int start_index = entrys[entrys.size() - 1];

    for(int i = start_index; i < cells[start_index].id + cells[start_index].layer_size; i++){
        if(cells[i].cost != INT_MAX) return i;
    }
    
    return -1;
}

void getPath(vector <int> parent, int exit_index, vector <int> &path){
    if(parent[exit_index] == -1){
        path.push_back(exit_index);
        return;
    }
    getPath(parent, parent[exit_index], path);
    path.push_back(exit_index);
}


int main(int argc, char *argv[]){
    vector <cell> cells;    //adjacency list
    vector <int> entrys;
    parser(argv[1], cells, entrys);

    findVerticalNeighbor(cells, entrys);

    vector<vector<int>> distance(6, vector<int>(cells.size(), INT_MAX));
    vector<vector<int>> parent(6, vector<int>(cells.size(), -1));

    for(int i = 0; i < 6; i++){
        if(cells[i].cost != INT_MAX) Dijkstra(cells, distance[i], parent[i], i);
    }

    //find the exit
    int exit_index = findExit(cells, entrys);

    int min_index = 0;
    int min_distance = INT_MAX;
    for(int i = 0; i < 6; i++){
        if(distance[i][exit_index] < min_distance){
            min_index = i;
            min_distance = distance[i][exit_index];
        }
    }

    if(min_distance == INT_MAX){
        cout << "fail" << endl;
    }
    else{
        vector <int> path;
        getPath(parent[min_index], exit_index, path);

        for(size_t i = 0; i < path.size(); i++){
            cout << path[i];
            if(i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
    
    return 0;
}