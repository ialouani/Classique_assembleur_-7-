#!/bin/bash
udevadm info --query=all --name=/dev/sda | grep ID_SERIAL > file1.txt
export short_serial_number_value=$(tail -1 file1.txt)
echo $short_serial_number_value > file1.txt
sed -i -e 's/E: ID_SERIAL_SHORT=//' file1.txt
sed -n '1p' file1.txt
