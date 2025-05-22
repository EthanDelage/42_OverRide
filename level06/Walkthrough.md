## Brief

This one is a simple little program that will prompt the user for two input.
One is called the `login` and the other is the `serial` which is an unsigned integer.

The program will then call the `auth` function.

## Exploit

Here there is no such thing as an exploit, the goal is simply to understand how the `auth` function and how it can return 0.

The function will first take the forth character of the string to create a seed.

Then it will `XOR` the whole string with this seed.

To find the correct input to open a new shell we just need to create a python script that will take a string and give us the number that is compared to our user input in order to spawn the shell or not.

Using the python script with the user input being `deadbeef` the output is `6234512`.

## Commands
 
```bash
(echo deadbeef; echo 6234512; cat) | ./level06
cat /home/users/level07/.pass
```
