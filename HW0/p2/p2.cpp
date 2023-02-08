#include<bits/stdc++.h>

#define BUFFER_SIZE 20

using namespace std;

typedef struct _point{
    int x;
    double y;
}point;

double k = 0.5;
double w_max = 1.15;
double w_min = 0.85;

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
double **p;             //p_i: the best position that bird i has ever been
double *p_best_loss;    //record the best cost for individual bird i

double *g;              // the best position that this flock of the birds have ever been
double g_best_loss = DBL_MAX;     //record the best cost for global cost

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
    fclose(data);
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


//calculate the R(x) in given x point with the coeffieient pi
double R(double *p, double x){
    double ret = 0;
    for(int i = 0; i < Dim; i++){
        ret += p[i] * pow(x, i);
    }
    return ret;
}

//calculate the loss of the given coefficient pi loss=sum(1~N) |y-R(x)|
double loss(double *p){
    double ret = 0;
    for(int i = 0; i < N; i++){
        ret += abs(points[i].y - R(p, double(points[i].x)));
    }
    return ret;
}

void iterate(){

    //init p_i,j: represent the best position that bird i has ever been
    p = new double *[Num_b];
    for(int i = 0; i < Num_b; i++){
        p[i] = new double[Dim];
    }

    for(int i = 0; i < Num_b; i++){
        for(int j = 0; j < Dim; j++){
            p[i][j] = x[i][j];
        }
    }

    p_best_loss = new double[Num_b];
    for(int i = 0; i < Num_b; i++){
        p_best_loss[i] = loss(p[i]);
    }

    g = new double[Dim];

    //find the smallest cost in p and copy to g
    int min_index = 0;
    double min_value = p_best_loss[0];
    for(int i = 0; i < Num_b; i++){
        if(p_best_loss[i] < min_value){
            min_index = i;
            min_value = p_best_loss[i];
        }
    }

    for(int i = 0; i < Dim; i++){
        g[i] = p[min_index][i];
    }
    g_best_loss = min_value;

    w = new double[Max_cycle];
    for(int cycle = 0; cycle < Max_cycle; cycle++){
        w[cycle] = w_max - (w_max - w_min) * cycle / Max_cycle;
    }
    
    for(int cycle = 0; cycle < Max_cycle; cycle++){
        for(int i = 0; i < Num_b; i++){
            for(int j = 0; j < Dim; j++){
                v[i][j] = v[i][j] * w[cycle] + C1 * (p[i][j] - x[i][j]) * R1[cycle][i][j] + C2 * (g[j] - x[i][j]) * R2[cycle][i][j];
                if(v[i][j] > Vmax[j]) v[i][j] = Vmax[j];
                else if(v[i][j] < -Vmax[j]) v[i][j] = -Vmax[j];

                x[i][j] = x[i][j] + v[i][j];
                if(x[i][j] > Max_boundary[j]) x[i][j] = Max_boundary[j];
                else if(x[i][j] < Min_boundary[j]) x[i][j] = Min_boundary[j];
            }
            if(loss(x[i]) < p_best_loss[i]){
                for(int j = 0; j < Dim; j++){
                    p[i][j] = x[i][j];
                }
                p_best_loss[i] = loss(x[i]);

                if(p_best_loss[i] < g_best_loss){
                    for(int j = 0; j < Dim; j++){
                        g[j] = p[i][j];
                    }
                    g_best_loss = p_best_loss[i];
                }
            }
        }
    }
}

void outputAnswer(){
    for(int i = 0; i < Dim; i++){
        cout << g[i] << endl;
    }
}

void freeMemory(){
    delete [] Min_boundary;
    delete [] Max_boundary;
    delete [] points;

    for(int i = 0; i < Num_b; i++){
        delete [] x[i];
        delete [] v[i];
        delete [] p[i];
    }
    delete []x;
    delete []v;
    delete []p;

    delete [] Vmax;

    for(int i = 0; i < Max_cycle; i++){
        for(int j = 0; j < Num_b; j++){
            delete [] R1[i][j];
            delete [] R2[i][j];
        }
        delete [] R1[i];
        delete [] R2[i];
    }
    delete [] R1;
    delete [] R2;

    delete [] w;
    delete [] p_best_loss;
    delete [] g;
}

int main(int argc, char *argv[]){
    readSet(argv[1]);
    readData(argv[2]);
    initialization();
    setting();
    readR1(argv[3]);
    readR2(argv[4]);
    iterate();
    outputAnswer();
    freeMemory();
    return 0;
}