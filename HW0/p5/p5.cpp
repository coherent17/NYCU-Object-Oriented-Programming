#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

#define MAX_GIFT_NAME_SIZE 50
#define MAX_NAME_SIZE 50
#define MAX_WANT_NAME_SIZE 50
#define BUFFER_SIZE 1000

typedef struct _gift_node{
    string gift_name;
    bool good;
    bool given;
}gift_node;

typedef struct _student_node{
    string name;
    string want_name;
    gift_node *give;
    gift_node *get;
    struct _student_node *next;
}student_node;

typedef struct _mood_node{
    int mood_point;
    student_node *head;
    struct _mood_node *next;
}mood_node;

typedef struct _host{
    int count;
    string *names;
}host;

mood_node *createMoodNode(int mood_point){
    mood_node *newnode = new mood_node;
    newnode->mood_point = mood_point;
    newnode->head = nullptr;
    newnode->next = nullptr;
    return newnode;
}

student_node *createStudentNode(string name, string want_name, string gift_name, gift_node *gift_addr){
    student_node *Student = new student_node;
    Student->name = name;
    Student->want_name = want_name;
    Student->give = gift_addr;
    Student->get = nullptr;
    Student->next = nullptr;
    return Student;
}

void initList(mood_node *& List){
    mood_node *tail = List;
    mood_node *temp = createMoodNode(-2);
    List = temp;
    tail = temp;
    for(int i = -1; i <= 2; i++){
        temp = createMoodNode(i);
        tail->next = temp;
        tail = temp;
    }
}

void insert_list(student_node **head, student_node **tail, student_node *s){
    if(*head == nullptr){
        *head = s;
        *tail = s;
    }
    else{
        (*tail)->next = s;
        *tail = s;
    }
}

void printList(mood_node *List){
    mood_node *temp = List;
    while(temp){

        if(temp->head){
            cout << temp->mood_point << " -> ";
            student_node *s = temp->head;
            while(s){
                cout << s->name;
                if(temp->mood_point == 0) cout << "(0)";
                if(s->next != nullptr){
                    cout << " -> ";
                }
                s = s->next;
            }
            cout << endl;
        }
        temp = temp->next;
    }
}

void printGiftList(gift_node *gifts, int student_num){
    for(int i = 0; i < student_num; i++){
        cout << gifts[i].gift_name << ": " << gifts[i].good << " " << gifts[i].given << endl;
    }
}

void parser(char *filename, int &student_num, gift_node *&gifts, mood_node *&List, host &hostInfo){
    FILE *input = fopen(filename, "r");
    fscanf(input, "%d", &student_num);

    gifts = new gift_node[student_num];
    int gift_index = 0;

    student_node *head = nullptr;
    student_node *tail = nullptr;

    for(int i = 0; i < student_num; i++){
        char name[MAX_NAME_SIZE], want_name[MAX_NAME_SIZE], gift_name[MAX_GIFT_NAME_SIZE];
        int good;
        fscanf(input, "%s %s %s %d", name, want_name, gift_name, &good);
        gift_node g;
        g.gift_name = string(gift_name);
        g.good = (good == 1) ? true : false;
        g.given = false;
        gifts[gift_index] = g;
        student_node *s = createStudentNode(string(name), string(want_name), string(gift_name), &gifts[gift_index]);
        insert_list(&head, &tail, s);
        gift_index++;
    }
    fgetc(input);
    //insert the linkedlist into mood_point = 0 position
    mood_node *temp = List;
    while(temp){
        if(temp->mood_point == 0){
            temp->head = head;
            break;
        }
        temp = temp->next;
    }

    //read the host's friend
    char buffer[BUFFER_SIZE];
    char buffer_copy[BUFFER_SIZE];
    fscanf(input, "%[^\n]", buffer);
    strncpy(buffer_copy, buffer, strlen(buffer));

    int host_count = 0;
    char *token = strtok(buffer, " ");
    while(token != NULL){
        host_count++;
        token = strtok(NULL, " ");
    }

    hostInfo.count = host_count;
    hostInfo.names = new string [host_count];

    token = strtok(buffer_copy, " ");
    int index = 0;
    while(token != NULL){
        hostInfo.names[index++] = string(token);
        token = strtok(NULL, " ");
    }
    fclose(input);
}

student_node *findPeople(string name, mood_node *List){
    mood_node *temp = List;
    while(temp){
        student_node *s = temp->head;
        while(s){
            if(!name.compare(s->name)){
                return s;
            }
            s = s->next;
        }
        temp = temp->next;
    }
    return nullptr;
}

student_node *removeStudentNode(mood_node *&List, string rm_name){
    mood_node *temp = List;
    while(temp){

        student_node *s = temp->head;

        //if the delete node is head node:
        if(!temp->head && !rm_name.compare(s->name)){
            temp->head = 
        }

        while(s){
            if(!temp->head && !rm_name.compare(s->name)){
                break;
            }
            s = s->next;
        }

        temp = temp->next;
    }
}

void firstChange(host hostInfo, mood_node *&List){
    for(int i = 0; i < 1; i++){
        student_node *current = findPeople(hostInfo.names[i], List);
        student_node *want_people = findPeople(current->want_name, List);
        if(!want_people->give->given){
            want_people->give->given = true;
            current->get = want_people->give;

        }
        cout << current->name << " " << want_people->give->gift_name << " " << want_people->give->good <<endl;
    }
}

int main(int argc, char *argv[]){
    
    //create the list (mood_node linkedlist)
    mood_node *List;
    initList(List);
    gift_node *gifts = nullptr;

    int student_num;
    host hostInfo;

    parser(argv[1], student_num, gifts, List, hostInfo);
    printList(List);    //initial state: all mood point = 0
    printGiftList(gifts, student_num);
    firstChange(hostInfo, List);
    printGiftList(gifts, student_num);
    return 0;
}