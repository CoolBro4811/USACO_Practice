#!/bin/bash

# Function to list input devices and allow user to select one
select_device() {
  local device_type=$1
  local devices=($(ls /dev/input/event*))
  echo "Available $device_type devices:"
  for i in "${!devices[@]}"; do
    device_info=$(evemu-describe "${devices[$i]}" | grep -m 1 'Device name')
    echo "$i) ${devices[$i]} - $device_info"
  done

  local choice
  while true; do
    read -p "Select the number corresponding to the $device_type: " choice
    if [[ $choice =~ ^[0-9]+$ ]] && [ $choice -ge 0 ] && [ $choice -lt ${#devices[@]} ]; then
      echo "${devices[$choice]}"
      return
    else
      echo "Invalid selection. Please try again."
    fi
  done
}

# Select mouse and keyboard
mouse_device=$(select_device "mouse")
keyboard_device=$(select_device "keyboard")

# Create a new seat (e.g., seat1)
seat_name="seat1"
sudo loginctl seat-status "$seat_name" &>/dev/null
if [ $? -ne 0 ]; then
  echo "Creating new seat: $seat_name"
  sudo loginctl attach "$seat_name" "$mouse_device"
  sudo loginctl attach "$seat_name" "$keyboard_device"
else
  echo "$seat_name already exists. Attaching devices to the existing seat."
  sudo loginctl attach "$seat_name" "$mouse_device"
  sudo loginctl attach "$seat_name" "$keyboard_device"
fi

# Start Xephyr on display :1 with the new seat
echo "Starting Xephyr for $seat_name..."
Xephyr :1 -seat "$seat_name" -screen 1024x768 -host-cursor &

