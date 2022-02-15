// CPPCode.cpp
// Written by: Gregory Eglen
// Date: 02/15/2022

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

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
	PyObject* my_module = PyImport_ImportModule("PythonCode");
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
	pName = PyUnicode_FromString((char*)"PythonCode");
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
	pName = PyUnicode_FromString((char*)"PythonCode");
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

// Changed main return type to int
int main() {
	int menuInput = 0;                                                                       // Variable to store user input for the menu
	int userInput = 0;                                                                       // Variable to store user input integer to perform listed functions

	// Menu loop that exits if a user enters 3
	while (menuInput != 3) {
		cout << "\n1: Display a multiplication table" << endl;
		cout << "2: Double a value" << endl;
		cout << "3: Exit" << endl;
		cout << "Enter your selection as a number 1, 2, 3. \n" << endl;
		cin >> menuInput;

		// A loop that returns to the menu if any of the input checks fail
		while (true) {
			// Input validation to ensure a user enters an integer
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "\nInvalid input. Please enter a number. \n" << endl;
				break;
			}

			// Input validation to ensure a user enters a valid menu selection
			if (menuInput < 1) {
				cout << "\nInvalid input.Please enter number 1, 2, or 3. \n" << endl;
				break;
			}

			// Input validation to ensure a user enters a valid menu selection
			if (menuInput > 3) {
				cout << "\nInvalid input.Please enter number 1, 2, or 3. \n" << endl;
				break;
			}
			break;
		}

		// A switch statement that handles validated menuInput to run the correct function the user desires
		switch (menuInput) {
			
			case 1:
				cout << "\nMultiplication Table" << endl;
				cout << "Enter an integer to create the multiplication table:" << endl;
				cin >> userInput;
				
				// Input validation to ensure a user enters an integer
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "\nInvalid input. Please enter a number. \n" << endl;
					break;
				}

				cout << "\nInteger used to create multiplication table: " << userInput << endl;
				cout << "Your table results:\n" << endl;
				cout << callIntFunc("MultiplicationTable", userInput) << endl;                   // Calls the Python function MultiplcationTable that creates the table from the entered integer
				break;

			case 2:
				cout << "\nDouble a Value" << endl;
				cout << "Enter an integer to be doubled:" << endl;
				cin >> userInput;

				// Input validation to ensure a user enters an integer
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "\nInvalid input. Please enter a number. \n" << endl;
					break;
				}

				cout << "\nInteger to be doubled: " << userInput << endl;
				cout << "Your result: " << callIntFunc("DoubleValue", userInput) << endl;       // Calls the Python function DoubleValue that doubles the entered integer
				break;

			default:
				break;

		}
	}

	cout << "\nExiting program. Have a wonderful day!" << endl;

	// Commented out the example code from the provided file
	//CallProcedure("printsomething");
	//cout << callIntFunc("PrintMe","House") << endl;
	//cout << callIntFunc("SquareValue", 2);

	return 0;
}