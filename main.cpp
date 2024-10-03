//	   _____ _             _            _     _      _     _   
//	  / ____| |           | |          | |   | |    (_)   | |  
//	 | (___ | |_ _   _  __| | ___ _ __ | |_  | |     _ ___| |_ 
//	  \___ \| __| | | |/ _` |/ _ \ '_ \| __| | |    | / __| __|
//	  ____) | |_| |_| | (_| |  __/ | | | |_  | |____| \__ \ |_ 
//	 |_____/ \__|\__,_|\__,_|\___|_| |_|\__| |______|_|___/\__|
//
//	 Store a list of students (First Name, Last Name, Student ID, GPA). 
//	 Commands: 
//	 - ADD: adds a student to list
//	 - PRINT: print student list
//	 - DELETE: delete student by ID number
//	 - QUIT: quit application
//
//	 By: Sawyer Scheve
//
//	 Last Edited: 10/3/2024
//

#include "Arch-Linux-BTW.h"

struct student { // Student data type holds all of a given student's information.
	char first[81]; // First name.
	char last[81]; // Last name.
	int id; // ID number.
	float gpa; // GPA to two decimal places.
};

void Add(std::vector<student*> &list) { // Add a student to list.
	student* s = new student;

	// Set first name.
	std::cout << "First Name: ";
	std::cin >> s->first;
	
	// Set last name
	std::cout << "Last Name: ";
	std::cin >> s->last;

	// Set ID.
	std::cout << "ID: ";
	std::cin >> s->id;

	// Set GPA.
	std::cout << "GPA: ";
	std::cin >> s->gpa;

	list.push_back(s);
}

void Print(std::vector<student*> &list) { // Print the student list.
	for(int i = 0; i < list.size(); i++) {
		std::cout << list[i]->first << " " << list[i]->last << '\n' 
			<< list[i]->id << '\n' 
			<< std::setprecision(3) << list[i]->gpa << '\n' << std::endl;
	}
}

void Delete(std::vector<student*> &list) { // Delete student from list.
	int id;
	
	std::cout << "Student ID: ";
	std::cin >> id;

	for(std::vector<student*>::iterator i = list.begin(); i != list.end(); i++) {
		if((*i)->id == id) {
			delete *i;
			list.erase(i);
			return;
		}
	}
}

bool Quit() { // Quit program.
	return false;
}

// Entry point.
int main() {
	bool isRunning = true;
	std::vector<student*> list; // Student list
	
	// Program Loop
	while(isRunning) {
		char* command;

		std::cout << "Command [ADD, PRINT, DELETE, QUIT]: ";
		std::cin >> command;

		if(strcmp(command, "ADD") == 0) {
			Add(list);
		}
		if(strcmp(command, "PRINT") == 0) {
			Print(list);
		}
		if(strcmp(command, "DELETE") == 0) {
			Delete(list);
		}
		if(strcmp(command, "QUIT") == 0) {
			isRunning = Quit();
		}
	}
}
