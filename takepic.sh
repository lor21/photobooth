#!/bin/bash -ex

DATE=`date +%s`

gvfs-mount -s gphoto2
sleep 5
gphoto2 --capture-image-and-download --keep --filename ${DATE}.jpg
epiphany-browser ${DATE}.jpg

