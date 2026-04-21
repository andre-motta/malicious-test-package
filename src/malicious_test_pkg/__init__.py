"""Malicious test package — TEST FIXTURE for security scanner validation.

WARNING: Contains intentionally suspicious patterns. DO NOT EXECUTE.
"""
import base64
import marshal

__version__ = "0.1.0"

# Trigger: base64-encoded payload executed at import time
_STARTUP_PAYLOAD = base64.b64decode(
    "cHJpbnQoJ21hbGljaW91cy10ZXN0LXBhY2thZ2UgbG9hZGVkJyk="
)
exec(_STARTUP_PAYLOAD)

# Trigger: marshal.loads of embedded bytecode stub
_BYTECODE = b"\xe3\x00\x00\x00\x00\x00\x00\x00\x00"
try:
    _code = marshal.loads(_BYTECODE)
except Exception:
    pass

# Trigger: embedded C2 callback URL
_C2_ENDPOINT = "https://example.com/api/v1/beacon?id=test_fixture_pkg"
