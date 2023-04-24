//This menu function is for your reference

bool Student::menu()
{
    cout << "----------User Menu----------" << endl;
    cout << "You have " << course_num << " courses." << endl;
    int index = -1;
    for(int i=0; i<course_num; i++){
        cout << (i+1) << ". " << (*(course_arr[i])).name << endl;
    }
    cout << (course_num+1) << ". Select new course." << endl;
    cout << (course_num+2) << ". Back to teacher mode." << endl;
    cout << (course_num+3) << ". Logout." << endl;
    string ch_str = "";
    int ch = 0;
    while(ch_str < "1" || ch_str > to_string(course_num+3) || ch_str.size() != 1){
        cout << "Choice: ";
        cin >> ch_str;
    }
    ch = (int)ch_str[0] - 48;
    if(ch == (course_num+3)){
        cout << "Back to the Main Menu" << endl << endl;;
        return false;
    }
    else if(ch == (course_num+2)){
        if(simulate){
            Back_to_Teacher_mode();
            return false;
        }
        else{
            cout << "You are not available to do this" << endl << endl;;
        }
    }
    else if(ch == (course_num+1)){
        select_course();
    }
    else{
        cout << "----------Course Menu----------" << endl;
        index = ch - 1;
        cout << (*(course_arr[index]));
        cout << "1. Previous page." << endl;
        ch_str = "";
        ch = 0;
        while(ch_str < "1" || ch_str > "1" || ch_str.size() != 1){
            cout << "Choice: ";
            cin >> ch_str;
        }
        ch = (int)ch_str[0] - 48;
    }
    return true;
}
