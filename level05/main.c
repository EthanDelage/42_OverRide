int main(void) {
    uint len;
    char buf[100];
    uint count = 0;

    fgets((char *) buf, 100, stdin);
    do {
        strlen(buf);
        if (len <= count) {
            printf(buf);
            exit(0);
        }
        if ('A' <= buf[count] && buf[count] <= 'Z') {
            buf[count] ^= 0x20; // convert uppercase to lowercase
        }
        count += 1;
    } while (1);
}
