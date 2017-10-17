#include <IRremote.h>
int RECV_PIN = 11; //deklarasi pin receiver
IRrecv irrecv(RECV_PIN);//memasukkan varibael RECV_PIN ke irrecv sebagai fungsi IRrecv 
decode_results results;//deklarasi variabel results sebagai fungsi decode untuk menerjemahkan yg diterima receiver.
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);//print nilai results dalam bentuk heksadesimal
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
