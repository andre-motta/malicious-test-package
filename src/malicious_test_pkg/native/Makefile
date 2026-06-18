# Build test fixture binaries for security scanner validation.
# WARNING: These binaries contain intentionally suspicious string patterns.

CFLAGS = -shared -fPIC -Wall -Wextra

SHARED_LIBS = exfil.so backdoor.so keylogger.so
STATIC_LIBS = libstub.a

all: $(SHARED_LIBS) $(STATIC_LIBS)

%.so: %.c
	$(CC) $(CFLAGS) -o $@ $<

stub.o: stub.c
	$(CC) -c -o $@ $<

libstub.a: stub.o
	ar rcs $@ $<
	rm -f stub.o

clean:
	rm -f $(SHARED_LIBS) $(STATIC_LIBS) stub.o

.PHONY: all clean
