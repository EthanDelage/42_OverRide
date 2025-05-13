void main(void)

{
    int res;
    size_t index;
    long lVar1;
    char *pcVar2;
    char password [112];
    char pass_content [48];
    char username [100];
    int save_index;
    FILE *file;
    
    memset(username, '\0', 100);
    memset(pass_content, '\0', 48);
    memset(password, '\0', 112);
    file = (FILE *)0x0;
    save_index = 0;
    file = fopen("/home/users/level03/.pass","r");
    if (file == (FILE *)0x0) {
        fwrite("ERROR: failed to open password file\n",1,0x24,stderr);
                        /* WARNING: Subroutine does not return */
        exit(1);
    }
    index = fread(pass_content,1,0x29,file);
    save_index = (int)index;
    index = strcspn(pass_content,"\n");
    pass_content[index] = '\0';
    if (save_index != 41) {
        fwrite("ERROR: failed to read password file\n",1,0x24,stderr);
        fwrite("ERROR: failed to read password file\n",1,0x24,stderr);
                        /* WARNING: Subroutine does not return */
        exit(1);
    }
    fclose(file);
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");
    printf("--[ Username: ");
    fgets(username,100,stdin);
    index = strcspn(username,"\n");
    username[index] = '\0';
    printf("--[ Password: ");
    fgets(password,100,stdin);
    index = strcspn(password,"\n");
    password[index] = '\0';
    puts("*****************************************");
    res = strncmp(pass_content,password,0x29);
    if (res == 0) {
        printf("Greetings, %s!\n",username);
        system("/bin/sh");
        return;
    }
    printf(username);
    puts(" does not have access!");
    /* WARNING: Subroutine does not return */
    exit(1);
}