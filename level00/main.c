void main(void)
{
  int buf [4];
  
  puts("***********************************");
  puts("* \t     -Level00 -\t\t  *");
  puts("***********************************");
  printf("Password:");
  __isoc99_scanf("%d",buf);
  if (buf[0] == 0x149c) {
    puts("\nAuthenticated!");
    system("/bin/sh");
  }
  else {
    puts("\nInvalid Password!");
  }
  return;
}