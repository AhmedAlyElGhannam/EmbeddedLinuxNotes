# Session Three

## .profile
> unlike `.bashrc` that runs when a new bash terminal is created, `.profile` runs a number of commands **upon user login**---`.profile` is unique to every user.
> > `.profile` is used when even a shell is not present **boomvine sound effect**

> Scenario: putting `date` command in .profile will NOT show the output if by default my Linux opens the desktop *since it needs a terminal to show its output on a terminal* --- so, hypothetically, we can make the OS launch into a TERMINAL by default and the `data` will be executed and its output will be displayed successfully.

> > `.profile` is present in /home/nemesis [aka unique for each user]
> > a backup copy is stored in /etc
> > the ACTUAL file that has the OG copy is located in `/etc/skel`
> > > The previous 3 points also apply to `.bashrc`


## Defining a Global & Local Variable (LOOK THIS UP)
> Global -> env for external commands && export -p for internal command in bash
> Local -> set for external commands


## Piping 
> piping `|` is a type of interprocess communication (IPC).
> > instead of giving a process/executable and input argument, the output of a process/executable is given to another process/executable as its input argument.

```bash
cat file.txt | grep Fady # instead of printing the .txt content on the terminal, it is given as an input argument to grep to search it for the pattern `Fady`
```

```bash 
cat oldpasswd | grep yasm* | tr ":" "\n"
```
> `tr` command replaces every instance of a character in a given input stream with another character.

```bash
cat oldpasswd | grep yasm /etc/group
```
> This type of piping will be ignored and `grep` will give priority for the file it is given over the one passed by piping.


## Redirection
> redirection is NOT used with 2 processes: it is used with a process + file(s) **wink wink**
> `>` (also known as `1>` **boomvine sound effect**) is used to print the output of a process into a **FILE**. It overwrites the file content (aka it deletes and writes from scratch)
```bash
cat hehe.txt > file.txt
```
> '>>' is used to print the output of a process into a **FILE**. It appends the file content.
```bash
cat haha.txt >> file.txt
```
```bash
cmake --build build > log.txt >> history.txt 
```

### File Descriptor
> Each process has 3 files with the following 3 files with these descriptors created by default with the following functions:
> > 0: aka `stdin` -> it is used as input buffer for app from terminal.
> > 1: aka `stdout` -> it is used as output buffer for app to terminal.
> > 2: aka `stderr` -> it is used as output buffer for app errors to terminal.

### Creating a new EMPTY file
```bash
touch file
echo "" > file
vim file
```

### Showing the PID of a process in an opened terminal
```bash
ps -t /dev/pts/0
```

> `2>` is used to direct the stuff being printed to `stderr` (aka fd 2) to another file.
> > by extension, `NUM>` is used to direct the stuff being printed to file with fd NUM to another file.
```bash
./a.out Fady 2> error.txt
./a.out Fady 3> hello.txt
```

> `<` is used to direct the **content of a file to an executable** as its input argument.
```bash
./a.out < input.txt # contains 1 as input to a.out
```

### INPUT fd MUST be 0 but OUTPUT fd can be any fd even if it is 0

## Random Command Collection

> `whereis` prints the path of an app (must be defined under PATH environment variable)
```bash
whereis ls # /usr/bin
```

> `find` searches for a file/directory inside a directory
```bash
find . -name log # -name is used to when passing pattern name
```

> `locate` searches for a file in the entire system (it is slow, tho)

> `wc` prints the word count of a certain file
```bash
wc txt # always adds 1 for every EOL && 1 for EOF
wc -l txt # prints the number of lines inside a file
```

## Links

### Soft Links
> literally the same thing as shortcuts in Windows
```bash
ln -s OG_FILE SHCUT_FILE
```
> > fd is present in **RAM** and created alongside processes
> > inode is a struct (unique to every file) that contains all the metadata of a file --- it is created upon file creation and is stored on **disk** (its size is 4KB by default --- DEBATABLE)
> Soft link is a POINTER to a file's inode aka it is a shortcut to this file---its size is 6-8 bytes.

### Hard Links
> 
```bash
ln OG_FILE SHCUT_FILE
```
> Hard link is a reference to an inode (like in C++)---it has its problems but its size is literally 0B.

### Hard Links have their limitations compared to Soft Links (even tho soft links consume storage and hard links do not)
> Soft Links work for files && directories, but Hard Links work only for files.

> > `-i` flag prints inode of files when using `ls`

### How to cat the inode of a shortcut (when using cat with link, it prints the content of a file---just like how you can access the address of a pointer vs content of a pointer vs dereferencing a pointer)

### BRIGHTNESS TASK via a.out



