

#include "Config.h"
#include <RotaryEncoder.h>
#include "Mouse.h"
#include "Matrix.h"



bool switching = false;
Matrix matrix(ROWS, COLS, (int*)rowPins, (int*)colPins);
Matrix toggle(TROWS, TCOLS, (int*)rowTogglePins, (int*)colTogglePins);
RotaryEncoder rotaryEncoder(rotaryPins[0], rotaryPins[1]);

int toggleMap(bool x, bool y, bool z){
  return ( (int)x << 2 ) | ( (int)y << 1 ) | ( (int)z );
}

char keyToChar(bool x, bool y, bool z, int r, int c){
  int pos = toggleMap(x, y, z);
  int index = ( pos * ROWS * COLS ) + ( r * ROWS ) + c;

  return ((char*)MAT)[ index ];
}


void onPressHandler(int r, int c) {
  int x = toggle.getKeyState(1, 1)->state;
  int y = toggle.getKeyState(1, 0)->state;
  char key = keyToChar(switching, x, y, r, c);
  switch (key & 0xFF) {
    case LCLK: 
      Mouse.press(MOUSE_LEFT);
      break;
    case RCLK:
      Mouse.press(MOUSE_RIGHT);
      break;
    case MCLK:
      Mouse.press(MOUSE_MIDDLE);
      break;
    case UWHL:
      Mouse.move(0, 0,  WHEEL_SPEED);
      break;
    case DWHL:
      Mouse.move(0, 0, -WHEEL_SPEED);
      break;
    default:
      Keyboard.press(key);
  }
}

void onDuringHandler(int r, int c) {
  int x = toggle.getKeyState(1, 1)->state;
  int y = toggle.getKeyState(1, 0)->state;
  char key = keyToChar(switching, x, y, r, c);
  switch (key & 0xFF) {
    case UWHL:
      Mouse.move(0, 0,  WHEEL_SPEED);
      break;
    case DWHL:
      Mouse.move(0, 0, -WHEEL_SPEED);
      break;
  }
}

void onReleaseHandler(int r, int c) {
  /***
   * トグルする→キーを押し込み→トグル解除→キーを開放　とすると、
   * キー入力とキー開放が別なキーになってしまうため、
   * キーリリースをしたら同一キーに割り振っているキーは全て開放処理する
   * */
  for (int i=0; i < pow( 2, TOGGLES ); i++){
    char key = keyToChar((bool)(i&B100), (bool)(i&B010), (bool)(i&B001), r, c);
    switch (key & 0xFF) {
      case LCLK: 
        Mouse.release(MOUSE_LEFT);
        break;
      case RCLK:
        Mouse.release(MOUSE_RIGHT);
        break;
      case MCLK:
        Mouse.release(MOUSE_MIDDLE);
        break;
      default:
        Keyboard.release(key);
    }
  }
}

void onReleaseToggle(int r, int c) {
  if(r == 0 && c == 0) { // 切り替えキーの場合、スイッチングする
    switching = !switching;
    digitalWrite(LED_PIN, switching ? HIGH : LOW); // LEDも切り替え
  }
}

void updateEncoder(){
  int rotaryDir = (int)(rotaryEncoder.getDirection());
  if (rotaryDir == 0) return;

  int x = toggle.getKeyState(1, 1)->state;
  int y = toggle.getKeyState(1, 0)->state;
  int index = toggleMap(switching, x, y) * 2;
  char key = (rotaryDir < 0) ? ((char*)ROT)[index] : ((char*)ROT)[index+1];
  switch (key & 0xFF) {
    case LCLK: 
      Mouse.click(MOUSE_LEFT);
      break;
    case RCLK:
      Mouse.click(MOUSE_RIGHT);
      break;
    case MCLK:
      Mouse.click(MOUSE_MIDDLE);
      break;
    case UWHL:
      Mouse.move(0, 0,  WHEEL_SPEED);
      break;
    case DWHL:
      Mouse.move(0, 0, -WHEEL_SPEED);
      break;
    default:
      Keyboard.write(key);
  }
}

void setup() {
  delay(5000);
  
  Serial.begin(9600);
  
  matrix.onPressHandler = &onPressHandler;
  matrix.onDuringHandler = &onDuringHandler;
  matrix.onReleaseHandler = &onReleaseHandler;
  
  toggle.onReleaseHandler = &onReleaseToggle;

  pinMode(LED_PIN, OUTPUT);   // LED用に出力に設定
  
  Keyboard.begin();
  Mouse.begin();
}


void loop() {
  
  //各入力を更新
  toggle.tick();
  matrix.tick();
  rotaryEncoder.tick();

  //エンコーダー更新
  updateEncoder();
}
