/*
Font created by Mike Swan.  
Github: n00dles101
*/


// *********************************************************************
// Types and data that describes how numbers are drawed
// *********************************************************************

// Type that describes how a brick is falling down
struct LetterFallInstruction
{
  int type;  // Number of the block type
  int color; // Color of the brick
  int xPos;      // x-position (starting from the left number staring point) where the brick should be placed
  int yStop;     // y-position (1-16, where 16 is the last line of the matrix) where the brick should stop falling
  int rotation;    // Number of 90-degree (clockwise) rotations a brick is turned from the standard position
};

//
// ASCII characters
//

// *********************************************************************
// ascii 33 - !
// *********************************************************************

static const LetterFallInstruction a33[5] = {
    {0,0,2,16,0},
    {2,5,3,13,2},
    {1,3,1,13,2},
    {7,1,1,10,3},
    {7,6,3,10,0}
};

// *********************************************************************
// ascii 34 - "
// *********************************************************************

static const LetterFallInstruction a34[4] = {
    {7,0,1,11,3},
    {7,1,4,11,3},
    {7,2,1,10,1},
    {7,5,4,10,1}
};

// *********************************************************************
// ascii 35 - #
// *********************************************************************

static const LetterFallInstruction a35[9] = {
    {7,0,0,16,2},
    {7,5,4,16,1},
    {0,6,2,15,0},
    {7,3,0,14,2},
    {7,1,4,14,1},
    {6,3,0,12,2},
    {6,4,3,12,2},
    {6,6,0,10,0},
    {6,7,3,10,0}
};

// *********************************************************************
// ascii 36 - $
// *********************************************************************

static const LetterFallInstruction a36[8] = {
    {2,2,0,16,3},
    {7,0,3,16,1},
    {7,3,4,14,3},
    {1,6,2,13,3},
    {1,7,1,13,1},
    {7,3,0,12,1},
    {7,1,1,10,3},
    {2,2,3,10,1}
};

// *********************************************************************
// ascii 37 - %
// *********************************************************************

static const LetterFallInstruction a37[7] = {
    {0,6,4,16,0},
    {7,1,0,16,3},
    {7,3,1,15,1},
    {0,0,2,13,0},
    {7,5,3,12,0},
    {7,7,4,10,1},
    {0,2,0,10,0}
};

// *********************************************************************
// ascii 38 - &
// *********************************************************************

static const LetterFallInstruction a38[8] = {
    {2,1,1,16,1},
    {4,0,4,16,0},
    {5,4,0,15,0},
    {6,7,2,14,3},
    {7,6,1,12,0},
    {5,3,4,12,0},
    {5,1,0,11,0},
    {2,2,2,10,3}
};

// *********************************************************************
// ascii 39 - '
// *********************************************************************

static const LetterFallInstruction a39[2] = {
    {7,3,2,10,1},
    {7,0,2,11,3}
};

// *********************************************************************
// ascii 40 - (
// *********************************************************************

static const LetterFallInstruction a40[4] = {
    {5,0,1,16,1},
    {2,6,0,14,0},
    {2,3,0,13,2},
    {4,5,1,10,1}
};

// *********************************************************************
// ascii 41 - )
// *********************************************************************

static const LetterFallInstruction a41[4] = {
    {4,6,2,16,1},
    {2,0,4,14,0},
    {2,3,4,13,2},
    {5,6,2,10,1}
};

// *********************************************************************
// ascii 42 - *
// *********************************************************************

static const LetterFallInstruction a42[6] = {
    {4,6,0,14,1},
    {5,5,3,14,1},
    {0,2,1,12,0},
    {0,0,3,12,0},
    {2,1,3,10,1},
    {1,2,0,10,3}
};

// *********************************************************************
// ascii 43 - +
// *********************************************************************

static const LetterFallInstruction a43[5] = {
    {2,1,2,15,0},
    {2,6,0,14,3},
    {0,3,4,13,0},
    {3,4,0,12,0},
    {0,2,2,11,0}
};

// *********************************************************************
// ascii 44 -,
// *********************************************************************

static const LetterFallInstruction a44[2] = {
    {7,4,1,16,3},
    {7,0,2,15,2}
};

// *********************************************************************
// ascii 45 - - 
// *********************************************************************

static const LetterFallInstruction a45[3] = {
    {3,1,1,13,0},
    {2,6,3,13,3},
    {1,0,0,13,1}
};


// *********************************************************************
// ascii 46 - .
// *********************************************************************

static const LetterFallInstruction a46[1] = {
    {0,1,3,16,0}
};

// *********************************************************************
// ascii 47 - /
// *********************************************************************

static const LetterFallInstruction a47[5] = {
    {4,6,0,16,1},
    {7,0,1,14,3},
    {7,3,2,13,2},
    {7,5,3,11,0},
    {7,7,4,10,1}
};

// *********************************************************************
// ascii 48 - 0
// *********************************************************************

static const LetterFallInstruction a48[10] = {
    {7,0,2,16,3},
    {6,3,0,16,2},
    {7,4,4,16,1},
    {3,2,0,14,1},
    {6,5,1,14,1},
    {0,1,4,14,0},
    {1,3,3,12,3},
    {6,7,0,11,3},
    {0,2,2,10,0},
    {6,3,4,11,1}
};

// *********************************************************************
// ascii 49 - 1
// *********************************************************************

static const LetterFallInstruction a49[8] = {
    {0,4,0,16,0},
    {1,2,2,16,1},
    {1,4,3,16,3},
    {7,3,2,14,3},
    {5,1,2,13,0},
    {6,6,0,11,0},
    {7,6,0,10,1},
    {0,0,2,10,0}
};

// *********************************************************************
// ascii 50 - 2
// *********************************************************************

static const LetterFallInstruction a50[9] = {
    {7,4,0,16,2},
    {1,2,2,16,1},
    {1,6,3,16,3},
    {0,2,0,14,0},
    {1,3,2,13,3},
    {1,2,4,13,2},
    {6,6,3,10,0},
    {7,0,2,10,1},
    {0,6,0,10,0}
};

// *********************************************************************
// ascii 51 - 3
// *********************************************************************

static const LetterFallInstruction a51[9] = {
    {1,2,1,16,3},
    {1,5,0,16,1},
    {5,4,4,16,0},
    {6,6,3,14,2},
    {0,2,1,13,0},
    {1,1,3,12,3},
    {6,5,4,11,1},
    {1,3,1,10,3},
    {1,3,0,10,1}
};

// *********************************************************************
// ascii 52 - 4
// *********************************************************************

static const LetterFallInstruction a52[8] = {
    {2,1,4,16,0},
    {3,2,4,15,1},
    {3,3,5,13,3},
    {1,0,1,13,3},
    {1,5,0,13,1},
    {7,1,0,11,3},
    {7,3,0,10,1},
    {2,6,4,11,2}
};

// *********************************************************************
// ascii 53 - 5
// *********************************************************************

static const LetterFallInstruction a53[10] = {
    {2,3,0,16,1},
    {2,4,1,16,3},
    {0,6,4,16,0},
    {0,7,4,14,0},
    {2,1,1,13,1},
    {2,5,0,13,2},
    {3,2,2,12,0},
    {1,4,0,10,1},
    {1,1,1,10,3},
    {0,0,4,10,0}
};

// *********************************************************************
// ascii 54 - 6
// *********************************************************************

static const LetterFallInstruction a54[10] = {
    {4,4,1,16,1},
    {4,3,3,16,1},
    {2,3,0,15,0},
    {0,0,4,14,0},
    {3,3,0,14,1},
    {7,4,1,13,2},
    {7,2,3,13,1},
    {6,6,0,11,3},
    {6,6,3,10,0},
    {7,4,2,10,1}
};

// *********************************************************************
// ascii 55 - 7
// *********************************************************************

static const LetterFallInstruction a55[6] = {
    {0,0,2,16,0},
    {0,5,3,14,0},
    {2,5,4,12,0},
    {2,6,2,11,3},
    {0,0,0,10,0},
    {3,1,2,9,0},
};

// *********************************************************************
// ascii 56 - 8
// *********************************************************************

static const LetterFallInstruction a56[8] = {
    {5,1,0,16,1},
    {4,4,3,16,1},
    {2,2,0,14,0},
    {1,2,4,14,0},
    {0,5,2,13,0},
    {0,6,0,11,0},
    {0,0,4,11,0},
    {3,1,1,9,0}
};

// *********************************************************************
// ascii 57 - 9
// *********************************************************************

static const LetterFallInstruction a57[7] = {
    {2,3,4,16,0},
    {2,2,4,15,2},
    {3,7,1,12,0},
    {6,6,4,12,3},
    {7,5,0,11,0},
    {7,4,4,10,1},
    {1,1,1,10,1}
};

// *********************************************************************
// ascii 58 - :
// *********************************************************************

static const LetterFallInstruction a58[2] = {
    {0,1,2,15,0},
    {0,6,2,11,0}
};

// *********************************************************************
// ascii 59 - ;
// *********************************************************************

static const LetterFallInstruction a59[3] = {
    {7,3,1,16,3},
    {7,4,2,15,2},
    {0,2,2,11,0}
};

// *********************************************************************
// ascii 60 - <
// *********************************************************************

static const LetterFallInstruction a60[5] = {
    {7,6,3,16,0},
    {7,1,1,15,2},
    {0,3,0,13,0},
    {7,2,1,11,3},
    {7,4,3,10,1}
};


// *********************************************************************
// ascii 61 - =
// *********************************************************************

static const LetterFallInstruction a61[4] = {
    {1,1,2,15,3},
    {1,2,1,15,1},
    {1,3,2,11,3},
    {1,5,1,11,1}
};


// *********************************************************************
// ascii 62 - >
// *********************************************************************

static const LetterFallInstruction a62[5] = {
    {7,4,1,16,3},
    {7,2,3,15,1},
    {0,5,4,13,0},
    {7,3,3,11,0},
    {7,1,1,10,2}
};

// *********************************************************************
// ascii 63 - ?
// *********************************************************************

static const LetterFallInstruction a63[6] = {
    {7,1,2,16,3},
    {4,3,2,14,1},
    {2,2,4,12,0},
    {2,6,2,11,3},
    {0,4,0,11,0},
    {3,5,1,9,0}
};


// *********************************************************************
// ascii 64 - @
// *********************************************************************

static const LetterFallInstruction a64[8] = {
    {6,2,1,16,0},
    {6,1,3,16,2},
    {1,3,0,15,0},
    {1,4,2,13,1},
    {3,5,0,12,1},
    {7,6,1,10,1},
    {6,3,2,10,0},
    {1,2,4,12,2}
};


// *********************************************************************
// ascii 65 - A
// *********************************************************************

static const LetterFallInstruction a65[9] = {
    {0,2,0,16,0},
    {0,1,4,16,0},
    {5,5,3,14,1},
    {4,2,0,14,1},
    {4,1,4,13,0},
    {5,0,0,13,0},
    {4,3,4,11,0},
    {5,2,0,11,0},
    {0,1,2,10,0}
};


// *********************************************************************
// ascii 66 - B
// *********************************************************************

static const LetterFallInstruction a66[9] = {
    {2,7,0,16,0},
    {1,6,2,16,3},
    {4,3,4,15,0},
    {2,1,0,15,2},
    {2,4,0,13,3},
    {5,1,3,13,0},
    {0,7,0,11,0},
    {4,0,4,11,0},
    {3,3,0,9,0}
};


// *********************************************************************
// ascii 67 - C
// *********************************************************************

static const LetterFallInstruction a67[8] = {
    {6,5,1,16,0},
    {6,3,3,16,2},
    {7,1,0,15,3},
    {5,7,0,14,0},
    {7,6,0,12,1},
    {6,3,0,10,0},
    {7,6,2,10,2},
    {7,7,4,10,0}
};

// *********************************************************************
// ascii 68 - D
// *********************************************************************

static const LetterFallInstruction a68[9] = {
    {3,7,0,16,1},
    {0,2,1,16,0},
    {5,3,3,16,0},
    {6,5,4,14,3},
    {1,1,0,14,2},
    {6,2,4,12,1},
    {7,5,0,11,0},
    {7,3,2,10,3},
    {6,4,0,10,2}
};

// *********************************************************************
// ascii 69 - E
// *********************************************************************

static const LetterFallInstruction a69[9] = {
    {0,6,4,16,0},
    {3,2,0,16,0},
    {3,3,0,15,0},
    {4,4,0,14,1},
    {2,1,1,13,3},
    {2,6,0,13,2},
    {3,0,0,10,0},
    {3,4,0,9,0},
    {0,2,4,10,0}
};


// *********************************************************************
// ascii 70 - F
// *********************************************************************

static const LetterFallInstruction a70[7] = {
    {2,1,0,16,0},
    {3,2,0,15,1},
    {1,3,1,13,0},
    {5,4,2,13,1},
    {5,5,0,11,0},
    {0,6,2,10,2},
    {0,4,4,10,0}
};

// *********************************************************************
// ascii 71 - G
// *********************************************************************

static const LetterFallInstruction a71[8] = {
    {6,7,1,16,0},
    {7,4,3,16,2},
    {4,2,4,15,0},
    {3,1,0,15,1},
    {3,0,1,15,1},
    {0,2,0,11,2},
    {6,6,3,10,0},
    {6,7,1,10,2}
};

// *********************************************************************
// ascii 72 - H
// *********************************************************************

static const LetterFallInstruction a72[9] = {
    {0,6,0,16,0},
    {1,5,4,16,0},
    {1,2,0,14,0},
    {1,1,4,15,2},
    {3,7,1,13,1},
    {0,3,2,13,2},
    {3,4,4,12,1},
    {3,5,5,12,1},
    {2,1,0,11,2}
};

// *********************************************************************
// ascii 73 - I
// *********************************************************************

static const LetterFallInstruction a73[8] = {
    {6,5,0,16,0},
    {4,1,2,16,0},
    {0,2,4,16,0},
    {4,7,2,14,0},
    {6,6,2,12,3},
    {0,2,4,10,0},
    {7,1,0,10,0},
    {6,3,1,10,2}
};

// *********************************************************************
// ascii 74 - J
// *********************************************************************

static const LetterFallInstruction a74[7] = {
    {1,7,1,16,3},
    {6,2,0,16,1},
    {6,3,3,15,3},
    {6,4,3,13,1},
    {6,2,4,11,1},
    {0,6,2,10,0},
    {0,1,0,10,0}
};

// *********************************************************************
// ascii 75 - K
// *********************************************************************

static const LetterFallInstruction a75[9] = {
    {0,2,4,16,0},
    {3,6,0,16,1},
    {2,2,1,16,2},
    {6,7,3,15,1},
    {0,5,1,13,0},
    {3,4,0,12,1},
    {1,2,1,11,0},
    {7,0,3,11,1},
    {7,1,4,10,2}
};

// *********************************************************************
// ascii 76 - L
// *********************************************************************

static const LetterFallInstruction a76[6] = {
    {1,3,3,16,3},
    {1,1,2,16,1},
    {0,0,0,16,0},
    {2,4,0,14,0},
    {2,2,0,13,2},
    {0,6,0,10,0}
};

// *********************************************************************
// ascii 77 - M
// *********************************************************************

static const LetterFallInstruction a77[9] = {
    {1,0,0,16,0},
    {2,1,4,16,0},
    {1,3,0,15,2},
    {2,3,4,15,2},
    {0,5,2,13,0},
    {4,6,0,12,1},
    {5,2,3,12,3},
    {6,2,4,11,3},
    {6,1,0,11,1}
};

// *********************************************************************
// ascii 78 - N
// *********************************************************************

static const LetterFallInstruction a78[9] = {
    {1,6,0,16,0},
    {2,1,4,16,0},
    {1,3,0,15,2},
    {2,0,4,15,2},
    {4,4,2,13,0},
    {2,6,0,12,0},
    {1,1,4,12,0},
    {1,2,4,11,2},
    {2,4,0,11,2}
};


// *********************************************************************
// ascii 79 - O
// *********************************************************************

static const LetterFallInstruction a79[9] = {
    {4,1,0,16,0},
    {5,0,4,16,0},
    {0,4,2,16,0},
    {6,4,0,14,3},
    {6,5,4,14,1},
    {6,6,0,12,1},
    {6,2,4,12,3},
    {0,1,3,10,0},
    {0,4,1,10,0}
};


// *********************************************************************
// ascii 80 - P
// *********************************************************************

static const LetterFallInstruction a80[8] = {
    {0,6,0,16,0},
    {4,2,0,14,1},
    {5,4,2,13,3},
    {7,5,4,12,0},
    {6,0,0,13,1},
    {4,1,0,11,0},
    {7,2,4,11,2},
    {3,4,1,9,0}
};

// *********************************************************************
// ascii 81 - Q
// *********************************************************************

static const LetterFallInstruction a81[9] = {
    {5,2,3,16,1},
    {4,0,1,15,1},
    {7,3,4,14,0},
    {0,5,0,14,0},
    {6,6,4,13,3},
    {0,3,0,12,0},
    {7,1,4,11,1},
    {6,2,0,10,0},
    {6,5,2,10,2}
};

// *********************************************************************
// ascii 82 - R
// *********************************************************************

static const LetterFallInstruction a82[9] = {
    {0,2,4,16,0},
    {0,3,0,16,0},
    {2,1,4,14,2},
    {1,0,1,14,1},
    {2,6,0,14,2},
    {7,1,4,11,3},
    {7,0,0,11,3},
    {7,4,0,10,1},
    {2,5,2,10,3}
};

// *********************************************************************
// ascii 83 - S
// *********************************************************************

static const LetterFallInstruction a83[9] = {
    {6,2,0,16,2},
    {6,7,2,16,0},
    {7,3,4,15,3},
    {0,5,3,14,0},
    {1,6,2,13,1},
    {6,0,0,13,3},
    {5,1,0,11,0},
    {0,1,2,10,0},
    {7,2,4,10,0}
};

// *********************************************************************
// ascii 84 - T
// *********************************************************************

static const LetterFallInstruction a84[6] = {
    {0,3,2,16,0},
    {3,2,2,14,1},
    {3,1,3,14,1},
    {2,5,2,10,1},
    {2,6,3,10,3},
    {0,1,0,10,0}
};

// *********************************************************************
// ascii 85 - U
// *********************************************************************

static const LetterFallInstruction a85[9] = {
    {6,1,4,16,1},
    {0,4,2,16,0},
    {6,3,0,16,3},
    {4,5,4,14,0},
    {5,6,0,14,0},
    {6,1,4,12,3},
    {6,0,0,12,1},
    {7,4,4,10,1},
    {7,5,0,10,2}
};

// *********************************************************************
// ascii 86 - V
// *********************************************************************

static const LetterFallInstruction a86[10] = {
    {6,0,1,16,3},
    {7,1,3,16,1},
    {6,4,3,14,0},
    {1,0,1,14,1},
    {2,6,0,14,2},
    {7,1,4,13,2},
    {7,3,0,11,3},
    {7,4,4,11,0},
    {7,3,4,10,2},
    {7,5,0,10,1}
};


// *********************************************************************
// ascii 87 - W
// *********************************************************************

static const LetterFallInstruction a87[8] = {
    {2,0,1,16,2},
    {1,1,3,16,2},
    {3,4,5,15,1},
    {3,3,0,15,1},
    {2,1,4,13,2},
    {1,2,0,13,2},
    {0,6,0,10,0},
    {0,4,4,10,0}
};


// *********************************************************************
// ascii 88 - X
// *********************************************************************

static const LetterFallInstruction a88[7] = {
    {7,6,0,16,1},
    {7,7,4,16,2},
    {3,2,1,14,0},
    {0,5,2,13,0},
    {3,6,1,11,0},
    {7,3,4,10,3},
    {7,1,0,10,0}
};

// *********************************************************************
// ascii 89 - Y
// *********************************************************************

static const LetterFallInstruction a89[7] = {
    {0,2,2,16,0},
    {1,7,2,14,0},
    {7,6,3,13,1},
    {6,5,3,11,0},
    {7,6,4,10,2},
    {6,2,1,12,1},
    {2,1,0,11,2}
};

// *********************************************************************
// ascii 90 - Z
// *********************************************************************

static const LetterFallInstruction a90[9] = {
    {2,5,0,16,1},
    {1,3,3,16,3},
    {3,1,1,15,0},
    {0,0,2,14,0},
    {7,6,3,13,2},
    {1,1,4,11,2},
    {4,7,3,11,0},
    {7,6,1,10,3},
    {7,2,0,10,1}
};

// holds the number of blocks in each character
                                   // ! " # $ % & ' ( ) * + , - . / 0  1 2 3 4 5  6  7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U  V W X Y Z
static const int blocksPerChar[64] = {5,4,9,8,7,8,2,4,4,6,5,2,3,1,5,10,8,9,9,8,10,10,6,8,7,2,3,5,4,5,6,8,9,9,8,9,9,7,8,9,8,7,9,6,9,9,9,8,9,9,9,6,9,10,8,7,7,9};

static const LetterFallInstruction getFallinstrByAscii(int num, int blockindex)
{
  switch (num) {
    case 33:
        return a33[blockindex];
        break;
    case 34:
        return a34[blockindex];
        break;
    case 35:
        return a35[blockindex];
        break;
    case 36:
        return a36[blockindex];
        break;
    case 37:
        return a37[blockindex];
        break;
    case 38:
        return a38[blockindex];
        break;
    case 39:
        return a39[blockindex];
        break;
    case 40:
        return a40[blockindex];
        break;
    case 41:
        return a41[blockindex];
        break;
    case 42:
        return a42[blockindex];
        break;
    case 43:
        return a43[blockindex];
        break;
    case 44:
        return a44[blockindex];
        break;
    case 45:
        return a45[blockindex];
        break;
    case 46:
        return a46[blockindex];
        break;
    case 47:
        return a47[blockindex];
        break;  
    case 48:
        return a48[blockindex];
        break;  
    case 49:
        return a49[blockindex];
        break;
    case 50:
        return a50[blockindex];
        break;
    case 51:
        return a51[blockindex];
        break;
    case 52:
        return a52[blockindex];
        break;
    case 53:
        return a53[blockindex];
        break;
    case 54:
        return a54[blockindex];
        break;
    case 55:
        return a55[blockindex];
        break;
    case 56:
        return a56[blockindex];
        break;
    case 57:
        return a57[blockindex];
        break;
    case 58:
        return a58[blockindex];
        break;
    case 59:
        return a59[blockindex];
        break;
    case 60:
        return a60[blockindex];
        break;
    case 61:
        return a61[blockindex];
        break;
    case 62:
        return a62[blockindex];
        break;
    case 63:
        return a63[blockindex];
        break;
    case 64:
        return a64[blockindex];
        break;
    case 65:
        return a65[blockindex];
        break;
    case 66:
        return a66[blockindex];
        break;
    case 67:
        return a67[blockindex];
        break;
    case 68:
        return a68[blockindex];
        break;
    case 69:
        return a69[blockindex];
        break;
    case 70:
        return a70[blockindex];
        break;
    case 71:
        return a71[blockindex];
        break;
    case 72:
        return a72[blockindex];
        break;
    case 73:
        return a73[blockindex];
        break;
    case 74:
        return a74[blockindex];
        break;
    case 75:
        return a75[blockindex];
        break;
    case 76:
        return a76[blockindex];
        break;
    case 77:
        return a77[blockindex];
        break;
    case 78:
        return a78[blockindex];
        break;
    case 79:
        return a79[blockindex];
        break;
    case 80:
        return a80[blockindex];
        break;
    case 81:
        return a81[blockindex];
        break;
    case 82:
        return a82[blockindex];
        break;
    case 83:
        return a83[blockindex];
        break;
    case 84:
        return a84[blockindex];
        break;
    case 85:
        return a85[blockindex];
        break;
    case 86:
        return a86[blockindex];
        break;
    case 87:
        return a87[blockindex];
        break;
    case 88:
        return a88[blockindex];
        break;
    case 89:
        return a89[blockindex];
        break;
    case 90:
    default:
        return a90[blockindex];
  }    
}


























