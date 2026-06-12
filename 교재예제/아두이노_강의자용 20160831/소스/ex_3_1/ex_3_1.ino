/*
 예제 3.1
 입출력핀을 이용하여 LCD모듈에 표시하기
*/

// LCD 모듈 라리브러리를 불러온다
#include <LiquidCrystal.h>

// time 변수 설정
unsigned int time;
// LCD 설정
// LiquidCrytral(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // 16X2 LCD 설정
  lcd.begin(16, 2);
  // 첫째 줄에 Arduino 표시
  lcd.print("Arduino");
}

void loop() {
  // 두 번째 줄 첫번째 칸으로 커서 이동	
  lcd.setCursor(0,1);
  // time 변수값 출력
  lcd.print(time);
  // time 변수값 증가
  ++time;
  // 100ms 동안 지연
  delay(100);
}
