#include <WiFi.h>
#include <HTTPClient.h>


// Ganti dengan kredensial jaringan Wi-Fi Anda
// const char* ssid = "Lab IT";
// const char* password = "labit2024";




 const char* ssid = "Wokwi-GUEST";
 const char* password = "";




// URL lengkap server yang akan diakses
const char* serverUrl = "http://4e89-175-45-190-4.ngrok-free.app/api/posts";


// Interval waktu antara setiap permintaan (dalam milidetik)
const unsigned long interval = 5000;
unsigned long previousMillis = 0;


void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);


  Serial.print("Menghubungkan ke WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Terhubung!");
}






void loop() {




  unsigned long currentMillis = millis();


  // Periksa apakah interval waktu telah berlalu
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;


    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;


      // Inisialisasi HTTPClient dengan URL server
      http.begin(serverUrl);


      // Mengirim permintaan HTTP GET
      int httpResponseCode = http.GET();


      // Menampilkan kode status HTTP
      Serial.print("Kode status HTTP: ");
      Serial.println(httpResponseCode);


      // Menutup koneksi
      http.end();
    } else {
      Serial.println("WiFi tidak terhubung.");
    }
  }
}
