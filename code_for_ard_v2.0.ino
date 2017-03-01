/*In this file, part-1:we are gonna transmit a string t to esp module*/
/*and part2: print the data recieved from espmodule on serial monitor*/
/*these two are two individual functions used to check the 2 way communication i.e transmission to esp(part1)
 * and receiving from esp(part2)
 */

/*In this we are going to establish a two way communication between arduino and esp i.e arduino transmits data and esp receives it .
 * the data recievd by esp is again transmitted back to arduino 
 * the dta then recievd by arduino is printed on the serial monitor.
 * It is necessary to implement this part because as per our frame work as long as 
 * arduino keeps running or not in reset position esp cannot bypass arduino to communicate with pc i.e serial monitor.so to check whether data is rx'ed perfectly it transmits back to arduino the recieved data as it is to print on serial monitor. 
 * In this repository file-1 is used to be uploaded in arduino and file2 is to be loaded in esp module.
 * file 1 transmits data from arduino and receives from esp
 * file2 recieves data from arduino and transmits back as it is.
 * 
 * NOTE:we use software serial of arduino to transmit data to esp but on esp side there is only 1 serila i.e hardware serial so implementyour logic by keeping that in conscience.
 */

#include <SoftwareSerial.h>
char ch[20];
char se[20];
const byte rxPin = 2; // Wire this to Tx Pin of ESP8266
const byte txPin = 3; // Wire this to Rx Pin of ESP8266

// We'll use a software serial interface to connect to ESP8266
SoftwareSerial ESP8266 (rxPin, txPin);

void setup() {
  Serial.begin(115200);
  ESP8266.begin(115200); // Initialize or set the baudrate used by ESP8266
  delay(1000); // Let the module self-initialize
}

void loop() {
  
 for(int i=0;i<40;i=i+10)
{
  String k="";
  int m=i;
  String t="temp "+String(m)+'\0';//updating the string t along with for loop
  
   int l=t.length();
   t.toCharArray(se,20); //conversion of string t to character array for serial transmission to espmodule
   /*for loop to transmit character array odf string t to esp module*/
    for (int i=0;i<l;i++)
   {
    ESP8266.write(se[i]);
   }
    delay(2000); 
/*part-2:receiving datafrom esp and printing on serial monitor*/

   while (ESP8266.available()>0)
   {
       for (int i=0;i<10;i++)
       {  
         ch[i] = ESP8266.read();//reading character by character from serial line
          if (ch[i]=='\0')//if loop to stop reading when ever null character encountered
          {   break; }
           k+= ch[i];//concatenation of every character read to a string k
       }
    }

   Serial.println(k);  //printing on serial monitor
   
}   
    
} 
