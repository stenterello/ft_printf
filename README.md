# ft_printf

The "ft_printf" repository contains the C implementation of a replica of the `printf` function with its major formatting functions and flags. This project focuses on providing a comprehensive and efficient implementation of the `printf` function.

The project is implemented in C and is part of the projects completed for the curriculum at 42School. It has achieved a score of 125 out of 100.

## Features

The "ft_printf" function supports the following formatting features:

- Conversion specifiers: `%d`, `%i`, `%u`, `%x`, `%X`, `%c`, `%s`, `%p`
- Flags: `-`, `0`, `+`, ` `, `#`
- Field width and precision

## Usage

1. Clone the repository to your local system:

   ```shell
   git clone https://github.com/stenterello/ft_printf.git

2. Navigate to the main directory of the repository

   ```shell
   cd ft_printf

3. Compile the program using the provided Makefile:

   ```shell
   make

4. Link the library to your project:
    - Include the header file in your source code:
		```shell
		#include "ft_printf.h"
	- Compile the source code with the library:
		```shell
		gcc your_source.c -L. -lft_printf -o your_program

## Project structure 

The repository structure is as follows:

- src/: Contains the source code files for the ft_printf implementation.
- includes/: Contains the header files.
- libft/: Contains the library functions used by ft_printf.
- Makefile: Compiles the project and creates the library.