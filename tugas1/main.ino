int loops=0;
int sec=0;

void setup() {
  // put your setup code here, to run once:
  // Reset TCCR1
  TCCR1A = 0;
  TCCR1B = 0;

  TCCR1B &= ~(1 << WGM13);
  TCCR1B |= (1 << WGM12);

  // Set Prescale to 8
  TCCR1B |= (1 << CS11); 

  // Set the Top Point
  TCNT1 = 0;
  OCR1A = 39999;

  TIMSK1 = (1 << OCIE1A);
  sei();
  Serial.begin(115200);
}

void loop() {

}

ISR(TIMER1_COMPA_vect){
  if(++loops==50){
    Serial.print("Detik ke-");
    Serial.println(++sec);
    loops=0;
  }
}