#include<iostream>
using namespace std;
class  Student {
    int roll_no;
    string name;
    float sgpa;
 public:
    void get_data() {
        cout << "Enter name of the student: ";
        cin >> name;
        cout << "Enter roll no of the student: ";
        cin >> roll_no;
        cout << "Enter SGPA of the student: ";
        cin >> sgpa;
    }
    void display() {
        cout << name << "       " << roll_no << "      " << sgpa << endl;
    }
    // Friend functions for sorting
    friend void insertion_sort(Student A[], int size);
    friend void shell_sort(Student A[], int size);
    friend void radix_sort(Student A[], int size);
    friend void count_sort(Student A[], int size, int exp);
    friend Student get_max(Student A[], int n);
 };
 Student get_max(Student A[], int n) {
    Student max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i].sgpa > max.sgpa)
            max = A[i];
    }
    return max;
 }
 void insertion_sort(Student A[], int n) {
    int i, j;
    Student t;
    for (i = 1; i < n; i++) {
        t = A[i];
        for (j = i - 1; j >= 0; j--) {
            if (A[j].roll_no > t.roll_no)
                A[j + 1] = A[j];
            else
                break;
        }
        A[j + 1] = t;
    }
 }
 void shell_sort(Student A[], int size) {
    int interval = size / 2;
    while (interval >= 1) {
        int i, j;
        Student t;
        for (i = interval; i < size; i++) {
            t = A[i];
            for (j = i - interval; j >= 0; j -= interval) {
                if (A[j].name > t.name)
                    A[j + interval] = A[j];
                else
                    break;
            }
            A[j + interval] = t;
        }
        interval /= 2;
    }
 }
 void count_sort(Student A[], int size, int exp) {
    Student output[size];
    int count[10] = {0};
    for (int i = 0; i < size; i++)

    
        count[int(A[i].sgpa * 100) / exp % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--) {
        output[count[int(A[i].sgpa * 100) / exp % 10] - 1] = A[i];
        count[int(A[i].sgpa * 100) / exp % 10]--;
    }
    for (int i = 0; i < size; i++)
        A[i] = output[i];
 }
 void radix_sort(Student A[], int size) {
    Student m = get_max(A, size);
    int max_sgpa = int(m.sgpa * 100);
    for (int exp = 1; max_sgpa / exp > 0; exp *= 10)
        count_sort(A, size, exp);
 }
 int main() {
    Student arr[15];
    int i, N;
    cout << "Enter the number of students: ";
    cin >> N;
    for (i = 0; i < N; i++)
        arr[i].get_data();
    insertion_sort(arr, N);
    cout << "Sorted by Roll No using Insertion Sort:" << endl;
    cout << "NAME" << "    " << "ROLL NO" << "  " << "SGPA" << endl;
    for (i = 0; i < N; i++)
        arr[i].display();
    cout << "--------------------------------------------------" << endl;
    shell_sort(arr, N);
    cout << "Sorted by Name using Shell Sort:" << endl;
    cout << "NAME" << "    " << "ROLL NO" << "  " << "SGPA" << endl;
    for (i = 0; i < N; i++)
        arr[i].display();
    cout << "--------------------------------------------------" << endl;
    radix_sort(arr, N);
    cout << "Sorted by SGPA using Radix Sort:" << endl;
    cout << "NAME" << "    " << "ROLL NO" << "  " << "SGPA" << endl;
    for (i = 0; i < N; i++)
        arr[i].display();
    return 0;
 }