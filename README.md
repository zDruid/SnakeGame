# Instructions  

## Snake Game Specification

The Snake Game is nearly as old as computer graphics. In this game, players control a snake, represented as a sequence of glyphs navigating it around a fixed-size board. It's easy at first, because the board is mostly blank, aside from a short snake and morsels of candy. The challenge is, as the snake eats candy, it grows longer and longer, eventually filling many of the locations on the board. *Snakes that bump into themselves or the edges of the board lose*. So the game gets tougher as the snake gets longer.

## Candy

The snake game periodically must create a piece of candy on the board for the snake to eat. This candy has been defined in `Candy.h` and `Candy.cpp`. A static method is provided that creates a random instance of Candy whose location does not overlap with any part of the snake. It has random calories, random color, and a glyph that is a digit matching its caloric value.


## Steps


### 1. Implement SnakeLinkedList.cpp
Create a SnakeLinkedList in SnakeLinkedList.cpp

### 2. Implement Snake, a subclass of SnakeLinkedList
The `Snake` class is a subclass of `SnakeLinkedList`. It will add methods specific to the snake game. Declarations and comments describing these methods are provided in Snake.h and Snake.cpp.

### 3. Get it working without Candy
After completing steps 1 & 2 you should be able to run the game and move the snake around the board. Before candy is introduced, there will be nothing for the snake to eat, so it will not grow in length. Even before there's food on the board, consider adding a command key to the switch statement that simulates the snake getting a meal, perhaps growing for a few turns afterwards. If you get this far, your project will be in very good shape to complete. The remaining work will be to add the food you designed in the Canvas discussion.

### 4. Implement the Candy logic in main()

Note the comments in `main()` indicating how to add candy to the board and what to do when the snake's head encounters a candy.
