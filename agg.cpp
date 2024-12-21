#include <iostream>
#include <string>

using namespace std;

class Character {
    private:
        int age;
        double height;
    public:
        Character() : age(0),height(0) {};
        Character(int a, double h) : age(a), height(h) {};
        int get_age(){ return this->age;}
        int get_height(){ return this->height;}
        virtual void power(int apple) = 0;
};

class Student : public Character {
    private: 
        string name;
        double grade;
    public: 
        Student() : Character(0,0), name("timothie"), grade(1.1) {};
        Student(int a, double h, string n, double g) : Character(a,h), name(n), grade(g) {};
        string get_name(){ return this->name;}
        double get_grade(){ return this->grade;}
        void set_name (string n_name){ this->name = n_name;}
        void set_grade(double n_grade){ this->grade = n_grade;}
        void power (int apple){
            double inflict = static_cast<double>(apple) * 1.5;
            cout << this->name << " cast a spell on there Teacher for " << inflict << " damage." << endl;
        }
};

class Teacher : public Character {
    private:
        string name;
        string subject;
    public: 
        Teacher() : Character(0,0), name("timothie"), subject("") {};
        Teacher(int a, double h, string n, string s) : Character(a,h), name(n), subject(s) {};
        string get_name(){ return this->name;}
        string get_subject(){ return this->subject;}
        void set_name (string n_name){ this->name = n_name;}
        void set_subject(string n_subject){ this->subject = n_subject;}
        void power(int apple){
            double myfavnum = static_cast<double>(apple) * 1.834295;
            cout << "Random Error " << myfavnum <<": The Teacher has quit as they are sick of this shit." << endl;
        }
};

class Classroom {
    private:
        Teacher** teachers;
        Student** students;
        int max_class_size;
        int current_student_num;
        int max_teacher_num;
    public:
        // initialise, add student, add teacher
        Classroom(int max_size, int max_teachers){
            this->max_class_size = max_size;
            this->max_teacher_num = max_teachers;
            students = new Student*[this->max_class_size];
            for (int i = 0; i < this->max_class_size; i++){
                students[i] = nullptr;
            }
            teachers = new Teacher*[this->max_teacher_num];
            for (int i = 0; i < this->max_teacher_num; i++){
                teachers[i] = nullptr;
            }
        }
        Classroom() : Classroom(0,0) {};
        bool add_student(Student* student){
            if (this->max_class_size == this->current_student_num){
                return false;
            }
            for (int i = 0; i < this->max_class_size; i++){
                if (students[i] == nullptr){
                    students[i] = student;
                    return true;
                }
            }
            return false;
        }
};

int main(void){

    Classroom A(10,2);

    Student* bob = new Student(15,180,"Bobby",99.1);

    cout << A.add_student(bob) << endl;

    return 0;
}