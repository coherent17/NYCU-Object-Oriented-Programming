#include<bits/stdc++.h>
#define TEAM_NAME_SIZE 20

using namespace std;

typedef struct _group{
    string teams[4];
    int scores[4][4];
}group;

typedef struct _team_id{
    string team;
    int group_id;
}team_id;

void readFirstPart(char *filename, group *&groups, team_id *&teams_id){
    FILE *input = fopen(filename, "r");

    //read the team in the same group and init the score
    for(int i = 0; i < 8; i++){
        char t1[TEAM_NAME_SIZE];
        char t2[TEAM_NAME_SIZE];
        char t3[TEAM_NAME_SIZE];
        char t4[TEAM_NAME_SIZE];
        fscanf(input, "%s %s %s %s", t1, t2, t3, t4);
        groups[i].teams[0] = string(t1);
        groups[i].teams[1] = string(t2);
        groups[i].teams[2] = string(t3);
        groups[i].teams[3] = string(t4);

        //init the score table
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                groups[i].scores[j][k] = 0;
            }
        }

        for(int j = 0; j < 4; j++){
            teams_id[4 * i + j].group_id = i;
            teams_id[4 * i + j].team = 
        }
    }

    //read the score in the match
    for(int i = 0; i < 48; i++){
        int score1, score2;
        char t1[TEAM_NAME_SIZE];
        char t2[TEAM_NAME_SIZE];
        char vs[TEAM_NAME_SIZE];
        fscanf(input, "%s %s %d %s %d", t1, t2, &score1, vs, &score2);

        cout << t1 << " " << t2 << " " << score1 << " " << score2 << endl;

        // //find the match is in which groups:
        // int group_id = 0;
        // bool canBreak = false;
        // for(group_id = 0; group_id < 8; group_id++){
        //     if(canBreak) break;
        //     for(int i = 0; i < 4; i++){
        //         string t12string(t1);
        //         cout << t1 << endl;
        //         if(!t12string.compare(groups[group_id].teams[i])){
        //             canBreak = true;
        //             break;
        //         }
        //     }
        // }

        // //put the score into the the 2D matrix:
        // int index1 = -1;
        // int index2 = -2;
        // for(int i = 0; i < 4; i++){
        //     if(!string(t1).compare(groups[group_id].teams[i])) index1 = i;
        //     if(!string(t2).compare(groups[group_id].teams[i])) index2 = i;
        // }
        // groups[group_id].scores[index1][index2] = score1;
        // groups[group_id].scores[index2][index2] = score2;
    }

    fclose(input);
}

void printGroup(group *groups){
    for(int i = 0; i < 8; i++){
        cout << "group: " << i + 1 << endl;
        for(int j = 0; j < 4; j++){
            cout << groups[i].teams[j] << " ";
        }
        cout << endl;

        cout << "scores : " << endl;
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                cout << groups[i].scores[j][k];
            }
            cout << endl;
        }
        cout << "\n\n";
    }

    
}

int main(int argc, char *argv[]){
    group *groups = new group[8];
    team_id *teams_id = new team_id[32];
    readFirstPart(argv[1], groups);
    printGroup(groups);
    return 0;
}