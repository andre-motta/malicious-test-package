# malicious-test-package

> **WARNING: THIS IS A TEST FIXTURE — NOT A REAL PACKAGE**

This repository contains a deliberately suspicious Python package designed to trigger security vulnerability scanners. It exists solely as a test fixture for the ai-helpers pipeline's security audit gate.

**This package is NOT published to PyPI and must NEVER be installed or executed.**

Every file in this repo contains intentionally suspicious patterns (base64 payloads, eval/exec calls, network exfiltration stubs, marshal bytecode, etc.) that mimic real supply-chain attacks. The git history is also crafted to trigger commit-level scanning heuristics.

## Purpose

The ai-helpers pipeline runs a security audit (hexora static analysis + git history scan) before allowing any Python package to be onboarded into Red Hat's AI distribution. This repo provides a stable, reliably-detectable test target for integration tests of that security gate.

## What's in here

### Python source patterns (hexora / static analysis)

| File | Suspicious patterns |
|------|-------------------|
| `setup.py` | eval, exec, base64 decode, urllib in install hook |
| `src/malicious_test_pkg/__init__.py` | base64+exec at import, marshal, C2 URL |
| `src/malicious_test_pkg/payload.py` | compile+exec, os.popen, marshal roundtrip |
| `malicious_test_pkg.pth` | .pth code execution |
| `.github/workflows/exfiltrate.yml` | env dump, curl to external URL |

### Native binary fixtures (binary scanner / malcontent)

These are compiled shared libraries containing intentionally suspicious string
literals. They exercise the binary file detection (extension + magic header) and
malcontent YARA analysis stages of the security pipeline.

| File | Suspicious patterns |
|------|-------------------|
| `native/exfil.so` | C2 endpoints, DNS exfil hostname, socket syscall names, credential env vars |
| `native/backdoor.so` | `/bin/sh` paths, reverse-shell command, base64 payload, exec/ptrace/setuid strings, anti-debug refs |
| `native/keylogger.so` | `/etc/shadow`, SSH key paths, browser credential stores, `/dev/input` keylogging, cron/systemd persistence |
| `native/libstub.a` | Minimal static archive — triggers `!<arch>` magic-header detection |

**Rebuilding:** `cd src/malicious_test_pkg/native && make clean && make`

The C sources (`exfil.c`, `backdoor.c`, `keylogger.c`, `stub.c`) and `Makefile`
are included in the sdist so the binaries can be recompiled on any platform.

## License

MIT — this is test scaffolding, not software.
