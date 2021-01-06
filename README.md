# Unicode Sprite Editor (Not finished)
Inspired by OneLoneCoder's Sprite Editor for [olcConsoleGameEngine](https://github.com/OneLoneCoder/videos/blob/master/olcConsoleGameEngine.h).

## VS Projects
UnicodeSpriteEditor consists of two projects, the console engine and the sprite editor itself.

### [Console Engine](https://github.com/Fedron/UnicodeSpriteEditor/tree/main/ConsoleEngine)
The console engine provides an API for drawing to the console as if it were a window using pixels. It also provides utilities for some UI, transitioning between scenes (Similar to Unity scenes), and managing the game loop.

### [Sprite Editor](https://github.com/Fedron/UnicodeSpriteEditor/tree/main/SpriteEditor)
The sprite editor uses the Console Engine to draw the application to the console. It also contains all the logic for the actual sprite editor.
