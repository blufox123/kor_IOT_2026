/*
 예제 9.2
 온습도 센서를 이용한 온습도 측정
*/

// DHT 라이브러리를 추가한다
#include <dht.h>

// DHT11 이란 이름으로 센서 이름을 설정한다
dht DHT11;

// DHT11이 연결된 핀을 설정한다
int DHT11Pin = 2;

void setup()
{
  // 시리얼 통신을 설정하고 초기 메세지를 출력한다
  Serial.begin(9600);
  Serial.println("EX 9.2 DHT11 Test ");
  Serial.println("");
}

void loop()
{
  // check라는 변수에 DHT11의 상태를 읽어 저장한다
  int check = DHT11.read11(DHT11Pin);
  // DHT11의 상태에 따라 온습도 데이터를 출력하던지 에러메세지를 출력한다
  switch (check)
  {
    case DHTLIB_OK:  // 정상적으로 데이터가 전송되었을 때 습도와 온도를 출력한다.
      Serial.print("Temperture is ");
      Serial.print(DHT11.temperature ,0);
      Serial.print("oC");
      Serial.print("\t");
      Serial.print("Humisity is ");
      Serial.print(DHT11.humidity ,0);
      Serial.println("%");
      break;
    case DHTLIB_ERROR_CHECKSUM: 
      Serial.println("Checksum error"); 
      break;
    case DHTLIB_ERROR_TIMEOUT: 
      Serial.println("Time out error"); 
      break;
    case DHTLIB_ERROR_CONNECT:
      Serial.println("Connect error");
      break;
    case DHTLIB_ERROR_ACK_L:
      Serial.println("Ack Low error");
      break;
    case DHTLIB_ERROR_ACK_H:
      Serial.println("Ack High error");
      break;
    default: 
      Serial.println("Unknown error"); 
      break;
  }
  // 온습도를 다시 측정하기 위해 2초 쉰다
  delay(2000);
}

