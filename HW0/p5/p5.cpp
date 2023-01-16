#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_GIFT_NAME_SIZE 50
#define MAX_NAME_SIZE 50
#define MAX_WANT_NAME_SIZE 50

typedef struct _gift_node{
    char gift_name[MAX_GIFT_NAME_SIZE];
    bool good;
    bool given;
}gift_node;

typedef struct _student_node{
    char name[MAX_NAME_SIZE];
    char want_name[MAX_WANT_NAME_SIZE];
    gift_node *give;
    gift_node *get;
    struct _student_node *next;
}student_node;

typedef struct _mood_node{
    int mood_point;
    student_node *head;
    struct _mood_node *next;
}mood_node;

mood_node *createMoodNode(int mood_point){
    mood_node *newnode = (mood_node *)malloc(sizeof(mood_node));
    newnode->head = NULL;
    newnode->mood_point = mood_point;
    newnode->next = NULL;
    return newnode;
}

gift_node *createGiftNode(char *gift_name, int good){
    gift_node *newnode = (gift_node *)malloc(sizeof(gift_node));
    strncpy(gift_name, newnode->gift_name, strlen(gift_name));
    bool isgood = good == 1 ? 1 : 0;
    newnode->good = good;
    newnode->given = false;
}

void createList(mood_node **List){
    mood_node *newnode = createMoodNode(-2);
    *List = newnode;
    mood_node *tail = newnode;

    for(int i = -1; i <= 2; i++){
        newnode = createMoodNode(i);
        tail->next = newnode;
        tail = newnode;
    }
}

void printList(mood_node *List){
    mood_node *temp = List;
    while(temp){
        printf("%d ->\n", temp->mood_point);
        temp = temp->next;
    }
}

void parser(char *filename, int *student_num, mood_node **List){
    FILE *input = fopen(filename, "r");
    int n;
    fscanf(input, "%d", &n);
    *student_num = n;

    createList(List);

    gift_node **gift_node_array = (gift_node **)malloc(sizeof(gift_node *) * n);
    
    for(int i = 0; i < n; i++){
        char name[MAX_NAME_SIZE];
        char want_received[MAX_NAME_SIZE];
        char gift_name[MAX_GIFT_NAME_SIZE];
        int good;
        fscanf(input, "%s %s %s %d", name, want_received, gift_name, &good);
        bool isgood = good == 1 ? 1 : 0;
        createGiftNode(gift_name, isgood);
    }


    fclose(input);
}


int main(int argc, char *argv[]){
    
    int student_num;
    mood_node *List = NULL;
    parser(argv[1], &student_num, &List);

    createList(&List);
    printList(List);


    return 0;
}