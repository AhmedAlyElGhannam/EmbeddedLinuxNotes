# Session Two

## VIM
### Modes
#### Navigation Mode (View-Only Mode)
1. search ascendingly => `/TEXT`
1. search descendingly => `?TEXT`
1. find next precedence after searching => n
1. find previous after searching => N
> How to copy?
> > Copying a Word: press `v` then press arrow to select the word; then `yy` then esc.
> > Copying a Line: press `yy` at any position in line; then esc.

> How to paste?
> > Pasting a word: press `p`.
> > Pasting a Line: press `p`.

> How to delete?
> > Character-by-character: Press `x`.
> > Entire Line: Press `dd`.

> How to Undo?
> > Press `u`.

#### Insert Mode (Edit File)
1. press `i` to go to Insert Mode from Navigation Mode.

#### Command Mode 
1. press `:` to go to Command Mode from Navigation Mode.
1. `:wq` => save and quit.
1. `:q!` => exit without saving aka force quit.
1. `:q` => exit normally if you did not make any changes.
1. `:w` => save without exiting.

## nano
nano is simple enough and there is no need to explain it.

## Wildcards
> Used to signify a string of characters that I do not know. 
> > When searching for a file, I can write `Fa*` to say that the file starts with "Fa" and the rest is unknown; or I can write `*a*` to say that I know neither the beginning nor the end of the name.

> `*` is used for a string of characters, `?` is used for a single character.

```bash
	# list all files starting with h
	ls h*

	# copy all files with these extensions
	cp {*.pdf, *.jpg} DESTINATION

	# if I want to search for a file names "proactive"
	ls ????????? 	# will give me all files with names of 9 characters
	ls p???????? 	# will give me all files with names of 9 characters starting with p
	ls p???[a-d]*  	# will give me all files with names starting with p and the 5th char is either a || b || c || d (name length is not determined here due to use of wildcard)
```

## Searching Commands

### grep
> used to search for a pattern in a file.
```bash
# grep PATTERN FILE
grep main main.c
```
> > the flag `-i` is used to be case insensitive (when searching for patterns in files or files in directories).
> > the flag `-r` is used to search for a file inside a directory.
> > the flag `-n` is used to print the line number where the pattern is present inside the file.
> > the flag `-`

## Environment Variables
> In order to access environment variables, use `${VAR}`; also, print their value using `echo`.
> > `HOME` == /home/nemesis
```bash
echo ${HOME} # prints /home/nemesis
```
> > `PWD` == current working directory
```bash
echo ${PWD} # prints /home/nemesis/Playground/EmbeddedLinuxNotes
```
> > `USER` == stores current user name
```bash
echo ${USER} # prints nemesis
```
> > `HOSTNAME` == stores device name
```bash
echo ${HOSTNAME} # prints hahamakingmachine
```

> > `PATH` == stores all paths to executables (aka external commands)
```bash
echo ${PATH} # prints /home/nemesis/.cargo/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
```
> > in order to add an executable path to environment variables:
```bash
# PATH="${PATH}:NEW_PATH_TO_EXECUTABLE"
PATH="${PATH}:${PWD}" # while standing @ directory where executable is located
```
> > Changes to PATH is NOT permanent; it reverts to its default state once the shell session ends.

### Variables are either `Local` || `Global`
> What does it mean when I say this variable is "Global"?
> > It means that all instances of the shell are inherited from a process that has all of these "environment variables" recognized. 

> How to make a variable Global?
> > preceed the variable definition with the keyword `export`.
```bash
export MYVAR="HELLO"
```
> > This makes all shell instances birthed from where this variable is defined see the definition of MYVAR.

> How to make a variable Local?
> > just define the variable without export.
```bash
MYVAR="HELLO"
```
> > This makes MYVAR only visible in this shell instance ONLY.

> What makes environment variables like SHELL and HOME visible to all shell instances?
> > cuz they are defined by the `init` process; the place where all shell instances are birthed from.

> How to delete a Global variable?
> > use the flag `-d` as seen below:
```bash
export -d MYVAR="HELLO"
```

> In order to show ALL global variable + environment variables => use `env`
```bash
SHELL=/bin/bash
SESSION_MANAGER=local/hahamakingmachine:@/tmp/.ICE-unix/1986,unix/hahamakingmachine:/tmp/.ICE-unix/1986
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
SSH_AGENT_LAUNCHER=gnome-keyring
XDG_MENU_PREFIX=gnome-
.
.
.
```

### Command Execution
> For internal commands: bash asks itself if the command is known or not ? Known => execute it : not known => search for its path in PATH variable and forky forky aka fork() aka create a process for it.

## Alias (neither an external nor internal command)
> Give a command a nickname.
```bash
alias ahmed="ls -i"
```
> > To delete an alias => use `unalias`.

## Creating User Environment
> .bashrc == hidden file contains the startup script for bash => to customize its appearance + execute commands on startup + append PATH environment variable + create command alias. (works only with bash)
> > In case the user is dumb enough to delete .bashrc => there is a backup copy stored in /etc called `bash.bashrc` (cuz it is a configuration file **wink wink**)

## Tricky Question: Who creates the PATH variable (or all environment variables) ?
> Init process; NOT .bashrc
