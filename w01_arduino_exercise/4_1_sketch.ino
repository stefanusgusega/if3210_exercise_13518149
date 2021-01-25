#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
const int kPinSpeaker = 9;
const int kNotes = 7;
const int notes[kNotes] = {NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4
  , NOTE_F4, NOTE_E4,0};
const int beats[kNotes] = {1,1,2,2,2,4,4};
const int beat_length = 10;

void setup()
{
 pinMode(kPinSpeaker, OUTPUT);
}

void loop()
{
  for (int i = 0; i < kNotes; i++) {
    if (notes[i] == 0) {
    	delay(beats[i] * beat_length);
    }
    else {
    	ourTone(notes[i], beats[i]*beat_length);
    }
  }
}

void ourTone(int freq, int duration) {
	tone(kPinSpeaker, freq, duration);
  	delay(duration);
}