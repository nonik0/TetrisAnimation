#pragma once

#include "TetrisCommon.h"

// *********************************************************************
// Types and data that describes how numbers are drawn
// *********************************************************************

static const int xShiftClock[4] = {SQUARE, 7, 17, 24};

// *********************************************************************
// Fall instructions for all numbers
// *********************************************************************

static const BlockFallData ZeroFall[] = {
    {L_SHAPE_REVERSE, ROTATION_0, PALETTE_CYAN, 4, 16},
    {S_SHAPE, ROTATION_90, PALETTE_ORANGE, 2, 16},
    {I_SHAPE, ROTATION_90, PALETTE_YELLOW, 0, 16},
    {HALF_CROSS, ROTATION_90, PALETTE_MAGENTA, 1, 16},
    {S_SHAPE_REVERSE, ROTATION_0, PALETTE_GREEN, 4, 14},
    {HALF_CROSS, ROTATION_270, PALETTE_MAGENTA, 0, 13},
    {S_SHAPE_REVERSE, ROTATION_0, PALETTE_GREEN, 4, 12},
    {S_SHAPE_REVERSE, ROTATION_0, PALETTE_GREEN, 0, 11},
    {HALF_CROSS, ROTATION_90, PALETTE_MAGENTA, 4, 10},
    {HALF_CROSS, ROTATION_90, PALETTE_MAGENTA, 0, 9},
    {S_SHAPE_REVERSE, ROTATION_90, PALETTE_GREEN, 1, 8},
    {L_SHAPE_REVERSE, ROTATION_270, PALETTE_CYAN, 3, 8}};
static const size_t ZeroFallSize = sizeof(ZeroFall) / sizeof(ZeroFall[0]);

static const BlockFallData OneFall[] = {
    {L_SHAPE_REVERSE, ROTATION_0, PALETTE_CYAN, 4, 16},
    {I_SHAPE, ROTATION_90, PALETTE_YELLOW, 4, 15},
    {I_SHAPE, ROTATION_270, PALETTE_YELLOW, 5, 13},
    {L_SHAPE_REVERSE, ROTATION_180, PALETTE_CYAN, 4, 11},
    {SQUARE, ROTATION_0, PALETTE_RED, 4, 8}};
static const size_t OneFallSize = sizeof(OneFall) / sizeof(OneFall[0]);

static const BlockFallData TwoFall[] = {
    {SQUARE, ROTATION_0, PALETTE_RED, 4, 16},
    {I_SHAPE, ROTATION_90, PALETTE_YELLOW, 0, 16},
    {L_SHAPE, ROTATION_270, PALETTE_BLUE, 1, 16},
    {L_SHAPE, ROTATION_0, PALETTE_BLUE, 1, 15},
    {I_SHAPE, ROTATION_180, PALETTE_YELLOW, 1, 12},
    {L_SHAPE, ROTATION_90, PALETTE_BLUE, 0, 12},
    {L_SHAPE_REVERSE, ROTATION_270, PALETTE_CYAN, 3, 12},
    {SQUARE, ROTATION_0, PALETTE_RED, 4, 10},
    {I_SHAPE, ROTATION_0, PALETTE_YELLOW, 1, 8},
    {L_SHAPE_REVERSE, ROTATION_270, PALETTE_CYAN, 3, 8},
    {L_SHAPE, ROTATION_90, PALETTE_BLUE, 0, 8}};
static const size_t TwoFallSize = sizeof(TwoFall) / sizeof(TwoFall[0]);

static const BlockFallData ThreeFall[] = {
    {L_SHAPE, ROTATION_270, PALETTE_BLUE, 3, 16},
    {L_SHAPE_REVERSE, ROTATION_90, PALETTE_CYAN, 0, 16},
    {I_SHAPE, ROTATION_180, PALETTE_YELLOW, 1, 15},
    {SQUARE, ROTATION_0, PALETTE_RED, 4, 14},
    {I_SHAPE, ROTATION_180, PALETTE_YELLOW, 1, 12},
    {L_SHAPE, ROTATION_90, PALETTE_BLUE, 0, 12},
    {I_SHAPE, ROTATION_270, PALETTE_YELLOW, 5, 12},
    {L_SHAPE_REVERSE, ROTATION_0, PALETTE_CYAN, 3, 11},
    {I_SHAPE, ROTATION_0, PALETTE_YELLOW, 1, 8},
    {L_SHAPE, ROTATION_90, PALETTE_BLUE, 0, 8},
    {L_SHAPE_REVERSE, ROTATION_270, PALETTE_CYAN, 3, 8}};
static const size_t ThreeFallSize = sizeof(ThreeFall) / sizeof(ThreeFall[0]);

static const BlockFallData FourFall[] = {
    {SQUARE, ROTATION_0, PALETTE_RED, 4, 16},
    {SQUARE, ROTATION_0, PALETTE_RED, 4, 14},
    {I_SHAPE, ROTATION_0, PALETTE_YELLOW, 1, 12},
    {L_SHAPE, ROTATION_90, PALETTE_BLUE, 0, 12},
    {L_SHAPE_REVERSE, ROTATION_0, PALETTE_CYAN, 0, 10},
    {L_SHAPE_REVERSE, ROTATION_270, PALETTE_CYAN, 3, 12},
    {I_SHAPE, ROTATION_270, PALETTE_YELLOW, 4, 10},
    {L_SHAPE_REVERSE, ROTATION_180, PALETTE_CYAN, 0, 9},
    {I_SHAPE, ROTATION_90, PALETTE_YELLOW, 5, 10}};
static const size_t FourFallSize = sizeof(FourFall) / sizeof(FourFall[0]);

static const BlockFallData FiveFall[] = {
    {SQUARE, ROTATION_0, PALETTE_RED, 0, 16},
    {L_SHAPE_REVERSE, ROTATION_90, PALETTE_CYAN, 2, 16},
    {L_SHAPE_REVERSE, ROTATION_0, PALETTE_CYAN, 3, 15},
    {I_SHAPE, ROTATION_90, PALETTE_YELLOW, 5, 16},
    {I_SHAPE, ROTATION_0, PALETTE_YELLOW, 1, 12},
    {L_SHAPE, ROTATION_90, PALETTE_BLUE, 0, 12},
    {L_SHAPE_REVERSE, ROTATION_270, PALETTE_CYAN, 3, 12},
    {SQUARE, ROTATION_0, PALETTE_RED, 0, 10},
    {I_SHAPE, ROTATION_180, PALETTE_YELLOW, 1, 8},
    {L_SHAPE, ROTATION_90, PALETTE_BLUE, 0, 8},
    {L_SHAPE_REVERSE, ROTATION_270, PALETTE_CYAN, 3, 8}};
static const size_t FiveFallSize = sizeof(FiveFall) / sizeof(FiveFall[0]);

static const BlockFallData SixFall[] = {
    {L_SHAPE_REVERSE, ROTATION_90, PALETTE_CYAN, 0, 16},
    {S_SHAPE_REVERSE, ROTATION_90, PALETTE_GREEN, 2, 16},
    {HALF_CROSS, ROTATION_270, PALETTE_MAGENTA, 0, 15},
    {HALF_CROSS, ROTATION_270, PALETTE_MAGENTA, 4, 16},
    {S_SHAPE_REVERSE, ROTATION_0, PALETTE_GREEN, 4, 14},
    {I_SHAPE, ROTATION_180, PALETTE_YELLOW, 1, 12},
    {L_SHAPE_REVERSE, ROTATION_180, PALETTE_CYAN, 0, 13},
    {I_SHAPE, ROTATION_0, PALETTE_YELLOW, 2, 11},
    {SQUARE, ROTATION_0, PALETTE_RED, 0, 10},
    {I_SHAPE, ROTATION_0, PALETTE_YELLOW, 1, 8},
    {L_SHAPE, ROTATION_90, PALETTE_BLUE, 0, 8},
    {L_SHAPE_REVERSE, ROTATION_270, PALETTE_CYAN, 3, 8}};
static const size_t SixFallSize = sizeof(SixFall) / sizeof(SixFall[0]);

static const BlockFallData SevenFall[] = {
    {SQUARE, ROTATION_0, PALETTE_RED, 4, 16},
    {L_SHAPE, ROTATION_0, PALETTE_BLUE, 4, 14},
    {I_SHAPE, ROTATION_90, PALETTE_YELLOW, 5, 13},
    {L_SHAPE_REVERSE, ROTATION_180, PALETTE_CYAN, 4, 11},
    {I_SHAPE, ROTATION_180, PALETTE_YELLOW, 1, 8},
    {L_SHAPE_REVERSE, ROTATION_270, PALETTE_CYAN, 3, 8},
    {L_SHAPE, ROTATION_90, PALETTE_BLUE, 0, 8}};
static const size_t SevenFallSize = sizeof(SevenFall) / sizeof(SevenFall[0]);

static const BlockFallData EightFall[] = {
    {I_SHAPE, ROTATION_0, PALETTE_YELLOW, 1, 16},
    {HALF_CROSS, ROTATION_90, PALETTE_MAGENTA, 0, 16},
    {I_SHAPE, ROTATION_90, PALETTE_YELLOW, 5, 16},
    {L_SHAPE, ROTATION_270, PALETTE_BLUE, 2, 15},
    {S_SHAPE, ROTATION_0, PALETTE_ORANGE, 0, 14},
    {L_SHAPE, ROTATION_270, PALETTE_BLUE, 1, 12},
    {HALF_CROSS, ROTATION_90, PALETTE_MAGENTA, 4, 13},
    {L_SHAPE_REVERSE, ROTATION_90, PALETTE_CYAN, 0, 11},
    {S_SHAPE, ROTATION_0, PALETTE_ORANGE, 0, 10},
    {S_SHAPE, ROTATION_0, PALETTE_ORANGE, 4, 11},
    {S_SHAPE_REVERSE, ROTATION_90, PALETTE_GREEN, 0, 8},
    {S_SHAPE_REVERSE, ROTATION_90, PALETTE_GREEN, 2, 8},
    {L_SHAPE, ROTATION_180, PALETTE_BLUE, 4, 9}};
static const size_t EightFallSize = sizeof(EightFall) / sizeof(EightFall[0]);

static const BlockFallData NineFall[] = {
    {SQUARE, ROTATION_0, PALETTE_RED, 0, 16},
    {I_SHAPE, ROTATION_0, PALETTE_YELLOW, 2, 16},
    {L_SHAPE, ROTATION_270, PALETTE_BLUE, 2, 15},
    {L_SHAPE, ROTATION_180, PALETTE_BLUE, 4, 15},
    {I_SHAPE, ROTATION_180, PALETTE_YELLOW, 1, 12},
    {I_SHAPE, ROTATION_270, PALETTE_YELLOW, 5, 12},
    {S_SHAPE_REVERSE, ROTATION_0, PALETTE_GREEN, 0, 12},
    {L_SHAPE, ROTATION_270, PALETTE_BLUE, 2, 11},
    {S_SHAPE_REVERSE, ROTATION_0, PALETTE_GREEN, 4, 9},
    {HALF_CROSS, ROTATION_90, PALETTE_MAGENTA, 0, 10},
    {S_SHAPE_REVERSE, ROTATION_90, PALETTE_GREEN, 0, 8},
    {HALF_CROSS, ROTATION_180, PALETTE_MAGENTA, 2, 8}};
static const size_t NineFallSize = sizeof(NineFall) / sizeof(NineFall[0]);

static const BlockFallData* DigitFallData[10] = {ZeroFall, OneFall, TwoFall, ThreeFall, FourFall, FiveFall, SixFall, SevenFall, EightFall, NineFall};
static const int DigitBlockCount[10] = {ZeroFallSize, OneFallSize, TwoFallSize, ThreeFallSize, FourFallSize, FiveFallSize, SixFallSize, SevenFallSize, EightFallSize, NineFallSize};

// *********************************************************************
// Helper function that that return the falling instruction for a given number
// *********************************************************************
static const BlockFallData getBlockFallData(int digit, int blockIndex)
{
  return DigitFallData[digit][blockIndex];
}