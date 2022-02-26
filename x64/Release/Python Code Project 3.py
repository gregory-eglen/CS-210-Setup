# Python Code Project 3.py
# Written by: Gregory Eglen
# Date: 02/19/2022

import re
import string


def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v

# This function reads the input file and stores the items in a list which is returned
def ReadFile():
    # Opens input file
    f = open('CS210_Project_Three_Input_File.txt')

    # Reads file contents and stores them in a list of strings titled 'contents'
    contents = f.readlines()

    # Close File
    f.close()

    return contents

# This function takes a list and prints an item in the list once and the frequency the item appears in the list
def PrintList():
    contents = ReadFile()  # Variable that stores the input file in a list by calling ReadFile() function

    print(contents)

    # This for loop enumerates through the contents of the file and prints the frequency the item appears in the list
    for i, item in enumerate(contents):
        if i <= contents.index(item):
            print("{} {}".format(item.strip().ljust(16, ' '), contents.count(item)))

    print("\n")

# This function takes a string as an argument, calls capitalize on the string to format it correctly, and appends a new line to the string to properly find it in the list contents
def FindItem(search_term):
    search_list = ReadFile()                                               # Variable that stores the input file in a list by calling ReadFile()
    search_frequency = search_list.count(search_term.capitalize() + "\n")  # Stores the number of times the search term appears in the list
    return search_frequency                                                # Returns int representing the number of times the search term appears in the list

# This function reads the input file and creates a file called frequency.dat that records the items of the list and the frequency they appear in the list
def CreateDataFile():
    input_data = ReadFile()  # Variable that stores the input file contents in a list

    # Creates or opens the file to store the frequency list
    f = open('frequency.dat', 'w')

    # This for loop enumerates through the stored list and writes the information to the output file
    for i, item in enumerate(input_data):
        if i <= input_data.index(item):
            f.write(item.strip())
            f.write(' ')
            f.write(str(input_data.count(item)))
            f.write('\n')

    # Close the created file
    f.close()
