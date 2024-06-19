
#define trig_pin_sol 5
#define echo_pin_sol 4
#define trig_pin_sag 13
#define echo_pin_sag 12
#define trig_pin 3
#define echo_pin 2

const int sag_enable = 11;  // ENABLE A
const int sag_ileri = 10;   // INPUT 1
const int sag_geri = 9;     // INPUT 2                                                     
const int sol_ileri = 8;    // INPUT 3
const int sol_geri = 7;     // INPUT 4
const int sol_enable = 6;   // ENABLE B

long sure_sag, mesafe_sag, sure_sol, mesafe_sol, sure, mesafe;

void setup() {
  Serial.begin(9600);

  // pinMode(trig_pin_sag, OUTPUT);
  // pinMode(echo_pin_sag, INPUT);

  // pinMode(trig_pin_sol, OUTPUT);
  // pinMode(echo_pin_sol, INPUT);

  // pinMode(trig_pin, OUTPUT);
  // pinMode(echo_pin, INPUT);
  pinMode(sag_ileri, OUTPUT);
  pinMode(sag_geri, OUTPUT);
  pinMode(sol_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sag_enable, OUTPUT);
  pinMode(sol_enable, OUTPUT);

  delay(2000);
}

void loop() {


    if (Serial.available()) {
    char command = Serial.read();
    switch (command) {
    case 'F':
     ileri();
      break;
    case 'B':
      geri();
      break;
    case 'L':
    sol();
      break;
    case 'R':
      sag();
      break;
    case 'P':
      dur();
      break;
    default:
    dur();
      break;
  }

  }  /* bluetooth için */
}
  // int ldrValue = analogRead(ldrPin);

  // if (ldrValue > 500 && ldrFlag == 0) {
  //   dur();
  //   Serial.println("Karanlık, bekliyor...");
  //   delay(5000);
  //   ldrFlag = 1;
  // }

  // digitalWrite(trig_pin_sag, LOW);
  // delayMicroseconds(5);
  // digitalWrite(trig_pin_sag, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(trig_pin_sag, LOW);
  // sure_sag = pulseIn(echo_pin_sag, HIGH);
  // mesafe_sag = sure_sag * 0.034 / 2;
  // Serial.print("mesafe sag: ");
  // Serial.println(mesafe_sag);
  // delayMicroseconds(5);

  // digitalWrite(trig_pin_sol, LOW);
  // delayMicroseconds(5);
  // digitalWrite(trig_pin_sol, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(trig_pin_sol, LOW);
  // sure_sol = pulseIn(echo_pin_sol, HIGH);
  // mesafe_sol = sure_sol * 0.034 / 2;
  // Serial.print("mesafe sol: ");
  // Serial.println(mesafe_sol);                        
  // delayMicroseconds(5);


  //    digitalWrite(trig_pin, LOW);
  //  delayMicroseconds(5);
  //  digitalWrite(trig_pin, HIGH);
  //  delayMicroseconds(10);
  //  digitalWrite(trig_pin, LOW);
  //  sure = pulseIn(echo_pin, HIGH);
  //  mesafe = sure * 0.034 / 2;                          
  //  Serial.print("mesafe ön: ");
  //  Serial.println(mesafe);
  //  delayMicroseconds(5);
 

  // if (mesafe > 30) {
  //   ileri();

  // }else{
  //   if(mesafe <30 && mesafe_sag < 30 && mesafe_sol < 30){
  //     dur();
  //     delay(1000);
  //     return;
  //   }

  //   dur();
  //   delay(500);
  //   geri();
  //   delay(200);
  //   dur();
  //   delay(200);

  //   if(mesafe_sag > mesafe_sol){
  //     sag();
  //     delay(180);
  //   }else{
  //     sol();
  //     delay(180);
  //   }



//   }

//}
void ileri() {
  digitalWrite(sag_ileri, LOW);
  digitalWrite(sag_geri, HIGH);
  digitalWrite(sol_ileri, LOW);
  digitalWrite(sol_geri, HIGH);
  analogWrite(sag_enable, 200);  // motor hızları 255 PWM
  analogWrite(sol_enable, 200);
}
void geri() {
  digitalWrite(sag_ileri, HIGH);
  digitalWrite(sag_geri, LOW);
  digitalWrite(sol_ileri, HIGH);
  digitalWrite(sol_geri, LOW);
  analogWrite(sag_enable, 200);  // motor hızları 255 PWM
  analogWrite(sol_enable, 200);
}
void dur() {
  digitalWrite(sag_ileri, LOW);
  digitalWrite(sag_geri, LOW);
  digitalWrite(sol_ileri, LOW);
  digitalWrite(sol_geri, LOW);
}

void sag() {
  digitalWrite(sag_ileri, LOW);
  digitalWrite(sag_geri, HIGH);
  digitalWrite(sol_ileri, HIGH);
  digitalWrite(sol_geri, LOW);
  analogWrite(sag_enable, 200);  // motor hızları 255 PWM
  analogWrite(sol_enable, 200);
}

void sol() {
  digitalWrite(sag_ileri, HIGH);
  digitalWrite(sag_geri, LOW);
  digitalWrite(sol_ileri, LOW);
  digitalWrite(sol_geri, HIGH);
  analogWrite(sag_enable, 200);  // motor hızları 255 PWM
  analogWrite(sol_enable, 200);
}
