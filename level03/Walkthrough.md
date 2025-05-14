## Brief

This program will use `scanf` to get the user input.
Then this input will be compared to a constant variable and the result will be used in a `switch` statement.

## Exploit

The goal of this exercise seems to consist of understanding the source code.

First our user input is stored in a `int` variable, this variable is then subtracted to a constant variable: `322424845`. We will call the result of the subtraction`res`.

The result will then be used in a switch statement. There are 15 value that will trigger a branch of the `switch` statement otherwise it will go to `default`.

The `decrypt` function is called with `res` if it enters a branch of the `switch`, with a random value otherwise.

The `decrypt` use our user input to operate a `XOR` on a byte string. If the resulting string is equal to `"Congratulations!"` it opens a new shell.

To determine which `res` value will be used to `XOR` the byte string we can do: `buf[0] ^ congrat[0] = 18`

## Commands

The `res` value needs to be 18 so : `user input = 322424845 - 18 = 322424827`

```bash
(python -c "print('322424827')"; echo "cat /home/users/level04/.pass") | ./level03
```