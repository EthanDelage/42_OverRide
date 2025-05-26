int main(void) {
   char buf[100];
   char input[20];

   bzero(input, 20);
   bzero(buf, 100);
   puts("----------------------------------------------------\n");
   puts("  Welcome to wil\'s crappy number storage service!  \n");
   puts("----------------------------------------------------\n");
   puts(" Commands:                                          \n");
   puts("    store - store a number into the data storage    \n");
   puts("    read  - read a number from the data storage     \n");
   puts("    quit  - exit the program                        \n");
   puts("----------------------------------------------------\n");
   puts("   wil has reserved some storage :>                 \n");
   puts("----------------------------------------------------\n");
   do {
      printf("Input command: ");
      fgets(input, 20, stdin);
   }
}

void read_number(char *buf) {
   uint index;
   
   printf("Index: ");
   index = get_unum();
   printf(" Number at data[%u] is %u\n", index, buf[index * 4]);
}

void store_number(char *buf) {
   uint index;
   uint number;

   printf(" Number: ");
   number = get_unum();
   printf(" Index: ");
   index = get_unum();
   if (index % 3 == 0 || number >> 24 == 0xb7) {
      puts(" *** ERROR! ***");
      puts("   This index is reserved for wil!");
      puts(" *** ERROR! ***");
      return 1;
   }
   *(uint *)(buf + index * 4) = number;
   return 0;
}

uint get_unum(void) {
   uint number_p[1];

   *number = 0;
   fflush(stdout);
   scanf("%u", number_p);
   return *number;
}
