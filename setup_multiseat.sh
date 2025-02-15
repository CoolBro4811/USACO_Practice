#!/bin/bash

echo "Cleaning up any old Xephyr instances and lock files..."
sudo pkill Xephyr
sudo rm -f /tmp/.X*-lock

if [ "$(echo $XDG_SESSION_TYPE)" != "x11" ]; then
  echo "Error: This script requires an X11 session."
  exit 1
fi

echo "Installing required packages..."
sudo pacman -S --needed xorg-server xorg-xinput xorg-xinit

echo "Setting up virtual X servers..."

if ! ps aux | grep -q "Xephyr :1"; then
  Xephyr :1 -screen 1024x768 -ac &
  XEPHYR1_PID=$!
else
  echo "Display :1 is already in use, skipping Xephyr setup."
fi


echo "Cleaning up any old Xephyr instances and lock files..."
sudo pkill Xephyr
sudo rm -f /tmp/.X*-lock

if [ "$(echo $XDG_SESSION_TYPE)" != "x11" ]; then
  echo "Error: This script requires an X11 session."
  exit 1
fi


echo "Setting up virtual X servers..."
XEPHYR1_PID=""
XEPHYR2_PID=""

Xephyr :1 -screen 1024x768 -ac &
XEPHYR1_PID=$!
Xephyr :2 -screen 1024x768 -ac &
XEPHYR2_PID=$!

sleep 2

echo "Assigning input devices..."

USER1_KEYBOARD="AT Translated Set 2 keyboard"   # Onboard keyboard
USER1_MOUSE="ELAN0676:00 04F3:3195 Touchpad"     # First mouse

USER2_KEYBOARD="SONiX USB DEVICE"      # Second keyboard
USER2_MOUSE="ROCCAT ROCCAT Kone Pure Ultra"       # Second mouse

echo "Associating input devices with virtual displays..."
xinput --map-to-output "$USER1_KEYBOARD" :1
xinput --map-to-output "$USER1_MOUSE" :1
xinput --map-to-output "$USER2_KEYBOARD" :2
xinput --map-to-output "$USER2_MOUSE" :2

echo "Setting up user sessions..."

xinit -- :1 &

xinit -- :2 &

wait $XEPHYR1_PID
wait $XEPHYR2_PID

echo "Multi-seat setup complete!"

