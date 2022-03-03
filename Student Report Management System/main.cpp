#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdbool>
using namespace std;

class Student {
  public:
    string firstName, lastName;
    float arabicMark = 0, mathMark = 0, englishMark = 0, scienceMark = 0;

    void takeNames ();
    void takeMarks();
    void setFile();
    void setMark ();    
};

void presentation(int &);
void getFile();

int main() {

    int choice;
    bool loop = 1;

    while (loop) {
        presentation(choice);
        if (choice == 0) {
            loop = 0;
        }
        else if (choice == 1) {
            Student student;

            student.takeNames();
            student.takeMarks();
            student.setFile();
        }
        else if (choice == 2) {
            getFile();
        }
        else if (choice == 3) {
            Student newMark;
            newMark.setMark();
        }
        else {
            cout<< "Enter a correct choice!!!"<< endl;
        }
    }
}
void presentation(int &choice) {
    cout<< "\n0.exit"<< endl;
    cout<< "1.add new student or new Notes"<< endl;
    cout<< "2.get the information of student"<< endl;
    cout<< "3.change a subject's mark"<< endl;
    cout<< "enter your choice: "; cin>> choice;
}
void Student::takeNames () {
    cout<< "enter your first name: "; cin>> firstName;
    cout<< "enter your last name: "; cin>> lastName;
}
void Student::takeMarks() {
    cout<< "Arabic's mark: "; cin>> arabicMark;
    if (!(arabicMark <= 20 && arabicMark >= 0)) arabicMark = 0;
    cout<< "Math's mark: "; cin>> mathMark;
    if (!(mathMark <= 20 && mathMark >= 0)) mathMark = 0;
    cout<< "English's mark: "; cin>> englishMark;
    if (!(englishMark <= 20 && englishMark >= 0)) englishMark = 0;
    cout<< "Science's mark: "; cin>> scienceMark;
    if (!(scienceMark <= 20 && scienceMark >= 0)) scienceMark = 0;
}
void Student::setFile() {

    string fullName = firstName + " " + lastName;
    
    fstream fout(fullName, ios::out);
    fout<< "Arabic: "<< arabicMark<< endl;
    fout<< "Math: "<< mathMark<< endl;
    fout<< "English: "<< englishMark<< endl;    
    fout<< "Science: "<< scienceMark<< endl;
    fout<< "your Grade is: "<< setprecision(3)<< static_cast<float> ((arabicMark+mathMark+englishMark+scienceMark)/4);
}
void Student::setMark () {
    int newMark, isDone = 0, counter = 0;
    takeNames();

    string fullName = firstName + " " + lastName; 
    char *subject = new char[20], *str = new char[3];

    cout<< "enter the new mark: ";cin>> newMark;
    cout<< "enter subject's name: ";cin>> subject;
    subject = strlwr(subject);

    fstream fin(fullName, ios::in);
    while (fin>> str) {
        counter++;
        if (counter == 2) arabicMark = atoi(str);
        else if (counter == 4) mathMark = atoi(str);
        else if (counter == 6) englishMark = atoi(str);
        else if (counter == 8) scienceMark = atoi(str);
    }
    if (!strcmp(subject, "arabic")) {
        arabicMark = newMark;
        isDone = 1;
    }
    else if (!strcmp(subject, "math")) {
        mathMark = newMark;
        isDone = 1;
    }
    else if (!strcmp(subject, "english")) {
        englishMark = newMark;
        isDone = 1;
    }
    else if (!strcmp(subject, "science")) {
        scienceMark = newMark;
        isDone = 1;
    }
    
    if (isDone) setFile(); 
    else cout<< "enter a correct subject!!!"<< endl; 
}
void getFile() {

    string firstName, lastName, fullName, str;

    cout<< "Enter the first name: "; cin>> firstName;
    cout<< "Enter the last name: "; cin>> lastName;
    fullName = firstName + " " + lastName;

    fstream fin(fullName, ios::in);
    int counter = 0;

    while (fin>> str) {
        counter++;        
        if (counter%2 == 0 && counter < 9) {
            cout<< str;
            cout<< endl;
        }
        else
            cout<< str<< ' ';
    }
}
