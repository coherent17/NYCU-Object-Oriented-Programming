#include "Group.h"
#include "Student.h"
#include <iomanip>
#define MAX_SCORE 100
#define MIN_SCORE 0

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

Group::Group(){
        student_num = 0;
        sum_score_Calculus = 0;
        high_Calculus = MIN_SCORE;
        low_Calculus = MAX_SCORE;
        sum_score_English = 0;
        high_English = MIN_SCORE;
        low_English = MAX_SCORE;
        sum_score_Physics = 0;
        high_Physics = MIN_SCORE;
        low_Physics = MAX_SCORE;
}

Group::~Group(){

}

void Group::addStudent(Student S){
    students.push_back(S);
    student_num++;
    sum_score_Calculus += S.Scores[0];
    high_Calculus = max(high_Calculus, S.Scores[0]);
    low_Calculus = min(low_Calculus, S.Scores[0]);
    sum_score_English += S.Scores[1];
    high_English = max(high_English, S.Scores[1]);
    low_English = min(low_English, S.Scores[1]);
    sum_score_Physics += S.Scores[2];
    high_Physics = max(high_Physics, S.Scores[2]);
    low_Physics = min(low_Physics, S.Scores[2]);
}

void Group::removeStudentByID(string id){
    for(size_t i = 0; i < students.size(); i++){
        if(students[i].id == id){
            students.erase(students.begin() + i);
            student_num--;

            //update the sum and high low grade
            sum_score_Calculus = 0;
            high_Calculus = MIN_SCORE;
            low_Calculus = MAX_SCORE;
            sum_score_English = 0;
            high_English = MIN_SCORE;
            low_English = MAX_SCORE;
            sum_score_Physics = 0;
            high_Physics = MIN_SCORE;
            low_Physics = MAX_SCORE;
            for(size_t i = 0; i < students.size(); i++){
                sum_score_Calculus += students[i].Scores[0];
                sum_score_English += students[i].Scores[1];
                sum_score_Physics += students[i].Scores[2];
                high_Calculus = max(high_Calculus, students[i].Scores[0]);
                low_Calculus = min(low_Calculus, students[i].Scores[0]);
                high_English = max(high_English, students[i].Scores[1]);
                low_English = min(low_English, students[i].Scores[1]);
                high_Physics = max(high_Physics, students[i].Scores[2]);
                low_Physics = min(low_Physics, students[i].Scores[2]);
            }
            cout << "Remove Successfully" << endl;
            return;
        }
    }
    cout << "Student doesn't exist" << endl;
}

void Group::removeStudentByName(string name){
    for(size_t i = 0; i < students.size(); i++){
        if(students[i].name == name){
            students.erase(students.begin() + i);
            student_num--;

            //update the sum and high low grade
            sum_score_Calculus = 0;
            high_Calculus = MIN_SCORE;
            low_Calculus = MAX_SCORE;
            sum_score_English = 0;
            high_English = MIN_SCORE;
            low_English = MAX_SCORE;
            sum_score_Physics = 0;
            high_Physics = MIN_SCORE;
            low_Physics = MAX_SCORE;
            for(size_t i = 0; i < students.size(); i++){
                sum_score_Calculus += students[i].Scores[0];
                sum_score_English += students[i].Scores[1];
                sum_score_Physics += students[i].Scores[2];
                high_Calculus = max(high_Calculus, students[i].Scores[0]);
                low_Calculus = min(low_Calculus, students[i].Scores[0]);
                high_English = max(high_English, students[i].Scores[1]);
                low_English = min(low_English, students[i].Scores[1]);
                high_Physics = max(high_Physics, students[i].Scores[2]);
                low_Physics = min(low_Physics, students[i].Scores[2]);
            }
            cout << "Remove Successfully" << endl;
            return;
        }
    }
    cout << "Student doesn't exist" << endl;
}

void Group::gradeDistribution(){
    if(student_num == 0){
        cout << "No Student" << endl;
        return;
    }
    cout << "Student Num: " << student_num << endl;

    cout << "<Calculus>" << endl;
    cout << "Avg: " << fixed << setprecision(2) <<double(sum_score_Calculus) / double(student_num) << endl;
    cout << "Max: " << high_Calculus << endl;
    cout << "Min: " << low_Calculus << endl;

    cout << "<English>" << endl;
    cout << "Avg: " << double(sum_score_English) / double(student_num) << endl;
    cout << "Max: " << high_English << endl;
    cout << "Min: " << low_English << endl;

    cout << "<Physics>" << endl;
    cout << "Avg: " << double(sum_score_Physics) / double(student_num) << endl;
    cout << "Max: " << high_Physics << endl;
    cout << "Min: " << low_Physics << endl;
    cout << endl;
}

void Group::printStudentsInOrder(){
    cout << "Student Num: " << student_num << endl;
    for(size_t i = 0; i < students.size(); i++){
        cout << "<Student " << i + 1 << ">";
        cout << students[i] << endl;
    }
}

bool idcmp(Student& a, Student& b){
    return a.getid() < b.getid();
}

bool namecmp(Student& a, Student& b){
    return a.getname() < b.getname();
}

void Group::printStudentsInId(){
    cout << "Student Num: " << student_num << endl;
    vector<Student> temp = students;
    sort(temp.begin(), temp.end(), idcmp);
    for(size_t i = 0; i < temp.size(); i++){
        cout << "<Student " << i + 1 << ">";
        cout << temp[i] << endl;
    }
}

void Group::printStudentsInName(){
    cout << "Student Num: " << student_num << endl;
    vector<Student> temp = students;
    sort(temp.begin(), temp.end(), namecmp);
    for(size_t i = 0; i < temp.size(); i++){
        cout << "<Student " << i + 1 << ">";
        cout << temp[i] << endl;
    }
}