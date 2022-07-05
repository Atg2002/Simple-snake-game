# Simple Snake Game

This game has been written in c++ , using stnadard libraries such as cstdlib, iostream and conio.h.
The game depicts the snake body with o's and head with O. The fruit is displayed with an F.

## Working
The working is pretty simple:

### Setup function
Initialises the variables used in the game and assigns a random coordinate to fruit.


### Draw function
Draws the board with blank spaces and #. Checks whether at give cordinate there is supposed to be a tail or fruit and draws accordingly.

#### Input function
_kbhit() checks if keyboard is pressed. _getch() gets char and checks for a(LEFT), s(down), d(right) and w(up).

### Logic function
Updates the x and y cordinates of snakes tail and head. Changes direction depending on key pressed and updates score if fruit 'has been eaten'.
