## Brief

This is a short and simple program that only check if the user input is equal to a certain number, if it is the program will spawn a new shell with the correct rights to read the .pass file.

## Exploit

This is a simple exploit where the user input needs to be equal to `0x149c`. To do so we use a simple command to convert this hexadecimal number to an int and put it in the stdin of the program.

## Commands

```bash
(python -c "print(int('0x149c', 16))"; cat /home/users/level01/.pass) | ./level00
```
