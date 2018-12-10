//#include <Tone.h>
#include <Wire.h>
#include <Servo.h> 


#define SLAVE_ADDRESS 0x04
#define MotorDX_F 1
#define MotorSX_F 2
#define MotorDX_R 3
#define MotorSX_R 4
#define DistanceBrakeOnOff 5
#define DistanceMeterOnOff 6
#define DistanceLOW 7
#define DistanceHIGH 8
#define DistanceMin 9
#define Interrupt2Raspberry 10
#define REEDContactEnabled 11
#define REEDStatus 12
#define ServoPos 13 

#define REGISTERS_LEN 20

#define CMD_READ 1
#define CMD_WRITE 2
#define CMD_READ_ALL 3
#define CMD_STOP 4
#define CMD_FORWARD 5
#define CMD_BACKWARD 6
#define CMD_ROTATE_LEFT 7
#define CMD_ROTATE_RIGHT 8
#define CMD_STEP_FORWARD 9
#define CMD_STEP_BACKWARD 10
#define CMD_STEP_LEFT 11
#define CMD_STEP_RIGHT 12
#define CMD_SET_SERVO 13
#define SERVO_PIN 4

#define BUZZER_PIN 12
#define OCTAVE_OFFSET 0
//Tone tone1;
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int servoPos = 0;    // variable to store the servo position 
/*
int notes[] = { 0,
NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4,
NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5,
NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6,
NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7
};
*/
//char *song = "The Simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";
//char *song = "Indiana:d=4,o=5,b=250:e,8p,8f,8g,8p,1c6,8p.,d,8p,8e,1f,p.,g,8p,8a,8b,8p,1f6,p,a,8p,8b,2c6,2d6,2e6,e,8p,8f,8g,8p,1c6,p,d6,8p,8e6,1f.6,g,8p,8g,e.6,8p,d6,8p,8g,e.6,8p,d6,8p,8g,f.6,8p,e6,8p,8d6,2c6";
//char *song = "TakeOnMe:d=4,o=4,b=160:8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5,8f#5,8e5,8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5";
//char *song = "Entertainer:d=4,o=5,b=140:8d,8d#,8e,c6,8e,c6,8e,2c.6,8c6,8d6,8d#6,8e6,8c6,8d6,e6,8b,d6,2c6,p,8d,8d#,8e,c6,8e,c6,8e,2c.6,8p,8a,8g,8f#,8a,8c6,e6,8d6,8c6,8a,2d6";
//char *song = "Muppets:d=4,o=5,b=250:c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,8a,8p,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,8e,8p,8e,g,2p,c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,a,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,d,8d,c";
//char *song = "Xfiles:d=4,o=5,b=125:e,b,a,b,d6,2b.,1p,e,b,a,b,e6,2b.,1p,g6,f#6,e6,d6,e6,2b.,1p,g6,f#6,e6,d6,f#6,2b.,1p,e,b,a,b,d6,2b.,1p,e,b,a,b,e6,2b.,1p,e6,2b.";
//char *song = "Looney:d=4,o=5,b=140:32p,c6,8f6,8e6,8d6,8c6,a.,8c6,8f6,8e6,8d6,8d#6,e.6,8e6,8e6,8c6,8d6,8c6,8e6,8c6,8d6,8a,8c6,8g,8a#,8a,8f";
//char *song = "20thCenFox:d=16,o=5,b=140:b,8p,b,b,2b,p,c6,32p,b,32p,c6,32p,b,32p,c6,32p,b,8p,b,b,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,g#,32p,a,32p,b,8p,b,b,2b,4p,8e,8g#,8b,1c#6,8f#,8a,8c#6,1e6,8a,8c#6,8e6,1e6,8b,8g#,8a,2b";
//char *song = "Bond:d=4,o=5,b=80:32p,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d#6,16d#6,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d6,16c#6,16c#7,c.7,16g#6,16f#6,g#.6";
//char *song = "MASH:d=8,o=5,b=140:4a,4g,f#,g,p,f#,p,g,p,f#,p,2e.,p,f#,e,4f#,e,f#,p,e,p,4d.,p,f#,4e,d,e,p,d,p,e,p,d,p,2c#.,p,d,c#,4d,c#,d,p,e,p,4f#,p,a,p,4b,a,b,p,a,p,b,p,2a.,4p,a,b,a,4b,a,b,p,2a.,a,4f#,a,b,p,d6,p,4e.6,d6,b,p,a,p,2b";
char *song = "StarWars:d=4,o=5,b=45:32p,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#.6,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#6";
//char *song = "GoodBad:d=4,o=5,b=56:32p,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,d#,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,c#6,32a#,32d#6,32a#,32d#6,8a#.,16f#.,32f.,32d#.,c#,32a#,32d#6,32a#,32d#6,8a#.,16g#.,d#";
//char *song = "TopGun:d=4,o=4,b=31:32p,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,16f,d#,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,g#";
//char *song = "A-Team:d=8,o=5,b=125:4d#6,a#,2d#6,16p,g#,4a#,4d#.,p,16g,16a#,d#6,a#,f6,2d#6,16p,c#.6,16c6,16a#,g#.,2a#";
//char *song = "Flinstones:d=4,o=5,b=40:32p,16f6,16a#,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,d6,16f6,16a#.,16a#6,32g6,16f6,16a#.,32f6,32f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,a#,16a6,16d.6,16a#6,32a6,32a6,32g6,32f#6,32a6,8g6,16g6,16c.6,32a6,32a6,32g6,32g6,32f6,32e6,32g6,8f6,16f6,16a#.,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#6,16c7,8a#.6";
//char *song = "Jeopardy:d=4,o=6,b=125:c,f,c,f5,c,f,2c,c,f,c,f,a.,8g,8f,8e,8d,8c#,c,f,c,f5,c,f,2c,f.,8d,c,a#5,a5,g5,f5,p,d#,g#,d#,g#5,d#,g#,2d#,d#,g#,d#,g#,c.7,8a#,8g#,8g,8f,8e,d#,g#,d#,g#5,d#,g#,2d#,g#.,8f,d#,c#,c,p,a#5,p,g#.5,d#,g#";
//char *song = "Gadget:d=16,o=5,b=50:32d#,32f,32f#,32g#,a#,f#,a,f,g#,f#,32d#,32f,32f#,32g#,a#,d#6,4d6,32d#,32f,32f#,32g#,a#,f#,a,f,g#,f#,8d#";
//char *song = "Smurfs:d=32,o=5,b=200:4c#6,16p,4f#6,p,16c#6,p,8d#6,p,8b,p,4g#,16p,4c#6,p,16a#,p,8f#,p,8a#,p,4g#,4p,g#,p,a#,p,b,p,c6,p,4c#6,16p,4f#6,p,16c#6,p,8d#6,p,8b,p,4g#,16p,4c#6,p,16a#,p,8b,p,8f,p,4f#";
//char *song = "MahnaMahna:d=16,o=6,b=125:c#,c.,b5,8a#.5,8f.,4g#,a#,g.,4d#,8p,c#,c.,b5,8a#.5,8f.,g#.,8a#.,4g,8p,c#,c.,b5,8a#.5,8f.,4g#,f,g.,8d#.,f,g.,8d#.,f,8g,8d#.,f,8g,d#,8c,a#5,8d#.,8d#.,4d#,8d#.";
//char *song = "LeisureSuit:d=16,o=6,b=56:f.5,f#.5,g.5,g#5,32a#5,f5,g#.5,a#.5,32f5,g#5,32a#5,g#5,8c#.,a#5,32c#,a5,a#.5,c#.,32a5,a#5,32c#,d#,8e,c#.,f.,f.,f.,f.,f,32e,d#,8d,a#.5,e,32f,e,32f,c#,d#.,c#";
//char *song = "MissionImp:d=16,o=6,b=95:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,a#5,8c,2p,32p,a#5,g5,2f#,32p,a#5,g5,2f,32p,a#5,g5,2e,d#,8d";

int addressToRead=0;
int lenToRead=1;
int registers[REGISTERS_LEN];

int state = 0;
//HC RS04 Sensore ultrasuoni
int triggerPort = 7;
int echoPort = 8;
int led =13;
volatile int stateInt = HIGH;


int sxForward   = 6;   
int sxBackward   = 5;   
int dxForward = 10;  
int dxBackward  = 9;

int DEBUG = 0; // DEBUG counter; if set to 1, will write values back via serial


void parseCommand(int cmd[],int len){
    if(DEBUG) {
      Serial.print("cmd len= ");
      Serial.println(len);
      Serial.print("cmd[0]= ");
      Serial.println(cmd[0]);
      Serial.print("cmd[1]= ");
      Serial.println(cmd[1]);
      Serial.print("cmd[2]= ");
      Serial.println(cmd[2]);

    }
  if (cmd[0]==CMD_WRITE){
    addressToRead=0;
    lenToRead=1;
    switch (cmd[1]){
      case MotorDX_F:
        registers[MotorDX_F]=cmd[2];
        analogWrite(dxForward,cmd[2]);
        registers[0]=0;
        break;
      case MotorSX_F:
        registers[MotorSX_F]=cmd[2];
        analogWrite(sxForward,cmd[2]);
        registers[0]=0;
        break;
      case MotorDX_R:
        registers[MotorDX_R]=cmd[2];
        analogWrite(dxBackward,cmd[2]);
        registers[0]=0;
        break;
      case MotorSX_R:
        registers[MotorSX_R]=cmd[2];
        analogWrite(sxBackward,cmd[2]);
        registers[0]=0;
        break;
      case DistanceBrakeOnOff:
        registers[DistanceBrakeOnOff]=cmd[2];
        registers[0]=0;
        break;
      case DistanceMeterOnOff:
        registers[DistanceMeterOnOff]=cmd[2];
        registers[0]=0;
        break;
      case DistanceMin:
        registers[DistanceMin]=cmd[2];
        registers[0]=0;
        break;
      case Interrupt2Raspberry:
        registers[Interrupt2Raspberry]=cmd[2];
        registers[0]=0;
        break;
      case REEDContactEnabled:
        registers[REEDContactEnabled]=cmd[2];
        registers[0]=0;
        break;
    }
  }
  if (cmd[0]==CMD_STOP){
    stopCar();
    addressToRead=0;
    lenToRead=1;
    registers[0]=0;
  }
  if (cmd[0]==CMD_FORWARD){
    moveForward(cmd[1]);
    addressToRead=0;
    lenToRead=1;
    registers[0]=0;
  }
  if (cmd[0]==CMD_BACKWARD){
    moveBackward(cmd[1]);
    addressToRead=0;
    lenToRead=1;
    registers[0]=0;
  }
  if (cmd[0]==CMD_ROTATE_LEFT){
    rotateLeft(cmd[1]);
    addressToRead=0;
    lenToRead=1;
    registers[0]=0;
  }
  if (cmd[0]==CMD_ROTATE_RIGHT){
    rotateRight(cmd[1]);
    addressToRead=0;
    lenToRead=1;
    registers[0]=0;
  }
  if (cmd[0]==CMD_STEP_FORWARD){
    stepForward(cmd[1],cmd[2]);
    addressToRead=0;
    lenToRead=1;
    registers[0]=0;
  }
  if (cmd[0]==CMD_STEP_BACKWARD){
    stepBackward(cmd[1],cmd[2]);
    addressToRead=0;
    lenToRead=1;
    registers[0]=0;
  }
  if (cmd[0]==CMD_STEP_LEFT){
    stepLeft(cmd[1],cmd[2]);
    addressToRead=0;
    lenToRead=1;
    registers[0]=0;
  }
  if (cmd[0]==CMD_STEP_RIGHT){
    stepRight(cmd[1],cmd[2]);
    addressToRead=0;
    lenToRead=1;
    registers[0]=0;
  }

  if (cmd[0]==CMD_READ){
    addressToRead=cmd[1];
    lenToRead=cmd[2];
    registers[0]=0;
  }
  if (cmd[0]==CMD_READ_ALL){
    addressToRead=0;
    lenToRead=REGISTERS_LEN;
    registers[0]=0;
  }
  if (cmd[0]==CMD_SET_SERVO){
    registers[ServoPos]=cmd[1];
    myservo.write(registers[ServoPos]);
  }
}

void initRegisters(){
  for (int i=0;i<REGISTERS_LEN;i++)
    registers[i]=0;
  registers[DistanceBrakeOnOff]=1;
  registers[DistanceMeterOnOff]=1;
  registers[DistanceMin]=15;
  registers[REEDContactEnabled]=1;
  registers[ServoPos]=90;
}
void setup() {
    initRegisters();
    myservo.attach(SERVO_PIN);
    myservo.write(registers[ServoPos]); 
    pinMode(2, INPUT);  
    pinMode(led, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(2), blink, CHANGE);
    pinMode(dxForward, OUTPUT);   
    pinMode(dxBackward, OUTPUT);   
    pinMode(sxForward, OUTPUT);   
    pinMode(sxBackward, OUTPUT);
    pinMode(triggerPort, OUTPUT);
    pinMode(echoPort, INPUT );
    if (DEBUG) {           // If we want to see the pin values for debugging...
      Serial.begin(9600);  // ...set up the serial ouput on 0004 style
    }         
    // initialize i2c as slave
    Wire.begin(SLAVE_ADDRESS);

    // define callbacks for i2c communication
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);

    if(DEBUG) {
      Serial.println("Ready!");

    }
    //tone1.begin(BUZZER_PIN);
    //play_rtttl(song);

}
void loop() {
    delay(250);

    if(registers[REEDContactEnabled])
      registers[REEDStatus]=stateInt;
    if (registers[DistanceMeterOnOff])
      calc_distance();
    
}
void blink(){
  stateInt = digitalRead(2);
  
}

// callback for received data
  void receiveData(int byteCount){
    int cmd[byteCount];
    int i=0;
    int n;

    while(Wire.available()) {
        n = Wire.read();
        cmd[i]=n;
        i++;
     }
     if(byteCount)
       parseCommand(cmd,byteCount);
  }


// callback for sending data
void sendData(){
  Serial.print("addressToRead: ");
  Serial.println(addressToRead);
  Serial.print("lenToRead: ");
  Serial.println(lenToRead);
  for (int i=0;i<lenToRead;i++)
    Wire.write(registers[i]);
}

//calculate distance
void calc_distance(){
  //porta bassa l'uscita del trigger
  digitalWrite( triggerPort, LOW );
 
  //invia un impulso di 10microsec su trigger
  digitalWrite( triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( triggerPort, LOW );
 
  long duration = pulseIn( echoPort, HIGH );
 
  long r = 0.034 * duration / 2;
  if(registers[DistanceBrakeOnOff]) {
    if(r<registers[DistanceMin]){
      if(DEBUG) { 
        Serial.print( "Brack, Distance <: " );
        Serial.println(r);
      }
      stepBackward(200,0.3);
    }
  }
  if(DEBUG) { 
    Serial.print( "durata: " );
    Serial.print( duration );
    Serial.print( " , " );
    Serial.print( "distanza: " );
    //dopo 38ms è fuori dalla portata del sensore
    if( duration > 38000 ) Serial.println( "fuori portata");
    else { Serial.print( r ); Serial.println( "cm" );}
  }
}
void stopCar(){
  analogWrite(dxForward,0);
  analogWrite(sxForward,0);
  analogWrite(dxBackward,0);
  analogWrite(sxBackward,0);
}
void moveForward(int spd){
  stopCar();
  analogWrite(dxForward,spd);
  analogWrite(sxForward,spd);
}
void moveBackward(int spd){
  stopCar();
  analogWrite(dxBackward,spd);
  analogWrite(sxBackward,spd);
}
void rotateLeft(int spd){
  stopCar();
  analogWrite(sxBackward,spd);
  analogWrite(dxForward,spd);
}
void rotateRight(int spd){
  stopCar();
  analogWrite(dxBackward,spd);
  analogWrite(sxForward,spd);
}
void stepForward(int spd,int dly){
  stopCar();
  analogWrite(dxForward,spd);
  analogWrite(sxForward,spd);
  delay(dly*1000);
  stopCar();
}
void stepBackward(int spd,int dly){
  stopCar();
  analogWrite(dxBackward,spd);
  analogWrite(sxBackward,spd);
  delay(dly*1000);
  stopCar();
}
void stepLeft(int spd,int dly){
  stopCar();
  analogWrite(sxBackward,spd);
  analogWrite(dxForward,spd);
  delay(dly*1000);
  stopCar();
}
void stepRight(int spd,int dly){
  stopCar();
  analogWrite(dxBackward,spd);
  analogWrite(sxForward,spd);
  delay(dly*1000);
  stopCar();
}
void play_rtttl(char *p)
{
  // Absolutely no error checking in here

  byte default_dur = 4;
  byte default_oct = 6;
  int bpm = 63;
  int num;
  long wholenote;
  long duration;
  byte note;
  byte scale;

  // format: d=N,o=N,b=NNN:
  // find the start (skip name, etc)

  while(*p != ':') p++;    // ignore name
  p++;                     // skip ':'

  // get default duration
  if(*p == 'd')
  {
    p++; p++;              // skip "d="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    if(num > 0) default_dur = num;
    p++;                   // skip comma
  }

  Serial.print("ddur: "); Serial.println(default_dur, 10);

  // get default octave
  if(*p == 'o')
  {
    p++; p++;              // skip "o="
    num = *p++ - '0';
    if(num >= 3 && num <=7) default_oct = num;
    p++;                   // skip comma
  }

  Serial.print("doct: "); Serial.println(default_oct, 10);

  // get BPM
  if(*p == 'b')
  {
    p++; p++;              // skip "b="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    bpm = num;
    p++;                   // skip colon
  }

  Serial.print("bpm: "); Serial.println(bpm, 10);

  // BPM usually expresses the number of quarter notes per minute
  wholenote = (60 * 1000L / bpm) * 4;  // this is the time for whole note (in milliseconds)

  Serial.print("wn: "); Serial.println(wholenote, 10);


  // now begin note loop
  while(*p)
  {
    // first, get note duration, if available
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    
    if(num) duration = wholenote / num;
    else duration = wholenote / default_dur;  // we will need to check if we are a dotted note after

    // now get the note
    note = 0;

    switch(*p)
    {
      case 'c':
        note = 1;
        break;
      case 'd':
        note = 3;
        break;
      case 'e':
        note = 5;
        break;
      case 'f':
        note = 6;
        break;
      case 'g':
        note = 8;
        break;
      case 'a':
        note = 10;
        break;
      case 'b':
        note = 12;
        break;
      case 'p':
      default:
        note = 0;
    }
    p++;

    // now, get optional '#' sharp
    if(*p == '#')
    {
      note++;
      p++;
    }

    // now, get optional '.' dotted note
    if(*p == '.')
    {
      duration += duration/2;
      p++;
    }
  
    // now, get scale
    if(isdigit(*p))
    {
      scale = *p - '0';
      p++;
    }
    else
    {
      scale = default_oct;
    }

    scale += OCTAVE_OFFSET;

    if(*p == ',')
      p++;       // skip comma for next note (or we may be at the end)

    // now play the note
/* da scommentare
    if(note)
    {
      Serial.print("Playing: ");
      Serial.print(scale, 10); Serial.print(' ');
      Serial.print(note, 10); Serial.print(" (");
      Serial.print(notes[(scale - 4) * 12 + note], 10);
      Serial.print(") ");
      Serial.println(duration, 10);
      tone1.play(notes[(scale - 4) * 12 + note]);
      delay(duration);
      tone1.stop();
    }
    else
    {
      Serial.print("Pausing: ");
      Serial.println(duration, 10);
      delay(duration);
    }
    */
  }
}

