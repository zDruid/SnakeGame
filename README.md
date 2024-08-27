# Instructions  

## Snake Game Specification

The Snake Game is nearly as old as computer graphics. In this game, players control a snake, represented as a sequence of glyphs navigating it around a fixed-size board. It's easy at first, because the board is mostly blank, aside from a short snake and morsels of candy. The challenge is, as the snake eats candy, it grows longer and longer, eventually filling many of the locations on the board. *Snakes that bump into themselves or the edges of the board lose*. So the game gets tougher as the snake gets longer.

![](assets/screenshot1.png)

In the image above, the player's snake is shown early in the game. Its head is depicted as an '@' sign, and its body segments are depicted as a sequence of `o` (lowercase oh) characters. A piece of candy lies just to the right of the head. The player eats this candy by moving the head right by two columns. The piece of candy is particularly yummy, because it contains six calories. When the snake eats it, the snake absorbs those calories. Snakes convert calories to new segments, so for the next six turns, the snake grows by one segment per turn.

![](assets/screenshot2.png)

In the image above, the snake has eaten the candy. As soon as the candy disappears, a new candy appears elsewhere on the board. That new candy has a random position that does not intersect the snake, and it has a random caloric value (seven, this time). The player's job now is to steer the ever-lengthening snake to the next piece of candy.

![](assets/screenshot3.png)

Notice now that the player's snake is 13 segments long, six longer than its length when it ate the last candy. The game continues, getting tougher as the snake is left with less room to maneuver.

## Candy

The snake game periodically must create a piece of candy on the board for the snake to eat. This candy has been defined in `Candy.h` and `Candy.cpp`. A static method is provided that creates a random instance of Candy whose location does not overlap with any part of the snake. It has random calories, random color, and a glyph that is a digit matching its caloric value.


## Steps


### 1. Complete the three linked list labs (seriously!)
[The week 8 labs](https://deanza.instructure.com/courses/33583/assignments/1050403) provide step-by-step support for creating a SnakeLinkedList. This is a large part of the code needed in SnakeLinkedList.cpp. **Do these labs first.** If done well, the code you create for the labs should simply drop-in to `SnakeLinkedList.cpp`.

### 2. Implement Snake, a subclass of SnakeLinkedList
The `Snake` class is a subclass of `SnakeLinkedList`. It will *inherit all of your good work* from the labs and add methods specific to the snake game. Declarations and comments describing these methods are provided in Snake.h and Snake.cpp.

Isn't subclassing great? With it, you're able to inherit every line of your (somewhat generic) linked list lab code adding only snake-game specific logic. We could have used templates to make the SnakeLinkedList even more general, creating an *Anything* LinkedList. Feel free to try this after you get the project working.

### 3. Get it working without Candy
After completing steps 1 & 2 you should be able to run the game and move the snake around the board. Before candy is introduced, there will be nothing for the snake to eat, so it will not grow in length. Even before there's food on the board, consider adding a command key to the switch statement that simulates the snake getting a meal, perhaps growing for a few turns afterwards. If you get this far, your project will be in very good shape to complete. The remaining work will be to add the food you designed in the Canvas discussion.

### 4. Implement the Candy logic in main()

Note the comments in `main()` indicating how to add candy to the board and what to do when the snake's head encounters a candy.


### 5. Extra work for a prize? (Warning: this is difficult)

Notice that the `Snake` class is declared with a virtual method called `steer()`. It accepts a few parameters that are ignored (or ought to be), like the current position of candy on the board.

Build a subclass of `Snake` called `AutonomousSnake` that steers itself and plays the game well. Your new class should override `steer()` and add whatever else it needs to work. The author of an autonomous snake that achieves the longest length per number of turns will earn a real-world prize.

To qualify for a prize, autonomous snake must be provided on time with the rest of your project. If you create a working autonomous snake, run it, and save the `SnakeLogFile.txt` under a new name (like `HighScore.txt`). 
