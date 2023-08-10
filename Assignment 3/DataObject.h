#pragma once
#include <iostream>

// A struct to replace the standard data value to be stored within each node of each double linked list of the hash table
struct DataObject {
public:
	const char* name;
	unsigned int age;
	unsigned int salary;

	// An overloaded operator for making the record that calls it equal to another nominated record
	void operator = (const DataObject rhs) {
		this->name = rhs.name;
		this->age = rhs.age;
		this->salary = rhs.salary;
	};

	// An overloaded operator for checking whether the record that calls it is identical to another nominated record
	bool operator == (const DataObject rhs) {
		// If any of the record particulars are different, return that they do not match (false)
		if (!(this->name == rhs.name) || !(this->age == rhs.age) || !(this->salary == rhs.salary)) {
			return false;
		}
		// Otherwise return that they do match (true)
		return true;
	};

	// A function for printing this one data object to the console
	void Print() {
		std::cout << "\tName: [" << this->name << "]\tAge: [" << this->age << "]\tSalary: [" << this->salary << "]." << std::endl;
	};
};