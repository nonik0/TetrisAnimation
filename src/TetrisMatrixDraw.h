/*
Copyright (c) 2018 Tobias Blum . All right reserved.

Tetris Matrix Clock

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#pragma once

#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "TetrisCommon.h"

#define TETRIS_MAX_NUMBERS 9
#define TETRIS_DISTANCE_BETWEEN_DIGITS 7
#define TETRIS_Y_DROP_DEFAULT 16

// Type that describes the current state of a drawn number
struct NumberFallState
{
  int value;      // Digit to draw (0-9)
  int blockIndex; // The index of the brick (as defined in the falling instructions) that is currently falling
  int xPos;       // x-position of the number relative to the matrix where the number should be placed.
  int yPos;       // y-position of the brick it already has (incrementing with each step)
};

class TetrisMatrixDraw
{
public:
  TetrisMatrixDraw(Adafruit_GFX &display);
  bool drawNumber(int x = 0, int y = 0, bool displayColon = false);
  // bool drawText(int x = 0, int y = 0);
  // void drawChar(String letter, uint8_t x, uint8_t y, uint16_t color);
  void drawShape(BlockType blockType, uint16_t color, int xPos, int yPos, BlockRotation blockRotation);
  void drawLargerShape(int scale, BlockType blockType, uint16_t color, int xPos, int yPos, BlockRotation blockRotation);
  void setTime(String time, bool forceRefresh = false);
  void setNumber(int value, bool forceRefresh = false);
  // void setText(String txt, bool forceRefresh = false);
  void setFallState(int index, int value, int xPos);
  void drawColon(int x, int y, uint16_t colonColor);
  int calculateWidth();

  static const uint16_t tetrisRED = 0xF800;
  static const uint16_t tetrisGREEN = 0x07E0;
  static const uint16_t tetrisBLUE = 0x325F;
  static const uint16_t tetrisWHITE = 0xFFFF;
  static const uint16_t tetrisYELLOW = 0xFFE0;
  static const uint16_t tetrisCYAN = 0x07FF;
  static const uint16_t tetrisMAGENTA = 0xF81F;
  static const uint16_t tetrisORANGE = 0xFB00;
  static const uint16_t tetrisBLACK = 0x0000;
  uint16_t DefaultPalette[9] = {
      tetrisRED,
      tetrisGREEN,
      tetrisBLUE,
      tetrisWHITE,
      tetrisYELLOW,
      tetrisCYAN,
      tetrisMAGENTA,
      tetrisORANGE,
      tetrisBLACK};

private:
  Adafruit_GFX *_display;
  bool _debug = false;
  int _scale = 1;
  bool _drawOutline = false;
  uint16_t _outlineColor = 0x0000;
  NumberFallState _fallStates[TETRIS_MAX_NUMBERS];
  int _displayValueCharCount;

  void initializeColors();
  void resetNumStates();
  void drawLargerBlock(int x_pos, int y_pos, int scale, uint16_t color);
};