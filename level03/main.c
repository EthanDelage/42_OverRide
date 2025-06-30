int main(void) {
    uint seed;
    int value;

    seed = time(NULL);
    srand(seed);
    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &value);
    test(value, 322424845);
    return 0;
}

void test(int param_1,int param_2)

{
    int random_value;
    int res;

    res = param_2 - param_1;
    switch(res) {
    default:
        random_value = rand();
        decrypt(random_value);
        break;
    case 1:
        decrypt(res);
        break;
    case 2:
        decrypt(res);
        break;
    case 3:
        decrypt(res);
        break;
    case 4:
        decrypt(res);
        break;
    case 5:
        decrypt(res);
        break;
    case 6:
        decrypt(res);
        break;
    case 7:
        decrypt(res);
        break;
    case 8:
        decrypt(res);
        break;
    case 9:
        decrypt(res);
        break;
    case 16:
        decrypt(res);
        break;
    case 17:
        decrypt(res);
        break;
    case 18:
        decrypt(res);
        break;
    case 19:
        decrypt(res);
        break;
    case 20:
        decrypt(res);
        break;
    case 21:
        decrypt(res);
    }
    return;
}

int decrypt(int value) {
    unsigned char buf[17] = {0x51, 0x7d, 0x7c, 0x75, 0x60, 0x73, 0x66, 0x67, 0x7e, 0x73, 0x66, 0x7b, 0x7d, 0x7c, 0x61, 0x33, 0x00};
    char congrat[] = "Congratulations!";
    int index = 0;

    while (buf[index] != 0x0) {
        buf[index] ^= value;
        index++;
    }
    if (strcmp(congrat, buf)) {
        return system("/bin/sh");
    } else {
        return puts("\nInvalid Password");
    }
}