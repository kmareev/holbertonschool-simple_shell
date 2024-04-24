Insert project image

# C - Simple Shell Project

## Project Overview


## Flowchart
![Flowchart (1)](https://github.com/kmareev/holbertonschool-simple_shell/assets/158859905/d22ae80c-b06e-4754-8f5c-569829b31035)



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
To compile the code using :<br>

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

## Libraries

## Contributors


