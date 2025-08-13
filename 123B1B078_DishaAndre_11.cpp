#include <iostream>
#include <string>
using namespace std;

#define TABLE_SIZE 10


class Employee {
public:
    int emp_id;
    string name;
    string phone_number;

    Employee(int id, string n, string phone) : emp_id(id), name(n), phone_number(phone) {}
    Employee() : emp_id(-1), name(""), phone_number("") {}  

    void display() {
        cout << "Employee ID: " << emp_id << ", Name: " << name << ", Phone: " << phone_number << endl;
    }
};


class HashTable {
private:
    Employee* table[TABLE_SIZE];
    string resolution_method;

    
    int hashFunction(int emp_id) {
        int sum = 0;
        while (emp_id != 0) {
            sum += emp_id % 10;
            emp_id /= 10;
        }
        return (sum * 3) % TABLE_SIZE;
    }

   
    int linearProbe(int index) {
        return (index + 1) % TABLE_SIZE;
    }

    int quadraticProbe(int index, int i) {
        return (index + i * i) % TABLE_SIZE;
    }

public:
    HashTable(string method = "linear") : resolution_method(method) {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

   
    void insert(Employee* emp) {
        int index = hashFunction(emp->emp_id);
        int i = 0;
        int original_index = index;

        while (table[index] != nullptr && table[index]->emp_id != -1) {
            if (resolution_method == "linear")
                index = linearProbe(index);
            else if (resolution_method == "quadratic")
                index = quadraticProbe(original_index, i++);
            
            if (i >= TABLE_SIZE) {
                cout << "Hash table is full, cannot insert employee." << endl;
                return;
            }
        }
        table[index] = emp;
    }

   
    Employee* search(int emp_id) {
        int index = hashFunction(emp_id);
        int i = 0;
        int original_index = index;

        while (table[index] != nullptr) {
            if (table[index]->emp_id == emp_id)
                return table[index];
            if (resolution_method == "linear")
                index = linearProbe(index);
            else if (resolution_method == "quadratic")
                index = quadraticProbe(original_index, i++);
            
            if (i >= TABLE_SIZE)
                return nullptr;
        }
        return nullptr;
    }

    
    void remove(int emp_id) {
        int index = hashFunction(emp_id);
        int i = 0;
        int original_index = index;

        while (table[index] != nullptr) {
            if (table[index]->emp_id == emp_id) {
                cout << "Deleting employee: ";
                table[index]->display();
                table[index] = new Employee();  
                return;
            }
            if (resolution_method == "linear")
                index = linearProbe(index);
            else if (resolution_method == "quadratic")
                index = quadraticProbe(original_index, i++);
            
            if (i >= TABLE_SIZE)
                return;
        }
        cout << "Employee ID " << emp_id << " not found." << endl;
    }

   
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            if (table[i] != nullptr && table[i]->emp_id != -1)
                table[i]->display();
            else
                cout << "Empty" << endl;
        }
    }
};


int main() {
    
    HashTable hashTable("linear");  
   
    Employee* emp1 = new Employee(101, "Alice", "1234567890");
    Employee* emp2 = new Employee(202, "Bob", "0987654321");
    Employee* emp3 = new Employee(303, "Charlie", "5678901234");
    Employee* emp4 = new Employee(404, "David", "3456789012");
    Employee* emp5 = new Employee(505, "Eva", "2345678901");

    hashTable.insert(emp1);
    hashTable.insert(emp2);
    hashTable.insert(emp3);
    hashTable.insert(emp4);
    hashTable.insert(emp5);

   
    cout << "Hash Table after insertion:" << endl;
    hashTable.display();


    int search_id = 303;
    Employee* found = hashTable.search(search_id);
    if (found != nullptr) {
        cout << "\nFound: ";
        found->display();
    } else {
        cout << "\nEmployee ID " << search_id << " not found." << endl;
    }

    int delete_id = 202;
    hashTable.remove(delete_id);
    
  
    cout << "\nHash Table after deletion:" << endl;
    hashTable.display();

    return 0;
}