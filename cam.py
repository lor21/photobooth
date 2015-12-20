from gpiozero import Button
from subprocess import call
import time
from datetime import date

def capture( ):
	print "button pressed"

	#filename = time.ctime() + ".jpg"
	filename = time.strftime("%y%m%d%H%M%S") + ".jpg"
	
	call(["gphoto2","--capture-image-and-download","--keep","--filename",filename])
   	return

button = Button(2)
button.when_pressed = capture

call(["gvfs-mount", "-s", "gphoto2"])

while True:
	button.wait_for_press()
	

