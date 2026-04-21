# malicious-test-package

> **WARNING: THIS IS A TEST FIXTURE — NOT A REAL PACKAGE**

This repository contains a deliberately suspicious Python package designed to trigger security vulnerability scanners. It exists solely as a test fixture for the [AIPCC Package Onboarding](https://gitlab.com/redhat/rhel-ai/core/package-onboarding) pipeline's security audit gate.

**This package is NOT published to PyPI and must NEVER be installed or executed.**

Every file in this repo contains intentionally suspicious patterns (base64 payloads, eval/exec calls, network exfiltration stubs, marshal bytecode, etc.) that mimic real supply-chain attacks. The git history is also crafted to trigger commit-level scanning heuristics.

## Purpose

The AIPCC pipeline runs a security audit (hexora static analysis + git history scan) before allowing any Python package to be onboarded into Red Hat's AI distribution. This repo provides a stable, reliably-detectable test target for integration tests of that security gate.

## What's in here

| File | Suspicious patterns |
|------|-------------------|
| `setup.py` | eval, exec, base64 decode, urllib in install hook |
| `src/malicious_test_pkg/__init__.py` | base64+exec at import, marshal, C2 URL |
| `src/malicious_test_pkg/payload.py` | compile+exec, os.popen, marshal roundtrip |
| `malicious_test_pkg.pth` | .pth code execution |
| `.github/workflows/exfiltrate.yml` | env dump, curl to external URL |

## License

MIT — this is test scaffolding, not software.
