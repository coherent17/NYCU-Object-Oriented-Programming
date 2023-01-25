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
    char *msg = new char [partial_img_size * partial_img_size];

    while(fscanf(input, "%d %d %d %d %[^\n]", &leftJoint, &topJoint, &rightJoint, &downJoint, msg) != EOF){
        partial_img temp;
        temp.leftJoint = leftJoint;
        temp.topJoint = topJoint;
        temp.rightJoint = rightJoint;
        temp.downJoint = downJoint;
        temp.msg = string(msg).substr(1, partial_img_size * partial_img_size);
        img.push_back(temp);
        fgetc(input);
        if(leftJoint != 0) JointID.insert(make_pair(leftJoint, count));
        if(topJoint != 0) JointID.insert(make_pair(topJoint, count));
        if(rightJoint != 0) JointID.insert(make_pair(rightJoint, count));
        if(downJoint != 0) JointID.insert(make_pair(downJoint, count));

        count++;
    }
    delete msg;
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

    char *New_msgArray = new char[partial_img_size * partial_img_size];

    int index = 0;

    for(int i = 0; i < partial_img_size; i++){
        for(int j = 0; j < partial_img_size; j++){
            New_msgArray[index++] = msg2DArray[i][j];
        }
    }



    //put it back to original array
    temp.leftJoint = downJoint;
    temp.topJoint = leftJoint;
    temp.rightJoint = topJoint;
    temp.downJoint = rightJoint;
    temp.msg = string(New_msgArray);
    img[idx] = temp;

    for(int i = 0; i < partial_img_size; i++){
        delete msg2DArray[i];
    }
    delete []msg2DArray;
    delete New_msgArray;
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

int main(int argc, char *argv[]){
    vector<partial_img> img;

    //map the joint ID to partial img
    unordered_map <int, int> JointID;
    parser(argv[1], img, JointID);
    printImg(img);

    BFS(img, JointID);
    printImg(img);

    return 0;
}