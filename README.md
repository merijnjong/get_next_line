# get_next_line
In this exercise I have to write a function that returns a line read from a file descriptor. 
Function name | get_next_line |
--- | --- |
Prototype | char *get_next_line(int fd); |
Turn in files | [get_next_line.c](https://github.com/merijnjong/get_next_line/blob/main/get_next_line.c), [get_next_line.utils.c](https://github.com/merijnjong/get_next_line/blob/main/get_next_line_utils.c), [get_next_line.h](https://github.com/merijnjong/get_next_line/blob/main/get_next_line.h) |
Parameters | fd: The file descriptor to read from |
Return value | Read line: correct behaviour<br />NULL: there is nothing else to read, or an error occured |
External functions | read, malloc, free |

### Instructions
* The function should return the line that was read.<br />
If there is nothing else to read or if an error occurred, it should return NULL.<br />
* The function should work as expected both when reading a file and when
reading<br />from the standard input.
* The returned line should include the terminating '\n' character,
except if the end of<br />the file was reached and it does not end with a '\n' character.
* The header file [get_next_line.h](https://github.com/merijnjong/get_next_line/blob/main/get_next_line.h) must at least once contain the prototype of the
<br />get_next_line() function.
* All the helper functions needed should be added in the [get_next_line.utils.c](https://github.com/merijnjong/get_next_line/blob/main/get_next_line_utils.c) file
* Because the function will have to read files in get_next_line(), add this option to the<br />
compiler call: -D BUFFER_SIZE=n<br />
It will define the buffer size for read().<br />
The buffer size value will be modified by peer-evaluators and the Moulinette grading<br />system
in order to test the code.<br />
* Compile the code as follows (a buffer size of 42 is used as an example):<br />
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 "files".c<br />

### Forbidden
* It is not allowed to use the function library created in the previous [libft](https://github.com/merijnjong/libft) project.
* lseek() is forbidden.
* Global variables are forbidden.<br />

### Bonus part
* Develop get_next_line() using only one static variable.
* get_next_line() can manage multiple file descriptors at the same time.<br />
For example, if it can read from the file descriptors 3, 4 and 5, it should be
able to read<br />from a different fd per call without losing the reading thread of each
file descriptor or<br />returning a line from another fd.<br />
It means that it should be able to call get_next_line() to read from fd 3, then
fd 4, then 5,<br />then once again 3, once again 4, and so forth.
* Append the "_bonus.[c\h]" suffix to the bonus part files.
It means that, in addition to the<br />mandatory part files, the 3 following
files will be turned in:<br />
• [get_next_line_bonus.c](https://github.com/merijnjong/get_next_line/blob/main/get_next_line_bonus.c)<br />
• [get_next_line_bonus.h](https://github.com/merijnjong/get_next_line/blob/main/get_next_line_bonus.h)<br />
• [get_next_line_utils_bonus.c](https://github.com/merijnjong/get_next_line/blob/main/get_next_line_utils_bonus.c)
