#include<bits/stdc++.h>

using namespace std;

#define EMPTY 0

int partial_img_size = EMPTY;

typedef struct _partial_img{
    int leftJoint = EMPTY;
    int topJoint = EMPTY;
    int rightJoint = EMPTY;
    int downJoint = EMPTY;
    string msg;
}partial_img;

void parser(char *filename, vector<partial_img> &img){
    FILE *input = fopen(filename, "r");
    fscanf(input, "%d", &partial_img_size);

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
    }
    delete msg;
    fclose(input);
}

ostream& operator<<(ostream& out, partial_img& p){
    out << p.leftJoint << " " << p.topJoint << " " << p.rightJoint << " " << p.downJoint << " " << p.msg << endl;
    return out;
}

void printImg(vector<partial_img> img){
    for(partial_img p : img){
        cout << p;
    } 
}

int main(int argc, char *argv[]){
    vector<partial_img> img;
    parser(argv[1], img);
    printImg(img);
    
    return 0;
}