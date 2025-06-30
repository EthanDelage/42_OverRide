int main(void) {
  puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n- -------------------------------------------");
  handle_msg();
  return 0;
}

void handle_msg(void) {
  undefined1 local_c8 [140];
  undefined8 local_3c;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined8 local_1c;
  undefined4 local_14;
  
  local_3c = 0;
  local_34 = 0;
  local_2c = 0;
  local_24 = 0;
  local_1c = 0;
  local_14 = 140;
  set_username(local_c8);
  set_msg(local_c8);
  puts(">: Msg sent!");
  return;
}

void set_username(char *param_1) {
  long lVar1;
  char buf[140];
  int index;
  
  bzero(buf, 140);
  puts(">: Enter your username");
  printf(">>: ");
  fgets(buf,128,_stdin);
  for (index = 0; (index < 41 && (buf[index] != '\0')); index = index + 1) {
    *(char *)(param_1 + 140 + index) = buf[index];
  }
  printf(">: Welcome, %s",param_1 + 140);
  return;
}

void set_msg(char *param_1) {
  long lVar1;
  char buf[1024];
  
  bzero(buf, 1024);
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(buf,1024,_stdin);
  strncpy(param_1,local_408,(long)*(int *)(param_1 + 180));
  return;
}

void secret_backdoor(void) {
  char buf[128];
  
  fgets(buf,128,_stdin);
  system(buf);
  return;
}