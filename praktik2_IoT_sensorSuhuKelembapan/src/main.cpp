#include <Arduino.h> 
#include <DHT.h>

#define DHTPIN 27      // Pin yang terhubung ke sensor DHT22
#define DHTTYPE DHT22  // Tipe sensor DHT

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();  // Inisialisasi sensor
}

void loop() {
  delay(2000);  // Delay antar pembacaan

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Cek apakah pembacaan gagal
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Gagal membaca sensor!");
    return;
  }

  // Tampilkan hasil pembacaan
  Serial.print("Kelembaban: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println(" *C");
}
