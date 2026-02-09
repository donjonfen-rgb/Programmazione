*This project has been created as part of the 42 curriculum by <ggaritta>*

# Get Next Line (GNL) Project
## Description
The Get Next Line (GNL) project is a programming exercise focused on reading text from a file or input stream line by line, handling arbitrary buffer sizes efficiently. The goal is to create a reusable function, typically called get_next_line(), which returns the next line of a file on each call, until the end of the file is reached.
Key aspects of this project include:
Handling buffered reading, preventing memory leaks, and efficiently managing dynamic memory.
Supporting multiple file descriptors simultaneously (optional, depending on project requirements).
Returning lines including the newline character, while handling files of unknown or large size.
This project is often used to strengthen understanding of file I/O, pointers, memory management, and dynamic data structures in C programming.
## Algorithm Explanation and Justification
The selected algorithm for get_next_line() is based on buffered reading with dynamic memory management:
### Static Buffer per File Descriptor:
A static buffer is maintained for each open file descriptor to store data read from the file but not yet returned.
This allows the function to handle multiple calls without losing previously read data.
### Reading in Chunks:
Data is read from the file in fixed-size chunks (BUFFER_SIZE) using the read() system call.
This prevents reading the entire file into memory at once, which is critical for large files.
### Line Extraction:
After each read, the buffer is scanned for a newline character (\n).
If found, the line is extracted and returned; remaining data is stored for the next call.
### Dynamic Memory Management:
The line is dynamically allocated based on its length.
Remaining buffer content is shifted to the start of the buffer to prepare for the next read.
### End-of-File Handling:
If read() returns 0 (EOF), any remaining data in the buffer is returned as the final line.
Subsequent calls return NULL.
### Justification:
This approach balances efficiency, correctness, and flexibility:
Efficient because it reads in chunks instead of character-by-character.
Correct because it handles files of arbitrary length, including edge cases (empty files, last line without newline).
Flexible because it supports multiple file descriptors concurrently using static storage.


# Get Next Line (GNL) Project

## Description
The **Get Next Line (GNL)** project is a programming exercise focused on reading text from a file or input stream **line by line**, handling arbitrary buffer sizes efficiently. The goal is to create a reusable function, typically called `get_next_line()`, which returns the next line of a file on each call, until the end of the file is reached.  

Key aspects of this project include:
- Handling **buffered reading**, preventing memory leaks, and efficiently managing dynamic memory.
- Supporting multiple file descriptors simultaneously (optional, depending on project requirements).
- Returning lines including the newline character, while handling files of unknown or large size.

This project is often used to strengthen understanding of **file I/O, pointers, memory management, and dynamic data structures** in C programming.

---

## Algorithm Explanation and Justification

The **selected algorithm** for `get_next_line()` is based on **buffered reading with dynamic memory management**:

1. **Static Buffer per File Descriptor**  
   - A static buffer is maintained for each open file descriptor to store data read from the file but not yet returned.
   - This allows the function to handle multiple calls without losing previously read data.

2. **Reading in Chunks**  
   - Data is read from the file in fixed-size chunks (`BUFFER_SIZE`) using the `read()` system call.
   - This prevents reading the entire file into memory at once, which is critical for large files.

3. **Line Extraction**  
   - After each read, the buffer is scanned for a newline character (`\n`).
   - If found, the line is extracted and returned; remaining data is stored for the next call.

4. **Dynamic Memory Management**  
   - The line is dynamically allocated based on its length.
   - Remaining buffer content is shifted to the start of the buffer to prepare for the next read.

5. **End-of-File Handling**  
   - If `read()` returns 0 (EOF), any remaining data in the buffer is returned as the final line.
   - Subsequent calls return `NULL`.

**Justification**:  
This approach balances **efficiency, correctness, and flexibility**:
- Efficient because it reads in chunks instead of character-by-character.
- Correct because it handles files of arbitrary length, including edge cases (empty files, last line without newline).
- Flexible because it supports multiple file descriptors concurrently using static storage.

---

## Instructions

### Compilation
Compile the project with:
```gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl_test```

Compile the bonus project with:
```gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils.c -o gnl_bonasso_test```

## Resources

GNU C Library Documentation – read(2)
- reference for low-level file reading.

Dynamic Memory Management in C
- guides on memory allocation for dynamic buffers.

Tutorials on file I/O and line reading in C:

42 Network GNL Project Guidelines

GeeksforGeeks: Reading a File Line by Line in C

## AI Assistance
AI was abused to:
Draft this README, not the markdown though, that I did.
It supported me in difficult times, i asked it jokes and an estimate of the end project date. Schedule events but didn't save those anwers. They were soundly wrong
