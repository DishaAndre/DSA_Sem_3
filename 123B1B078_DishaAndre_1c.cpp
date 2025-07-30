#include <iostream>
using namespace std;

class Student {
    int rollNo;
    string name;
    float sgpa;
    
    public:
    void getData() {
        cout << "Enter Roll No of the student: ";
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
    friend int getMax(Student arr[], int n);
    friend void countSort(Student arr[], int n, int exp);
    friend void radixSort(Student arr[], int n);
};
int getMax(Student arr[], int n) {
    float max = arr[0].sgpa;
        for (int i = 1; i < n; i++) {
            if (arr[i].sgpa > max)
                max = arr[i].sgpa;
            }
    return int(max * 10);
}
void countSort(Student arr[], int n, int exp) {
    Student output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[(int(arr[i].sgpa * 10) / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(int(arr[i].sgpa * 10) / exp) % 10] - 1] = arr[i];
        count[(int(arr[i].sgpa * 10) / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void radixSort(Student arr[], int n) {
    int m = getMax(arr, n);
        for (int exp = 1; m / exp > 0; exp *= 10) {
            countSort(arr, n, exp);
        }
    }
int main() {
    cout << "Enter the number of the students: ";
    int n;
    cin >> n;
    Student students[n];
    cout << "Enter details of the students:"<<endl;
    for (int i = 0; i < n; i++) {
        students[i].getData();
    } 
    radixSort(students, n); 
    cout << "Top 10 Toppers by SGPA:"<<endl;
    for (int i = n-1; i >= n-10; i--) {
        students[i].ShowData();
    } 
return 0;
}