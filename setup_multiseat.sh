#!/bin/bash

echo "Cleaning up any old Xephyr instances and lock files..."
sudo pkill Xephyr
sudo rm -f /tmp/.X*-lock

if [ "$(echo $XDG_SESSION_TYPE)" != "x11" ]; then
  echo "Error: This script requires an X11 session."
  exit 1
fi

echo "Installing required packages..."
sudo pacman -S --needed xorg-server xorg-utils xinput xorg-xinit

echo "Setting up virtual X servers..."

if ! ps aux | grep -q "Xephyr :1"; then
  Xephyr :1 -screen 1024x768 -ac &
  XEPHYR1_PID=$!
else
  echo "Display :1 is already in use, skipping Xephyr setup."
fi

if ! ps aux | grep -q "Xephyr :2"; then
  Xephyr :2 -screen 1024x768 -ac &
  XEPHYR2_PID=$!
else
  echo "Display :2 is already in use, skipping Xephyr setup."
fi

sleep 2

echo "Detecting input devices..."
DEVICES=($(xinput list --name-only | grep -i 'keyboard\|mouse'))

if [ ${#DEVICES[@]} -eq 0 ]; then
  echo "No input devices detected. Exiting."
  exit 1
fi

echo "Assigning input devices..."
USER1_KEYBOARD=""
USER2_KEYBOARD=""
USER1_MOUSE=""
USER2_MOUSE=""

for DEVICE in "${DEVICES[@]}"; do
    if [[ $DEVICE =~ "keyboard" ]]; then
        USER1_KEYBOARD=$DEVICE
    elif [[ $DEVICE =~ "mouse" && -z $USER1_MOUSE ]]; then
        USER1_MOUSE=$DEVICE
    fi
done

for DEVICE in "${DEVICES[@]}"; do
    if [[ $DEVICE =~ "keyboard" && $DEVICE != $USER1_KEYBOARD ]]; then
        USER2_KEYBOARD=$DEVICE
    elif [[ $DEVICE =~ "mouse" && $DEVICE != $USER1_MOUSE ]]; then
        USER2_MOUSE=$DEVICE
    fi
done

echo "Associating input devices with virtual displays..."
xinput --map-to-output "$USER1_KEYBOARD" :1 || exit 1
xinput --map-to-output "$USER1_MOUSE" :1 || exit 1
xinput --map-to-output "$USER2_KEYBOARD" :2 || exit 1
xinput --map-to-output "$USER2_MOUSE" :2 || exit 1

echo "Setting up user sessions..."

if ! ps aux | grep -q "X :1"; then
  xinit -- :1 &
else
  echo "Session for :1 is already running."
fi

if ! ps aux | grep -q "X :2"; then
  xinit -- :2 &
else
  echo "Session for :2 is already running."
fi

wait $XEPHYR1_PID
wait $XEPHYR2_PID

echo "Multi-seat setup complete!"

