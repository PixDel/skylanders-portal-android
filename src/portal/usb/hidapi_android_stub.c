/* Android: no hidapi backend yet. Every call reports "no device", so portal_mode=usb finds no
 * portal and the software portal (the portal menu) is used. A real backend would open the device
 * through Android's UsbManager (a file descriptor from Java) and hand it to libusb. */
#include <stddef.h>
#include <wchar.h>

#include "hidapi.h"

int HID_API_EXPORT hid_init(void) { return 0; }
int HID_API_EXPORT hid_exit(void) { return 0; }

struct hid_device_info HID_API_EXPORT* hid_enumerate(unsigned short vendor_id,
                                                     unsigned short product_id) {
  (void)vendor_id;
  (void)product_id;
  return NULL;
}

void HID_API_EXPORT hid_free_enumeration(struct hid_device_info* devs) { (void)devs; }

hid_device* HID_API_EXPORT hid_open(unsigned short vendor_id, unsigned short product_id,
                                    const wchar_t* serial_number) {
  (void)vendor_id;
  (void)product_id;
  (void)serial_number;
  return NULL;
}

void HID_API_EXPORT hid_close(hid_device* dev) { (void)dev; }

int HID_API_EXPORT hid_write(hid_device* dev, const unsigned char* data, size_t length) {
  (void)dev;
  (void)data;
  (void)length;
  return -1;
}

int HID_API_EXPORT hid_send_output_report(hid_device* dev, const unsigned char* data,
                                          size_t length) {
  (void)dev;
  (void)data;
  (void)length;
  return -1;
}

int HID_API_EXPORT hid_read_timeout(hid_device* dev, unsigned char* data, size_t length,
                                    int milliseconds) {
  (void)dev;
  (void)data;
  (void)length;
  (void)milliseconds;
  return -1;
}

const wchar_t* HID_API_EXPORT hid_error(hid_device* dev) {
  (void)dev;
  return L"USB portals are not supported on Android yet";
}
