#define rightSensor 9
#define leftSensor 10

#define INleft1 7
#define INleft2 6
#define INright1 5
#define INright2 4

#define enableRight 3
#define enableLeft 11

#define maxSpeed 200
#define minSpeed 50

void setup() {
  Serial.begin(9600);
  pinMode(rightSensor,INPUT);
  pinMode(leftSensor,INPUT);

}

void loop() {
  
  int right = digitalRead(rightSensor);
  int left = digitalRead(leftSensor);
  Serial.print("right : ");
  Serial.print(right);
  Serial.print(" Left : ");
  Serial.print(left);

  if(!right && !left){
    Forward(maxSpeed,maxSpeed); //right ,left
  }
  else if(!right && left){
    Left(maxSpeed,minSpeed); //right,left
  }
  else if(right && !left){
    Right(minSpeed,maxSpeed); //right ,left
  }
  else if(right && left){
    Forward(0,0); //right,left
  }

}

void Forward(int ra,int la){
  digitalWrite(INleft1,HIGH);
  digitalWrite(INleft2,LOW);
  digitalWrite(INright1,HIGH);
  digitalWrite(INright2,LOW);
  analogWrite(enableRight,ra);
  analogWrite(enableLeft,la);
  Serial.println("Forward");
}
void Right(int ra, int la){
  digitalWrite(INleft1,HIGH);
  digitalWrite(INleft2,LOW);
  digitalWrite(INright1,LOW);
  digitalWrite(INright2,HIGH);
  analogWrite(enableRight,ra);
  analogWrite(enableLeft,la);
  Serial.println("Right");
}
void Left(int ra, int la){
  digitalWrite(INleft1,LOW);
  digitalWrite(INleft2,HIGH);
  digitalWrite(INright1,HIGH);
  digitalWrite(INright2,LOW);
  analogWrite(enableRight,ra);
  analogWrite(enableLeft,la);
  Serial.println("Left");
}
