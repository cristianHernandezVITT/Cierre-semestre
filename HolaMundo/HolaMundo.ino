/*
  Programa: Control de Raspberry Pi Pico W
  Autor: [Tu Nombre]
  Fecha: [Fecha de creación]

  Descripción:
  Este programa inicializa la comunicación serial en una Raspberry Pi Pico W y envía un mensaje de bienvenida.
  Posteriormente, entra en un bucle infinito donde puede agregar más funcionalidades.

  Licencia: [Tipo de licencia]
*/

#include <Arduino.h>

void setup() {
  // Inicializa la comunicación serial a 115200 baudios.
  Serial.begin(115200);
  
  // Envía un mensaje de bienvenida.
  Serial.println("Hola, Raspberry Pi Pico W!");

  // Configuraciones adicionales aquí.
}

void loop() {
  // Código principal que se ejecuta repetidamente.
while(Serial.available() > 0){

String cadena = Serial.readStringUntil('\n');
cadena = cadena.substring(0,cadena.length());
Serial.println(cadena);
}
  // Por ejemplo, podrías agregar lógica para leer sensores, controlar actuadores, etc.

  // Retraso mínimo para evitar saturar el bucle.
  delay(1000);
}