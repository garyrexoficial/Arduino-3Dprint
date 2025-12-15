#include <DHT.h>

// Configuración del sensor
#define DHTPIN 2          // Pin digital donde conectaste el KY-015
#define DHTTYPE DHT11     // Tipo de sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Monitoreo de temperatura y humedad iniciado...");
}

void loop() {
  // Espera entre lecturas
  delay(2000);

  // Lectura de datos
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Validación de lectura
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error al leer el sensor.");
    return;
  }

  // Mostrar datos
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // Alerta si humedad supera umbral
  if (humedad > 60) {
    Serial.println("⚠️ ¡Humedad alta! Considera secar el filamento.");
  }
}
