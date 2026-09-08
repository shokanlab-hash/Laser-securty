// Настройка пинов Raspberry Pi Pico
const int RED_PIN = 12;    // Красный к GP12
const int GREEN_PIN = 11;  // Зеленый к GP11
const int BLUE_PIN = 13;   // Синий к GP13

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

// Функция для создания стандартных цветов
void setColor(int r, int g, int b) {
  digitalWrite(RED_PIN, r);
  digitalWrite(GREEN_PIN, g);
  digitalWrite(BLUE_PIN, b);
}

// Функция для сложных цветов (оранжевый и розовый)
void pulseColor(int r_time, int g_time, int b_time, int duration_ms) {
  int cycles = duration_ms / (r_time + g_time + b_time + 1);
  for (int i = 0; i < cycles; i++) {
    if (r_time > 0) { setColor(1, 0, 0); delayMicroseconds(r_time); }
    if (g_time > 0) { setColor(0, 1, 0); delayMicroseconds(g_time); }
    if (b_time > 0) { setColor(0, 0, 1); delayMicroseconds(b_time); }
  }
}

void loop() {
  // 1. БЕЛЫЙ (Все цвета вместе)
  setColor(1, 1, 1);
  delay(1500);

  // 2. ФИОЛЕТОВЫЙ (Красный + Синий)
  setColor(1, 0, 1);
  delay(1500);

  // 3. ЖЕЛТЫЙ (Красный + Зеленый)
  setColor(1, 1, 0);
  delay(1500);

  // 4. ОРАНЖЕВЫЙ (Много красного + мало зеленого)
  pulseColor(1000, 250, 0, 1500);

  // 5. РОЗОВЫЙ (Много красного + мало синего)
  pulseColor(1000, 0, 400, 1500);

 
}

}

