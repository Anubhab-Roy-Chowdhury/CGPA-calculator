#include<bits/stdc++.h>
using namespace std;
class Subject {
    public:
    string subjectname;
    int credits;
    float gradepoints;
    Subject(string subjectname, int credits, float gradepoints) {
        this->subjectname = subjectname;
        this->credits = credits;
        this->gradepoints = gradepoints;
    }

};
class Student{
    public:
    string studentname;
    vector<Subject> subjects;
    Student(string studentname) {
        this->studentname = studentname;
    }
    void addsubject(string subjectname, int credits, float gradepoints) {
        Subject newSubject(subjectname, credits, gradepoints);
        subjects.push_back(newSubject);
    }
    float calculateCGPA() {
        float totalGradePoints = 0.0;
        int totalCredits = 0;
        for (const auto& subject : subjects) {
            totalGradePoints += subject.gradepoints * subject.credits;
            totalCredits += subject.credits;
        }
        if (totalCredits == 0) return 0.0; // Avoid division by zero
        return totalGradePoints / totalCredits;
    }
    void displaycgpa() {
        cout << "CGPA for " << studentname << ": " << calculateCGPA() << endl;
    }



};
int main() {
   string studentname;
   int numofsubs;
   cout<<"Enter student name";
   getline(cin, studentname);
   cout << "Enter the number of subjects: ";
   cin >> numofsubs;
    cin.ignore(); // Ignore the newline character left in the input buffer
   Student student(studentname);
   for(int i=0;i<numofsubs;i++){
    string subjectname;
    int credits;
    float gradepoints;
    
    cout<< "Enter subject name: ";
    
    getline(cin, subjectname);
    cout << "Enter credits for " << subjectname << ": ";
    cin >> credits;
    cout << "Enter grade points for " << subjectname << ": ";
    cin >> gradepoints;
    
    student.addsubject(subjectname, credits, gradepoints);
   

 cin.ignore(); // Prepare for next getline

   }
    student.displaycgpa();
   

    return 0;
}