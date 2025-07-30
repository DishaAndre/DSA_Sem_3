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
        cin >> name;
        cout << "Enter Salary of the Employee: ";
        cin >> salary;
        cout << endl;
}
void ShowData() {
    cout << "EMP-ID: " << empId << ", Name: " << name << ", Salary: " << salary << endl;
} 
friend int partition(Employee arr[], int low, int high);
friend void quickSort(Employee arr[], int low, int high);
};

int partition(Employee arr[], int low, int high) {
    int pivot = arr[high].empId; 
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j].empId < pivot) { 
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
return (i + 1);
}
void quickSort(Employee arr[], int low, int high) {
    if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}
}
int main() {
    cout << "Enter the number of the Employees: ";
    int n;
    cin >> n;
    Employee employees[n];
    cout << "Enter details of the employees:" << endl;
    for (int i = 0; i < n; i++) {
        employees[i].getData();
    }
    quickSort(employees, 0, n - 1);
    cout << "Employees arranged by Employee-ID in the Ascending Order are:" << endl;
    for (int i = 0; i < n; i++) {
        employees[i].ShowData();
    }
return 0;
}