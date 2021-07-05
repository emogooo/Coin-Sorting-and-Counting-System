#define MotorPin 5
#define ir5 A0
#define ir10 A1
#define ir25 A2
#define ir50 A3
#define ir100 A4
int esikDegeri = 100;
int sure5k = 0;
int sure10k = 0;
int sure25k = 0;
int sure50k = 0;
int sure100k = 0;
int sureEsikDegeri = 10;
double toplamPara = 0;
int sayac[] = {0, 0, 0, 0, 0};
bool kontrol = false;

void setup() { 
  Serial.begin(9600);
  pinMode(MotorPin, OUTPUT);
  digitalWrite(MotorPin, HIGH);
}

void loop() {
  kontrol = false;
  if((analogRead(ir5) < esikDegeri) && ( millis() - sure5k ) > sureEsikDegeri ){
    sure5k = millis();
    sayac[0]++;
    kontrol = true;
    toplamPara += 0.05;
  }
  if(analogRead(ir10) < esikDegeri && ( millis() - sure10k ) > sureEsikDegeri ){
    sure10k = millis();
    sayac[1]++;
    kontrol = true;
    toplamPara += 0.1;
  }
  if(analogRead(ir25) < esikDegeri && ( millis() - sure25k ) > sureEsikDegeri ){
    sure25k = millis();
    sayac[2]++;
    kontrol = true;
    toplamPara += 0.25;
  }
  if(analogRead(ir50) < esikDegeri && ( millis() - sure50k ) > sureEsikDegeri ){
    sure50k = millis();
    sayac[3]++;
    kontrol = true;
    toplamPara += 0.5;
  }
  if(( analogRead(ir100) < esikDegeri ) && (( millis() - sure100k ) > sureEsikDegeri )){
    sure100k = millis();
    sayac[4]++;
    kontrol = true;
    toplamPara += 1;
  }
  if(kontrol){
    Serial.print("Toplam Para: ");
    Serial.print(toplamPara);
    Serial.println(" TL");
    
    Serial.print("5 Kuruş Adedi : ");
    Serial.println(sayac[0]);
    
    Serial.print("10 Kuruş Adedi : ");
    Serial.println(sayac[1]);
    
    Serial.print("25 Kuruş Adedi : ");
    Serial.println(sayac[2]);
    
    Serial.print("50 Kuruş Adedi : ");
    Serial.println(sayac[3]);
    
    Serial.print("1 Lira Adedi : ");
    Serial.println(sayac[4]);
    temizle();
  }
}

void temizle(){
  for(int i = 0; i < 25; i++){
    Serial.println("");
  }
}
