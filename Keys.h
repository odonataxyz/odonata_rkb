#ifndef OdnataRKBKeys_h
#define OdnataRKBKeys_h

#include "Keyboard.h"

#define SHFT KEY_LEFT_SHIFT
#define CTRL KEY_LEFT_CTRL
#define ALT  KEY_LEFT_ALT
#define DLT  KEY_DELETE
#define ENTR KEY_RETURN
#define BS   KEY_BACKSPACE
#define TAB  KEY_TAB
#define EMP  0x00
#define PLUS ':'
#define ESC  KEY_ESC
#define KPLS 0xDF
#define KMNS 0xDE
#define SLSH 0xDC
#define ASTR 0xDD

#define KP_1          0xE1
#define KP_2          0xE2
#define KP_3          0xE3
#define KP_4          0xE4
#define KP_5          0xE5
#define KP_6          0xE6
#define KP_7          0xE7
#define KP_8          0xE8
#define KP_9          0xE9
#define KP_0          0xEA
#define KP_D          0xEB

//マウス機能
#define LCLK              0xFF //左クリック
#define RCLK              0xFE //右クリック
#define MCLK              0xFD //中クリック
#define UWHL              0xFC //ホイールアップ
#define DWHL              0xFB //ホイールダウン

#define UARW  KEY_UP_ARROW
#define DARW  KEY_DOWN_ARROW
#define LARW  KEY_LEFT_ARROW
#define RARW  KEY_RIGHT_ARROW
#define PGUP  KEY_PAGE_UP
#define PGDN  KEY_PAGE_DOWN
#define HOME  KEY_HOME
#define END   KEY_END

#define BRCT 0x5B //[
#define BLCT 0x5D //]
#define ARCT 0x3C //<
#define ALCT 0x3E //>
#define CRCT 0x7B //{
#define CLCT 0x7D //}
#define ATMK 0x40 //@
#define CTMK 0x5E //^

#endif
