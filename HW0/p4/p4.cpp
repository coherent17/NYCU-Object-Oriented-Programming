#include<bits/stdc++.h>

#define MAX_TEAM_NAME_SIZE 20
#define BUFFER_SIZE 20
#define NUM_GROUP 8
#define TEAMS_PER_GROUP 4
#define FIRST_MATCH_ROUND 48
#define WIN_POINTS 3
#define DRAW_POINTS 1

using namespace std;

typedef struct _group{
    string teams[TEAMS_PER_GROUP];

    //win +3, lose +0, draw +1
    int points[TEAMS_PER_GROUP] = {0};
    int scores[TEAMS_PER_GROUP] = {0};
}group;

void readFirstPart(char *filename, group *&groups, map<string, pair<int, int>> &groupID){
    FILE *input = fopen(filename, "r");

    //read the team in the same group
    for(int i = 0; i < NUM_GROUP; i++){
        char t[TEAMS_PER_GROUP][MAX_TEAM_NAME_SIZE];
        fscanf(input, "%s %s %s %s", t[0], t[1], t[2], t[3]);
        for(int j = 0; j < TEAMS_PER_GROUP; j++){
            groups[i].teams[j] = string(t[j]);
            groupID[string(t[j])] = make_pair(i,j);
        }
    }

    for(int i = 0; i < FIRST_MATCH_ROUND; i++){
        int score1, score2;
        char t1[MAX_TEAM_NAME_SIZE], t2[MAX_TEAM_NAME_SIZE];
        char buffer[BUFFER_SIZE];   //read vs
        fscanf(input, "%s %s %d %s %d", t1, t2, &score1, buffer, &score2);

        int t1_groupID = groupID[string(t1)].first;
        int t1_teamID = groupID[string(t1)].second;

        int t2_groupID = groupID[string(t2)].first;
        int t2_teamID = groupID[string(t2)].second;
        
        groups[t1_groupID].scores[t1_teamID]+= score1;
        groups[t2_groupID].scores[t2_teamID]+= score2;

        if(score1 > score2){
            groups[t1_groupID].points[t1_teamID]+= WIN_POINTS;
        }
        else if(score1 < score2){
            groups[t2_groupID].points[t2_teamID]+= WIN_POINTS;
        }
        else{
            groups[t1_groupID].points[t1_teamID]+= DRAW_POINTS;
            groups[t2_groupID].points[t2_teamID]+= DRAW_POINTS;
        }
    }

    // //read the score in the match
    // for(int i = 0; i < 48; i++){
    //     int score1, score2;
    //     char t1[TEAM_NAME_SIZE];
    //     char t2[TEAM_NAME_SIZE];
    //     char vs[TEAM_NAME_SIZE];
    //     fscanf(input, "%s %s %d %s %d", t1, t2, &score1, vs, &score2);

    //     cout << t1 << " " << t2 << " " << score1 << " " << score2 << endl;

    //     // //find the match is in which groups:
    //     // int group_id = 0;
    //     // bool canBreak = false;
    //     // for(group_id = 0; group_id < 8; group_id++){
    //     //     if(canBreak) break;
    //     //     for(int i = 0; i < 4; i++){
    //     //         string t12string(t1);
    //     //         cout << t1 << endl;
    //     //         if(!t12string.compare(groups[group_id].teams[i])){
    //     //             canBreak = true;
    //     //             break;
    //     //         }
    //     //     }
    //     // }

    //     // //put the score into the the 2D matrix:
    //     // int index1 = -1;
    //     // int index2 = -2;
    //     // for(int i = 0; i < 4; i++){
    //     //     if(!string(t1).compare(groups[group_id].teams[i])) index1 = i;
    //     //     if(!string(t2).compare(groups[group_id].teams[i])) index2 = i;
    //     // }
    //     // groups[group_id].scores[index1][index2] = score1;
    //     // groups[group_id].scores[index2][index2] = score2;
    // }

    fclose(input);
}

void printGroup(group *groups){
    for(int i = 0; i < NUM_GROUP; i++){
        cout << "Group : " << i << endl;
        for(int j = 0; j < TEAMS_PER_GROUP; j++){
            cout << groups[i].teams[j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Scores : " << endl;
    for(int i = 0; i < NUM_GROUP; i++){
        cout << "Group : " << i + 1 << endl;
        for(int j = 0; j < TEAMS_PER_GROUP; j++){
            cout << groups[i].scores[j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Points : " << endl;
    for(int i = 0; i < NUM_GROUP; i++){
        cout << "Group : " << i + 1 << endl;
        for(int j = 0; j < TEAMS_PER_GROUP; j++){
            cout << groups[i].points[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char *argv[]){
    group *groups = new group[NUM_GROUP];
    map<string, pair<int, int>> groupID;

    readFirstPart(argv[1], groups, groupID);
    printGroup(groups);

    delete [] groups;
    return 0;
}