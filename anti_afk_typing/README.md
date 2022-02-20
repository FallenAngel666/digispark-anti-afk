# digispark-anti-afk typing
This script enables a DigiSpark to type text inside any input field you select. 
This will ensure that you won't be logged out due to inactivity.

## how to run
Plug into any USB type-A connector, wait till it initializes (around 5 sec) and it will start typing.

## configs
- `MIN_TYPING_DELAY` and `MAX_TYPING_DELAY` define the range between the single character prints in milliseconds. (`random(MIN_TYPING_DELAY, MAX_TYPING_DELAY`)
- `DELETE_WRITTEN_TEXT` defines if a written text should be deleted. The script will then send a key stroke "ctrl+'A'" and afterwards delete button, so it will delete everything.
	- if `DELETE_WRITTEN_TEXT ` is set, `MIN_TEXT_SIE` and `MAX_TEXT_SIZE` will be used for defining how long the text (messured by characters) should be, before deleting everything.

- `alpha` defines the character array/string which is used for typing. These will be picked randomly. To increase the probability, the lower case characters are present multiple times.
