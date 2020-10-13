CC      = gcc
CFLAGS  =

TARGET  = igate
SRCS    = src/igate.c

LDFLAGS = -lusb-1.0 -lreadline
Q       = @

all: igate

igate:
	$(Q) $(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	$(Q) rm -rf igate