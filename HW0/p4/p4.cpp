#include<bits/stdc++.h>

#define MAX_TEAM_NAME_SIZE 20
#define BUFFER_SIZE 20
#define NUM_GROUP 8
#define TEAMS_PER_GROUP 4
#define GROUP_MATCH_ROUND 48
#define WIN_POINTS 3
#define DRAW_POINTS 1
#define NOT_FOUND -1
#define NUM_MATCH 15

using namespace std;

typedef struct _group{
    string teams[TEAMS_PER_GROUP];

    //win +3, lose +0, draw +1
    int points[TEAMS_PER_GROUP] = {0};
    int scores[TEAMS_PER_GROUP] = {0};
    int first_place = NOT_FOUND;
    int second_place = NOT_FOUND;
}group;


//match element in knonkout stage
typedef struct _match{
    bool isPK = false;
    bool complete = true;
    int score1;
    int score2;
    int PKscore1;
    int PKscore2;
}match;



bool cmp(pair<int, int> x, pair <int, int> y){
    if (x.first != y.first){
        return x.first > y.first;
    }
    else{
        return x.second > y.second;
    }
}

void findWinners(group &g){
    pair<int, int> PointWithScore[4];
    for(int i = 0; i < TEAMS_PER_GROUP; i++){
        PointWithScore[i] = make_pair(g.points[i], g.scores[i]);
    }

    sort(PointWithScore, PointWithScore + TEAMS_PER_GROUP, cmp);

    for(int i = 0; i < TEAMS_PER_GROUP; i++){
        if(g.points[i] == PointWithScore[0].first && g.scores[i] == PointWithScore[0].second){
            g.first_place = i;
        }
        if(g.points[i] == PointWithScore[1].first && g.scores[i] == PointWithScore[1].second){
            g.second_place = i;
        }
    }
}

void GroupMatch(FILE *input, group *&groups, map<string, pair<int, int>> &groupID){

    //read the team in the same group
    for(int i = 0; i < NUM_GROUP; i++){
        char t[TEAMS_PER_GROUP][MAX_TEAM_NAME_SIZE];
        fscanf(input, "%s %s %s %s", t[0], t[1], t[2], t[3]);
        for(int j = 0; j < TEAMS_PER_GROUP; j++){
            groups[i].teams[j] = string(t[j]);
            groupID[string(t[j])] = make_pair(i,j);
        }
    }

    for(int i = 0; i < GROUP_MATCH_ROUND; i++){
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

    //find the winner of the first round
    for(int i = 0; i < NUM_GROUP; i++){
        findWinners(groups[i]);
    }
}

void KnockoutStage(FILE *input, match *&matches){
    char buffer[BUFFER_SIZE] = {"\0"};
    while(fscanf(input, "%[^\n]", buffer) != EOF){
        if(!strcmp(buffer, "=")) break;
        fgetc(input);
        cout << buffer << endl;
    }
}

void printGroup(group *groups){
    for(int i = 0; i < NUM_GROUP; i++){
        cout << "Group : " << i + 1 << endl;
        cout << "\t Names : ";
        for(int j = 0; j < TEAMS_PER_GROUP; j++){
            cout << groups[i].teams[j] << " ";
        }
        cout << endl;

        cout << "\t Points : ";
        for(int j = 0; j < TEAMS_PER_GROUP; j++){
            cout << groups[i].points[j] << " ";
        }
        cout << endl;

        cout << "\t Scores : ";
        for(int j = 0; j < TEAMS_PER_GROUP; j++){
            cout << groups[i].scores[j] << " ";
        }
        cout << endl;

        cout << "\t First Place : ";
        cout << groups[i].first_place << endl;

        cout << "\t Second Place : ";
        cout << groups[i].second_place << endl;
    }
    cout << endl;
}

int main(int argc, char *argv[]){
    group *groups = new group[NUM_GROUP];
    map<string, pair<int, int>> groupID;

    FILE *input = fopen(argv[1], "r");

    GroupMatch(input, groups, groupID);
    printGroup(groups);

    match *matches = new match[NUM_MATCH];
    KnockoutStage(input, matches);

    fclose(input);
    delete [] groups;
    return 0;
}