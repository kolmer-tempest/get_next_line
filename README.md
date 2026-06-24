_This project as been created as part of the 42 curriculum by bpires-k._
#
# get_next_line
## Description
This project had the goal set to creat a custom functions that would read file and return it line by line, storing the current line until the next call of the function.
The bonus had the same objective but saved lines from diferent files at the same time, giving the user freedom to read different files at the same time.

I decided to aproach the project with a straight forward algorithm using string manipulation functions. The funtion will call a helper function that will save gradualy the line using the buffer size defined when compiling. After the loop detects a \n in the saved line it will return this string and the main function will process this string to save the string until the \n in a diferent variable and modify the line to save the begining of the next line until it reaches the end of the file, where the function just returns NULL. I used string manipulation functions because i think its easier to understand, implement and modify.
In the bonus part, i just needed to modify the variable were the line is stored to be an array of strings and save the maximum amount of files the system uses at the same time. 
## Instructions
This is a functions that needs a buffer size with the name BUFFER_SIZE to compile properly. If there is no indication of a buffer size or the size that was given is 0 or less the function just returns NULL. Make sure to always compile with -D BUFFER_SIZE=X and X being any number you desire
## Resources
I used mainly youtube videos, linux manuals and coding tutorials for reference and used custom testers check different cases, debug and test my functions.
I didn't use any kind of AI for this project.

