#include<bits/stdc++.h>

using namespace std;

#define EMPTY INT_MIN

int partial_img_size = EMPTY;

typedef struct _partial_img{
    int leftJoint = EMPTY;
    int topJoint = EMPTY;
    int rightJoint = EMPTY;
    int downJoint = EMPTY;
    
    int left = EMPTY;
    int top = EMPTY;
    int right = EMPTY;
    int down = EMPTY;
    string msg;
}partial_img;

void parser(char *filename, vector<partial_img> &img, unordered_map <int, int> &JointID){
    FILE *input = fopen(filename, "r");
    fscanf(input, "%d", &partial_img_size);
    int count = 0;
    int leftJoint, topJoint, rightJoint, downJoint;
    char *msg = new char [partial_img_size * partial_img_size + 1];

    while(fscanf(input, "%d %d %d %d ", &leftJoint, &topJoint, &rightJoint, &downJoint) != EOF){
        fscanf(input, "\"");
        for(int i = 0; i < partial_img_size * partial_img_size; i++){
            fscanf(input, "%c", &msg[i]);
        }
        msg[partial_img_size * partial_img_size] = '\0';
        fscanf(input, "\"");

        partial_img temp;
        temp.leftJoint = leftJoint;
        temp.topJoint = topJoint;
        temp.rightJoint = rightJoint;
        temp.downJoint = downJoint;
        temp.msg = string(msg).substr(0, partial_img_size * partial_img_size);
        img.push_back(temp);
        fgetc(input);
        if(leftJoint != 0) JointID.insert(make_pair(leftJoint, count));
        if(topJoint != 0) JointID.insert(make_pair(topJoint, count));
        if(rightJoint != 0) JointID.insert(make_pair(rightJoint, count));
        if(downJoint != 0) JointID.insert(make_pair(downJoint, count));

        count++;
    }
    delete []msg;
    fclose(input);
}

ostream& operator<<(ostream& out, partial_img& p){
    out << "LeftID = " << p.leftJoint << " TopID = " << p.topJoint << " RightID = " << p.rightJoint << " DownID = " << p.downJoint << endl;
    out << "Left = " << p.left << " Top = " << p.top << " Right = " << p.right << " Down = " << p.down << endl;
    out << "msg: " << endl;
    int index = 0;
    for(int i = 0; i < partial_img_size; i++){
        for(int j = 0; j < partial_img_size; j++){
            out << p.msg.c_str()[index++] << " ";
        }
        out << endl;
    }
    out << endl;
    return out;
}

void printImg(vector<partial_img> img){
    int count = 0;
    for(partial_img p : img){
        cout << "Image : " << count++ << endl;
        cout << p;
    } 
}

void rightRotate(vector<partial_img> &img, int idx){
    partial_img temp = img[idx];
    int leftJoint = temp.leftJoint;
    int topJoint = temp.topJoint;
    int rightJoint = temp.rightJoint;
    int downJoint = temp.downJoint;
    string msg = temp.msg;

    const char *msgArray = msg.c_str();

    char **msg2DArray = new char *[partial_img_size];
    for(int i = 0; i < partial_img_size; i++){
        msg2DArray[i] = new char[partial_img_size];
    }

    int count = 0;
    for(int i = 0; i < partial_img_size; i++){
        for(int j = 0; j < partial_img_size; j++){
            msg2DArray[i][j] = msgArray[count++];
        }
    }

    for(int i = 0; i < partial_img_size >> 1; i++){
        for(int j = i; j < partial_img_size - 1 - i; j++){
            char a = msg2DArray[i][j];
            char b = msg2DArray[j][partial_img_size-1-i]; 
            char c = msg2DArray[partial_img_size-1-i][partial_img_size-1-j];
            char d = msg2DArray[partial_img_size-1-j][i];

            msg2DArray[i][j] = d;
            msg2DArray[j][partial_img_size-1-i] = a; 
            msg2DArray[partial_img_size-1-i][partial_img_size-1-j] = b;
            msg2DArray[partial_img_size-1-j][i] = c;
        }
    }

    char *New_msgArray = new char[partial_img_size * partial_img_size + 1];

    int index = 0;

    for(int i = 0; i < partial_img_size; i++){
        for(int j = 0; j < partial_img_size; j++){
            New_msgArray[index++] = msg2DArray[i][j];
        }
    }
    New_msgArray[partial_img_size * partial_img_size] = '\0';

    //put it back to original array
    temp.leftJoint = downJoint;
    temp.topJoint = leftJoint;
    temp.rightJoint = topJoint;
    temp.downJoint = rightJoint;
    temp.msg = string(New_msgArray);
    img[idx] = temp;

    for(int i = 0; i < partial_img_size; i++){
        delete []msg2DArray[i];
    }
    delete []msg2DArray;
    delete []New_msgArray;
}

bool checkFinish(partial_img p){
    if(p.leftJoint != 0 && p.left == EMPTY) return false;
    if(p.topJoint != 0 && p.top == EMPTY) return false;
    if(p.rightJoint != 0 && p.right == EMPTY) return false;
    if(p.downJoint != 0 && p.down == EMPTY) return false;

    return true;
}

void BFS(vector<partial_img> &img, unordered_map <int, int> JointID){
    vector<bool> visited;
    visited.resize(img.size(), false);

    queue<int> q;

    visited[0] = true;
    q.push(0);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        //find the left neighbor
        if(img[curr].leftJoint != 0 && img[curr].left == EMPTY){
            int partial_img_neighbor_index = JointID[-img[curr].leftJoint];
            if(!visited[partial_img_neighbor_index]){
                while(img[partial_img_neighbor_index].rightJoint != -img[curr].leftJoint){
                    rightRotate(img, partial_img_neighbor_index);
                }
                img[curr].left = partial_img_neighbor_index;
                img[partial_img_neighbor_index].right = curr;

                visited[partial_img_neighbor_index] = checkFinish(img[partial_img_neighbor_index]);
                q.push(partial_img_neighbor_index);
            }
        }

        //find the top neightbor
        if(img[curr].topJoint != 0 && img[curr].top == EMPTY){
            int partial_img_neighbor_index = JointID[-img[curr].topJoint];
            if(!visited[partial_img_neighbor_index]){
                while(img[partial_img_neighbor_index].downJoint != -img[curr].topJoint){
                    rightRotate(img, partial_img_neighbor_index);
                }
                img[curr].top = partial_img_neighbor_index;
                img[partial_img_neighbor_index].down = curr;

                visited[partial_img_neighbor_index] = checkFinish(img[partial_img_neighbor_index]);
                q.push(partial_img_neighbor_index);
            }            
        }

        //find the right neighbor
        if(img[curr].rightJoint != 0 && img[curr].right == EMPTY){
            int partial_img_neighbor_index = JointID[-img[curr].rightJoint];
            if(!visited[partial_img_neighbor_index]){
                while(img[partial_img_neighbor_index].leftJoint != -img[curr].rightJoint){
                    rightRotate(img, partial_img_neighbor_index);
                }
                img[curr].right = partial_img_neighbor_index;
                img[partial_img_neighbor_index].left = curr;

                visited[partial_img_neighbor_index] = checkFinish(img[partial_img_neighbor_index]);
                q.push(partial_img_neighbor_index);
            }
        }

        //find the down neighbor
        if(img[curr].downJoint != 0 && img[curr].down == EMPTY){
            int partial_img_neighbor_index = JointID[-img[curr].downJoint];
            if(!visited[partial_img_neighbor_index]){
                while(img[partial_img_neighbor_index].topJoint != -img[curr].downJoint){
                    rightRotate(img, partial_img_neighbor_index);
                }
                img[curr].down = partial_img_neighbor_index;
                img[partial_img_neighbor_index].top = curr;

                visited[partial_img_neighbor_index] = checkFinish(img[partial_img_neighbor_index]);
                q.push(partial_img_neighbor_index);
            }
        }

    }
}

//find the left top most partial_img
int left_top(vector<partial_img> img){
    int idx = 0;
    while(img[idx].left != EMPTY){
        idx = img[idx].left;
    }

    while(img[idx].top != EMPTY){
        idx = img[idx].top;
    }
    return idx;
}

int **getPartialImagePlacement(vector<partial_img> img, int left_top_index, int &row, int &col){
    row = 1;
    col = 1;

    //calculate img row
    int idx = left_top_index;
    while(img[idx].right != EMPTY){
        idx = img[idx].right;
        col++;
    }

    //calculate img col
    idx = left_top_index;
    while(img[idx].down != EMPTY){
        idx = img[idx].down;
        row++;
    }

    int **partial_image_placement = new int *[row];
    for(int i = 0; i < row; i++){
        partial_image_placement[i] = new int[col];
    }

    int *flatten_result = new int[img.size()];
    int flatten_result_index = 0;

    idx = left_top_index;
    int head_idx = idx;

    while(img[head_idx].down != EMPTY){
        while(img[idx].right != EMPTY){
            flatten_result[flatten_result_index++] = idx;
            idx = img[idx].right;
        }
        flatten_result[flatten_result_index++] = idx;
        idx = img[head_idx].down;
        head_idx = img[head_idx].down;
    }

    while(img[idx].right != EMPTY){
        flatten_result[flatten_result_index++] = idx;
        idx = img[idx].right;
    }
    flatten_result[flatten_result_index++] = idx;

    flatten_result_index = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            partial_image_placement[i][j] = flatten_result[flatten_result_index++];
        }
    }

    delete []flatten_result;
    return partial_image_placement;
}

void outputAnswer(char *filename, int **partial_image_placement, vector<partial_img> img, int row, int col){
    
    FILE *output = fopen(filename, "w");
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < partial_img_size; j++){
            for(int k = 0; k < col; k++){
                for(int l = 0; l < partial_img_size; l++){
                    fprintf(output, "%c", img[partial_image_placement[i][k]].msg.c_str()[j * partial_img_size + l]);
                }
            }
            if(i != row - 1 || j != partial_img_size - 1) fprintf(output, "\n");
        }
    }
    fclose(output);
}

void free_partial_image_placement(int **partial_image_placement, int row){
    for(int i = 0; i < row; i++){
        delete []partial_image_placement[i];
    }
    delete []partial_image_placement;
}

int main(int argc, char *argv[]){
    vector<partial_img> img;
    int row, col;
    unordered_map <int, int> JointID;
    parser(argv[1], img, JointID);
    BFS(img, JointID);
    int left_top_partial_img_idx = left_top(img);
    int **partial_image_placement = getPartialImagePlacement(img, left_top_partial_img_idx, row, col);
    outputAnswer(argv[2], partial_image_placement, img, row, col);
    free_partial_image_placement(partial_image_placement, row);

    cout << row << " " << col << endl;
    return 0;
}