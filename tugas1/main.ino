int dec(int binary_val)
{
  int  num, decimal_val = 0, base = 1, rem;

  binary_val = num;
  while (num > 0)
  {
      rem = num % 10;
      decimal_val = decimal_val + rem * base;
      num = num / 10 ;
      base = base * 2;
  }
  return decimal_val;
}

void fun1(uint16_t angle){
  Serial.print(angle);
  Serial.print(" ");
  OCR1A = (angle*11.11)+2000;
  Serial.println(OCR1A);
  // Serial.println(dec(OCR1A));
}

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);

  // Reset TCCR1
  TCCR1A = 0;
  TCCR1B = 0;

  // Set mode 14 (fast PWM)
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << WGM13);

  // Set Prescale to 8
  TCCR1B |= (1 << CS11); 

  // Set the Top Point
  ICR1 = 39999;

  // Set to non-inverting mode
  TCCR1A |= (1 << COM1A1);

  // Set pin for output
  DDRB |= (1 << PB1);

  Serial.begin(115200);
}

void loop() {
  int readd = analogRead(A0);
  uint16_t ang = (readd/1023.0)*180.0;
  fun1(ang);
}

ISR(TIMER1_COMPA_vect){

}