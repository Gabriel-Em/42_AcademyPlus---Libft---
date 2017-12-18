# 42 Academy+Plus - Libft
A 42 (school) project that required us to create our own library containing our implementation of some existing Standard C Library functions as well as some extra ones.

For more details regarding the project see Subject.pdf.

# Contents

## Libc functions
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memccpy
- ft_memmove
- ft_memchr
- ft_memcmp
- ft_strlen
- ft_strdup
- ft_strcpy
 -ft_strncpy
- ft_strcat
- ft_strlcat
- ft_strchr
- ft_strrchr
- ft_strstr
- ft_strnstr
- ft_strcmp
- ft_strncmp
- ft_atoi
- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint
- ft_toupper
- ft_tolower

## Additional Functions
- ft_memalloc 
- ft_memdel
- ft_strnew
- ft_strdel
- ft_strclr
- ft_striter
- ft_striteri
- ft_strmap
- ft_strmapi
- ft_strequ
- ft_strnequ
- ft_strsub
- ft_strjoin
- ft_strtrim
- ft_strsplit
- ft_itoa
- ft_putchar
- ft_putstr
- ft_putendl
- ft_putnbr
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

## Bonus Functions
- ft_lstnew
- ft_lstdelone
- ft_lstdel
- ft_lstadd
- ft_lstiter
- ft_lstmap

## Personal Functions
- ft_swap
- ft_strrev
- ft_quicksort
- ft_pow
- ft_min
- ft_max
- ft_isspace
- ft_isupper
- ft_islower
- ft_intlen
- ft_putnbrtab
- ft_word_count
- ft_lstappend

# How to use
 
 1. open a terminal and browse the **Libft** folder
 2. run the **Makefile** using the command **'make'** (this generates the library as **"libft.a"**)
 3. include **"libft.h"** header in your code and use any libft functions in your project
 4. compile your code with the library using `gcc -o myExecutable mySource.c libft.a`
 
# How to test
 
If you want to test the code, or your own implementation of libft you can use 
- @alelievr's [Libft Unit Test](https://github.com/alelievr/libft-unit-test)
- @yyang42's [moulitest](https://github.com/yyang42/moulitest)
- @TinfoilPancakes's [libft-testing-tools](https://github.com/TinfoilPancakes/libft-testing-tools)
- @jtoy's [Libftest](https://github.com/jtoty/Libftest) 

and follow the instructions on their repositories. (*Note: by the time you're reading this there's a good chance there are a lot more libft testers out there, so look them up yourself as well.*)
