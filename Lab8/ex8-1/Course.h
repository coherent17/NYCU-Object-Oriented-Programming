#include <string>
#include <vector>

using namespace std;

class TA;
class Teacher;
class Student;

class Course {
   private:
    string id;
    string name;
    Teacher* teacher;
    vector<TA*> TAs;
    vector<Student*> students;

   public:
    Course(string id, string name, Teacher* teacher);

    void addTA(TA* ta);
    void addStudent(Student* student);

    void printInfo();

    string getName();
};