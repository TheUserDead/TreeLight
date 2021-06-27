/*
This is FX program to animate light tree DIY lamp
*/

byte buttPin = 12;
int pinMassive[10] = {0,2,3,4,5,6,7,8,9,10}; // 0 - massive is switch state for poweroff mode
byte randomNum = 0;
boolean returne = 0;
int eithFXtimer = 100;
boolean eithFXflag = 1; //0 decrease | 1 increase
byte delaycounter = 0;

void setup(){
	randomSeed(analogRead(A0));
	for(int i=1; i<10; i++){
	    pinMode(pinMassive[i], OUTPUT);
	}
	pinMode(buttPin, INPUT);
	Serial.begin(115200);
}

void loop(){
	returne = 0;
	delaycounter = 0;
	randomNum = random(0, 12);

	if (pinMassive[0] > 9) pinMassive[0] = 0;

	poolButton();

	switch (pinMassive[0]) {
    	case 0:
      	  resetall();
      	  break;
    	case 1:
      	  digitalWrite(randomNum, 1);
      	  specialDelay(30);
    	  if(returne != 0) break;
      	  digitalWrite(randomNum, 0);
      	  break;
    	case 2:
    	  digitalWrite(randomNum, 1);
    	  specialDelay(random(10, 150));
    	  if(returne != 0) break;
    	  digitalWrite(randomNum, 0);
    	  break;
    	case 3:
    	  digitalWrite(randomNum, 1);
    	  specialDelay(50);
    	  if(returne != 0) break;
    	  randomNum = random(0, 12);
    	  digitalWrite(randomNum, 0);
    	  break;
    	case 4:
    	  digitalWrite(randomNum, 1);
    	  delay(random(10,150));
    	  randomNum = random(0, 12);
    	  digitalWrite(randomNum, 0);
    	  break;
    	case 5:
    	  digitalWrite(random(0, 12), 1);
    	  digitalWrite(random(0, 12), 1);
    	  digitalWrite(random(0, 12), 1);
    	  specialDelay(500);
    	  if(returne != 0) break;
    	  digitalWrite(random(0, 12), 0);
    	  digitalWrite(random(0, 12), 0);
    	  digitalWrite(random(0, 12), 0);
    	  break;
    	case 6:
    	  for(int i=1; i<10; i++){
    	      digitalWrite(pinMassive[i], 1);
    	      specialDelay(1000);
    	      if(returne != 0) break;
    	  }
    	  specialDelay(1000);
    	  if(returne != 0) break;
    	  for(int i=1; i<10; i++){
    	      digitalWrite(pinMassive[i], 0);
    	      specialDelay(1000);
    	      if(returne != 0) break;
    	  }
    	  break;
    	case 7:
    	  for(int i=1; i<10; i++){
    	      digitalWrite(random(0, 12), 1);
    	      delayMicroseconds(random(100, 700));
    	      digitalWrite(random(0, 12), 0);
    	  }
    	  break;
    	case 8:
    	  if(eithFXflag == 1 && eithFXtimer <= 5000)eithFXtimer = eithFXtimer + 1;
    	  if(eithFXflag == 1 && eithFXtimer >= 5000)eithFXtimer = eithFXtimer + 200;
    	  if(eithFXflag == 0 && eithFXtimer >= 5000)eithFXtimer = eithFXtimer - 200;
    	  if(eithFXflag == 0 && eithFXtimer <= 5000)eithFXtimer = eithFXtimer - 1;

    	  if(eithFXtimer > 20000) eithFXflag = 0;
    	  if(eithFXtimer < 500) eithFXflag = 1;
    	  
    	  for(int i=1; i<10; i++){
    	      digitalWrite(pinMassive[i], 1);    	      
    	  }
    	  for(int i=0; i<10; i++){
    	  	digitalWrite(pinMassive[i], 0);    	      
    	  }
    	  if(eithFXtimer <= 5000)delayMicroseconds(eithFXtimer*3);
    	  if(eithFXtimer >= 5000)delayMicroseconds(eithFXtimer);
    	  break;
    	case 9:
    	  for(int i=1; i<11; i++){
    	  	digitalWrite(i, 1);
    	  	// Serial.println(i);
    	  }
    	  break;
	}
}

void specialDelay(int ms){

int timer_passedbaddelay = 0;
int timer_baddelay = ms / 10;
while(timer_passedbaddelay <= timer_baddelay){
poolButton();
delay(10);
timer_passedbaddelay++;
if(returne != 0) break;
}
}

void poolButton(){
	int duration = 0;
	while (digitalRead(buttPin) == 1){
		duration++;
		Serial.println(duration);
		if(duration >= 1500){
			break;
			pinMassive[0] = 0;
			returne = 1;
			resetall();
		}
}
if (duration > 50 && duration < 1000){
	pinMassive[0]++;
	delay(500);
	returne = 1;
	resetall();
	FXNum(pinMassive[0]);
}
if(duration >= 1000){
	pinMassive[0] = 0;
	returne = 1;
	resetall();
}
}

void resetall(){
for(int i=1; i<11; i++)digitalWrite(i, 0);
}

void FXNum(int num){
for(int i=1; i<num+1; i++){
    digitalWrite(pinMassive[i], 1);
}
    delay(1200);
resetall();
}