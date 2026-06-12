/*
 예제 5.2.1
 스위치 입력마다 LED On/Off 바꾸기
 스위치 접점 횟수를 시리얼 통신으로 전송하기
 */

// 내장된 LED 사용을 위해 13번핀을 출력으로 설정
const int ledPin = 13;   
// 2번핀을 스위치 입력으로 설정
const int inputPin = 2;

// 스위치 입력 횟수 저장 변수
int count = 0;

void setup() {
  // 13번 핀에 내장된 LED를 출력으로 설정한다
  pinMode(ledPin, OUTPUT);
  // 스위치 입력을 위하여 2번핀을 입력으로 설정하고 풀업시킨다
  pinMode(inputPin, INPUT_PULLUP);
  // 시리얼 통신을 설정한다
  Serial.begin(9600);
}

void loop(){
  // 스위치 입력을 받는다
  int swInput = digitalRead(inputPin);
  // LED의 출력 상태를 확인한다
  int ledOutput = digitalRead(ledPin);
  
  // 스위치가 눌렸을 때
  if (swInput == LOW){
    if (ledOutput)  digitalWrite(ledPin, LOW);// LED가 점등되어 있으면 소등
    else   digitalWrite(ledPin, HIGH);// LED가 소등되어 있으면 점등
    ++count;
    // 스위치 입력 횟수를 시리얼 통신으로 전송한다.
    Serial.println(count);
  };
}

