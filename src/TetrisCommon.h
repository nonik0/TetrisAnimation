#pragma once

enum BlockType
{
  SQUARE,
  L_SHAPE,
  L_SHAPE_REVERSE,
  I_SHAPE,
  S_SHAPE,
  S_SHAPE_REVERSE,
  HALF_CROSS,
  CORNER_SHAPE
};

enum BlockRotation
{
  ROTATION_0,
  ROTATION_90,
  ROTATION_180,
  ROTATION_270
};

enum BlockColor
{
  PALETTE_RED,
  PALETTE_ORANGE,
  PALETTE_YELLOW,
  PALETTE_GREEN,
  PALETTE_CYAN,
  PALETTE_BLUE,
  PALETTE_MAGENTA,
  PALETTE_WHITE,
};

struct BlockFallData
{
  BlockType type;         // Number of the block type
  BlockRotation rotation; // Number of 90-degree (clockwise) rotations a brick is turned from the standard position
  BlockColor color;       // Color of the brick
  int xPos;               // x-position (starting from the left number staring point) where the brick should be placed
  int yPosFinal;          // y-position (1-16, where 16 is the last line of the matrix) where the brick should stop falling
};