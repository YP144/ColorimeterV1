ezButton button1(35);
void setup() {
  
  //set mode pin sebagai input/output bagi esp32
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(sensorOut,INPUT);

  //Setting frequency scaling to n%:
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  tft.initR(INITR_BLACKTAB); // inisialisasi ST7735s chip, black tab
  drawBlackScreen();

  tft.setCursor(15,15);
  tft.setTextColor(GREEN);
  tft.setTextSize(1.9);
  tft.print("COLORIMETER V1.0");

  tft.setCursor(40,36);
  tft.setTextColor(BLUE);
  tft.setTextSize(1.5);
  tft.print("LAB TF III");

  tft.setCursor(20,54);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("Adi");

  tft.setCursor(20,67);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("Dzaki");
  
  tft.setCursor(20,80);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("Jihad");

  tft.setCursor(20,93);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("Prian");

  tft.setCursor(20,106);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("Sayyid");
  
  tft.setCursor(20,119);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("Yosep");

  tft.setCursor(94,54);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("'069");

  tft.setCursor(94,67);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("'067");
  
  tft.setCursor(94,80);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("'064");

  tft.setCursor(94,93);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("'082");

  tft.setCursor(94,106);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("'061");
  
  tft.setCursor(94,119);
  tft.setTextColor(WHITE);
  tft.setTextSize(0.9);
  tft.print("'026");
  delay(7000);

  drawBlackScreen();

  Serial.begin(115200); 
  button1.setDebounceTime(25); // set debounce time to 100 milliseconds
  tft.setCursor(28,5);
  tft.setTextColor(GREEN);
  tft.setTextSize(0.7);
  tft.print("COLORIMETER V1.0");
  tft.fillRect(5,15,118,1, WHITE);
}

void drawBlackScreen() {
  tft.fillScreen(BLACK);
}
void loading(){
  blackloop();
  tft.setCursor(40,60);
  tft.setTextColor(YELLOW);
  tft.setTextSize(1.9);
  tft.print("LOADING...");
}
void blackloop(){
  tft.fillRect(0,18,128,110, BLACK);
}

void samplingRGB(){
  //BACA RED
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redfrequency = pulseIn(sensorOut,LOW);
//  R = ((redfrequency)*(-1.6685))+295.07;
  R = redfrequency*(-1.5806)+324.81 ;
  //BACA GREEN
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenfrequency = pulseIn(sensorOut,LOW);
//  G = ((greenfrequency*greenfrequency*greenfrequency)*((-7)/1000000))+(0.0077*greenfrequency*greenfrequency)+((-2.518)*greenfrequency)+313.1;
  G = greenfrequency*(-1.2356)+289.51;
  //BACA BLUE
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  bluefrequency = pulseIn(sensorOut,LOW);
//  B = ((bluefrequency)*(-1.8568))+282.09;
  B = bluefrequency*(-1.5982)+301.27;
}
void wait(){
  tft.setCursor(56,118);
  tft.setTextColor(YELLOW);
  tft.setTextSize(1.5);
  tft.print("WAIT !!");
  tft.fillRect(54,117,85,128, BLACK);
}
void loop() {
//  button1.loop(); // MUST call the loop() function first
  last_state = current_state;
//  current_state = button1.getState();
  Serial.print("button 1 state: ");
  Serial.println(current_state);
//  if(button1.isPressed()){
    Serial.print(F("tombol dipencet,akan diambil data"));
    Serial.println();
    loading();
    delay(2000);
    samplingRGB();
    Serial.print(F("R="));
    Serial.print(R);
    Serial.print(F("  G="));
    Serial.print(G);
    Serial.print(F("  B="));
    Serial.print(B);
    Serial.println();
    blackloop();
    tft.setTextSize(1.5);
    tft.setCursor(83,60);
    tft.print("R= ");
    tft.setCursor(98,60);
    tft.print(R);
    tft.setCursor(83,80);
    tft.print("G= ");
    tft.setCursor(98,80);
    tft.print(G);
    tft.setCursor(83,100);
    tft.print("B= ");
    tft.setCursor(98,100);
    tft.print(B); 
    tft.drawRect(10,50,66,66,WHITE);
    colorpicker();
  
//  if (current_state == 0 && last_state == 0){
//    wait();
//  }
  delay(5000);
}
