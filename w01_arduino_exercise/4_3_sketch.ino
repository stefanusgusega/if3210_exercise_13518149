#define NOTE_C7 2093
#define NOTE_D7 2349
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_Gb7 2957
#define NOTE_G7 3136
#define NOTE_A7 3520
#define NUM_NOTES 10

const int kPinSpeaker = 9;
const int kPinBtn1 = 2;
const int kPinBtn2 = 3;
const int tune1[NUM_NOTES] = {NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7,
                              NOTE_G7, NOTE_F7, NOTE_E7, NOTE_D7,
                              NOTE_C7,0};

const int tune2[NUM_NOTES] = {NOTE_D7, NOTE_E7, NOTE_Gb7, NOTE_G7,
                              NOTE_A7, NOTE_G7, NOTE_Gb7, NOTE_E7,
                              NOTE_D7,0};

const int beats[NUM_NOTES] = {1, 1, 2, 1,
                              1, 1, 2, 1,
                              4,0};
const int tempo = 100; // in ms
long lastTime = 0;

void setup()
{
 pinMode(kPinSpeaker, OUTPUT);
  pinMode(kPinBtn1, INPUT);
  pinMode(kPinBtn2, INPUT);
  digitalWrite(kPinBtn1, HIGH);
  digitalWrite(kPinBtn2, HIGH);
}

void loop()
{
  if (digitalRead(kPinBtn1) == LOW) {
  	playTune(1);
  }
  if (digitalRead(kPinBtn2) == LOW) {
  	playTune(2);
  }
}

void playTune(int number) {
  if (number == 1) {
    for (int i = 0; i < NUM_NOTES; i++) {
      if (tune1[i] == 0) {
      	delay(tempo*beats[i]);
      }
      else {
    	ourTone(tune1[i], tempo*beats[i]);
      }
      noTone(kPinSpeaker);
      delay(20);
    }
  }
  else if (number == 2) {
  	for (int i = 0; i < NUM_NOTES; i++) {
      if (tune2[i] == 0) {
      	delay(tempo*beats[i]);
      }
      else {
    	ourTone(tune2[i], tempo*beats[i]);
      }
      noTone(kPinSpeaker);
      delay(20);
    }
  }
}

void ourTone(int freq, int dur) {
  long timeDelay = 1000000/(2*freq);
  
  if (millis() < (lastTime + dur)) {
  	digitalWrite(kPinSpeaker, HIGH);
  	delayMicroseconds(timeDelay);
    digitalWrite(kPinSpeaker, LOW);
    delayMicroseconds(timeDelay);
  }
  lastTime = millis();
}