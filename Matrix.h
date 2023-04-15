#ifndef Matrix_h
#define Matrix_h

#include "Arduino.h"

typedef void (*InputHandler)(int r, int c);

struct KeyState {
  bool state;
  bool lastState;
  unsigned long checked;
  unsigned long lastRepeat;
  KeyState(){
    state = lastState = false;
    lastRepeat = checked = 0;
  }
};

class Matrix
{
  public:
    Matrix(int, int, int[], int[]);
    ~Matrix();
    void tick();
    KeyState* getKeyState(int row, int col);
    int debounce;
    InputHandler onPressHandler;
    InputHandler onDuringHandler;
    InputHandler onReleaseHandler;
  private:
    int _numrows, _numcols;
    int *_rows, *_cols;
    KeyState* **_keyStates;
};



#endif
