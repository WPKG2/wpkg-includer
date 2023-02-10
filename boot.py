import storage
import board, digitalio

button = digitalio.DigitalInOut(board.GP2)
button.direction = digitalio.Direction.INPUT
button.pull = digitalio.Pull.UP

# Disable devices only if button is not pressed.
if button.value:
    print(f"boot: button not pressed, disabling drive")
    storage.disable_usb_drive()
