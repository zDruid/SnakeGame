#include "Snake.h"
#include <iostream>

// Starts the snake off at row 5, col 5.  Gives the snake a tail that extends
// from the head to 5,4 and 5,3 (row, col)
Snake::Snake() {
  pushBack(5, 5);
  pushBack(5, 4);
  pushBack(5, 3);
}

// Returns whether or not the snake will "crash". Compute the snake's
// next position using its direction vector and it's current position.
// If that next position collides with the edges of the board or **with
// the snake itself**, then the snake will crash.
bool Snake::willCrash(const GameBoard *board) const {
  int nextRow = head()->row() + dRow();
  int nextCol = head()->col() + dCol();

  return !(nextRow >= 0 && nextCol >= 0 && nextRow < board->rowCount() &&
           nextCol < board->colCount() && !intersects(nextRow, nextCol));
}

// Return whether row,col matches the coordinates of one of the snake's nodes.
bool Snake::intersects(int row, int col) const {
  bool result = false;
  SnakeListNode *curNode = head();
  while (curNode != nullptr) {
    if (curNode->row() == row && curNode->col() == col) {
      result = true;
      break;
    }
    curNode = curNode->nextNode();
  }

  return result;
}

// Set the tiles on the gameboard corresponding to each of the snake's nodes.
void Snake::setTiles(GameBoard *board) const {
  SnakeListNode *curNode = head();
  while(curNode != nullptr) {
    board->setTileAt(curNode->row(), curNode->col(), _glyph, _color);
    curNode = curNode->nextNode();
  }
  board->setTileAt(head()->row(), head()->col(), _headGlyph, _color); 
}

// Update _dRow, _dCol to indicate the direction of next step.
// Autonomous subclass will override and ignore cmd.
// The default implementation ignores board and candy coords.
void Snake::steer(char cmd, const GameBoard *board, int candyRow,
                  int candyCol) {
  switch (cmd) {
  case arrowUpKey:
    _dRow = -1;
    _dCol = 0;
    break;

  case arrowDownKey:
    _dRow = 1;
    _dCol = 0;
    break;

  case arrowRightKey:
    _dRow = 0;
    _dCol = 1;
    break;

  case arrowLeftKey:
    _dRow = 0;
    _dCol = -1;
    break;

  default:
    (void)0; // no-op
  }
}

// Moves the head to nextRow,nextCol and adjusts the tail as needed.
void Snake::step(GameBoard *board) {
  int nextRow = head()->row() + _dRow;
  int nextCol = head()->col() + _dCol;

  // popback the snake
  // update the board by clearning the tail

  board->setTileAt(head()->row(), head()->col(), _glyph, _color); // update gameboard at location of prev head to be a normal link in the snake

  pushFront(nextRow, nextCol); // add new head to snake
  board->setTileAt(nextRow, nextCol, _headGlyph,_color); // update the board with a new head

  if (_calories > 0) {
    _calories--;
  }
  else {
    SnakeListNode *tailNode = tail();
    board->clearTileAt(tailNode->row(), tailNode->col());
    popBack();
  }
}

void Snake::eat(int calories, Color color) {
  _calories += calories;
  _color = color;
}
