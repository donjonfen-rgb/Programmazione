*This project has been created as part of the 42 curriculum by ggaritta.*

operations between linked lists
	https://www.youtube.com/watch?v=YjxKYxpf51E
	
	set int min and max as max values
	abs?
	costs?
- take > list of ints; 
- display sequence of instruction \n instruction
- if no param 
	are specified program must-n display anything, return to prompt
- errors handled "some arguments not being integers, some arguments
exceeding the integer limits, and/or the presence of duplicates." followed by ending with\n
100% moves limits > 100 nums 700 ops
					500 nums 5500 ops

EX {$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error}
EX2 {$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>}



## checker
h, c
makefile bonus rule
the checker as the bonus program has to read the prompt given by the Manda and execute those moves
- case of error, you must display "Error" followed by a ’\n’ on the standard error. 
Errors might be: 
	- args are not integers,
	- args are bigger than integer' -already managed-, 
	- there are duplicates, 
	- an instruction doesn’t exist and/or is incorrectly formatted.