/*In this file the esp module reads each and every character transmitted by arduino untill a null character is encountered 
 * and transmits back the data as it is along with extra null character which is helpful for arduino to know when it should stop reading /recieving data from esp to print
*/
char ch[10];
void setup() {
 Serial.begin(115200);//Initialize the baud rate required for serial communication

}

void loop() {
  
 String k="";
  
  while(Serial.available()>0)//checking for data transmitted by arduino if available enter into while loop
    {
   
    for (int i=0;i<10;i++)
   {  
   
    ch[i] = Serial.read();//read character by character of data sent by arduino
    if (ch[i]=='\0')
     {   break; }//stop reading data only when ending character is null
     k+= ch[i];
     Serial.write(ch[i]);//transmit back to arduino character by character
     
}
 Serial.write('\0');//appending a null character along with above data sinceif loop above doesn't read null character
 for (int i = 0; i < 10; i++)//for loop to reinitialize char array ch to null
 {
    ch[i]='\0';
 }
  } 
 delay(2000); 

}

