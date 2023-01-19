#include <assert.h>
#include <stdio.h>

#include <Windows.h>
#include <hidsdi.h>

#define DEVICE_USAGE_GAMEPAD 0x05

int main() {
    printf("Looking for HID controller(s)...\n");

    HWND hwnd = GetConsoleWindow();

    RAWINPUTDEVICE devices[1];
    devices[0].dwFlags = RIDEV_INPUTSINK;
    devices[0].usUsage = DEVICE_USAGE_GAMEPAD;
    devices[0].usUsagePage = 1;
    devices[0].hwndTarget = hwnd;

    UINT count = 0;
    if (GetRawInputDeviceList(NULL, &count, sizeof(RAWINPUTDEVICELIST)) == -1) {
        printf("GetRawInputDeviceList failed. Error code: %d\n", GetLastError());
        return GetLastError();
    }

    printf("Found %d gamepad devices.\n", count);
    
    PRAWINPUTDEVICELIST device_list = malloc(count * sizeof(RAWINPUTDEVICELIST));

    if (GetRawInputDeviceList(device_list, &count, sizeof(RAWINPUTDEVICELIST)) == -1) {
        printf("GetRawInputDeviceList failed. Error code: %d\n", GetLastError());
        return GetLastError();
    }
    
    for (UINT i = 0; i < count; i++) {
        DWORD device_type = device_list[i].dwType;
    
        if (device_type != RIM_TYPEHID) {
            continue;
        }

        printf("%d: ", i);

        // char device_name[1000] = {0};
        // UINT device_name_size = sizeof(device_name);
        // if (GetRawInputDeviceInfo(device_list[i].hDevice, RIDI_DEVICENAME, device_name, &device_name_size) <= 0) {
        //     printf("GetRawInputDeviceInfo failed. Error code: %d\n", GetLastError());
        //     return GetLastError();
        // }
        // printf("%s\n", device_name);

        // switch (device_type) {
        //     case RIM_TYPEHID:
        //         printf("The device is an HID that is not a keyboard and not a mouse.\n");
        //         break;
        //     case RIM_TYPEKEYBOARD:
        //         printf("The device is a keyboard.\n");
        //         break;
        //     case RIM_TYPEMOUSE:
        //         printf("The device is a mouse.\n");
        //         break;
        //     default:
        //         printf("The device is an unknown type.\n");
        //         break;
        // }

        // printf("-- Begin device info --\n");
        
        RID_DEVICE_INFO device_info;
        UINT device_info_size = sizeof(device_info);
        device_info.cbSize = device_info_size;
        GetRawInputDeviceInfo(device_list[i].hDevice, RIDI_DEVICEINFO, &device_info, &device_info_size);

        printf("%x %x\n", device_info.hid.dwVendorId, device_info.hid.dwProductId);

        // printf("VendorId: %x\n", device_info.hid.dwVendorId);
        // printf("ProductId: %x\n", device_info.hid.dwProductId);
        // printf("VersionNumber: %x\n", device_info.hid.dwVersionNumber);

        // printf("-- End device info --\n");
    }

    free(device_list);

    return 0;
}