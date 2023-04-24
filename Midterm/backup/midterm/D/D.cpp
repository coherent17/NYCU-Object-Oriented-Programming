#include <string>
#include <iostream>
#include "Class.h"

using namespace std;

int main()
{
    while(true){
        cout << endl;
        cout << "----------Main Menu----------" << endl;
        cout << "1. Search a Course" << endl;
        cout << "2. Teacher Login" << endl;
        cout << "3. Teacher Register" << endl;
        cout << "4. Student Login" << endl;
        cout << "5. Student Register" << endl;
        cout << "6. Add a New Course" << endl;

        string ch_str = "";
        int ch = 0;
        while(ch_str < "1" || ch_str > "6" || ch_str.size() != 1){
            cout << "Choice: ";
            cin >> ch_str;
            if(ch_str.size() == 0){
                break;
            }
        }
        if(ch_str.size() == 0){
            break;
        }
        ch = (int)ch_str[0] - 48;
        cout << endl;
        if(ch == 1){
            string name;
            cout << "Name: ";
            cin >> name;
            bool flag = false;
            for(int i=0; i<Course::total_vec.size(); i++){
                if(Course::total_vec[i] == name){
                    flag = true;
                    cout << *(Course::total_obj_ptr_vec[i]);
                    break;
                }
            }
            if(!flag){
                cout << "This name does not exist. Please register first." << endl;
            }
        }
        else if(ch == 2){
            string name;
            cout << "Name: ";
            cin >> name;
            bool flag = false;
            //cout << "There are " << Teacher::total_vec.size() << " teachers" << endl;
            for(int i=0; i<Teacher::total_vec.size(); i++){
                //cout << "Teacher name: " << Teacher::total_vec[i] << endl;
                if(Teacher::total_vec[i] == name){
                    flag = true;
                    string password;
                    cout << "password: ";
                    cin >> password;
                    if((*(Teacher::total_obj_ptr_vec[i])).check_password(password)){
                        cout << endl << "Login Success" << endl;
                        while( (*(Teacher::total_obj_ptr_vec[i])).menu() );
                    }
                    else{
                        cout << "Wrong password! Back to the Main Menu" << endl;
                    }
                }
            }
            if(!flag){
                cout << "This name does not exist. Please register first." << endl;
            }
        }
        else if(ch == 3){
            string name;
            cout << "Your name: ";
            cin >> name;
            cout << "password: ";
            string password;
            cin >> password;
            //Teacher* teacher_ptr = new Teacher(name, password);
            Teacher::createNewTeacher(name, password);
        }
        else if(ch == 4){
            string name;
            cout << "Name: ";
            cin >> name;
            bool flag = false;
            for(int i=0; i<Student::total_vec.size(); i++){
                if(Student::total_vec[i] == name){
                    flag = true;
                    string password;
                    cout << "password: ";
                    cin >> password;
                    if((*(Student::total_obj_ptr_vec[i])).check_password(password)){
                        cout << endl << "Login Success" << endl ;
                        
                        while( (*(Student::total_obj_ptr_vec[i])).menu() );
                    }
                    else{
                        cout << "Wrong password! Back to the Main Menu" << endl;
                    }
                }
            }
            if(!flag){
                cout << "This name does not exist. Please register first." << endl;
            }
        }
        else if(ch == 5){
            string name;
            cout << "Your name: ";
            cin >> name;
            cout << "password: ";
            string password;
            cin >> password;
            //static Student student_temp(name, password);
            //Student* stu_ptr = new Student(name, password);
            Student::createNewStudent(name, password);
        }
        else if(ch == 6){
            string course_name;
            cout << "Course name: ";
            cin >> course_name;
            cout << "Teacher name: ";
            string name;
            cin >> name;
            bool flag = false;
            for(int i=0; i<Teacher::total_vec.size(); i++){
                if(Teacher::total_vec[i] == name){
                    flag = true;
                    string password;
                    cout << "password: ";
                    cin >> password;
                    if((*(Teacher::total_obj_ptr_vec[i])).check_password(password)){
                        cout << endl << "Open course successfully" << endl;
                        //Course* course_ptr = new Course( course_name, (Teacher::total_obj_ptr_vec[i]) );
                        Course::createNewCourse( course_name, (Teacher::total_obj_ptr_vec[i]) );
                    }
                    else{
                        cout << "Wrong password! Back to the Main Menu" << endl;
                    }
                }
            }
            if(!flag){
                cout << "This name does not exist. Please register first." << endl;
            }
        }
    }
    return 0;
}