// Deklarasi pin untuk sensor IR
const int sensor1 = A0;
const int sensor2 = A1;
const int sensor3 = A2;
const int sensor4 = A3;
const int sensor5 = A4;

void setup() {
  // Memulai komunikasi serial pada baud rate 9600
  Serial.begin(9600);

  // Mengatur pin sensor IR sebagai input
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
}

void loop() {
  // Membaca nilai dari masing-masing sensor
  int nilaiSensor1 = analogRead(sensor1);
  int nilaiSensor2 = analogRead(sensor2);
  int nilaiSensor3 = analogRead(sensor3);
  int nilaiSensor4 = analogRead(sensor4);
  int nilaiSensor5 = analogRead(sensor5);

  // Menampilkan nilai sensor di Serial Monitor
  Serial.print("Sensor 1: ");
  Serial.print(nilaiSensor1);
  Serial.print("\t Sensor 2: ");
  Serial.print(nilaiSensor2);
  Serial.print("\t Sensor 3: ");
  Serial.print(nilaiSensor3);
  Serial.print("\t Sensor 4: ");
  Serial.print(nilaiSensor4);
  Serial.print("\t Sensor 5: ");
  Serial.println(nilaiSensor5);

  // Menunggu sebentar sebelum mengulangi loop
  delay(500);
}
