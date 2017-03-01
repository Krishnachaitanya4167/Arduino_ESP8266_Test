# Arduino_ESP8266_Test
Transfer of data between arduino and Esp8266 Bi-directionally

/*In this we are going to establish a two way communication between arduino and esp i.e arduino transmits data and esp receives it 
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

For this code and logic to work we need to slightly alter the circuit .
1)first connect the circuit by following the procedure mentioned in file procedure for hardware.
2)Now,wait till you see "done uploading" message on the screen.
3)After the uploading is done,now remove the wires of rx,tx from 0,1 pins of arduino and connect them to 4,3 pins respectively.
4)i.e the tx of esp is to be connected to software serial rx of arduino and vice versa. 

file-1:code_for_ard_v2.0.ino
   It is to be uploaded into arduino uno
   
 file-2: 	check_esp.ino
   It is to be uploaded into Esp8266-wifi-module.


