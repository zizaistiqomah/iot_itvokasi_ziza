#include <Arduino.h>  // Wajib untuk PlatformIO + ESP32




// Deklarasi pin LED
int lampu = 26;
int lampu2 = 18;




void setup() {
    Serial.begin(115200);  // Inisialisasi komunikasi Serial
    Serial.println("ESP32 Blinking LED");




    // Atur pin sebagai OUTPUT
    pinMode(lampu, OUTPUT);
    pinMode(lampu2, OUTPUT);
}




void loop() {
    // Nyalakan kedua LED
    digitalWrite(lampu, HIGH);
    digitalWrite(lampu2, HIGH);
    Serial.println("LED ON");
   
    delay(1000); // Tunggu 1 detik




    // Matikan kedua LED
    digitalWrite(lampu, LOW);
    digitalWrite(lampu2, LOW);
    Serial.println("LED OFF");
   
    delay(1000); // Tunggu 1 detik sebelum mengulang
}
