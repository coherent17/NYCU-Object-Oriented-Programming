#include<bits/stdc++.h>

#define BUFFER_SIZE 20
#define k 0.5
#define w_max 1.15
#define w_min 0.85

using namespace std;

typedef struct _point{
    int x;
    double y;
}point;

//variable for set file
int Dim, Num_b, Max_cycle, *Min_boundary, *Max_boundary;
double C1, C2;

//variable for data file
int N;
point *points;

//position of bird_i
double **x;

//velocity of bird_i
double **v;

//setting variable
double *Vmax;

//vatiable for R1 R2
double ***R1, ***R2;

//iterate variable
double *w;

void readSet(char *filename){
    char buffer[BUFFER_SIZE];
    FILE *set = fopen(filename, "r");
    
    fscanf(set, "%s %d", buffer, &Dim);
    fscanf(set, "%s %d", buffer, &Num_b);
    fscanf(set, "%s %d", buffer, &Max_cycle);
    fscanf(set, "%s %lf", buffer, &C1);
    fscanf(set, "%s %lf", buffer, &C2);

    Min_boundary = new int[Dim];
    Max_boundary = new int[Dim];
    fscanf(set, "%s", buffer);
    for(int i = 0; i < Dim; i++){
        fscanf(set, "%d", &Min_boundary[i]);
    }

    fscanf(set, "%s", buffer);
    for(int i = 0; i < Dim; i++){
        fscanf(set, "%d", &Max_boundary[i]);
    }
    fclose(set);
}

void readData(char *filename){
    FILE *data = fopen(filename, "r");
    fscanf(data, "%d", &N);
    points = new point[N];

    for(int i = 0; i < N; i++){
        fscanf(data, "%d %lf", &points[i].x, &points[i].y);
    }
}

void printSetParameter(){
    cout << "Dim " << Dim << endl;
    cout << "Num_b " << Num_b << endl;
    cout << "Max_cycle " << Max_cycle << endl;
    cout << "C1 " << C1 << endl;
    cout << "C2 " << C2 << endl;
    cout << "Min_boundary ";
    for(int i = 0; i < Dim; i++){
        cout << Min_boundary[i] << " ";
    }
    cout << endl << "Max_boundary ";
    for(int i = 0; i < Dim; i++){
        cout << Max_boundary[i] << " ";
    }
    cout << endl;
}

void printDataParameter(){
    cout << N << endl;
    for(int i = 0; i < N; i++){
        cout << points[i].x << " " << points[i].y << endl;
    }
}

void initialization(){
    x = new double *[Num_b];
    v = new double *[Num_b];
    for(int i = 0; i < Num_b; i++){
        x[i] = new double[Dim];
        v[i] = new double[Dim];
    }

    for(int i = 0; i < Num_b; i++){
        for(int j = 0; j < Dim; j++){
            x[i][j] = Min_boundary[j] + (Max_boundary[j] - Min_boundary[j]) * i / (Num_b - 1);
            v[i][j] = 0;
        }
    }
}

void setting(){
    Vmax = new double[Dim];
    for(int i = 0; i < Dim; i++){
        Vmax[i] = (Max_boundary[i] - Min_boundary[i]) * k / 2;
    }
}

void readR1(char *filename){
    R1 = new double **[Max_cycle];
    for(int i = 0; i < Max_cycle; i++){
        R1[i] = new double *[Num_b];
        for(int j = 0; j < Num_b; j++){
            R1[i][j] = new double[Dim];
        }
    }

    char buffer[BUFFER_SIZE];
    FILE *rand = fopen(filename, "r");
    for(int i = 0; i < Max_cycle; i++){
        for(int j = 0; j < Num_b; j++){
            for(int m = 0; m < Dim; m++){
                fscanf(rand, "%lf", &R1[i][j][m]);
            }
        }
        fscanf(rand, "%s", buffer);
    }
    fclose(rand);
}

void readR2(char *filename){
    R2 = new double **[Max_cycle];
    for(int i = 0; i < Max_cycle; i++){
        R2[i] = new double *[Num_b];
        for(int j = 0; j < Num_b; j++){
            R2[i][j] = new double[Dim];
        }
    }

    char buffer[BUFFER_SIZE];
    FILE *rand = fopen(filename, "r");
    for(int i = 0; i < Max_cycle; i++){
        for(int j = 0; j < Num_b; j++){
            for(int m = 0; m < Dim; m++){
                fscanf(rand, "%lf", &R2[i][j][m]);
            }
        }
        fscanf(rand, "%s", buffer);
    }
    fclose(rand);
}

void iterate(){
    w = new double[Max_cycle];
    for(int cycle = 0; cycle < Max_cycle; cycle++){
        w[cycle] = w_max - (w_max - w_min) * cycle / Max_cycle;
    }

    for(int cycle = 0; cycle < Max_cycle; cycle++){
        //update v
        for(int i = 0; i < Num_b; i++){
            for(int j = 0; j < Dim; j++){
                v[i][j] = v[i][j] * w[cycle] + C1 * ...
            }
        }
    }

}

int main(int argc, char *argv[]){
    readSet(argv[1]);
    readData(argv[2]);
    initialization();
    setting();
    readR1(argv[3]);
    readR2(argv[4]);
    iterate();
    return 0;
}