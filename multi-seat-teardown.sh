#!/bin/bash

# Check if the script is run as root
if [[ $EUID -ne 0 ]]; then
    echo "This script must be run as root"
    exit 1
fi

# Define the seat service names (update if you have more seats)
SEAT_SERVICES=("multi-seat-seat1.service" "multi-seat-seat2.service")

# Stop and disable the multi-seat services
echo "Stopping and disabling multi-seat services..."
for SERVICE in "${SEAT_SERVICES[@]}"; do
    systemctl stop "$SERVICE"
    systemctl disable "$SERVICE"
done

# Remove the X11 seat configuration files
echo "Removing X11 seat configuration files..."
rm -f /etc/X11/xorg.conf.d/10-seat1.conf
rm -f /etc/X11/xorg.conf.d/10-seat2.conf
# You can add more files here if you have additional seat configurations (e.g., seat3.conf, seat4.conf)

# Reload systemd to apply changes
echo "Reloading systemd..."
systemctl daemon-reload

# Reboot the system to ensure changes take effect
echo "Rebooting the system to finalize changes..."
reboot
