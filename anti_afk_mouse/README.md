# digispark-anti-afk typing
This script enables a DigiSpark to move the mouse in a small radius on the screen.
This will ensure that you won't be logged out due to inactivity.

## how to run
Plug into any USB type-A connector, wait till it initializes (around 5 sec) and it will start moving the mouse.

## configs
- `MOUSE_MOVE_RADIUS` is the radius of pixel for x-axis and y-axis. This is the area the mouse will be moving in.
- `MOUSE_DELAY_MIN` and `MOUSE_DELAY_MAX` are defining the timeframe the mouse will be moving between the points (`random(MOUSE_DELAY_MIN, MOUSE_DELAY_MAX)`).
- `RECENTER_FIRST` is optional and when set, the script will try to put the mouse to the center of your screen. The `RESOLUTION` configs are needed then.
	- if `RECENTER_FIRST` is set, `RESOLUTION_X` and `RESOLUTION_Y` should be updated according to your screen resolution. 
	From this values the script will try to calculate the center and move the mouse there.
	This can take a while since DigiMouse is a bit tricky to use. Arduno chip does not have any feedback for curent position or screen settings. 
	That's why the script is moving the mouse to the top left corner and tries to reposition to the middle of your screen. 
	If that didn't work for you, please raise a bug and disable this option. 
