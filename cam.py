from gpiozero import Button
from subprocess import call
import time
from datetime import date

def capture( ):
	for i in range(3):
		call(["touch", "./3.jpg"])
		time.sleep(1)
		call(["touch", "./2.jpg"])
		time.sleep(1)
		call(["touch", "./1.jpg"])
		time.sleep(1)
		filename = time.strftime("%y%m%d%H%M%S") + ".jpg"
		call(["gphoto2","--capture-image-and-download","--keep","--filename",filename])
	time.sleep(5);
	call(["touch", "./startup.jpg"])
   	return

button = Button(2)
button.when_pressed = capture

call(["gvfs-mount", "-s", "gphoto2"])

call(["touch", "./startup.jpg"])

while True:
	button.wait_for_press()
	

