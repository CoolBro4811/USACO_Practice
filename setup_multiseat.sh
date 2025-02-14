#!/bin/bash

echo "Starting Multi-Seat Xephyr Setup..."

echo "Installing required packages..."
sudo pacman -S --noconfirm --needed xorg-server-xephyr xorg-xinput i3

echo "Detecting input devices..."
KEYBOARDS=($(xinput list --name-only | grep -i "keyboard"))
MICE=($(xinput list --name-only | grep -i "mouse\|touchpad"))

if [ ${#KEYBOARDS[@]} -lt 3 ] || [ ${#MICE[@]} -lt 3 ]; then
    echo "Error: Not enough keyboards or mice connected. You need at least 3 of each."
    exit 1
fi

KEYBOARD1="${KEYBOARDS[0]}"
MOUSE1="${MICE[0]}"

KEYBOARD2="${KEYBOARDS[1]}"
MOUSE2="${MICE[1]}"

KEYBOARD3="${KEYBOARDS[2]}"
MOUSE3="${MICE[2]}"

echo "Assigned devices:"
echo "User 1 -> Keyboard: $KEYBOARD1, Mouse: $MOUSE1"
echo "User 2 -> Keyboard: $KEYBOARD2, Mouse: $MOUSE2"
echo "User 3 -> Keyboard: $KEYBOARD3, Mouse: $MOUSE3"

# Start Xephyr sessions
echo "Launching Xephyr sessions..."

Xephyr :1 -ac -screen 960x1080 &  
DISPLAY=:1 startx /usr/bin/xterm -- :1 vt1 &

Xephyr :2 -ac -screen 960x1080 &  
DISPLAY=:2 startx /usr/bin/xterm -- :2 vt2 &

Xephyr :3 -ac -screen 960x1080 &  
DISPLAY=:3 startx /usr/bin/xterm -- :3 vt3 &

sleep 5  # sometimes slow, give it time

echo "Assigning input devices..."

xinput --set-int-prop "$KEYBOARD1" "Device Enabled" 8 1
xinput --set-int-prop "$MOUSE1" "Device Enabled" 8 1

xinput --set-int-prop "$KEYBOARD2" "Device Enabled" 8 1
xinput --set-int-prop "$MOUSE2" "Device Enabled" 8 1

xinput --set-int-prop "$KEYBOARD3" "Device Enabled" 8 1
xinput --set-int-prop "$MOUSE3" "Device Enabled" 8 1

echo "Starting i3 window manager..."

DISPLAY=:1 i3 &
DISPLAY=:2 i3 &
DISPLAY=:3 i3 &

echo "Setup complete! Users can now work independently on the same machine."
