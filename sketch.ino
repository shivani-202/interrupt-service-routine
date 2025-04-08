//assign button ports
const byte button1 = 33, button2 = 32, button3 = 35, button4= 34;
bool debounce_active1 = false, debounce_active2 = false, debounce_active3 = false, debounce_active4 = false;
const int ledPin = 17;
bool LEDState = false;
int buttonState = 0;
int lastMillis = 0;
//bool button_test = 1;
bool last_button1 = true;
bool button1_state = false, button2_state = false, button3_state = false, button4_state = false;
bool current_button = true;
bool button1_change = false, button2_change = false, button3_change = false, button4_change = false;

//Interupt Service Routine for button 1
void IRAM_ATTR button1_ISR() {
//test if debounce timing is active 
//if yes then ignore
if(debounce_active1 == false){
  //read current pin state
  //set the button1 active flag
  button1_state = digitalRead(button1); //read current pin state
  button1_change = true;
  }
}

//Interupt Service Routine for button 2
void IRAM_ATTR button2_ISR() {
//test if debounce timing is active 
//if yes then ignore
if(debounce_active2 == false){
  //read current pin state
  //set the button2 active flag
  button2_state = digitalRead(button2); //read current pin state
  button2_change = true;
  }
}

//Interupt Service Routine for button 3
void IRAM_ATTR button3_ISR() {
//test if debounce timing is active 
//if yes then ignore
if(debounce_active3 == false){
  //read current pin state
  //set the button3 active flag
  button3_state = digitalRead(button3); //read current pin state
  button3_change = true;
  }
}

//Interupt Service Routine for button 4
void IRAM_ATTR button4_ISR() {
//test if debounce timing is active 
//if yes then ignore
if(debounce_active4 == false){
  //read current pin state
  //set the button4 active flag
  button4_state = digitalRead(button4); //read current pin state
  button4_change = true;
  }
}

void setup() {
 Serial.begin(115200);
 //assign button input types
 pinMode(button1, INPUT_PULLUP);
 pinMode(button2, INPUT_PULLUP);
 pinMode(button3, INPUT);
 pinMode(button4, INPUT);
 pinMode(ledPin,OUTPUT);
 //setup interupt pins and function call
 attachInterrupt(button1, button1_ISR, CHANGE);
 attachInterrupt(button2, button2_ISR, CHANGE);
 attachInterrupt(button3, button3_ISR, CHANGE);
 attachInterrupt(button4, button4_ISR, CHANGE);
 digitalWrite(ledPin, LEDState);  //turn led off
 Serial.println("Setup complete");
}

void loop() {
 // Code ...
 bool debounce1_active = false, debounce2_active = false, debounce3_active = false, debounce4_active = false;
 bool button1_active =false,button2_active =false,button3_active =false,button4_active =false; 
 unsigned long start_time1, start_time2, start_time3, start_time4;
 unsigned long current_time;
 unsigned long debounce_time = 20000;

 //get current time for this loop
 current_time = millis();

 
 //-----------------------------------------------------------------
 //                         button 1 debounce
 //-----------------------------------------------------------------
 //check if button1 is active
 if(button1_change == true){
  //check if debounce active
  if(debounce1_active=false){
    //set active flag & save current time
    debounce1_active = true;
    start_time1 = millis();
    }
  //debounce time test
  //check if current time is more then 10msec
  //past start time
  if(current_time - start_time1 > debounce_time){
    //10msec has passed since button change
    //now compare if current button state and
    //past state are the same
    bool now_button = digitalRead(button1);
    if(button1_state != now_button){
      //buttons states do not match
      //do antoher 10msec debounce
      //save current button state
      button1_state = now_button;
      //set new start time for debounce
      start_time1 = millis();
      goto Next2;
    } else {
      //button states do match
      //valid button change
      //turn off debounce and change flags
      debounce1_active = false;
      //turn off button change flag
      button1_change = false;
      //set button active flag
      button1_active = true;
    }

  }
 }
 Next2:
  //-----------------------------------------------------------------
 //                         button 2 debounce
 //-----------------------------------------------------------------
 //check if button2 is active
 if(button2_change == true){
  //check if debounce active
  if(debounce2_active=false){
    //set active flag & save current time
    debounce2_active = true;
    start_time2 = millis();
    }
  //debounce time test
  //check if current time is more then 10msec
  //past start time
  if(current_time - start_time2 > debounce_time){
    //10msec has passed since button change
    //now compare if current button state and
    //past state are the same
    bool now_button = digitalRead(button2);
    if(button2_state != now_button){
      //buttons states do not match
      //do antoher 10msec debounce
      //save current button state
      button2_state = now_button;
      //set new start time for debounce
      start_time2 = millis();
      goto Next3;
    } else {
      //button states do match
      //valid button change
      //turn off debounce and change flags
      debounce2_active = false;
      //turn off button change flag
      button2_change = false;
      //set button active flag
      button2_active = true;
    }

  }
 }
 Next3:
  //-----------------------------------------------------------------
 //                         button 3 debounce
 //-----------------------------------------------------------------
 //check if button3 is active
 if(button3_change == true){
  //check if debounce active
  if(debounce3_active=false){
    //set active flag & save current time
    debounce3_active = true;
    start_time3 = millis();
    }
  //debounce time test
  //check if current time is more then 10msec
  //past start time
  if(current_time - start_time3 > debounce_time){
    //10msec has passed since button change
    //now compare if current button state and
    //past state are the same
    bool now_button = digitalRead(button3);
    if(button3_state != now_button){
      //buttons states do not match
      //do antoher 10msec debounce
      //save current button state
      button3_state = now_button;
      //set new start time for debounce
      start_time3 = millis();
      goto Next4;
    } else {
      //button states do match
      //valid button change
      //turn off debounce and change flags
      debounce3_active = false;
      //turn off button change flag
      button3_change = false;
      //set button active flag
      button3_active = true;
    }

  }
 }
 Next4:
  //-----------------------------------------------------------------
 //                         button 4 debounce
 //-----------------------------------------------------------------
 //check if button4 is active
 if(button4_change == true){
  //check if debounce active
  if(debounce4_active=false){
    //set active flag & save current time
    debounce4_active = true;
    start_time4 = millis();
    }
  //debounce time test
  //check if current time is more then 10msec
  //past start time
  if(current_time - start_time4 > debounce_time){
    //10msec has passed since button change
    //now compare if current button state and
    //past state are the same
    bool now_button = digitalRead(button4);
    if(button4_state != now_button){
      //buttons states do not match
      //do antoher 10msec debounce
      //save current button state
      button4_state = now_button;
      //set new start time for debounce
      start_time4 = millis();
      goto Next5;
    } else {
      //button states do match
      //valid button change
      //turn off debounce and change flags
      debounce4_active = false;
      //turn off button change flag
      button4_change = false;
      //set button active flag
      button4_active = true;
    }

  }
 }
 Next5:

 //-----------------------------------------------------------------
 //                      active switch routines
 //-----------------------------------------------------------------
 //                         button 1 routine
 //-----------------------------------------------------------------
 if(button1_active == true){
  static bool button1_last = true;
  if(button1_state != button1_last){
    if(button1_state == true){
      Serial.println("Button 1 is IDLE"); 
      digitalWrite(ledPin, LOW);
    }else{
      Serial.println("Button 1 is ACTIVE"); 
      digitalWrite(ledPin, HIGH);
    }
    button1_active = false;
    button1_last = button1_state;
  }
  
 }
 //-----------------------------------------------------------------
 //                         button 2 routine
 //-----------------------------------------------------------------
 if(button2_active == true){
  static bool button2_last = true;
  if(button2_state != button2_last){
    if(button2_state == true){
      Serial.println("Button 2 is IDLE"); 
      digitalWrite(ledPin, LOW);
    }else{
      Serial.println("Button 2 is ACTIVE"); 
      digitalWrite(ledPin, HIGH);
    }
    button2_active = false;
    button2_last = button2_state;
  }
  
 }
 //-----------------------------------------------------------------
 //                         button 3 routine
 //-----------------------------------------------------------------
 if(button3_active == true){
  static bool button3_last = true;
  if(button3_state != button3_last){
    if(button3_state == true){
      Serial.println("Button 3 is IDLE"); 
      digitalWrite(ledPin, LOW);
    }else{
      Serial.println("Button 3 is ACTIVE"); 
      digitalWrite(ledPin, HIGH);
    }
    button3_active = false;
    button3_last = button3_state;
  }
  
 }
 //-----------------------------------------------------------------
 //                         button 4 routine
 //-----------------------------------------------------------------
 if(button4_active == true){
  static bool button4_last = true;
  if(button4_state != button4_last){
    if(button4_state == true){
      Serial.println("Button 4 is IDLE"); 
      digitalWrite(ledPin, LOW);
    }else{
      Serial.println("Button 4 is ACTIVE"); 
      digitalWrite(ledPin, HIGH);
    }
    button4_active = false;
    button4_last = button4_state;
  }
  
 }
 delay(1);
}
 