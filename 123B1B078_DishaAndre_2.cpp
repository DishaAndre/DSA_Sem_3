 #include<iostream>
 #include<string>
 using namespace std;
 class Employee{      //creating class employee
      int id;
      string name;
      float salary;
      public:
            void get_data(){     //get and output member functions
                 cout<<"Enter employee id:";
                 cin>>id;
                 cout<<"Enter employee name:";
                 cin.ignore();  //To clear the buffer
                 getline(cin, name);
                 cout<<"Enter employee salary:";
                 cin>>salary;
            }    
            void display(){
                 cout<<id<<"   ";
                 cout<<name<<"     ";
                 cout<<salary<<endl;
            }
            //all the sorting functions are declared as friend functions of class employee
            
            friend void quick_sort(Employee A[], int s, int e);
            friend int partition(Employee arr[], int s, int e);
            friend void merge_sort(Employee A[], int left, int right);
            friend void merge(Employee arr[], int left, int mid, int right);
 };
 void quick_sort(Employee A[], int s, int e){ //recursive function
                 if(s < e){
                          int pivot_pos = partition(A, s, e);
                          quick_sort(A, s, pivot_pos - 1);
                          quick_sort(A, pivot_pos + 1, e);
                 }
 }
 int partition(Employee arr[], int s, int e){
                 int low = s;
                 int high = e;
                 int pivot = arr[high].id;
                 //assuming arr[high] as pivot
                 while(low < high){
                       while(arr[low].id < pivot)
                             low++;
                       while(arr[high].id >= pivot)
                       
                             high--;
                       if(low < high){
                             Employee t = arr[low]; //swap
                             arr[low] = arr[high];
                             arr[high] = t;
                       }
                 }
                 //allocating the pivote at right position
                 Employee t = arr[e];
                 arr[e] = arr[low];
                 arr[low] = t;
                 return low;//returning pivot's position
 }
 void merge(Employee A[], int left, int mid, int right){
            int n1 = mid - left + 1;
            int n2 = right - mid;
           //dynamic allocation of two new arrays
            Employee* leftarray = new Employee[n1];
            Employee* rightarray = new Employee[n2];
           
            for(int i = 0; i < n1; i++)
                leftarray[i] = A[left + i];
               
            for(int j = 0; j < n2; j++)
                rightarray[j] = A[mid + 1 + j];  
               
            int i = 0, j = 0, k = left;
            //merging
            while(i < n1 && j < n2){
                if(leftarray[i].name <= rightarray[j].name){
                    A[k] = leftarray[i];
                    i++;
                }
                else{
                    A[k] = rightarray[j];
                    j++;
                }
                k++;
            }
            while(i < n1){
                A[k] = leftarray[i];
                i++;
                k++;
            }
            while(j < n2){
                A[k] = rightarray[j];
                j++;
                k++;
            }
            //freeing the reserved memory
            delete[] leftarray;
            delete[] rightarray;
 }
 void merge_sort(Employee arr[], int left, int right){
            //recursive function
            if(left < right){
                int mid = left + (right - left) / 2;
                merge_sort(arr, left, mid);
                merge_sort(arr, mid + 1, right);
                merge(arr, left, mid, right);
            }        
}
 int main(){
             Employee Arr[20];
             int n, i;
             cout<<"Number of Employees:";
             cin>>n;
             for(i = 0; i < n; i++)  //geting input by user
                 Arr[i].get_data();
             merge_sort(Arr, 0, n - 1);
             cout<<"List of employees sorted as per alphabetical order using merge sort"<<endl;
             for(i = 0; i < n; i++)  //displaying output
                 Arr[i].display();
             cout<<"--------------------------------------"<<endl;
             quick_sort(Arr, 0, n - 1);
             cout<<"List of employees sorted as per id order using quick sort"<<endl;
             for(i = 0; i < n; i++)
                 Arr[i].display();
             cout<<"--------------------------------------"<<endl;
             return 0;
 }       