## Brief

This program will iterate over our user input and lowercase every uppercase character that it find.
Then it uses our user input as a format string so we can exploit this.

## Exploit

Our user input is used as a format string of the printf function and then the exit function is called.

When `exit@plt` is called it jumps to the Global Offset Table (GOT) entry of the exit function by looking at the function pointer stored at address `0x080497e0`.

So we need to overwrite the value at address `0x080497e0` to point to the shellcode that we will put in our input.

Since the address of the buffer is pretty high (`0xffffd6a8`) we can't really print out that much character.
We will use the `h` format string in order to only write 2 bytes of memory.
This allow us to only print out up to `0xffff` character in total which is reasonable.

## Commands

To craft our payload we first need to put the addresses where we want to write in the stack.
These addresses are respectively `0x080497e0` and `0x080497e2` since we only write 2 byte at a time.
We also put a dummy 4 byte word in the stack which will be popped when using the padding format string.

Then we need to pop the stack 9 times in order to retrieve our user input in the stack.
Using the classic format string attack we pad the ninth argument to print the correct number of character.

Since our shellcode is located at `0xffffd6e6` after our format string, we first put `0xd6e6` in `0x080497e0`.
Then we use the dummy argument to pad a second parameter in order to write `0xffff` in `0x080497e2`.

We also need to add `0x00` to the end of our format string so that the program won't modify the value of the shellcode and we offset it by 3 bytes to align it.

```bash
(python -c "print('\xe0\x97\x04\x08' + '\xef\xbe\xad\xde' + '\xe2\x97\x04\x08' + '%x'*8 + '%54941x' + '%hn' + '%10531x' + '%hn' + '\x00' + '\x90' * 3 + '\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80')"; echo "cat /home/users/level06/.pass") | ./level05 
```
 