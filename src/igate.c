#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <libusb-1.0/libusb.h>
#include <usb.h>

#include <readline/readline.h>
#include <readline/history.h>

#define VENDOR_ID       (int)0x05AC
#define NORM_MODE       (int)0x1290 // Normal Mode
#define RECV_MODE       (int)0x1281 // Recovery Mode
#define WTF_MODE        (int)0x1227 // What The System (WTF) Mode
#define DFU_MODE        (int)0x1222 // DFU Mode
#define BUF_SIZE        (int)0x10000

#define CMD_LOG	".orbit_history" /* history file for readline/history.h */

struct libusb_device_handle *device == NULL; /* initalize device variable with NULL value */

void show_commands(bool is_global)
{
    if (is_global) printf("Usage: orbit [option] <argumants>\n  -s, --shell  Start interaction with iBoot/iBSS shell.\n");
    else printf("  reboot  Reboot iDevice.\n  go <address>  Jump to the specified memory address.\n help  Show available commands.\n");
}

void connect() {
	if ((device = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, RECV_MODE)) == NULL) {
		if ((device = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, WTF_MODE)) == NULL) {
			if ((device = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, DFU_MODE)) == NULL) {
			}
		}
	}
}

void close() {
	if (device != NULL) {
		libusb_close(device);
	}
}

// DANGEROUS: Do not use on new iPhones (only iPhone Original - iPhone 3GS)

void reset() {
	if (device != NULL) {
		libusb_reset_device(device);
    }
}

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
