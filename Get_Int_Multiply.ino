
int a;
int b;
int results;
// the setup function runs once when you press reset or power the board
void setup() {
Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  while(!Serial.available()){
    delay(100);
    
    }


  Serial.println("Enter first number :");
  delay(5000);
  a=Serial.parseInt();

  Serial.println("Enter 2nd number :");
  delay(5000);
  b=Serial.parseInt();
  
  results= multi(a,b);                  // wait for a second
  Serial.print("Multiplication is : ");
  Serial.println(results);
  delay(5000);
}


int multi(int x,int y){
int z=x*y;
 return z; 
}





