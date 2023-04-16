#include "numpy.h"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

numpy::numpy(){
    array = nullptr;
    row = 0;
    column = 0;
}

numpy::~numpy(){
    for(int i = 0; i < row; i++){
        delete []array[i];
    }
    delete []array;
    array = nullptr;
}

numpy::numpy(const char *input_file){
    ifstream fin(input_file, ios::binary);

    //read row and column
    fin.read(reinterpret_cast<char*>(&row), sizeof(row));
    fin.read(reinterpret_cast<char*>(&column), sizeof(column));

    array = new int*[row];
    for(int i = 0; i < row; i++){
        array[i] = new int[column];
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            fin.read(reinterpret_cast<char*>(&array[i][j]), sizeof(array[i][j]));
        }
    }
}
numpy::numpy(int x, int y){
    row = x;
    column = y;
    array = new int*[row];
    for(int i = 0; i < row; i++){
        array[i] = new int[column];
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            array[i][j] = 0;
        }
    }
}

numpy::numpy(const numpy &n){
    row = n.row;
    column = n.column;
    array = new int*[row];
    for(int i = 0; i < row; i++){
        array[i] = new int[column];
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            array[i][j] = n.array[i][j];
        }
    }
}

numpy::numpy(const numpy &a, int* rows, int* cols){
    row = rows[1] - rows[0];
    column = cols[1] - cols[0];
    array = new int*[row];
    for(int i = 0; i < row; i++){
        array[i] = new int[column];
    }

    int idx1 = 0, idx2 = 0;

    for(int i = rows[0]; i < rows[1]; i++){
        for(int j = cols[0]; j < cols[1]; j++){
            if(idx2 == cols[1] - 1){
                idx1++;
                idx2 = 0;
            }
            array[idx1][idx2] = a.array[i][j];
            idx2++;
        }
    }
}


//Q1
int numpy::max(){
    int max = -1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            max = max > array[i][j] ? max : array[i][j];
        }
    }
    return max;
}

int *numpy::argmax(){
    int *ret = new int[2];
    int max = -1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            max = max > array[i][j] ? max : array[i][j];
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(array[i][j] == max){
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return nullptr;
}

//Q2
int numpy::get_row(){
    return row;
}

int numpy::get_column(){
    return column;
}

ostream& operator<<(ostream& out, numpy& n){
    for(int i = 0; i < n.row; i++){
        for(int j = 0; j < n.column; j++){
            out << n.array[i][j] << " ";
        }
        if(i != n.row - 1)
            out << endl;
    }
    return out;
}

int* numpy::operator[](int i){
    return array[i];
}

void numpy::sort(int axis){
    if(axis == 0){
        for(int j = 0; j < column; j++){
            vector<int> v;
            for(int i = 0; i < row; i++){
                v.push_back(array[i][j]);
            }
            std::sort(v.begin(), v.end());
            for(int i = 0; i < row; i++){
                array[i][j] = v[i];
            }
        }
        return;
    }

    for(int i = 0; i < row; i++){
        vector<int> v;
        for(int j = 0; j < column; j++){
            v.push_back(array[i][j]);
        }
        std::sort(v.begin(), v.end());
        for(int j = 0; j < column; j++){
            array[i][j] = v[j];
        }
    }

}

numpy numpy::reshape(int newColumn, int b){
    numpy ret = numpy(newColumn, row * column / newColumn);

    int idx1 = 0, idx2 = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(idx2 == ret.column){
                idx1++;
                idx2 = 0;
            }
            ret.array[idx1][idx2] = array[i][j];
            idx2++;
        }
    } 
    return ret;
}

numpy numpy::operator*(numpy& n){
    numpy ret = numpy(row, n.column);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < n.column; j++) {
            for (int k = 0; k < column; k++) {
                ret.array[i][j] += array[i][k] * n.array[k][j];
            }
        }
    }
    return ret;
}

numpy concatenate(numpy& a, numpy& b, int axis){
    if(axis == 0){
        numpy ret = numpy(a.row + b.row, a.column);
        for(int i = 0; i < a.row + b.row; i++){
            for(int j = 0; j < a.column; j++){
                ret.array[i][j] = (i < a.row) ? a.array[i][j] : b.array[i - a.row][j];
            }
        }
        return ret;
    }

    numpy ret = numpy(a.row, a.column + b.column);
    for(int i = 0; i < a.row; i++){
        for(int j = 0; j < a.column + b.column; j++){
            ret.array[i][j] = (j < a.column) ? a.array[i][j] : b.array[i][j - a.column];
        }
    }
    return ret;
}