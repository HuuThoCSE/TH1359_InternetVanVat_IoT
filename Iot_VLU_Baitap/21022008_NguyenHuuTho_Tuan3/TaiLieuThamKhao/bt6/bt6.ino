
void setup()
{
 Serial.begin (9600);
 
  pinMode (8 , INPUT);
  pinMode (9 , OUTPUT);
}

void loop()

{
 int rain = digitalRead(8);
 Serial.println(rain);
if(rain==1)
{
  Serial.println("Its Raining");

   delay(500);
   digitalWrite(9,HIGH);
}
else if(rain==0)
{
  Serial.println("No Rain");
  
   delay(500);
   digitalWrite(9,LOW);
}

}
