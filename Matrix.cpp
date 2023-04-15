
#include "Matrix.h"


Matrix::Matrix(int numrows, int numcolumns, int rows[], int cols[]) {
  debounce = 15;
  _numrows = numrows;
  _numcols = numcolumns;
  _rows = rows;
  _cols = cols;
  _keyStates = new KeyState**[_numrows];
  for (int i=0; i < _numrows; i++){
    _keyStates[i] = new KeyState*[_numcols];
    pinMode(_rows[i], OUTPUT);
    digitalWrite(_rows[i], HIGH);
    for (int j = 0; j < _numcols; j++){
      pinMode(_cols[j], INPUT_PULLUP);
      _keyStates[i][j] = new KeyState();
    }
  }
}

Matrix::~Matrix() {}

KeyState* Matrix::getKeyState(int row, int col) {
  return _keyStates[row][col];
}

void Matrix::tick() {
  for (int i=0; i<_numrows; i++){
    digitalWrite(_rows[i], LOW);

    for (int j=0; j<_numcols; j++){
      KeyState* keyState = _keyStates[i][j];

      if ( digitalRead(_cols[j]) == LOW ){
        if ( keyState->state ){
          if ( !keyState->lastState && millis() - keyState->checked > debounce){
            keyState->lastState = true;
            if (onPressHandler){
              onPressHandler(i,j);
            }
          }
          if ( onDuringHandler && keyState->lastState ){
            if ( millis() - keyState->lastRepeat > debounce ){
              onDuringHandler(i,j);
              keyState->lastRepeat = millis();
            }
          }
        }else{
          keyState->state = true;
          keyState->checked = millis();
          keyState->lastState = false;
        }
      }else{
        if ( keyState->lastState ){
          keyState->lastState=false;
          if ( onReleaseHandler ){
            onReleaseHandler(i,j);
          }
        }
        keyState->state = false;
      }
    }
    digitalWrite(_rows[i], HIGH);
  }
}