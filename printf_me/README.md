*This project has been created as part of the 42 curriculum by <ggaritta>*

# LibftPrintf
## The subject of this project is to recode the behaviours of the Printf function

- Do not implement the buffer management of the original printf().
- Your function has to handle the following conversions: cspdiuxX%
- Your function will be compared against the original printf().
- You must use the command ar to create your library. Using the libtool command is forbidden.
- Your libftprintf.a has to be created at the root of your repository.
- Your header file must be named ft_printf.h and must contain the prototype of your ft_printf() function.

## From us is asked to implement:
- **`%c`** Prints a single character.
- **`%s`** Prints a string (as defined by the common C convention).
- **`%p`** The void * pointer argument has to be printed in hexadecimal format.
- **`%d`** - Prints a decimal (base 10) number.
- **`%i`** Prints an integer in base 10.
- **`%u`** Prints an unsigned decimal (base 10) number.
- **`%x`** Prints a number in hexadecimal (base 16) lowercase format.
- **`%X`** Prints a number in hexadecimal (base 16) uppercase format.
- **`%%`** Prints a percent sign.

## Resources:
The resulting project was aided by many:
- yt videos: anyone that could ask the questions at the time. 
- webpages like: stackoverflow, w3school, geeksforgeeks and such.
- others readme files tutorials

## Instructions

### updates
The Plan:
	find % in the string in input if there is.
	if not print as it is "gibberish".
	if % is found, enter parsing mode.
		look for cspdiuxX%

#### 1024
```A buffer size of 1024 bytes is commonly used because it aligns with typical system buffer sizes and provides a good balance between efficiency and memory usage```
`This size is consistent with the default line buffer size for standard input when connected to a terminal, which is often set to 1024 bytes`
`Using a buffer size of 1024 is a practical choice that minimizes the number of system calls while avoiding excessive memory allocation`

---

```sh
make - builds the project
```
# resources
	https://academichelp.net/coding/c-coding/write-to-a-file.html
	
## Uso dell’AI nel progetto
This Readme file was not subjected to AI prompts and modifications, neither was the code.
`when building main edge cases to test` or needed a schedule