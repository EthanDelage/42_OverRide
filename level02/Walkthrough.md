## Brief

This program will prompt the user two times in order to retrieve a password and username.

Both are store in buffers but `fgets` is used and there don't seem to be a way to overflow.

Instead, we can leverage the fact that the username is put inside the printf function.

## Exploit

The program read the flag and store it inside a buffer in the stack.

So we can craft a payload to print the string contained in this buffer.

To do so we need pop the argument in order to reach the `password` buffer where we will put the address of the `pass_content` buffer.

Via gdb we saw that the address of the `pass_content` buffer is `0x7fffffffe570`.

## Commands

```bash
(python -c "print('%p|' + '%c'*6 + ' || Flag: %s')"; python -c "print('\x70\xe5\xff\xff\xff\x7f')") | ./level02
```