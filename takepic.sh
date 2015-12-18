#!/bin/bash -x

DATE=`date +%s`

gvfs-mount -s gphoto2
sleep 10
gphoto2 --capture-image-and-download --keep --filename ${DATE}.jpg
epiphany-browser ${DATE}.jpg

