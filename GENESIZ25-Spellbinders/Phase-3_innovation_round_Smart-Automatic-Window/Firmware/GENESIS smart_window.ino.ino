#define TRIG_PIN 5
#define ECHO_PIN 18

#define RED_LED    25
#define GREEN_LED  26
#define WHITE_LED  27

#define BUZZER_PIN 14   
long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Ultrasonic trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Reset outputs
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  if (distance > 0 && distance < 15) {
    digitalWrite(RED_LED, HIGH);

    // FAST BEEP
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
  }
  else if (distance >= 15 && distance <= 40) {
    digitalWrite(WHITE_LED, HIGH);

    // SLOW BEEP
    digitalWrite(BUZZER_PIN, HIGH);
    delay(300);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  }
  else if (distance > 40) {
    digitalWrite(GREEN_LED, HIGH);
    delay(200);
  }
}
