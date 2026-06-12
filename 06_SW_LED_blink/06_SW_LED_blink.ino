// 10번, 12번 핀 세트
const int inputPin1 = 10;
const int outputPin1 = 12;
boolean led_flag1 = LOW;
boolean pre_val1 = HIGH, cur_val1 = HIGH;

// 11번, 13번 핀 세트
const int inputPin2 = 11;
const int outputPin2 = 13;
boolean led_flag2 = LOW;
boolean pre_val2 = HIGH, cur_val2 = HIGH;

boolean val1 = LOW;
boolean val2 = LOW;

void setup() {
  // 1번 세트 설정
  pinMode(inputPin1, INPUT_PULLUP);
  pinMode(outputPin1, OUTPUT);
  digitalWrite(outputPin1, led_flag1);

  // 2번 세트 설정
  pinMode(inputPin2, INPUT_PULLUP);
  pinMode(outputPin2, OUTPUT);
  digitalWrite(outputPin2, led_flag2);
}

void loop() {
  // 1번 세트 로직
  cur_val1 = digitalRead(inputPin1);

  if ((pre_val1 == HIGH) && (cur_val1 == LOW)) {
    led_flag1 = !led_flag1;   // 상태값 변경
  }

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

  pre_val1 = cur_val1;

  // 2번 세트 로직
  cur_val2 = digitalRead(inputPin2);

  if ((pre_val2 == HIGH) && (cur_val2 == LOW)) {
    led_flag2 = !led_flag2;   // 상태값 변경
  }

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

  pre_val2 = cur_val2;
}







