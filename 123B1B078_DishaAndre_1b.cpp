#include <iostream>
using namespace std;

    class Student {
    int rollNo;
    string name;
    float sgpa;

    public:
    void getData() {
        cout << "Enter the Roll No of student: ";
        cin >> rollNo;
        cout << "Enter Name of the student: ";
        cin >> name;
        cout << "Enter SGPA of the student: ";
        cin >> sgpa;
        cout<<endl;
}
void ShowData() {
    cout << "Roll No: " << rollNo << ", Name: " << name << ", SGPA: " << sgpa << endl;
}

friend void shellSort(Student arr[], int n);

};


void shellSort(Student arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Student temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].name > temp.name; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
int main() {
    cout << "Enter the number of students: ";
    int n;
    cin >> n;
    Student students[n];
    cout << "Enter details of the students:" << endl;
    for (int i = 0; i < n; i++) {
        students[i].getData();
    }
    shellSort(students, n);
    cout << "Students list arranged alphabetically using the Shell Sort:" << endl;
    for (int i = 0; i < n; i++) {
        students[i].ShowData();
    }
return 0;
}