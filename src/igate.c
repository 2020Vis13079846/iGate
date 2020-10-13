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

int main(int argc, char *argv[])
{
    if (argc > 2) {
        if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--shell") == 0) {
            libusb_init(NULL);
            connect();
            shell();
        } else show_commands(true);
    } else show_commands(true);
}
