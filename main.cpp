#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ptr_intro();
void ptr_compiler_error();
void str_ptr();
void vector_ptr();
void dynamic_memory_allocation();
void array_offset_notation();
void string_ptr_nullcharcheck();
int *largest_int(int *int_ptr1, int *int_ptr2);
int *create_array(size_t size, int init_value);
void display(const int *const array, size_t size);
void reference_rng_loop();

int main(){
//	ptr_intro();
//	ptr_compiler_error();
//	str_ptr();
//	vector_ptr();
//	dynamic_memory_allocation();
//	array_offset_notation();
//	string_ptr_nullcharcheck();

//	int a {100};
//	int b {200};
//	
//	int *largest_ptr {nullptr};
//	largest_ptr = largest_int(&a,&b);
//	cout << *largest_ptr << endl;

//	int *my_array;
//	
//	int size, init_value;
//	
//	cout << "How many numbers are in the array: " << endl;
//	cin >> size;
//	cout << "Specify the initial value: " << endl;
//	cin >> init_value;
//	
//	my_array = create_array(size,init_value); // Create storage
//	// Use the array
//	display(my_array, size);
//	delete [] my_array; // Delete array

	reference_rng_loop();
	
	return 0;
}

void ptr_intro(){
	int num {10};
	cout << "Value of num is: " << num <<endl;
	cout << "sizeof of num is: " << sizeof num << endl;
	cout << "Address of num is: " << &num << endl;
	
	int *p {nullptr};
	
	cout << "Value of p is: " << p <<endl;	
	
	p = &num;
	
	*p = 100;
	
	cout << "Value of num is: " << num <<endl;	
	cout << "Value of p is: " << p <<endl;	
	
}

void ptr_compiler_error(){
	int num1 {10};
	double num2 {100.1};
	cout << "Value of num1 is: " << num1 <<endl;	
	cout << "Value of num2 is: " << num2 <<endl;		
	
	int *p_num {nullptr};
	
	p_num = &num1;
	
	cout << "Value of p_num is: " << *p_num <<endl;	
	
//	p_num = &num2; // Compiler Error: cannot convert double* to int* in assignment
	
	
}

void str_ptr(){
	string name {"Matthew"};
	string *p {&name};
	
	cout << "The name is: " << name <<endl;
	
	name = "George";
	
	cout << "The name is: " << *p <<endl; // Dereference the pointer to get the name value
}

void vector_ptr(){
	vector<string> names {"Lala", "Po", "TinkyWinky"};
	vector<string> *v_ptr {nullptr};
	
	v_ptr = &names;
	
	cout << "Printing names..." << endl;
	for (auto name: *v_ptr) {
		cout << name << endl;
	}
	cout << "\n" << endl;
	cout << "Printing names again..." << endl;
	for (int i=0; i<(*v_ptr).size();i++) {
		cout << (*v_ptr).at(i) << endl;
	}
}

void dynamic_memory_allocation(){
	int *int_ptr {nullptr};
	int_ptr = new int; //Allocate storage
	cout << "Current value of int_ptr: " << *int_ptr << endl;
	*int_ptr = 10;
	cout << "Current value of int_ptr: " << *int_ptr << endl;
	delete int_ptr; //Deallocate storage
	
//	dynamic sized array
	
	int *array_ptr {nullptr};
	int size {};
	
	cout << "How big do you want the array? ";
	cin >> size;
	
	array_ptr = new int[size]; // Allocate memory
	
	for (int i=0;i<size;i++) {
		*(array_ptr+i) = i; //Give element a value
		cout << *(array_ptr+i) << endl; // Print the element
	}
	
//	array_ptr = nullptr; // Don't do this -- leads to memory leak

	delete [] array_ptr; // Deallocate memory
	
}

void array_offset_notation(){
	int int_array[] {1,2,3};
	int *p {int_array};
	
	cout << "\nArray offset notation--------------------" << endl;
	cout << *int_array << endl;
	cout << *(int_array+1) << endl;
	cout << *(int_array+2) << endl;
	
	cout << "\nDereference then increment pointer-----------------------" << endl;
	while (*p < 4) {
		cout << *p++ << endl; //Dereference then increment the pointer
	}
	
}

void string_ptr_nullcharcheck(){
	char name [] {"Mike"};
	char *p {name};
	
	cout << "First Character is :" << *p << endl;
	cout << "Second Character is :" << *(p+1) << endl;
	cout << "Third Character is :" << *(p+2) << endl;
	cout << "Fourth Character is :" << *(p+3) << endl;
	cout << "Fifth Character is :" << *(p+4) << endl;
	
	cout << endl;
	
	cout << "Loop till null char...." << endl;
	
	while (*p != '\0') {
		
		cout << *p++ << endl;
	}
}

int *largest_int(int *int_ptr1, int *int_ptr2) {
	if (*int_ptr1 > *int_ptr2)
		return int_ptr1;
	else
		return int_ptr2;
}

int *create_array(size_t size, int init_value=0) {
	// Return dynamically allocated memory
	int *new_storage {nullptr};
	
	new_storage = new int[size];
	for (size_t i {0};i<size;++i)
		*(new_storage+i)=init_value;
	return new_storage;
}

void display(const int *const array, size_t size){
	for (size_t i {0};i<size;++i){
		cout << array[i] << " ";
	}
	cout <<endl;
}

void reference_rng_loop(){
	vector<string> stooges {"Larry", "Moe", "Curly"};
	
	for (auto &str: stooges) {
		str = "Funny"; // Changes the actual
	}
	
	
	
	for (auto str: stooges) {
		cout << str << endl;
	}
}

