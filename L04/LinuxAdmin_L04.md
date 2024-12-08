# Session Four

## Regarding Hard Links
> In order for Hard Links to be created successfully between two files, the two files MUST exist on the `same partition` && be the same fs format.

## Users
> `root` is a unique **user** that is created by default in any Linux distro and permissions do not apply to them (aka can do anything and everything without double checking like casually deleting the rootfs **boomvine sound effect**)

Users are classified into two categories:
1. Normal User -> can interact with shell && OS. *They are given a user ID ranging from 1000 to 40k `EXCEPT root user; which is given a user ID of 0`*
1. System User -> cannot access/interact with shell. They are basically an abstraction for some system commands like ethernet/networking protocols over ethernet implemented in the kernel. Upon calling `tftp` as a normal user, the system user for `tftp` executes all the commands given to it related to TFTP by the normal user. They are defined on kernel level. *They are given an ID ranging from 1 to 99.*
1. Service User -> cannot access/interact with shell. They are basically a wrapper app that is based on the same functionality of a *system user*. As a normal user, upon creating a user service aka an app, this user service can communicate with system user(s) and/or other user service/application that also depend on a system user(s). **Service Users ALWAYS run in the background.** Example on Service Users: GNOME, Some/IP. *They are given an ID ranging from 100 to 999.*

> `root` user is a mix between Normal User && System User---cuz they can access shell and are created by the kernel.

> `/etc/passwd` is the file that holds all the users in the system.
```bash
	user:password:UID:GID:comment:HOME_USER_DIR:SHELL
       # user_name
	     # password status for user (exists `x` || expired `!`)this field is always written as 'x' because passwords should be encrypted
		      # User ID (0-40k)
			   # Group ID 
				# info about this user
					# home user directory/playground (for Normal users it is /home/USER but service/system users will have different directory)
						      # path to shell (/usr/bin/false) for system/service users
```
> Note: Some service users has a `home` directory. But, most of them (also most of/if not all system users) has it written as `/nonexistent`.
> Note: All system/service users have their `SHELL` field written as `/bin/false` || `/bin/noshell`
> Note: The actual user password is stored in `/etc/shadow`. Obviously, the password is encrypted using `sha256`: a one way encryption algorithm.

### Print Password-related Info for a Given User
> `chage` command is used to print password-related info for a user.
```bash
chage -l nemesis

Last password change					: Sep 16, 2024
Password expires					: never
Password inactive					: never
Account expires						: never
Minimum number of days between password change		: 0
Maximum number of days between password change		: 99999
Number of days of warning before password expires	: 7
```
### Adding Users
> `useradd` is the command that adds user and is installed by default. It requires flags and has lots of options.
> `adduser` is a *perl script* that uses `useradd`. It has a user-friendly TUI and prompts the one creating the new user to enter simple data and it does the complex flags/configurations for them. **it requires sudo privilage/root access to execute it**
> both `useradd` && `adduser` are located under `/usr/sbin`.
> Deez commands edit two files: `/etc/passwd` && `/etc/group`.
### Theoretically, you can create a user MANUALLY by writing directly to `/etc/passwd`
```bash
sudo vim /etc/passwd
# Ahmed: :1002:1002:,,,:/home/Ahmed:/bin/bash
```
> you can also create the password MANUALLY by calling `sha256` and passing your password THEN pasting the output inside `passwd`.
```bash
sudo apt install hashalot # package required to use sha256
sha256
123
```

### `#!`
> The shebang `#!` is used with scripts to say how **it will be executed**. Like `/bin/bash` || `/bin/sh` || `/usr/bin/perl` || `/usr/bin/python3`.

### To Change Password
> `passwd` + user name
> This command edit the file `/etc/shadow`.

### File Types For Source Files && Scripts
1. `.c` -> UTF8.
1. script like `.py` || `.sh` -> ASCII 

### Red Hat VIMP Question: What is the difference between root and sudo?
### Networking Protocols supported by Linux kernel: http, TFTP, FTP, UDP, TCP, ssh

## Groups
Divided into two types:
1. Primary Group -> Unique for every user---can only hold one user. *Each user can ONLY belong to one Primary Group.*
1. Secondary Group -> Can hold an infinite amount of users. *Each user can belong to MULTIPLE secondary groups.*
> Putting a user in a secondary group **gives them all the permissions given to members of that group.**
> Groups are located in `/etc/group`.
### Creating a new Group
> `groupadd` + group\_name

### Adding a User to a Group
> Edit `/etc/group` directly || `usermod` + other arguments.

### Sudo Group
> A group of users that have `admin privilages` via the ability to execute a command named `sudo`.
> Sudo Group is located in `/etc/sudoers`.

### To edit sudo permissions
```bash
sudo visudo 
```

### To View Binary Files
```bash
strings /usr/sbin/useradd
```

### To change from one user to another
```bash
su USER_NAME # change user but remain inside the current directory
su - USER_NAME # change user and cd to their home directory
```

### To see all the processes that spawned from a process
> `pstree` to view all running processes with their children

### To view the PID of a child process
> `ps -aux | grep PROC_NAME` 

### Deleting a User
> `sudo userdel USER_NAME`

### Can I delete the root user? *hmmm...*
> Nope. Cuz root is responsible for the init process. 
