# Stadia-ViGEm

XBox360 controller emulation for Stadia controller. Supports multiple devices and vibration. Forked from Mi-ViGEm (https://github.com/grayver/Mi-ViGEm) by grayver.
XBox360 emulation driver is provided by ViGEm (https://github.com/ViGEm/ViGEmBus), by Benjamin Höglinger.

## Requirements
- Windows 10 (should work on Windows 7 and 8 also)
- ViGEm bus installed (can be downloaded [here](https://github.com/ViGEm/ViGEmBus/releases))

## How it works
Stadia-ViGEm program at start scans for Stadia Controllers and then proxies found Stadia Controllers to virtual XBox360 gamepads (with help of ViGEmBus). Also Stadia-ViGEm subscribes to system device plug/unplug notifications and rescan devices on each notification.
All found devices are displayed in tray icon context menu. Manual device rescan can be initiated via tray icon context menu.

## Thanks to

grayver, the developer of Mi-ViGEm that makes up 95% of this program.

This project is inspired by following projects written on C#:
- https://github.com/irungentoo/Xiaomi_gamepad
- https://github.com/dancol90/mi-360

Thanks to following libraries and resources:
- https://github.com/libusb/hidapi for HID implementation
- https://github.com/zserge/tray for lightweight tray app implementation
- https://www.flaticon.com/authors/freepik for application icon
