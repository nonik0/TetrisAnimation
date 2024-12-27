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

#include "TetrisMatrixDraw.h"
#include "TetrisNumbers.h"
#include "TetrisLetters.h"

TetrisMatrixDraw::TetrisMatrixDraw(Adafruit_GFX &display)
{
  _display = &display;
  resetNumStates();
}
/*
void TetrisMatrixDraw::drawChar(String letter, uint8_t x, uint8_t y, uint16_t color)
{
  _display->setTextColor(color);
  _display->setCursor(x, y);
  _display->print(letter);
}
*/
void TetrisMatrixDraw::drawShape(BlockType blockType, uint16_t color, int xPos, int yPos, BlockRotation blockRotation)
{
  if (blockType == SQUARE)
  {
    _display->drawPixel(xPos, yPos, color);
    _display->drawPixel(xPos + 1, yPos, color);
    _display->drawPixel(xPos, yPos - 1, color);
    _display->drawPixel(xPos + 1, yPos - 1, color);
  }
  else if (blockType == L_SHAPE)
  {
    if (blockRotation == ROTATION_0)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos, yPos - 2, color);
    }
    else if (blockRotation == ROTATION_90)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
      _display->drawPixel(xPos + 2, yPos - 1, color);
    }
    else if (blockRotation == ROTATION_180)
    {
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 2, color);
      _display->drawPixel(xPos, yPos - 2, color);
    }
    else if (blockRotation == ROTATION_270)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos + 2, yPos, color);
      _display->drawPixel(xPos + 2, yPos - 1, color);
    }
  }
  else if (blockType == L_SHAPE_REVERSE)
  {
    if (blockRotation == ROTATION_0)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 2, color);
    }
    else if (blockRotation == ROTATION_90)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos + 2, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
    }
    else if (blockRotation == ROTATION_180)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos, yPos - 2, color);
      _display->drawPixel(xPos + 1, yPos - 2, color);
    }
    else if (blockRotation == ROTATION_270)
    {
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
      _display->drawPixel(xPos + 2, yPos - 1, color);
      _display->drawPixel(xPos + 2, yPos, color);
    }
  }
  else if (blockType == I_SHAPE)
  {
    if (blockRotation == ROTATION_90 || blockRotation == ROTATION_270)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos + 2, yPos, color);
      _display->drawPixel(xPos + 3, yPos, color);
    }
    else // if (blockRotation == ROTATION_0 || blockRotation == ROTATION_180)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos, yPos - 2, color);
      _display->drawPixel(xPos, yPos - 3, color);
    }
  }
  else if (blockType == S_SHAPE)
  {
    if (blockRotation == ROTATION_90 || blockRotation == ROTATION_270)
    {
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
      _display->drawPixel(xPos, yPos - 2, color);
    }
    else // if (blockRotation == ROTATION_0 || blockRotation == ROTATION_180)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
      _display->drawPixel(xPos + 2, yPos - 1, color);
    }
  }
  else if (blockType == S_SHAPE_REVERSE)
  {
    if (blockRotation == ROTATION_90 || blockRotation == ROTATION_270)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 2, color);
    }
    else // if (blockRotation == ROTATION_0 || blockRotation == ROTATION_180)
    {
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos + 2, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
    }
  }
  else if (blockType == HALF_CROSS)
  {
    if (blockRotation == ROTATION_0)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos + 2, yPos, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
    }
    else if (blockRotation == ROTATION_90)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos, yPos - 2, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
    }
    else if (blockRotation == ROTATION_180)
    {
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
      _display->drawPixel(xPos + 2, yPos - 1, color);
    }
    else if (blockRotation == ROTATION_270)
    {
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 2, color);
    }
  }
  else if (blockType == CORNER_SHAPE)
  {
    if (blockRotation == ROTATION_0)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
    }
    else if (blockRotation == ROTATION_90)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos, yPos - 1, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
    }
    else if (blockRotation == ROTATION_180)
    {
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
      _display->drawPixel(xPos, yPos - 1, color);
    }
    else if (blockRotation == ROTATION_270)
    {
      _display->drawPixel(xPos, yPos, color);
      _display->drawPixel(xPos + 1, yPos, color);
      _display->drawPixel(xPos + 1, yPos - 1, color);
    }
  }
}

void TetrisMatrixDraw::drawLargerBlock(int xPos, int yPos, int scale, uint16_t color)
{
  _display->fillRect(xPos, yPos, scale, scale, color);
  if (_drawOutline)
  {
    _display->drawRect(xPos, yPos, scale, scale, _outlineColor);
  }
}

void TetrisMatrixDraw::drawLargerShape(int scale, BlockType blockType, uint16_t color, int xPos, int yPos, BlockRotation blockRotation)
{
  int offset1 = 1 * scale;
  int offset2 = 2 * scale;
  int offset3 = 3 * scale;

  // Square
  if (blockType == SQUARE)
  {
    drawLargerBlock(xPos, yPos, scale, color);
    drawLargerBlock(xPos + offset1, yPos, scale, color);
    drawLargerBlock(xPos, yPos - offset1, scale, color);
    drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
  }
  else if (blockType == L_SHAPE)
  {
    if (blockRotation == ROTATION_0)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos, yPos - offset2, scale, color);
    }
    else if (blockRotation == ROTATION_90)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset2, yPos - offset1, scale, color);
    }
    else if (blockRotation == ROTATION_180)
    {
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset2, scale, color);
      drawLargerBlock(xPos, yPos - offset2, scale, color);
    }
    else if (blockRotation == ROTATION_270)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos + offset2, yPos, scale, color);
      drawLargerBlock(xPos + offset2, yPos - offset1, scale, color);
    }
  }
  else if (blockType == L_SHAPE_REVERSE)
  {
    if (blockRotation == ROTATION_0)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset2, scale, color);
    }
    else if (blockRotation == ROTATION_90)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos + offset2, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
    }
    else if (blockRotation == ROTATION_180)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos, yPos - offset2, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset2, scale, color);
    }
    else if (blockRotation == ROTATION_270)
    {
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset2, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset2, yPos, scale, color);
    }
  }
  else if (blockType == I_SHAPE)
  {
    if (blockRotation == ROTATION_90 || blockRotation == ROTATION_270)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos + offset2, yPos, scale, color);
      drawLargerBlock(xPos + offset3, yPos, scale, color);
      return;
    }
    else
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos, yPos - offset2, scale, color);
      drawLargerBlock(xPos, yPos - offset3, scale, color);
      return;
    }
  }
  else if (blockType == S_SHAPE)
  {
    if (blockRotation == ROTATION_90 || blockRotation == ROTATION_270)
    {
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
      drawLargerBlock(xPos, yPos - offset2, scale, color);
    }
    else
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset2, yPos - offset1, scale, color);
    }
  }
  else if (blockType == S_SHAPE_REVERSE)
  {
    if (blockRotation == ROTATION_90 || blockRotation == ROTATION_270)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset2, scale, color);
      return;
    }
    else
    {
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos + offset2, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
      return;
    }
  }
  else if (blockType == HALF_CROSS)
  {
    if (blockRotation == ROTATION_0)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos + offset2, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
    }
    else if (blockRotation == ROTATION_90)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos, yPos - offset2, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
    }
    else if (blockRotation == ROTATION_180)
    {
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset2, yPos - offset1, scale, color);
    }
    else if (blockRotation == ROTATION_270)
    {
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset2, scale, color);
    }
  }
  else if (blockType == CORNER_SHAPE)
  {
    if (blockRotation == ROTATION_0)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
    }
    else if (blockRotation == ROTATION_90)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
    }
    else if (blockRotation == ROTATION_180)
    {
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
      drawLargerBlock(xPos, yPos - offset1, scale, color);
    }
    else if (blockRotation == ROTATION_270)
    {
      drawLargerBlock(xPos, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos, scale, color);
      drawLargerBlock(xPos + offset1, yPos - offset1, scale, color);
    }
  }
}

void TetrisMatrixDraw::setFallState(int index, int value, int xPos)
{
  if (index < TETRIS_MAX_NUMBERS)
  {
    Serial.println(value);
    _fallStates[index].value = value;
    _fallStates[index].xPos = xPos;
    _fallStates[index].yPos = 0;
    _fallStates[index].blockIndex = 0;
  }
}

void TetrisMatrixDraw::setTime(String timeStr, bool forceRefresh)
{
  _displayValueCharCount = 4;
  timeStr.replace(":", "");
  for (uint8_t pos = 0; pos < 4; pos++)
  {
    int xOffset = pos * TETRIS_DISTANCE_BETWEEN_DIGITS * _scale;
    if (pos >= 2)
    {
      xOffset += (3 * _scale);
    }

    char digit = timeStr[pos];
    if (forceRefresh || digit != _fallStates[pos].value)
    {
      setFallState(pos, digit, xOffset);
    }
  }
}

void TetrisMatrixDraw::setNumber(int number, bool forceRefresh)
{
  String numberStr = String(number);
  if (numberStr.length() > TETRIS_MAX_NUMBERS)
  {
    Serial.println("Number too long");
    return;
  }

  for (uint8_t pos = 0; pos < numberStr.length(); pos++)
  {
    int digitXPos = pos * _scale * TETRIS_DISTANCE_BETWEEN_DIGITS;
    int digitValue = (int)numberStr[pos];
    // Only change the number if its different or being forced
    if (forceRefresh || digitValue != _fallStates[pos].value)
    {
      setFallState(pos, digitValue, digitXPos);
    }
    else
    {
      _fallStates[pos].xPos = digitXPos;
    }
  }
}
/*
void TetrisMatrixDraw::setText(String txt, bool forceRefresh)
{
  sizeOfValue = txt.length();
  int currentXShift = 0;
  for (uint8_t pos = 0; pos < sizeOfValue; pos++)
  {
    currentXShift = TETRIS_DISTANCE_BETWEEN_DIGITS * _scale * pos;
    char letter = txt.charAt(pos);
    if (forceRefresh || (int)letter != numstates[pos].numberToDraw)
    {
      setNumState(pos, (int)letter, currentXShift);
    }
    else
    {
      numstates[pos].xShift = currentXShift;
    }
  }
}

bool TetrisMatrixDraw::drawText(int x, int yFinish)
{
  // For each number position
  bool finishedAnimating = true;

  int scaledYOffset = (_scale > 1) ? _scale : 1;
  int y = yFinish - (TETRIS_Y_DROP_DEFAULT * _scale);

  // For each number position
  for (int numpos = 0; numpos < sizeOfValue; numpos++)
  {

    if (numstates[numpos].numberToDraw >= 33)
    {
      // Draw falling shape
      // if (numstates[numpos].blockindex < blocksPerNumber[numstates[numpos].num_to_draw])
      if (numstates[numpos].blockIndex < blocksPerChar[numstates[numpos].numberToDraw - 33])
      {
        finishedAnimating = false;
        LetterFallInstruction current_fall = getFallinstrByAscii(numstates[numpos].numberToDraw, numstates[numpos].blockIndex);

        // Handle variations of rotations
        uint8_t rotations = current_fall.rotation;
        if (rotations == 1)
        {
          if (numstates[numpos].fallIndex < (int)(current_fall.yStop / 2))
          {
            rotations = 0;
          }
        }
        if (rotations == 2)
        {
          if (numstates[numpos].fallIndex < (int)(current_fall.yStop / 3))
          {
            rotations = 0;
          }
          if (numstates[numpos].fallIndex < (int)(current_fall.yStop / 3 * 2))
          {
            rotations = 1;
          }
        }
        if (rotations == 3)
        {
          if (numstates[numpos].fallIndex < (int)(current_fall.yStop / 4))
          {
            rotations = 0;
          }
          if (numstates[numpos].fallIndex < (int)(current_fall.yStop / 4 * 2))
          {
            rotations = 1;
          }
          if (numstates[numpos].fallIndex < (int)(current_fall.yStop / 4 * 3))
          {
            rotations = 2;
          }
        }
        if (_scale <= 1)
        {
          drawShape(current_fall.type,
                    DefaultPalette[current_fall.color],
                    x + current_fall.xPos + numstates[numpos].xShift,
                    y + numstates[numpos].fallIndex - scaledYOffset,
                    rotations);
        }
        else
        {
          drawLargerShape(_scale,
                          current_fall.type,
                          DefaultPalette[current_fall.color],
                          x + (current_fall.xPos * _scale) + numstates[numpos].xShift,
                          y + (numstates[numpos].fallIndex * scaledYOffset) - scaledYOffset,
                          rotations);
        }
        // drawShape(current_fall.blocktype, tetrisColors[current_fall.color], x + current_fall.x_pos + numstates[numpos].x_shift, y + numstates[numpos].fallindex - 1, rotations);
        numstates[numpos].fallIndex++;

        if (numstates[numpos].fallIndex > current_fall.yStop)
        {
          numstates[numpos].fallIndex = 0;
          numstates[numpos].blockIndex++;
        }
      }

      // Draw already dropped shapes
      if (numstates[numpos].blockIndex > 0)
      {
        for (int i = 0; i < numstates[numpos].blockIndex; i++)
        {
          LetterFallInstruction fallen_block = getFallinstrByAscii(numstates[numpos].numberToDraw, i);
          if (_scale <= 1)
          {
            drawShape(fallen_block.type,
                      DefaultPalette[fallen_block.color],
                      x + fallen_block.xPos + numstates[numpos].xShift,
                      y + fallen_block.yStop - 1,
                      fallen_block.rotation);
          }
          else
          {
            drawLargerShape(_scale,
                            fallen_block.type,
                            DefaultPalette[fallen_block.color],
                            x + (fallen_block.xPos * _scale) + numstates[numpos].xShift,
                            y + (fallen_block.yStop * scaledYOffset) - scaledYOffset,
                            fallen_block.rotation);
          }
          // drawShape(fallen_block.blocktype, tetrisColors[fallen_block.color], x + fallen_block.x_pos + numstates[numpos].x_shift, y + fallen_block.y_stop - 1, fallen_block.num_rot);
        }
      }
    }
  }

  return finishedAnimating;
}
*/
bool TetrisMatrixDraw::drawNumber(int x, int y, bool displayColon)
{
  // For each number position
  bool finishedAnimating = true;
  int yFinish = y;
  int yStart = yFinish - (TETRIS_Y_DROP_DEFAULT * _scale);

  for (int pos = 0; pos < _displayValueCharCount; pos++)
  {
    if (_fallStates[pos].value < 0 || _fallStates[pos].value > 9)
    {
      log_w("Invalid number to draw: %d", _fallStates[pos].value);
      continue;
    }

    // Draw falling shape
    if (_fallStates[pos].blockIndex < DigitBlockCount[_fallStates[pos].value])
    {
      finishedAnimating = false;
      BlockFallData fallingBlock = getBlockFallData(_fallStates[pos].value, _fallStates[pos].blockIndex);

      // Handle variations of rotations
      BlockRotation rotation = fallingBlock.rotation;
      if (rotation == ROTATION_90)
      {
        if (_fallStates[pos].yPos < (int)(fallingBlock.yPosFinal / 2))
        {
          rotation = ROTATION_0;
        }
      }
      else if (rotation == ROTATION_180)
      {
        if (_fallStates[pos].yPos < fallingBlock.yPosFinal / 3)
        {
          rotation = ROTATION_0;
        }
        else if (_fallStates[pos].yPos < 2 * fallingBlock.yPosFinal / 3)
        {
          rotation = ROTATION_90;
        }
      }
      else if (rotation == ROTATION_270)
      {
        if (_fallStates[pos].yPos < fallingBlock.yPosFinal / 4)
        {
          rotation = ROTATION_0;
        }
        else if (_fallStates[pos].yPos < 2 * fallingBlock.yPosFinal / 4)
        {
          rotation = ROTATION_90;
        }
        else if (_fallStates[pos].yPos < 3 * fallingBlock.yPosFinal / 4)
        {
          rotation = ROTATION_180;
        }
      }

      if (_scale <= 1)
      {
        drawShape(fallingBlock.type,
                  DefaultPalette[fallingBlock.color],
                  x + fallingBlock.xPos + _fallStates[pos].xPos,
                  yStart + _fallStates[pos].yPos - 1,
                  rotation);
      }
      else
      {
        drawLargerShape(_scale,
                        fallingBlock.type,
                        DefaultPalette[fallingBlock.color],
                        x + (fallingBlock.xPos * _scale) + _fallStates[pos].xPos,
                        yStart + (_fallStates[pos].yPos * (_scale - 1)),
                        rotation);
      }
      _fallStates[pos].yPos++;

      // current block done falling, move to next block
      if (_fallStates[pos].yPos > fallingBlock.yPosFinal)
      {
        _fallStates[pos].yPos = 0;
        _fallStates[pos].blockIndex++;
      }
    }

    // Draw already dropped shapes
    if (_fallStates[pos].blockIndex > 0)
    {
      for (int i = 0; i < _fallStates[pos].blockIndex; i++)
      {
        BlockFallData fallenBlock = getBlockFallData(_fallStates[pos].value, i);
        if (_scale <= 1)
        {
          drawShape(fallenBlock.type,
                    DefaultPalette[fallenBlock.color],
                    x + fallenBlock.xPos + _fallStates[pos].xPos,
                    yStart + fallenBlock.yPosFinal - 1,
                    fallenBlock.rotation);
        }
        else
        {
          drawLargerShape(_scale,
                          fallenBlock.type,
                          DefaultPalette[fallenBlock.color],
                          x + (fallenBlock.xPos * _scale) + _fallStates[pos].xPos,
                          yStart + (fallenBlock.yPosFinal * (_scale - 1)),
                          fallenBlock.rotation);
        }
      }
    }
  }

  if (displayColon)
  {
    drawColon(x, yStart, tetrisWHITE);
  }

  return finishedAnimating;
}

void TetrisMatrixDraw::drawColon(int x, int y, uint16_t colonColor)
{
  int colonSize = 2 * _scale;
  int xColonPos = x + (TETRIS_DISTANCE_BETWEEN_DIGITS * 2 * _scale);
  _display->fillRect(xColonPos, y + (12 * _scale), colonSize, colonSize, colonColor);
  _display->fillRect(xColonPos, y + (8 * _scale), colonSize, colonSize, colonColor);
}

int TetrisMatrixDraw::calculateWidth()
{
  return (_displayValueCharCount * TETRIS_DISTANCE_BETWEEN_DIGITS) - 1;
}

void TetrisMatrixDraw::resetNumStates()
{
  for (int i = 0; i < TETRIS_MAX_NUMBERS; i++)
  {
    _fallStates[i].value = -1;
    _fallStates[i].yPos = 0;
    _fallStates[i].blockIndex = 0;
    _fallStates[i].xPos = 0;
  }
}