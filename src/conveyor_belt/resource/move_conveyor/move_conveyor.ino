#define RECV_MAX_COUNT  10000

#define PIN_ENA   8
#define PIN_DIR   9
#define PIN_PUL   10


typedef enum _CONVEYOR_STATE {Conveyor_Ready, Conveyor_Run} CONVEYOR_STATE;

unsigned long recv_cnt = 0;

unsigned long time_p = 0;
unsigned long time_serial_p = 0;

unsigned long step_count  = 0;
CONVEYOR_STATE state = Conveyor_Ready;

void setup() {
  Serial.begin(115200);
  Serial.println('s');

  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_DIR, OUTPUT);
  pinMode(PIN_PUL, OUTPUT);

  digitalWrite(PIN_ENA, LOW);
  digitalWrite(PIN_DIR, LOW);
}

void step_run(unsigned long time_c) {
  if((time_c - time_p) > 2) {
    if(state == Conveyor_Run) {

      digitalWrite(PIN_PUL, HIGH);
      delayMicroseconds(1000);
      digitalWrite(PIN_PUL, LOW);
      delayMicroseconds(1000);

      step_count--;
      if(step_count <= 0)
        state = Conveyor_Ready;

      if((time_c - time_serial_p) > 50) {
        Serial.println('_');
        
        time_serial_p = time_c;
      }
      time_p = time_c;
    } else {
      if((time_c - time_serial_p) > 50) {
        Serial.println('.');
        time_serial_p = time_c;
      }
      // Serial.write('.');
      time_p = time_c;
    }
  }
}

void loop() {
  unsigned long time_c = millis();

  if(Serial.available() > 0) {
    String receivedData = Serial.readStringUntil('\n');  // 줄바꿈 기준으로 데이터 읽기
    Serial.print("Received: ");
    Serial.println(receivedData);

    // 수신된 데이터를 숫자로 변환하여 step_count에 설정
    int command = receivedData.toInt();
    if (command > 0) {
      step_count = command;
      state = Conveyor_Run;  // 명령을 받으면 벨트를 실행
    }
  }

  step_run(time_c);
}