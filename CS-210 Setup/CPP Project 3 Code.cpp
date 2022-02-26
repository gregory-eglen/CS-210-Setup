// CPP Project 3 Code.cpp
// Written by: Gregory Eglen
// Date: 02/19/2022

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <vector>
#undef max

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char *procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("Python Code Project 3");
	PyErr_Print();	
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen: 
		You sent me: Test
Return:
	100 is returned to the C++	
*/
int callIntFunc(string proc, string param)
{
	char *procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char *paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject *pName, *pModule, *pDict, *pFunc, *pValue = nullptr, *presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"Python Code Project 3");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char *procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject *pName, *pModule, *pDict, *pFunc, *pValue = nullptr, *presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"Python Code Project 3");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


// Function that display's the program's main menu
void DisplayMenu() {
	cout << "****************************" << endl;
	cout << "* Grocery Tracking Program *" << endl;
	cout << "****************************" << endl;
	cout << "\n" << endl;

	cout << "1. Produce a list of all items purchased in a given day along with the number of times each item was purchased\n" << endl;
	cout << "2. Produce a number representing how many times a specific item was purchased in a given day\n" << endl;
	cout << "3. Produce a text-based histogram listing all items purchased in a given day,\n   along with a representation of the number of times each item was purchased\n" << endl;
	cout << "4. Exit program\n\n" << endl;
}

// Function that is called when a user inputs an invalid menu option
void InvalidMenuSelection() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\nInvalid menu selection. Please enter a valid option." << endl;
}

// Function that returns an int representing a menu selection option used for choosing which function for the program to perform
int MenuSelection() {
	int menuSelection = 0;                          // Variable to store user's menu selection
	
	cout << "Please make a menu selection" << endl;
	cin >> menuSelection;                           // Prompt user for thier menu selection


	// While loops used to validate user input
	while (cin.fail()) {
		InvalidMenuSelection();
		cin >> menuSelection;
	}

	while (menuSelection < 1) {
		InvalidMenuSelection();
		cin >> menuSelection;
	}

	while (menuSelection > 4) {
		InvalidMenuSelection();
		cin >> menuSelection;
	}

	return menuSelection;

}

// A function that takes an int as an argument to perform the user's requested function
// This function returns an int value for the main loop to determine if the program has been terminated
int PerformFunction(int functionSelected) {
	string itemSearch = "";             // Variable to store the item a user wishes to search for
	ifstream inFS;                      // Input file stream
	string itemName = "";               // Data value to store item name
	int itemFrequency = 0;              // Data value to store item frequency
	vector<string> itemsVector;         // Vector to store item names
	vector<int> frequencyVector;        // Vector to store item frequency
	int i = 0;                          // Integer for loops

	// Switch statement that checks the passed int and calls the appropriate function the user has chosen
	switch (functionSelected) {

		// Calls Python Function that prints the list from the input file
		case 1:
			cout << "---------------------------------------------" << endl;
			cout << "| Item          | Number of times purchased |" << endl;
			cout << "---------------------------------------------\n" << endl;
			CallProcedure("PrintList");
			break;

		// Outputs the results from the return of the called Python function to show the number of times an item appears in the list
		case 2: 
			cout << "\nWhich item would you like to search for? " << endl;
			cin >> itemSearch;
			cout << "\nSearching for: " << itemSearch << endl;
			cout << "\n" << itemSearch << " appears " << callIntFunc("FindItem", itemSearch) << " times in the list." << endl;
			cout << "\n" << endl;
			break;
		
		// Python function creates a frequency.dat file and C++ reads the created file to output the text-based histogram
		case 3:
			cout << "Creating frequency.dat file...\n" << endl;
			CallProcedure("CreateDataFile");

			cout << "Reading frequency.dat file...\n" << endl;
			
			// Try to open input file
			inFS.open("frequency.dat");

			// Throw error if unable to open file
			if (!inFS.is_open()) {
				cout << "Could not open file frequency.dat" << endl;
				return 1;                                                           // 1 indicates error
			}

			// Loop to store item names and frequencies in a vector
			while (!inFS.eof()) {
				inFS >> itemName;                                                   // Reads input from file
				
				if (inFS.fail()) {
					break;
				}

				itemsVector.push_back(itemName);                                    // Stores itemName in namesVector
				inFS >> itemFrequency;                                              // Reads input from file
				frequencyVector.push_back(itemFrequency);                           // Stores itemFrequency in frequencyVector
			}

			cout << "Closing file frequency.dat" << endl;
			inFS.close();                                                           // Closing file

			cout << "Histogram Results: \n" << endl;
			
			// For loop to ouput histogram
			for (i = 0; i < itemsVector.size(); i++) {
				cout << setw(0) << itemsVector.at(i) << setfill('*') << setw(frequencyVector.at(i)) << "" << endl;
			}
			cout << "\n" << endl;

			break;

		case 4:
			cout << "Exiting program. Goodbye, have a great day!\n" << endl;
			break;

		default:
			cout << "Exiting program. Goodbye, have a great day!\n" << endl;
			break;
	}

	return functionSelected;
}
int main(){ // Changed main() return type to int
	int loopInt = 0;                               // Variable to store loop integer
	
	// This is the main program loop. Loop is terminated if PerformFunction() returns 4, the exit option in the menu
	while (loopInt != 4) {
		DisplayMenu();
		loopInt = PerformFunction(MenuSelection());
	}
			
			
	// Commented out example code
	//CallProcedure("printsomething");
	//cout << callIntFunc("PrintMe","House") << endl;
	//cout << callIntFunc("SquareValue", 2);

	return 0;
}