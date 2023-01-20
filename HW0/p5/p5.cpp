#include<bits/stdc++.h>

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

//create the list of mood_node and return the entry of the head
mood_node **initList(mood_node *&List){
    int index = 0;
    mood_node **head_addr = new mood_node *[5];
    mood_node *tail = List;
    mood_node *temp = createMoodNode(-2);
    head_addr[index++] = temp;
    List = temp;
    tail = temp;
    for(int i = -1; i <= 2; i++){
        temp = createMoodNode(i);
        head_addr[index++] = temp;
        tail->next = temp;
        tail = temp;
    }
    return head_addr;
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
                else cout << "(" << s->get->gift_name << ")";
                if(s->next != nullptr){
                    cout << " -> ";
                }
                s = s->next;
            }
            cout << endl;
        }
        temp = temp->next;
    }
    cout << endl;
}

void insert_In_Alphabet_Order(mood_node **&head_addr, student_node *node_to_insert, int mood_point){

    if(head_addr[mood_point+2]->head == nullptr || strcmp(head_addr[mood_point+2]->head->name.c_str(), node_to_insert->name.c_str()) > 0){
        node_to_insert->next = head_addr[mood_point+2]->head;
        head_addr[mood_point+2]->head = node_to_insert;
        return;
    }


    student_node *current = head_addr[mood_point+2]->head;
    while(current->next != nullptr && strcmp(current->next->name.c_str(), node_to_insert->name.c_str()) < 0){
        current = current->next;
    }
    node_to_insert->next = current->next;
    current->next = node_to_insert;
}

void parser(char *filename, int &student_num, gift_node *&gifts, mood_node *&List, mood_node **&head_addr, host &hostInfo, string *&name_order){
    FILE *input = fopen(filename, "r");
    fscanf(input, "%d", &student_num);

    gifts = new gift_node[student_num];
    int gift_index = 0;
    name_order = new string[student_num];
    int name_order_index = 0;

    for(int i = 0; i < student_num; i++){
        char name[MAX_NAME_SIZE], want_name[MAX_NAME_SIZE], gift_name[MAX_GIFT_NAME_SIZE];
        int good;
        fscanf(input, "%s %s %s %d", name, want_name, gift_name, &good);
        name_order[name_order_index++] = string(name);
        gift_node g;
        g.gift_name = string(gift_name);
        g.good = (good == 1) ? true : false;
        g.given = false;
        gifts[gift_index] = g;
        student_node *s = createStudentNode(string(name), string(want_name), string(gift_name), &gifts[gift_index]);
        insert_In_Alphabet_Order(head_addr, s, 0);
        gift_index++;
    }
    fgetc(input);

    //read the host's friend
    char buffer[BUFFER_SIZE];
    char buffer_copy[BUFFER_SIZE];
    fscanf(input, "%[^\n]", buffer);
    strncpy(buffer_copy, buffer, strlen(buffer));
    buffer_copy[strlen(buffer)] = '\0';

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

void printGiftList(gift_node *gifts, int student_num){
    for(int i = 0; i < student_num; i++){
        cout << gifts[i].gift_name << ": " << gifts[i].good << " " << gifts[i].given << endl;
    }
}

student_node *findPeople(string name, mood_node *List, int *index){
    mood_node *temp = List;
    while(temp){
        student_node *s = temp->head;
        while(s){
            if(!name.compare(s->name)){
                *index = temp->mood_point;
                return s;
            }
            s = s->next;
        }
        temp = temp->next;
    }
    return nullptr;
}

void removeStudentNode(mood_node **&head_addr, student_node *node_to_remove, int mood_point){
    student_node *head = head_addr[mood_point + 2]->head;
    if(head == node_to_remove){
        head_addr[mood_point + 2]->head = head_addr[mood_point + 2]->head->next;
    }
    else{
        student_node *temp = head_addr[mood_point + 2]->head;
        while(temp->next != nullptr){
            if(temp->next == node_to_remove){
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
    }
}

void firstChange(host hostInfo, mood_node *&List, mood_node **&head_addr){
    for(int i = 0; i < hostInfo.count; i++){
        int mood_point1, mood_point2;
        student_node *current = findPeople(hostInfo.names[i], List, &mood_point1);
        student_node *want_people = findPeople(current->want_name, List, &mood_point2);
        if(!want_people->give->given){
            want_people->give->given = true;
            current->get = want_people->give;
            removeStudentNode(head_addr, current, mood_point1);
            if(want_people->give->good){
                current->get = want_people->give;
                insert_In_Alphabet_Order(head_addr, current, 2);
            }
            else{
                current->get = want_people->give;
                insert_In_Alphabet_Order(head_addr, current, -2);
            }
        }
    }
}

void secondChange(gift_node *gifts, mood_node **&head_addr, int student_num, mood_node *&List){
    while(head_addr[2]->head){
        //find the gift for the rest in mood_point = 0
        for(int i = 0; i < student_num; i++){
            if(gifts[i].given == true || head_addr[2]->head->give == &gifts[i]) continue;

            else{
                gifts[i].given = true;
                head_addr[2]->head->get = &gifts[i];
                student_node *temp = head_addr[2]->head;
                head_addr[2]->head = head_addr[2]->head->next;
                if(gifts[i].good){
                    insert_In_Alphabet_Order(head_addr, temp, 1);
                }
                else{
                    insert_In_Alphabet_Order(head_addr, temp, -1);
                }
            }
        }
    }
}

void output_mood(string *name_order, mood_node *List, int student_num){
    for(int i = 0; i < student_num; i++){
        cout << name_order[i] << " ";
        int mood_point;
        student_node *temp = findPeople(name_order[i], List, &mood_point);
        cout << temp->get->gift_name << " ";

        switch (mood_point){
            case 2:
                cout << ":)))" << endl;
                break;

            case 1:
                cout << ":)" << endl;
                break;

            case -1:
                cout << ":(" << endl;
                break;

            case -2:
                cout << ":(((" << endl;
                break;
        }
    }
}

void deleteList(mood_node **&head_addr){
    for(int i = 0; i < 5; i++){
        while(head_addr[i]->head){
            student_node *temp = head_addr[i]->head;
            head_addr[i]->head = head_addr[i]->head->next;
            delete temp;
        }
        delete head_addr[i];
    }
    delete [] head_addr;
}

int main(int argc, char *argv[]){
    
    //create the list (mood_node linkedlist)
    mood_node *List;
    mood_node **head_addr = initList(List);
    gift_node *gifts = nullptr;

    int student_num;
    host hostInfo;
    string *name_order;
    parser(argv[1], student_num, gifts, List, head_addr, hostInfo, name_order);
    printList(List);    //initial state: all mood point = 0

    firstChange(hostInfo, List, head_addr);
    printList(List);

    secondChange(gifts, head_addr, student_num, List);
    printList(List);

    output_mood(name_order, List, student_num);

    delete [] name_order;
    delete [] gifts;
    delete [] hostInfo.names;
    deleteList(head_addr);
    return 0;
}