#ifndef OdonataRKBConfig_h
#define OdonataRKBConfig_h

#include "Keys.h"

const int ROWS = 4; // 行数
const int COLS = 4; // 列数

const int colPins[COLS] = {21, 20, 19, 18};
const int rowPins[ROWS] = {15, 14, 16, 10};

const int TOGGLES = 3; // トグルボタンの数
const int TROWS = 2; // トグルキー行数
const int TCOLS = 2; // トグルキー列数

const int rowTogglePins[TROWS] = {8, 9};
const int colTogglePins[TCOLS] = {6, 7};

const int rotaryPins[] = {4, 5};

#define LED_PIN 3

#define WHEEL_SPEED 1 //マウスホイールの速度


//ロータリーエンコーダのキーマッピング
const char ROT[2][4][2] = {
  { /* default */
    {BRCT,  BLCT},  /* □ □ */
    {ARCT,  ALCT},  /* □ ■ */
    {UWHL,  DWHL},  /* ■ □ */
    {ATMK,  CTMK},  /* ■ ■ */
  },{ /* fn */
    {BRCT,  BLCT},  /* □ □ */
    {ARCT,  ALCT},  /* □ ■ */
    {UWHL,  DWHL},  /* ■ □ */
    {ATMK,  CTMK},  /* ■ ■ */
  }
};


//キーボードのキーマッピング
const char MAT[2][4][ROWS][COLS] = {
  { /* default */
    { /* □ □ */
      { 'a', 'b', KMNS,  'z'},
      { 'e', 'f', KPLS,  CTRL},
      { 'x', 'c',  'v',  SHFT},
      {ENTR,  BS,  EMP,  ALT }
    },{ /* □ ■ */
      {'h',  'o',  'd',  ' ' },
      {'g',  'r',  's',  CTRL},
      {'w',  't',  'y',  SHFT},
      {'/',  '*',  EMP,  ALT }
    },{ /* ■ □ */
      {'i',  'j',  'l',  TAB },
      {'n',  'm',  'k',  CTRL},
      {'p',  'u',  'q',  SHFT},
      {DLT,  RCLK,  EMP,  ALT }
    },{ /* ■ ■ */
      {KP_7,  KP_8,  KP_9,  ASTR  },
      {KP_4,  KP_5,  KP_6,  KMNS  },
      {KP_1,  KP_2,  KP_3,  KPLS  },
      {KP_0,  KP_D,  EMP,   SLSH  }
    }
  },{ /* fn */
    { /* □ □ */
      {KP_7,  KP_8,  KP_9,  ASTR  },
      {KP_4,  KP_5,  KP_6,  KMNS  },
      {KP_1,  KP_2,  KP_3,  KPLS  },
      {KP_0,  KP_D,  EMP,   SLSH  }
    },{ /* □ ■ */
      {KEY_PAGE_UP,   KEY_F8,  KEY_HOME, ESC },
      {KEY_PAGE_DOWN, UARW,    KEY_END,  CTRL},
      {LARW,          DARW,    RARW,     SHFT},
      {KEY_F11,       KEY_F12, EMP,      ALT }
    },{ /* ■ □ */
      {UWHL,  KEY_F8,  KEY_F9,  KEY_F10 },
      {DWHL,  KEY_F5,  KEY_F6,  CTRL},
      {KEY_F1,  KEY_F2,  KEY_F3,  SHFT},
      {KEY_F11, KEY_F12,  EMP,    ALT }
    },{ /* ■ ■ */
      {KEY_F7,  KEY_F8,  KEY_F9,  KEY_F10 },
      {KEY_F4,  KEY_F5,  KEY_F6,  CTRL},
      {KEY_F1,  KEY_F2,  KEY_F3,  SHFT},
      {KEY_F11, KEY_F12,  EMP,    ALT }
    }
  }
};

#endif
