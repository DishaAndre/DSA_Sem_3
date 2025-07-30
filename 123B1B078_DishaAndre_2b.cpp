#include <iostream>
using namespace std;

class Employee {
    int empId;
    string name;
    float salary;
    public:
    void getData() {
        cout << "Enter the Employee-ID: ";
        cin >> empId;
        cout << "Enter Name of the Employee: ";
        cin>>name;
        cout << "Enter Salary of the Employee: ";
        cin >> salary;
        cout << endl;
    }
void ShowData() {
    cout << "EMP-ID: " << empId << ", Name: " << name << ", Salary: " << salary << endl;
} 
friend void merge(Employee arr[], int left, int mid, int right);
friend void mergeSort(Employee arr[], int left, int right);
};

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid; 
    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2]; 
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    int i = 0; 
    int j = 0; 
    int k = left; 
    while (i < n1 && j < n2) {
        if (L[i].name <= R[j].name) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    } 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    } 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}
void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right); 
        merge(arr, left, mid, right);
    }
}
int main() {
    cout<<"Enter the number of the employees : ";
    int n;
    cin>>n;
    Employee employees[n];
    cout << "Enter details of the employees:" << endl;
    for (int i = 0; i < n; i++) {
        employees[i].getData();
    }
    mergeSort(employees, 0, n - 1);
    cout << "Employees arranged in the alphabetically order by Name:" << endl;
        for (int i = 0; i < n; i++) {
        employees[i].ShowData();
    } 
return 0;
}