char a_user_name[256];

void main(void) {
    char buf[64];
    int boolean;

    memset(buf, '\0', 64);
    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    fgets(a_user_name, 0x100, stdin);
    boolean = verify_user_name();
    if (boolean == 0) {
        puts("Enter Password: ");
        fgets(buf,100,stdin);
        boolean = verify_user_pass(buf);
        if ((boolean == 0) || (boolean != 0)) {
        puts("nope, incorrect password...\n");
        }
    }
    else {
        puts("nope, incorrect username...\n");
    }
}

int verify_user_name(void) {
    const char *expected_username = "dat_wil";
    const char *user_name = a_user_name;

    puts("Verifying username...\n");

    for (int i = 0; i < 7; i++) {
        if (user_name[i] != expected_username[i]) {
            return 1;
        }
    }

    return 0;
}

int verify_user_pass(char *buf) {
    const char *expected_pass = "admin";

    for (int i = 0; i < 5; i++) {
        if (buf[i] != expected_pass[i]) {
            return 1;
        }
    }

    return 0;
}
