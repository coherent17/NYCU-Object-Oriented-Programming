#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_GIFT_NAME_SIZE 50
#define MAX_NAME_SIZE 50
#define MAX_WANT_NAME_SIZE 50

typedef struct _gift_node{
    char gift_name[MAX_GIFT_NAME_SIZE];
    bool good;
    bool given;
}gift_node;

typedef struct _mood_node{

}mood_node;

typedef struct _student_node{
    char name[MAX_NAME_SIZE];
    char want_name[MAX_WANT_NAME_SIZE];
    gift_node *give;
    gift_node *get;
    struct _student_node *next;
}student_node;

typedef struct _participant_info{
    char name[MAX_NAME_SIZE];
    char want_received[MAX_NAME_SIZE];
    char gift_name[MAX_GIFT_NAME_SIZE];
    bool good;
}participant_info;

typedef struct _host_info{
    char name[MAX_NAME_SIZE];
}host_info;

void printInfo(participant_info *Infos, int n){
    for(int i = 0; i < n; i++){
        participant_info temp = Infos[i];
        printf("%s %s %s %d\n", temp.name, temp.want_received, temp.gift_name, temp.good);
    }
}

participant_info *parser(char *filename, int *student_num){
    FILE *input = fopen(filename, "r");
    int n;
    fscanf(input, "%d", &n);
    *student_num = n;

    participant_info *Infos = (participant_info *)malloc(sizeof(participant_info) * n);
    
    for(int i = 0; i < n; i++){
        participant_info temp;
        int good;
        fscanf(input, "%s %s %s %d", temp.name, temp.want_received, temp.gift_name, &good);
        temp.good = good == 1 ? 1 : 0;
        Infos[i] = temp;
    }


    fclose(input);
    return Infos;
}

int main(int argc, char *argv[]){
    
    int student_num;
    participant_info *Infos = parser(argv[1], &student_num);
    printInfo(Infos, student_num);
    return 0;
}