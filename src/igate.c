#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <libusb-1.0/libusb.h>
#include <usb.h>

#include <readline/readline.h>
#include <readline/history.h>

#define VENDOR_ID       (int)0x05AC
#define NORM_MODE       (int)0x1290
#define RECV_MODE       (int)0x1281
#define WTF_MODE        (int)0x1227
#define DFU_MODE        (int)0x1222
#define BUF_SIZE        (int)0x10000
