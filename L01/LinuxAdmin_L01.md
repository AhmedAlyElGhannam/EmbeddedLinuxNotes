# Linux Root Filesystem

## home/
folder for each user on the device

## bin/
folder containing all apps that can be run from any place (like GNU commands)

## sbin/
stands for system binaries --- creating user/changing user password/shutdown/network commands/... etc.
commands for communication + mounting + user stuff
**ALSO init applications _wink wink_** 

## etc/
aka configurations folder
contains all configuration files for all apps + contains users && their passwords + known wifi networks && their password + static IP for ethernet __wink wink__

## mnt/
basically the place where you can access your internal storage disks/other partitions (mounting points for block devices in the pc itself (not external memory devices) **wink wink**)

## media/
same as `mnt/` but for external storage devices

## dev/
stands for device --- pseudo folder --- holds all the devices on the system (aka device drivers aka files that represent deez devices **wink wink**)
*its size is ZERO...?!! (will know why soon enough! --- cuz it runs in RAM?!)*

## boot/
contains kernel files + bootloader (aka grub)

## opt/
contains optional/extra app configurations (not important)

## proc/ 
pseudo folder aka its size is 0 cuz all processes run in RAM --- it exists to let user know what processes are running on kernel (it is just an indicator and deleting it does not hurt the running processes; it just prevents the user from knowing what is running)

## sys/
pseudo folder aka its size is 0 cuz its contents are just representations for the actual hardware on my machine --- it exists to facilitate hardware register access for the user (deleting it will prevent the user from accessing their machine hardware)

## tmp/
pseudo folder --- temporary folder where files that you want to store temporarily --- deez files will be deleted upon a restart/shutdown/starting a new power cycle

## var/
contains logs --- kernel/daemon/device logs (deez files become large when playing with device drivers)

## usr/
mainly contains 4 directories: lib, bin, sbin, include
deez are the user's executables/libraries/system binaries/gcc header files + other stuff.

# Notes about libraries
1. `*.a` -> archive 
2. `*.so` -> shared object
3. Running over libraries saves RAM storage (app using deez libraries)

### Green -> executables vs Blue -> soft link
### `du` -> disk usage (used with files) 
### `shadow` file in /etc contains all passwords but encrypted
### `ldd` displays a binary's shared library dependency
### passing a flag to a command is either like `-r` for a single letter (hyphen) or like `--recursive` for a full word (n-dash aka 2 hyphens)
### deez are references that will be tackled `.` `..`
### `~` == current user's home directory
### `.` == current directory
### `..` == previous directory relative to current directory
### `cp` operates on files by default and needs to have `-r` flag to operate on directories

## Command Lines
1. `pwd` -> print working directory
1. `cd` -> change directory
1. `man` -> manual for **external commands** ([] option && <> must && ... multiple arguments) (-k + hint of the functionality of the command I am trying to run)
1. `rm` -> deletes a file or directory (-r == --recursive)
1. `ls` -> list directory content (-a == --all) (-l == long format) (-s == short format) (-h == human readable aka makes sizes printed in KB)
1. `help` -> manual for **internal commands** and some external commands
1. `type` -> shows info on the commands (internal commands are shown as shell built-in && external commands have their executable path printed on terminal aka location in /usr/bin)
1. `touch` -> creates an empty file with the given name (can create multiple files with the same command)
1. `mkdir` -> create directory (can create multiple directories with the same command)
1. `cp` -> copy directory or file (takes multiple source files/dirs and ONLY ONE destination)
1. `rmdir` -> removes an EMPTY directory
1. `cat` -> prints the content of a file on the terminal
1. `less` -> shows the content of a file in scrollable form (scroll up and down)
1. `more` -> same as `less` but scrolls faster and exits once you reach the end
1. 'search' -> searches files for stuff
1. `head` -> print 1st 10 lines of a file (-n NUM to print the 1st NUM lines in a file)
1. `tail` -> print last 10 lines of a file (-n NUM to print the last NUM lines in a file)
