![Project banner](https://github.com/kmareev/holbertonschool-simple_shell/assets/158859905/edf52c87-0548-401a-983d-038c377b450d)


# C - Simple Shell Project

## Project Overview
This Simple Shell project has been developed by a pair of students from Holberton School, Australia. It is a basic implementation of a command-line interpreter, drawing inspiration from the Unix shell. It facilitates the reading of user commands from standard input, their interpretation, and subsequent execution of corresponding actions. 

This project aims to demonstrate fundamental concepts of system programming, such as process management and file I/O, while providing a simple yet functional shell interface.


## Flowchart
![Flowchart (2)](https://github.com/kmareev/holbertonschool-simple_shell/assets/158859905/7748ffbc-50db-42ff-97e4-1d55caccaebc)




## Requirements
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to.

## Usage

### Instalation:
To use our simple shell, you can clone this repository:<br>

```git clone https://github.com/kmareev/holbertonschool-simple-shell.git```

### Execute the program:
To run our Simple Shell :<br>

```./hsh```

### For compilation:
To compile the code:<br>

 ```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```

## Testing
Your shell should work this way in interactive mode:

```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

As well as in non-interactive mode:
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```


## Contributors
- [Krisha Valencia](https://github.com/kmareev)
- [Rungruj Thitichirathitikan](https://github.com/LukeRRT)

