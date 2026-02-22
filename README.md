*This project has been created as part of the 42 curriculum by aalkiz.*

## Description
This project is about programming a function that returns a line read from a file descriptor. Repeated calls to the function allow you to read the text file pointed to by the file descriptor, one line at a time. It returns the line that was read, or NULL if there is nothing left to read or if an error occurs.

## Algorithm and Explanation
The algorithm relies heavily on utilizing a static variable. This allows the function to remember the reading state between successive calls. The logic is designed to read as little as possible each time it is called, returning the current line as soon as a newline character is encountered.

## Instructions
The project requires a specific compilation flag, `-D BUFFER_SIZE=n`, to define the buffer size for the `read()` function. 

Compile your code as follows:
`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`