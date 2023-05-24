#include<bits/stdc++.h>
using namespace std;

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
void initList(mood_node **mhead){
    (*mhead) = createMoodNode(-2);
    (*mhead)->next = createMoodNode(-1);
    (*mhead)->next->next = createMoodNode(0);
    (*mhead)->next->next->next = createMoodNode(1);
    (*mhead)->next->next->next->next = createMoodNode(2);
}



void insert_In_Alphabet_Order(mood_node *mhead, student_node *s, int mood_point){
    mood_node *temp = mhead;
    for(int i = -2; i < mood_point; i++){
        temp = temp->next;
    }

    if(temp->head == nullptr || s->name < (temp->head)->name){
        s->next = temp->head;
        temp->head = s;
    }
    else{
        student_node *current = temp->head;
        while(current->next != nullptr && current->next->name < s->name){
            current = current->next;
        }
        s->next = current->next;
        current->next = s;
    }
}

void printList(mood_node *mhead){
    mood_node *temp = mhead;
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

student_node *findStudent(string name, mood_node *mhead){
    mood_node *temp = mhead;
    while(temp){
        if(temp->head){
            student_node *s = temp->head;
            while(s){
                if(s->name == name){
                    return s;
                }
                s = s->next;
            }
        }
        temp = temp->next;
    }
    return nullptr;
}

void removeStudent(mood_node *mhead, student_node *node_to_remove){
    mood_node *temp = mhead;
    while(temp){
        if(temp->head){
            student_node *s = temp->head;
            if(s == node_to_remove){
                temp->head = temp->head->next;
            }
            else{
                while(s->next != nullptr){
                    if(s->next == node_to_remove){
                        s->next = s->next->next;
                        node_to_remove->next = nullptr;
                        return;
                    }
                    s = s->next;
                }
                
            }
        }
        temp = temp->next;
    }
}

void firstChange(mood_node *mhead, string *hosts, int count){
    for(int i = 0; i < count; i++){
        student_node *current = findStudent(hosts[i], mhead);
        student_node *want_people = findStudent(current->want_name, mhead);
        if(want_people->give->given == false){
            want_people->give->given = true;
            current->get = want_people->give;
            removeStudent(mhead, current);
            if(want_people->give->good){
                insert_In_Alphabet_Order(mhead, current, 2);
            }
            else{
                insert_In_Alphabet_Order(mhead, current, -2);
            }
        }
    }
}

void secondChange(mood_node *mhead, gift_node *gifts, int student_num, string *name_order){
    for(int i = 0; i < student_num; i++){
        student_node *current = findStudent(name_order[i], mhead);
        if(current->get != nullptr) continue;

        //loop through gifts to determine which gift to give to current student
        for(int j = 0; j < student_num; j++){
            if(gifts[j].given == true || current->give == &gifts[j]) continue;

            gifts[j].given = true;
            current->get = &gifts[j];
            removeStudent(mhead, current);
            if(gifts[j].good){
                insert_In_Alphabet_Order(mhead, current, 1);
            }
            else{
                insert_In_Alphabet_Order(mhead, current, -1);
            }
            break;
        }
    }
}

int getMoodPoint(string name, mood_node *mhead){
    mood_node *temp = mhead;
    while(temp){
        if(temp->head){
            student_node *s = temp->head;
            while(s){
                if(s->name == name){
                    return temp->mood_point;
                }
                s = s->next;
            }
        }
        temp = temp->next;
    }
    return -100;
}

void outputMood(mood_node *mhead, int student_num, string *name_order){
    for(int i = 0; i < student_num; i++){
        student_node *temp = findStudent(name_order[i], mhead);
        int mood_point = getMoodPoint(name_order[i], mhead);
        cout << name_order[i] << " " << temp->get->gift_name << " ";
        switch(mood_point){
            case 2: cout << ":)))" << endl; break;
            case 1: cout << ":)" << endl; break;
            case -1: cout << ":(" << endl; break;
            case -2: cout << ":(((" << endl; break;
        }
    }
}

void deleteList(mood_node **mhead){
    
    while((*mhead)->next->next->next->next->head){
        student_node *temp = (*mhead)->next->next->next->next->head;
        (*mhead)->next->next->next->next->head = (*mhead)->next->next->next->next->head->next;
        delete temp;
    }
    delete (*mhead)->next->next->next->next;


    while((*mhead)->next->next->next->head){
        student_node *temp = (*mhead)->next->next->next->head;
        (*mhead)->next->next->next->head = (*mhead)->next->next->next->head->next;
        delete temp;
    }
    delete (*mhead)->next->next->next;


    while((*mhead)->next->next->head){
        student_node *temp = (*mhead)->next->next->head;
        (*mhead)->next->next->head = (*mhead)->next->next->head->next;
        delete temp;
    }
    delete (*mhead)->next->next;


    while((*mhead)->next->head){
        student_node *temp = (*mhead)->next->head;
        (*mhead)->next->head = (*mhead)->next->head->next;
        delete temp;
    }
    delete (*mhead)->next;


    while((*mhead)->head){
        student_node *temp = (*mhead)->head;
        (*mhead)->head = (*mhead)->head->next;
        delete temp;
    }
    delete (*mhead);
}

int main(int argc, char *argv[]){

    int student_num;
    string line;
    ifstream fin(argv[1]);
    getline(fin, line);
    student_num = stoi(line);
    
    gift_node *gifts = new gift_node[student_num];
    mood_node *mhead = nullptr;
    initList(&mhead);
    string *name_order = new string[student_num];

    for(int i = 0; i < student_num; i++){
        string line;
        getline(fin, line);
        stringstream ss(line);
        string name, want_name, gift_name;
        char isgood;
        ss >> name >> want_name >> gift_name >> isgood;
        name_order[i] = name;
        gifts[i].gift_name = gift_name;
        gifts[i].good = (isgood == '1') ? true : false;
        gifts[i].given = false;
        student_node *s = createStudentNode(name, want_name, gift_name, &gifts[i]);
        insert_In_Alphabet_Order(mhead, s, 0);
    }

    //before gift exchange
    printList(mhead);

    //read the host
    string hosts_line;
    int count = 0;
    string hosts_copy;
    getline(fin, hosts_line);
    hosts_copy = hosts_line;
    stringstream ss(hosts_copy);
    while(ss >> hosts_copy){
        count++;
    }
    string *hosts = new string[count];
    ss.clear();
    ss.str(hosts_line);
    for(int i = 0; i < count; i++){
        ss >> hosts[i];
    }

    //make first change
    firstChange(mhead, hosts, count);
    printList(mhead);

    //make second change
    secondChange(mhead, gifts, student_num, name_order);
    printList(mhead);

    //output the moodpoint
    outputMood(mhead, student_num, name_order);

    fin.close();
    delete []gifts;
    delete []name_order;
    delete []hosts;
    deleteList(&mhead);
}