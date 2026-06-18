/*
 * WARNING: TEST FIXTURE — intentionally suspicious code.
 * DO NOT EXECUTE. Designed to trigger malcontent YARA rules.
 *
 * This file contains string literals that mimic network exfiltration
 * patterns. The functions are stubs and do nothing when called.
 */

#include <stdio.h>

/* Trigger: hardcoded C2 exfiltration endpoint */
static const char *C2_ENDPOINT = "https://example.com/api/v1/exfil?data=stolen";
static const char *BEACON_URL = "https://example.com/api/v1/beacon?id=agent42";

/* Trigger: DNS exfiltration hostname */
static const char *DNS_EXFIL = "data.evil-c2-server.example.com";

/* Trigger: network syscall references */
static const char *SYSCALLS[] = {
    "socket",
    "connect",
    "send",
    "recv",
    "sendto",
    "recvfrom",
    "getaddrinfo",
};

/* Trigger: credential/token theft from environment */
static const char *ENV_TARGETS[] = {
    "SECRET_TOKEN",
    "AWS_SECRET_ACCESS_KEY",
    "GITHUB_TOKEN",
    "API_KEY",
};

void exfiltrate_data(const char *data) {
    /* Stub — references socket API patterns for YARA matching */
    (void)data;
    (void)C2_ENDPOINT;
    (void)BEACON_URL;
    (void)DNS_EXFIL;
    (void)SYSCALLS;
    (void)ENV_TARGETS;
}

void phone_home(void) {
    /* Stub — would call back to C2 */
    printf("exfil: %s\n", C2_ENDPOINT);
}
