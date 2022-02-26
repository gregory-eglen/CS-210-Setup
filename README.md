# CS-210-Setup
This is the completed project 3 for my CS-210 class at SNHU

* Summarize the project and what problem it was solving.  
This project was a simulated commission by a fictional grocery store called "Corner Grocer". It is a project that combined C++ and Python. C++ was used to handle the menu options and user input. Python was used to analyze the input data file and create the output file. The program they requested was a grocery tracking program that would analyze an input txt file representing their produce sales for the day. The program should be able to produce a list of the sold items, along with the quantity sold. The program should allow a user to search for an item and return the amount of that item that was sold today. The program should also be able to output a .dat file containing a list of the items sold and the quantity sold. The last task the program must perform is to take the .dat file as an input and produce an on screen pictograph of the items sold and the quantity sold.

* What did you do particularly well?  
My program is very well organized. My code utilizes whitespace in a consistant manner and is very human readable. Every function I created has comments associated with it in order for others to understand the purpose of the function. Every function works as intended. The main() function in my C++ code has very few lines of code.

* Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?  
Enhancements to my code could include moving my C++ functions into a seperate file that could be included into the main C++ file. This would enhance the program by reducing recompilation time if the program was to be expanded upon. Enhancements to the functionality of the program could include being able to edit the output file if there needed to be a correction in the amount sold of a particular item. 
    
* Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?  
The biggest challenge I had in creating this program was getting the input .txt file to read correctly. The code I wrote uses readlines() Python functionality to read the inputs. I kept encountering a problem with the input file that would not store the last item in the file correctly because of the lack of a new line at the end of the file. I was able to get the functionality correct by inserting a new line at the end of the input file. I would have liked to be able to make the program work without this modification but I wasn't sure how. The most important resource I had when solving issues during this class was Google. Google results in Stack Overflow and other websites were invaluable for correcting errors and remembering proper syntax for some of the functions I used while writing the Python code.
    
* What skills from this project will be particularly transferable to other projects or course work?  
Before working on this project I was unaware how different programming languages can link together in a single project. Seeing the ability of C++ to use Python or another language and compile it into a working program was a cool skill to learn that should prove invaluable in my career.
    
* How did you make this program maintainable, readable, and adaptable?  
I made this program readable and maintainable by making sure I had plentiful comments and good usage of whitespace. Another programmer should be able to look at my code and understand everything the functions I wrote are doing. This is an important skill because in the future I may be working with many other people and programmers should make it easy for other humans to understand what the lines of code we write are doing.
