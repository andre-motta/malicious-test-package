/*
 * WARNING: TEST FIXTURE — intentionally suspicious code.
 * DO NOT EXECUTE. Designed to trigger malcontent YARA rules.
 *
 * This file contains string literals that mimic credential harvesting
 * and persistence patterns. The functions are stubs and do nothing.
 */

#include <stdio.h>

/* Trigger: credential file paths */
static const char *CRED_FILES[] = {
    "/etc/shadow",
    "/etc/passwd",
    "/etc/sudoers",
    "/etc/ssh/sshd_config",
};

/* Trigger: SSH key paths */
static const char *SSH_KEYS[] = {
    "/.ssh/id_rsa",
    "/.ssh/id_ed25519",
    "/.ssh/authorized_keys",
    "/.ssh/known_hosts",
};

/* Trigger: browser credential stores */
static const char *BROWSER_CREDS[] = {
    "/.mozilla/firefox/logins.json",
    "/.config/google-chrome/Default/Login Data",
    "/Library/Keychains/login.keychain-db",
};

/* Trigger: keylogging / input capture references */
static const char *KEYLOG[] = {
    "/dev/input/event0",
    "DISPLAY",
    "XOpenDisplay",
    "XQueryKeymap",
    "keylogger",
};

/* Trigger: persistence mechanisms */
static const char *PERSISTENCE[] = {
    "/etc/cron.d/",
    "/etc/systemd/system/",
    "~/.bashrc",
    "~/.profile",
    "/etc/ld.so.preload",
};

void harvest_credentials(void) {
    /* Stub — references credential paths for YARA matching */
    (void)CRED_FILES;
    (void)SSH_KEYS;
    (void)BROWSER_CREDS;
}

void start_keylogger(void) {
    /* Stub — references input device paths for YARA matching */
    (void)KEYLOG;
    (void)PERSISTENCE;
    printf("keylogger: targeting %s\n", CRED_FILES[0]);
}
