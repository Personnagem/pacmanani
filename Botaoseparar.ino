#include <Wire.h>
#include <LiquidCrystal_I2C.h>  

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define buttonPin  8
#define bot 3

int botread=0;

byte fan[8] = {
        B01110,
        B11111,
        B10101,
        B11111,
        B11111,
        B11111,
        B10101,
        B00000
};

byte pacmanusu[8] = {
        B00000,
        B01110,
        B11011,
        B11111,
        B11100,
        B01110,
        B00000,
        B00000
};

byte hit[8] = {
  0b00000,
  0b11011,
  0b01110,
  0b00100,
  0b00100,
  0b01110,
  0b11011,
  0b00000
};

byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};
byte pacman1[8] = {
        B00000,
        B01110,
        B11011,
        B11111,
        B11100,
        B01110,
        B00000,
        B00000
};
byte pacman2[8] = {
        B00000,
        B01110,
        B11011,
        B11111,
        B11111,
        B01110,
        B00000,
        B00000
};
byte pacman3[8] = {
        B00000,
        B01110,
        B11111,
        B11101,
        B10111,
        B00110,
        B00000,
        B00000
};
byte pacman4[8] = {
        B00000,
        B01110,
        B11011,
        B11111,
        B00111,
        B01110,
        B00000,
        B00000
};
byte fantasma1[8] = {
        B01110,
        B11111,
        B10101,
        B11111,
        B11111,
        B11111,
        B10101,
        B00000
};
byte fantasma2[8] = {
        B01110,
        B11111,
        B10101,
        B11111,
        B10001,
        B11111,
        B10101,
        B00000
};
byte vazio[8] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000
};


int pipes[16];
int birdY = 2;
int birdX = 7;
int score = 0;
int speedlvl = 400;

int life = 3; // number of lives

void setup() {
  lcd.backlight();  
  Serial.begin (9600);
  
  randomSeed(analogRead(0));
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(bot, INPUT);
  pinMode(6, OUTPUT);
  
  int i = 0;
  for (i = 0; i<16; i++) {
    pipes[i] = 0;
  }
 
  lcd.init();

  lcd.createChar(0, fan);
  lcd.createChar(1, pacmanusu);
  lcd.createChar(2, hit);
  lcd.createChar(3, heart);
  lcd.createChar(4, pacman1);
  lcd.createChar(5, pacman2);
  lcd.createChar(6, pacman3);
  lcd.createChar(7, pacman4);
  lcd.createChar(8, fantasma1);
  lcd.createChar(9, fantasma2);
  lcd.createChar(10, vazio);
}


void birdfly() {
  int buttonValue = digitalRead(buttonPin);
  int charId = 0;
  
  if (buttonValue == LOW) {
    birdY = 0;
    charId = 1;
  } else {
    birdY = 1;
    charId = 1;
    if (pipes[birdX] == 1) {
      charId = 2;
      life--;
      score--;
    }
  }
  
  lcd.setCursor(birdX, birdY);
  lcd.write((byte)charId);
}


void movePipes() {
  int dist = random(0, 2);
  // move the pipes along screen
  int i;
  for (i=1; i<16; i++) {
    pipes[i-1] = pipes[i];
  }
  
  if (dist == 1 && (pipes[16] == 2 || pipes[13] == 1)) {
      pipes[15] = 0;
  } else {
     pipes[15] = random(0, 2);
  }
    
  for (i = 0; i<16; i++) {
    if (pipes[i] != 0) {
      lcd.setCursor(i, 1);
      lcd.write((byte)0);
    }
  }

}


void showLives() {
  int i;
  for (i=0; i<life; i++) {
    lcd.setCursor(i, 0);
    lcd.write((byte)3);
  }
}

void showScore() {
  lcd.setCursor(13,0);
  lcd.print(score);
}

void nada0(){
  lcd.setCursor(15,0);
  lcd.write((byte)10);
}
void nada1(){
  lcd.setCursor(14,0);
  lcd.write((byte)10);
}
void nada2(){
  lcd.setCursor(13,0);
  lcd.write((byte)10);
}
void nada3(){
  lcd.setCursor(12,0);
  lcd.write((byte)10);
}
void nada4(){
  lcd.setCursor(11,0);
  lcd.write((byte)10);
}
void nada5(){
  lcd.setCursor(10,0);
  lcd.write((byte)10);
}
void nada6(){
  lcd.setCursor(9,0);
  lcd.write((byte)10);
}
void nada7(){
  lcd.setCursor(8,0);
  lcd.write((byte)10);
}
void nada8(){
  lcd.setCursor(7,0);
  lcd.write((byte)10);
}
void nada9(){
  lcd.setCursor(6,0);
  lcd.write((byte)10);
}
void nada10(){
  lcd.setCursor(5,0);
  lcd.write((byte)10);
}
void nada11(){
  lcd.setCursor(4,0);
  lcd.write((byte)10);
}
void nada12(){
  lcd.setCursor(3,0);
  lcd.write((byte)10);
}
void nada13(){
  lcd.setCursor(2,0);
  lcd.write((byte)10);
}
void nada14(){
  lcd.setCursor(1,0);
  lcd.write((byte)10);
}
void nada15(){
  lcd.setCursor(0,0);
  lcd.write((byte)10);
}
void nada16(){
  lcd.setCursor(0,1);
  lcd.write((byte)10);
}
void nada17(){
  lcd.setCursor(1,1);
  lcd.write((byte)10);
}
void nada18(){
  lcd.setCursor(2,1);
  lcd.write((byte)10);
}
void nada19(){
  lcd.setCursor(3,1);
  lcd.write((byte)10);
}
void nada20(){
  lcd.setCursor(4,1);
  lcd.write((byte)10);
}
void nada21(){
  lcd.setCursor(5,1);
  lcd.write((byte)10);
}
void nada22(){
  lcd.setCursor(6,1);
  lcd.write((byte)10);
}
void nada23(){
  lcd.setCursor(7,1);
  lcd.write((byte)10);
}
void nada24(){
  lcd.setCursor(8,1);
  lcd.write((byte)10);
}
void nada25(){
  lcd.setCursor(9,1);
  lcd.write((byte)10);
}
void nada26(){
  lcd.setCursor(10,1);
  lcd.write((byte)10);
}
void nada27(){
  lcd.setCursor(11,1);
  lcd.write((byte)10);
}
void nada28(){
  lcd.setCursor(12,1);
  lcd.write((byte)10);
}
void nada29(){
  lcd.setCursor(13,1);
  lcd.write((byte)10);
}
void nada30(){
  lcd.setCursor(14,1);
  lcd.write((byte)10);
}
void nada31(){
  lcd.setCursor(15,1);
  lcd.write((byte)10);
}

void pacmana() {
  lcd.setCursor(15,0);
  lcd.write((byte)7);
}
void pacmanb(){
  lcd.setCursor(14,0);
  lcd.write((byte)5);
}
void pacmanc(){
  lcd.setCursor(13,0);
  lcd.write((byte)7);
}
void pacmand(){
  lcd.setCursor(12,0);
  lcd.write((byte)5);
}
void pacmane(){
  lcd.setCursor(11,0);
  lcd.write((byte)7);
}
void pacmanf(){
  lcd.setCursor(10,0);
  lcd.write((byte)5);
}
void pacmang(){
  lcd.setCursor(9,0);
  lcd.write((byte)7);
}
void pacmanh(){
  lcd.setCursor(8,0);
  lcd.write((byte)5);
}
void pacmani(){
  lcd.setCursor(7,0);
  lcd.write((byte)7);
}
void pacmanj(){
  lcd.setCursor(6,0);
  lcd.write((byte)5);
}
void pacmank(){
  lcd.setCursor(5,0);
  lcd.write((byte)7);
}
void pacmanl(){
  lcd.setCursor(4,0);
  lcd.write((byte)5);
}
void pacmanm(){
  lcd.setCursor(3,0);
  lcd.write((byte)7);
}
void pacmann(){
  lcd.setCursor(2,0);
  lcd.write((byte)5);
}
void pacmano(){
  lcd.setCursor(1,0);
  lcd.write((byte)7);
}
void pacmanp(){
  lcd.setCursor(0,0);
  lcd.write((byte)6);
}
void pacmanq(){
  lcd.setCursor(0,1);
  lcd.write((byte)4);
}
void pacmanr(){
  lcd.setCursor(1,1);
  lcd.write((byte)5);
}
void pacmans(){
  lcd.setCursor(2,1);
  lcd.write((byte)4);
}
void pacmant(){
  lcd.setCursor(3,1);
  lcd.write((byte)5);
}
void pacmanu(){
  lcd.setCursor(4,1);
  lcd.write((byte)4);
}
void pacmanv(){
  lcd.setCursor(5,1);
  lcd.write((byte)5);
}
void pacmanw(){
  lcd.setCursor(6,1);
  lcd.write((byte)4);
}
void pacmanx(){
  lcd.setCursor(7,1);
  lcd.write((byte)5);
}
void pacmany(){
  lcd.setCursor(8,1);
  lcd.write((byte)4);
}
void pacmanz(){
  lcd.setCursor(9,1);
  lcd.write((byte)5);
}
void pacmanaa(){
  lcd.setCursor(10,1);
  lcd.write((byte)4);
}
void pacmanab(){
  lcd.setCursor(11,1);
  lcd.write((byte)5);
}
void pacmanac(){
  lcd.setCursor(12,1);
  lcd.write((byte)4);
}
void pacmanad(){
  lcd.setCursor(13,1);
  lcd.write((byte)5);
}
void pacmanae(){
  lcd.setCursor(14,1);
  lcd.write((byte)4);
}
void pacmanaf(){
  lcd.setCursor(15,1);
  lcd.write((byte)5);
}
void fantasmaa() {
  lcd.setCursor(15,0);
  lcd.write((byte)8);
}
void fantasmab(){
  lcd.setCursor(14,0);
  lcd.write((byte)8);
}
void fantasmac(){
  lcd.setCursor(13,0);
  lcd.write((byte)8);
}
void fantasmad(){
  lcd.setCursor(12,0);
  lcd.write((byte)8);
}
void fantasmae(){
  lcd.setCursor(11,0);
  lcd.write((byte)8);
}
void fantasmaf(){
  lcd.setCursor(10,0);
  lcd.write((byte)8);
}
void fantasmag(){
  lcd.setCursor(9,0);
  lcd.write((byte)8);
}
void fantasmah(){
  lcd.setCursor(8,0);
  lcd.write((byte)8);
}
void fantasmai(){
  lcd.setCursor(7,0);
  lcd.write((byte)8);
}
void fantasmaj(){
  lcd.setCursor(6,0);
  lcd.write((byte)8);
}
void fantasmak(){
  lcd.setCursor(5,0);
  lcd.write((byte)8);
}
void fantasmal(){
  lcd.setCursor(4,0);
  lcd.write((byte)8);
}
void fantasmam(){
  lcd.setCursor(3,0);
  lcd.write((byte)8);
}
void fantasman(){
  lcd.setCursor(2,0);
  lcd.write((byte)8);
}
void fantasmao(){
  lcd.setCursor(1,0);
  lcd.write((byte)8);
}
void fantasmap(){
  lcd.setCursor(0,0);
  lcd.write((byte)8);
}
void fantasmaq(){
  lcd.setCursor(0,1);
  lcd.write((byte)8);
}
void fantasmar(){
  lcd.setCursor(1,1);
  lcd.write((byte)8);
}
void fantasmas(){
  lcd.setCursor(2,1);
  lcd.write((byte)8);
}
void fantasmat(){
  lcd.setCursor(3,1);
  lcd.write((byte)8);
}
void fantasmau(){
  lcd.setCursor(4,1);
  lcd.write((byte)8);
}
void fantasmav(){
  lcd.setCursor(5,1);
  lcd.write((byte)8);
}
void fantasmaw(){
  lcd.setCursor(6,1);
  lcd.write((byte)8);
}
void fantasmax(){
  lcd.setCursor(7,1);
  lcd.write((byte)8);
}
void fantasmay(){
  lcd.setCursor(8,1);
  lcd.write((byte)8);
}
void fantasmaz(){
  lcd.setCursor(9,1);
  lcd.write((byte)8);
}
void fantasmaaa(){
  lcd.setCursor(10,1);
  lcd.write((byte)8);
}
void fantasmaab(){
  lcd.setCursor(11,1);
  lcd.write((byte)8);
}
void fantasmaac(){
  lcd.setCursor(12,1);
  lcd.write((byte)8);
}
void fantasmaad(){
  lcd.setCursor(13,1);
  lcd.write((byte)8);
}
void fantasmaae(){
  lcd.setCursor(14,1);
  lcd.write((byte)8);
}
void fantasmaaf(){
  lcd.setCursor(15,1);
  lcd.write((byte)8);
}

void loop() {
  lcd.clear();
  botread=digitalRead(bot);
  if(botread==HIGH){
  digitalWrite(6, HIGH);
  if (life > 0) {
    movePipes();
    birdfly();
    showLives();
    showScore();
    score++;
    speedlvl--;    
  } else {
    lcd.setCursor(3, 0);
    lcd.print("  Perdeu");
    lcd.setCursor(3, 1);
    lcd.print("Pontos: ");
    lcd.print(score);
  }

  delay(speedlvl); // speed of pipes will decrease and move faster the more points you have

}
  if(botread==LOW){
  lcd.clear();
  lcd.setCursor (3,0);
  lcd.print("PROJETO DO");
  lcd.setCursor (1,1);
  lcd.print("WENDELL GUSTAVO");
  delay(500);
  lcd.setCursor (3,0);
  lcd.print("PROJETO DO");
  pacmana();
  delay(500);
  nada0();
  lcd.setCursor (3,0);
  lcd.print("PROJETO DO");
  pacmanb();
  delay(500);
  nada1();
  lcd.setCursor (3,0);
  lcd.print("PROJETO DO");
  pacmanc();
  delay(500);
  nada2();
  lcd.setCursor (3,0);
  lcd.print("PROJETO D");
  pacmand();
  delay(500);
  nada3();
  lcd.setCursor (3,0);
  lcd.print("PROJETO ");
  pacmane();
  delay(500);
  nada4();
  lcd.setCursor (3,0);
  lcd.print("PROJETO");
  pacmanf();
  delay(500);
  nada5();
  lcd.setCursor (3,0);
  lcd.print("PROJET");
  pacmang();
  delay(500);
  nada6();
  lcd.setCursor (3,0);
  lcd.print("PROJE");
  pacmanh();
  delay(500);
  nada7();
  lcd.setCursor (3,0);
  lcd.print("PROJ");
  pacmani();
  delay(500);
  nada8();
  lcd.setCursor (3,0);
  lcd.print("PRO");
  pacmanj();
  delay(500);
  nada9();
  lcd.setCursor (3,0);
  lcd.print("PR");
  pacmank();
  delay(500);
  nada10();
  lcd.setCursor (3,0);
  lcd.print("P");
  pacmanl();
  delay(500);
  nada11();
  pacmanm();
  delay(500);
  nada12();
  pacmann();
  delay(500);
  nada13();
  pacmano();
  delay(500);
  nada14();
  pacmanp();
  delay(500);
  nada15();
  lcd.setCursor (1,1);
  lcd.print("WENDELL GUSTAVO");
  pacmanq();
  delay(500);
  nada16();
  lcd.setCursor (2,1);
  lcd.print("ENDELL GUSTAVO");
  pacmanr();
  delay(500);
  nada17();
  lcd.setCursor (3,1);
  lcd.print("NDELL GUSTAVO");
  pacmans();
  delay(500);
  nada18();
  lcd.setCursor (4,1);
  lcd.print("DELL GUSTAVO");
  pacmant();
  delay(500);
  nada19();
  lcd.setCursor (5,1);
  lcd.print("ELL GUSTAVO");
  pacmanu();
  delay(500);
  nada20();
  lcd.setCursor (6,1);
  lcd.print("LL GUSTAVO");
  pacmanv();
  delay(500);
  nada21();
  lcd.setCursor (7,1);
  lcd.print("L GUSTAVO");
  pacmanw();
  delay(500);
  nada22();
  lcd.setCursor (8,1);
  lcd.print(" GUSTAVO");
  pacmanx();
  delay(500);
  nada23();
  lcd.setCursor (9,1);
  lcd.print("GUSTAVO");
  pacmany();
  delay(500);
  nada24();
  lcd.setCursor (10,1);
  lcd.print("USTAVO");
  pacmanz();
  delay(500);
  nada25();
  lcd.setCursor (11,1);
  lcd.print("STAVO");
  pacmanaa();
  delay(500);
  nada26();
  lcd.setCursor (12,1);
  lcd.print("TAVO");
  pacmanab();
  delay(500);
  nada27();
  lcd.setCursor (13,1);
  lcd.print("AVO");
  pacmanac();
  delay(500);
  nada28();
  lcd.setCursor (14,1);
  lcd.print("VO");
  pacmanad();
  delay(500);
  nada29();
  lcd.setCursor (15,1);
  lcd.print("O");
  pacmanae();
  delay(500);
  nada30();
  lcd.setCursor (0,1);
  pacmanaf();
  delay(500);
  nada31();
  delay(500);
  fantasmaa();
  delay(500);
  nada0();
  fantasmab();
  delay(500);
  nada1();
  fantasmac();
  delay(500);
  nada2();
  fantasmad();
  delay(500);
  lcd.setCursor(12,0);
  lcd.print("O");
  fantasmae();
  delay(500);
  lcd.setCursor(11,0);
  lcd.print("DO");
  fantasmaf();
  delay(500);
  lcd.setCursor(10,0);
  lcd.print(" DO");
  fantasmag();
  delay(500);
  lcd.setCursor(9,0);
  lcd.print("O DO");
  fantasmah();
  delay(500);
  lcd.setCursor(8,0);
  lcd.print("TO DO");
  fantasmai();
  delay(500);
  lcd.setCursor(7,0);
  lcd.print("ETO DO");
  fantasmaj();
  delay(500);
  lcd.setCursor(6,0);
  lcd.print("JETO DO");
  fantasmak();
  delay(500);
  lcd.setCursor(5,0);
  lcd.print("OJETO DO");
  fantasmal();
  delay(500);
  lcd.setCursor(4,0);
  lcd.print("ROJETO DO");
  fantasmam();
  delay(500);
  lcd.setCursor(3,0);
  lcd.print("PROJETO DO");
  fantasman();
  delay(500);
  nada13();
  fantasmao();
  delay(500);
  nada14();
  fantasmap();
  delay(500);
  nada15();
  fantasmaq();
  delay(500);
  nada16();
  lcd.setCursor(1,1);
  lcd.print("W");
  fantasmar();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WE");
  fantasmas();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WEN");
  fantasmat();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WEND");
  fantasmau();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WENDE");
  fantasmav();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WENDEL");
  fantasmaw();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WENDELL");
  fantasmax();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WENDELL ");
  fantasmay();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WENDELL G");
  fantasmaz();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WENDELL GU");
  fantasmaaa();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WENDELL GUS");
  fantasmaab();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WENDELL GUST");
  fantasmaac();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WENDELL GUSTA");
  fantasmaad();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WENDELL GUSTAV");
  fantasmaae();
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("WENDELL GUSTAVO");
  fantasmaaf();
  delay(500);
  }
  
}
