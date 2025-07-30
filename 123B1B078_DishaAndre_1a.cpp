
#include <iostream>
using namespace std;

class Student {
    int prn;
    string name;
    float sgpa;

    public:
    void get_Data() {
    cout << "Enter PRN of student : ";
    cin >> prn;
    cout << "Enter Name of the student : ";
    cin >> name;
    cout << "Enter SGPA of the student : ";
    cin >> sgpa;
    cout<<endl;
}
void Show_Data() {
    cout << "Roll No: " << prn << ", Name: " << name << ", SGPA: " << sgpa << endl;
}

friend void insertion_Sort(Student arr[], int n);

};
void insertionSort(Student arr[], int n) {
    for (int i = 1; i < n; i++) {
    Student temp = arr[i];
    int j = i - 1; 
    while (j >= 0 && arr[j].prn > temp.prn) {
    arr[j + 1] = arr[j];
    j--;
}
    arr[j + 1] = temp;
}
}


int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Student s[n];
    cout << "Enter details of students:"<<endl;
    for (int i = 0; i < n; i++) 
        s[i].get_Data();

    cout << "Unsorted data of students:"<<endl;
    for (int i = 0; i < n; i++) 
        s[i].Show_Data(); 

    insertion_Sort(s, n);
    cout << "Students in ascending order of PRN:"<<endl;
    for (int i = 0; i < n; i++) 
        s[i].Show_Data(); 

return 0;
}