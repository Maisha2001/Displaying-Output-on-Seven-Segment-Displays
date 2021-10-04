//Declaring and initializing variables
int ptm = A0; //for potentiometer
int result,input,digit_one,digit_two;
static byte decoder_blank = 8;
static byte decoder_test = 9;

static byte decoder_pins[2][4] = { //Defining the pins for CD4511 decoder
  {0, 1, 2, 3},{4, 5, 6, 7}
};


void setup() {
  for (byte i=0; i<=9; i++) { //Set modes for decoder pin
    pinMode(i, OUTPUT); 
  }
  
  pinMode(ptm,INPUT); //Set modes for potentiometer pin
  
  //Turn off decoder_blank and decoder_test
  digitalWrite(decoder_blank, HIGH);
  digitalWrite(decoder_test, HIGH);
  
  writeDigit(0, 0); 
  writeDigit(1, 0); 
}


void loop() {
    input= analogRead(ptm);
    result = map(input,0,1023,0,99);

    digit_one = result % 10; 
    writeDigit(0,byte(digit_one));
    digit_two = result / 10;          
    writeDigit(1,byte(digit_two));
    delay(100);
}


void writeDigit(byte chip_num, byte num_value) {
  byte pins[] = {
    decoder_pins[chip_num][0], 
    decoder_pins[chip_num][1], 
    decoder_pins[chip_num][2], 
    decoder_pins[chip_num][3]
  };
  
  for (byte n=0; n<=3; n++) { 
    digitalWrite(pins[n], LOW); 
  }
  
  if (num_value == 0) { 
    //Data is already set to 0
  }
  if (num_value == 1) { 
    digitalWrite(pins[0], HIGH); 
  }
  if (num_value == 2) { 
    digitalWrite(pins[1], HIGH); 
  }
  if (num_value == 3) { 
    digitalWrite(pins[1], HIGH); 
    digitalWrite(pins[0], HIGH); 
  }
  if (num_value == 4) { 
    digitalWrite(pins[2], HIGH); 
  }
  if (num_value == 5) { 
    digitalWrite(pins[2], HIGH); 
    digitalWrite(pins[0], HIGH); 
  }
  if (num_value == 6) { 
    digitalWrite(pins[2], HIGH); 
    digitalWrite(pins[1], HIGH); 
  }
  if (num_value == 7) { 
    digitalWrite(pins[2], HIGH); 
    digitalWrite(pins[1], HIGH); 
    digitalWrite(pins[0], HIGH); 
  }
  if (num_value == 8) { 
    digitalWrite(pins[3], HIGH); 
  }
  if (num_value == 9) { 
    digitalWrite(pins[3], HIGH); 
    digitalWrite(pins[0], HIGH); 
  }
}
