# 42 Academy+Plus - Libft
A 42 (school) project that required us to create our own library containing our implementation of some existing Standard C Library functions as well as some extra ones.

For more details regarding the project see Subject.pdf.

# Contents

Libc functions | Additional Functions | Bonus Functions | Personal Functions
:-----------: | :-----------: | :-----------: | :-----------:
 ft_memset		| ft_memalloc	| ft_lstnew		  |  
 ft_bzero		  | ft_memdel		| ft_lstdelone  | 
 ft_memcpy		| ft_strnew		| ft_lstdel		  | 
 ft_memccpy		| ft_strdel		| ft_lstadd		  |    
 ft_memmove		| ft_strclr		| ft_lstiter	  |  
 ft_memchr		| ft_striter	| ft_lstmap		  | 
 ft_memcmp		| ft_striteri	|	| 
 ft_strlen		| ft_strmap		|	|
 ft_strdup		| ft_strmapi	|	| 
 ft_strcpy		| ft_strequ		|	|
 ft_strncpy		| ft_strnequ	|	|
 ft_strcat		| ft_strsub		| |
 ft_strlcat		| ft_strjoin	| |
 ft_strchr		| ft_strtrim	| |
 ft_strrchr		| ft_strsplit	| |
 ft_strstr		| ft_itoa		  | |
 ft_strnstr		| ft_putchar	| | 
 ft_strcmp		| ft_putstr		| |
 ft_strncmp		| ft_putendl	| |
 ft_atoi		  | ft_putnbr		  | | 
 ft_isalpha		| ft_putchar_fd	| | 
 ft_isdigit		| ft_putstr_fd	| |
 ft_isalnum		| ft_putendl_fd	| | 
 ft_isascii		| ft_putnbr_fd	| | 
 ft_isprint		| | | 
 ft_toupper		| | |
 ft_tolower		| | |
 
 # How to use
 
 1. open a terminal and browse the **Libft** folder
 2. run the **Makefile** using the command **'make'** (this generates the library as **"libft.a"**)
 3. include **"libft.h"** header in your code and use any libft functions in your project
 4. compile your code with the library using `gcc -o myExecutable mySource.c libft.a`
 
 # How to test
 
If you want to test the code, or your own implementation of libft you can use @alelievr's [Libft Unit Test](https://github.com/alelievr/libft-unit-test) and follow the instructions on his repository.
