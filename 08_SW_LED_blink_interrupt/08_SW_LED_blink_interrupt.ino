// 10번, 12번 핀 세트
const int inputPin1 = 10;
const int outputPin1 = 12;
volatile boolean led_flag1 = LOW;

// 11번, 13번 핀 세트
const int inputPin2 = 11;
const int outputPin2 = 13;
volatile boolean led_flag2 = LOW;

boolean val1 = LOW;
boolean val2 = LOW;

void sw1_Pressed(void){
  led_flag1 = !led_flag1;
}

void sw2_Pressed(void){
  led_flag2 = !led_flag2;
}

void setup() {
  Serial.begin(115200);

  // 1번 세트 설정
  pinMode(inputPin1, INPUT);
  pinMode(outputPin1, OUTPUT);
  digitalWrite(outputPin1, led_flag1);

  // 2번 세트 설정
  pinMode(inputPin2, INPUT);
  pinMode(outputPin2, OUTPUT);
  digitalWrite(outputPin2, led_flag2);

  // 인터럽트 설정
  attachInterrupt(digitalPinToInterrupt(inputPin1), sw1_Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(inputPin2), sw2_Pressed, FALLING);
}

void loop() {
  // 1번 세트 로직
  // 상태값에 따른 동작 구현
  if(led_flag1 == HIGH){
    val1 = !val1;
    digitalWrite(outputPin1, val1);
    delay(300);
  }
  else{
    val1 = LOW;
    digitalWrite(outputPin1, val1);
  }

  // 2번 세트 로직
  // 상태값에 따른 동작 구현
  if(led_flag2 == HIGH){
    val2 = !val2;
    digitalWrite(outputPin2, val2);
    delay(500);
  }
  else{
    val2 = LOW;
    digitalWrite(outputPin2, val2);
  }
}







