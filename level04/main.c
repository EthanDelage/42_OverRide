int main(void) {
    char buf[128];
    int pid;
    int eip;
    int ret;
    int zero = 0;

    pid = fork();
    memset(buf, '\0', 128);
    if (pid == 0) {
        prctl(1, 1);
        ptrace(PTRACE_TRACEME,0,0,0);
        puts("Give me some shellcode, k");
        gets(buf);
    } else {
        do {
            ret = wait(&zero);
            if (WIFEXITED(ret) || WIFSIGNALED(ret)) {
                puts("child is exiting...");
                return 0;
            }
            eip = ptrace(PTRACE_PEEKUSER,pid,0x2c,0);
        } while (eip != 0xb); // 0xb => execve() syscall
        puts("no exec() for you");
        kill(child_id,9);
    }
    return 0;
}