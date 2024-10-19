#include <Adafruit_NeoPixel.h>

#define PIN_NEOPIXEL PC0  // Pin del puerto C para el NeoPixel
#define NUMPIXELS 8       // Número de LEDs en el array Neopixel

Adafruit_NeoPixel strip(NUMPIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

void setup() {
  // Configurar Puerto B (RB0 - RB5) como entradas para los botones
  DDRB = 0x00;  // Puerto B como entrada
  PORTB = 0xFF; // Activar resistencias pull-up en puerto B

  // Configurar Puerto D como salida para los LEDs
  DDRD = 0xFF;  // Puerto D como salida (LEDs)
  PORTD = 0x00; // Inicializar LEDs apagados
  
  // Inicializar NeoPixel
  strip.begin();
  strip.show(); // Inicializar todos los LEDs apagados
}

void loop() {
  // Leer estado de los botones en el Puerto B
  uint8_t botones = PINB;
  
  if (!(botones & (1 << PB0))) {  // Si RB0 está presionado
    encenderBitsPares();           // Encender LEDs pares
  }
  if (!(botones & (1 << PB1))) {  // Si RB1 está presionado
    encenderBitsImpares();         // Encender LEDs impares
  }
  if (!(botones & (1 << PB2))) {  // Si RB2 está presionado
    encenderNeopixel(255, 0, 0);   // Encender color rojo en el Neopixel
  }
  if (!(botones & (1 << PB3))) {  // Si RB3 está presionado
    encenderNeopixel(0, 255, 0);   // Encender color verde en el Neopixel
  }
  if (!(botones & (1 << PB4))) {  // Si RB4 está presionado
    encenderNeopixel(0, 0, 255);   // Encender color azul en el Neopixel
  }
  if (!(botones & (1 << PB5))) {  // Si RB5 está presionado
    encenderNeopixel(255, 255, 255); // Encender color blanco en el Neopixel
  }
}

void encenderBitsPares() {
  PORTD = 0b01010101;  // Encender bits pares (0, 2, 4, 6)
}

void encenderBitsImpares() {
  PORTD = 0b10101010;  // Encender bits impares (1, 3, 5, 7)
}

void encenderNeopixel(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));  // Cambiar color de todos los LEDs
  }
  strip.show();  // Actualizar LEDs
}
