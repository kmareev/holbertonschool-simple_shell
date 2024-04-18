Insert project image

# C - Simple Shell Project

## Project Overview


## Flowchart

## Usage

### To install the program:
To use our simple shell, you can clone this repository:<br>

```git clone https://github.com/kmareev/holbertonschool-simple-shell.git```

### To execute the program:
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


