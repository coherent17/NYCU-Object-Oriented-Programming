#include <vector>
#include <string>

using namespace std;

class Personnel;
class Student;
class Teacher;
class TA;
class Course;

class E3 {
    vector<Personnel*> personnels;
    vector<Student*> students;
    vector<Teacher*> teachers;
    vector<TA*> TAs;

    vector<Course*> courses;

   public:
    ~E3();
    void importPersonnelsFromCsv(string csvFilename);
    void importCoursesFromCsv(string csvFilename);

    void printAllPersonnel();
    void printAllCourse();
};