/*
 예제 4.7
 8x8 Dot matrix 를 이용한 움직이는 화살표
*/

byte arrow1[] = {  // 첫 번째 화살표
  B00000000,
  B00000000,
  B00011000,
  B00100100,
  B01011010,
  B10100101,
  B01000010,
  B10000001};

byte arrow2[] = {  // 두 번째 화살표
  B00000000,
  B00011000,
  B00100100,
  B01011010,
  B10100101,
  B01000010,
  B10000001,
  B00000000};
  
byte arrow3[] = {  // 세 번째 화살표
  B00011000,
  B00100100,
  B01011010,
  B10100101,
  B01000010,
  B10000001,
  B00000000,
  B00000000};

// 행에 연결된 핀
const int columnPins[] = {  2, 3, 4, 5, 6, 7, 8, 9};
// 열에 연결된 핀
const int rowPins[]    = { 10,11,12,15,16,17,18,19};

void setup() {
  for (int i = 0; i < 8; i++)
  {
    // 행 핀을 출력으로 설정
    pinMode(columnPins[i], OUTPUT);
    // 열 핀을 출력으로 설정
    pinMode(rowPins[i], OUTPUT);
    // 행 핀에 모두 HIGH를 넣어 모든 LED 를 소등한다
    digitalWrite(columnPins[i], HIGH);
  }
}

void loop() {

  output(arrow1,80);  // 첫 번째 화살표 출력
  output(arrow2,80);  // 두 번째 화살표 출력
  output(arrow3,80);  // 세 번째 화살표 출력

  delay(300);         // 0.3초간 지연시킨다.

}

// 실제 Dot matrix를 출력하는 루틴
// image엔 화살표 이미지 데이터가 입력되고 time엔 표시 시간이 입력됨
void output( byte * image, unsigned long time)
{
  // 아두이노의 시작부터 현재 명령까지 
  //지난 시간이 1/1000 초 단위의 값이 start 변수에 입력된다. 
  unsigned long start = millis();  
 
  // time 변수값(tiem * 1/1000 초) 만큼 while문 내의 명령을 실행한다. 
  while (start + time > millis())
  {
    for(int row = 0; row < 8; row++)
    {
      // 해당하는 열에 LED를 출력하기 위해 HIGH를 넣는다      
      digitalWrite(rowPins[row], HIGH); 
      
      for(int column = 0; column < 8; column++)
      {
        // image 변수를 한자리(한 비트)씩 확인하여 1일 경우 LED를 점등한다.
        boolean pixel = bitRead(image[row],column);

        // 행에 LOW를 입력하여 해당 LED를 점등한다.
        if(pixel == 1)  digitalWrite(columnPins[column], LOW);

        // 300 마이크로 초 만큼 지연시킨다. LED를 300 마이크로 초 만큼 켜고 있는다.
        delayMicroseconds(300);
        // 점등시킨 LED를 소등한다
        digitalWrite(columnPins[column], HIGH);
      }
      // 현재의 열에 LOW 신호를 출력하여 해당 열의 LED를 모두 소등한다
      digitalWrite(rowPins[row], LOW);
    }
  }
}
      
    
