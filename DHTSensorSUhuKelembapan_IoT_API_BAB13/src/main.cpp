#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>


#include "DHT.h"




#define DHTPIN 27    
#define DHTTYPE DHT22  




DHT dht(DHTPIN, DHTTYPE);






// Ganti dengan kredensial WiFi Anda
const char* ssid = "Wokwi-GUEST";
const char* password = "";


unsigned long previousMillis = 0;
const long interval = 5000;  // Interval 5 detik (5000 ms)


void setup() {
  Serial.begin(115200);
 
  // Hubungkan ke WiFi
  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan ke WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Terhubung!");








  dht.begin();
 
  // Tunggu sebentar agar koneksi stabil
  delay(1000);
}


void loop() {
  unsigned long currentMillis = millis();


  // Lakukan POST setiap interval yang telah ditentukan
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;






    float h = round(dht.readHumidity());
    // Read temperature as Celsius (the default)
    float t = round(dht.readTemperature());
 
 
    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }
 


    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);




    // Inisialisasi HTTPClient
    HTTPClient http;
    String url = "http://08ed-175-45-190-2.ngrok-free.app/api/posts"; // Ganti dengan URL ngrok yang benar


    http.begin(url);  // Menggunakan HTTP, bukan HTTPS
    http.addHeader("Content-Type", "application/json");




String payload = "{\"nama_sensor\":\"Sensor GD\", \"nilai1\":" + String(h) + ", \"nilai2\":" + String(t) + "}";


Serial.println(payload);  // Untuk melihat apakah payload sudah terbentuk dengan benar


    // Kirim POST request
    int httpResponseCode = http.POST(payload);
   
    // Tampilkan kode respons HTTP
    Serial.print("Kode respons HTTP: ");
    Serial.println(httpResponseCode);


    // Tampilkan respons dari server jika request berhasil
    if (httpResponseCode == 200 || httpResponseCode == 201) {
      String response = http.getString();
      Serial.println("Respons dari server:");
      Serial.println(response);
    } else {
      Serial.println("Gagal mengirim data");
    }


    // Tutup koneksi HTTP
    http.end();
  }
}
