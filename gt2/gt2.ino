/***************************************************
  Adafruit HX8357D Breakout
  ----> http://www.adafruit.com/products/2050
 ****************************************************/

#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"

// CLK connects to SPI clock. On Mega's, its Digital 52
// MISO connects to SPI MISO. On Mega's, its Digital 50
// MOSI connects to SPI MOSI. On Mega's, its Digital 51
//
// These are 'flexible' lines that can be changed
// CS connects to our SPI Chip Select pin. We'll be using Digital 10
// D/C connects to our SPI data/command select pin. We'll be using Digital 9
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8 // RST can be set to -1 if you tie it to Arduino's reset

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);

// SoftSPI - note that on some processors this might be *faster* than hardware SPI!
//Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, MOSI, SCK, TFT_RST, MISO);

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


void setup() {
  Serial.begin(9600);
  delay(50);
  tft.begin();
  // rotation 1 is landscape with SPI pins on right side
  tft.setRotation(1);

}


void loop(void) {
  testText();
  delay(100);
  tft.fillScreen(HX8357_BLACK);
  tft.setTextColor(WHITE, BLACK);
  testRects(GREEN);
}


unsigned long testText() {
  tft.fillScreen(HX8357_BLACK);
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextColor(HX8357_WHITE);  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(HX8357_YELLOW); tft.setTextSize(2);
  tft.println(1234.56);
  tft.setTextColor(HX8357_RED);    tft.setTextSize(3);
  tft.println(0xDEADBEEF, HEX);
  tft.println();
  tft.setTextColor(HX8357_GREEN);
  tft.setTextSize(5);
  tft.println("OMG LOL");
  tft.setTextSize(2);
  tft.println("I implore thee,");
  tft.setTextSize(1);
  tft.println("my foonting turlingdromes.");
  tft.println("And hooptiously drangle me");
  tft.println("with crinkly bindlewurdles,");
  tft.println("Or I will rend thee");
  tft.println("in the gobberwarts");
  tft.println("with my blurglecruncheon,");
  tft.println("see if I don't!");
  
  tft.setTextColor(HX8357_WHITE);
  tft.println(F("Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, 'and what is the use of a book,' thought Alice 'without pictures or conversations?'"));

tft.println(F("So she was considering in her own mind (as well as she could, for the hot day made her feel very sleepy and stupid), whether the pleasure of making a daisy-chain would be worth the trouble of getting up and picking the daisies, when suddenly a White Rabbit with pink eyes ran close by her."));

tft.println(F("There was nothing so very remarkable in that; nor did Alice think it so very much out of the way to hear the Rabbit say to itself, 'Oh dear! Oh dear! I shall be late!' (when she thought it over afterwards, it occurred to her that she ought to have wondered at this, but at the time it all seemed quite natural); but when the Rabbit actually took a watch out of its waistcoat-pocket, and looked at it, and then hurried on, Alice started to her feet, for it flashed across her mind that she had never before seen a rabbit with either a waistcoat-pocket, or a watch to take out of it, and burning with curiosity, she ran across the field after it, and fortunately was just in time to see it pop down a large rabbit-hole under the hedge."));

tft.println(F("In another moment down went Alice after it, never once considering how in the world she was to get out again."));

tft.println(F("The rabbit-hole went straight on like a tunnel for some way, and then dipped suddenly down, so suddenly that Alice had not a moment to think about stopping herself before she found herself falling down a very deep well."));

tft.println(F("Either the well was very deep, or she fell very slowly, for she had plenty of time as she went down to look about her and to wonder what was going to happen next. First, she tried to look down and make out what she was coming to, but it was too dark to see anything; then she looked at the sides of the well, and noticed that they were filled with cupboards and book-shelves; here and there she saw maps and pictures hung upon pegs. She took down a jar from one of the shelves as she passed; it was labelled 'ORANGE MARMALADE', but to her great disappointment it was empty: she did not like to drop the jar for fear of killing somebody, so managed to put it into one of the cupboards as she fell past it."));
  
  return micros() - start;
}

unsigned long testRects(uint16_t color) {
  // left side
  tft.fillScreen(HX8357_BLACK);
  tft.drawRect(20, 20, 100, 100, color);
  // right side
  tft.drawRect(360, 20, 100, 100, color);
  tft.setTextColor(WHITE);
  tft.setCursor(24, 24);
  tft.setTextSize(3);
  tft.println("L Fan");
  tft.setCursor(364, 24);
  tft.println("R Fan");
  tft.setTextSize(5);
  tft.setTextColor(RED, BLACK);
  tft.setCursor(24, 74);
  tft.println("OFF");
  tft.setCursor(364, 74);
  tft.println("OFF");
  delay(1000);
  tft.fillRect(24, 74, 85, 40, BLACK);
  tft.fillRect(364, 74, 85, 40, BLACK);
  tft.setTextColor(WHITE, BLACK);
  for (int i = 0; i <= 42; i++) {
    tft.setTextSize(5);
    tft.setCursor(36, 74);
    tft.println(i);
    tft.setCursor(376, 74);
    tft.println(i);
    delay(60);
  }
  tft.setTextColor(YELLOW, BLACK);
  tft.setTextSize(5);
  tft.setCursor(24, 74);
  tft.println("MAX");
  tft.setCursor(364, 74);
  tft.println("MAX");

  delay(2000);
}

unsigned long testFilledRects(uint16_t color1, uint16_t color2) {
  unsigned long start, t = 0;
  int           n, i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(HX8357_BLACK);
  n = min(tft.width(), tft.height());
  for(i=n; i>0; i-=6) {
    i2    = i / 2;
    start = micros();
    tft.fillRect(cx-i2, cy-i2, i, i, color1);
    t    += micros() - start;
    // Outlines are not included in timing results
    tft.drawRect(cx-i2, cy-i2, i, i, color2);
  }

  return t;
}

unsigned long testFilledCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int x, y, w = tft.width(), h = tft.height(), r2 = radius * 2;

  tft.fillScreen(HX8357_BLACK);
  start = micros();
  for(x=radius; x<w; x+=r2) {
    for(y=radius; y<h; y+=r2) {
      tft.fillCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

unsigned long testCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int           x, y, r2 = radius * 2,
                w = tft.width()  + radius,
                h = tft.height() + radius;

  // Screen is not cleared for this one -- this is
  // intentional and does not affect the reported time.
  start = micros();
  for(x=0; x<w; x+=r2) {
    for(y=0; y<h; y+=r2) {
      tft.drawCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

unsigned long testTriangles() {
  unsigned long start;
  int           n, i, cx = tft.width()  / 2 - 1,
                      cy = tft.height() / 2 - 1;

  tft.fillScreen(HX8357_BLACK);
  n     = min(cx, cy);
  start = micros();
  for(i=0; i<n; i+=5) {
    tft.drawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      tft.color565(200, 20, i));
  }

  return micros() - start;
}

unsigned long testFilledTriangles() {
  unsigned long start, t = 0;
  int           i, cx = tft.width()  / 2 - 1,
                   cy = tft.height() / 2 - 1;

  tft.fillScreen(HX8357_BLACK);
  start = micros();
  for(i=min(cx,cy); i>10; i-=5) {
    start = micros();
    tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(0, i, i));
    t += micros() - start;
    tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(i, i, 0));
  }

  return t;
}

unsigned long testRoundRects() {
  unsigned long start;
  int           w, i, i2,
                cx = tft.width()  / 2 ,
                cy = tft.height() / 2 ;

  tft.fillScreen(HX8357_BLACK);
  w     = min(tft.width(), tft.height());
  start = micros();
  for(i=0; i<w; i+=8) {
    i2 = i / 2 - 2;
    tft.drawRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(i, 100, 100));
  }

  return micros() - start;
}

unsigned long testFilledRoundRects() {
  unsigned long start;
  int           i, i2,
                cx = tft.width()  / 2 + 10,
                cy = tft.height() / 2 + 10;

  tft.fillScreen(HX8357_BLACK);
  start = micros();
  for(i=min(tft.width(), tft.height()) - 20; i>25; i-=6) {
    i2 = i / 2;
    tft.fillRoundRect(cx-i2, cy-i2, i-20, i-20, i/8, tft.color565(100, i/2, 100));
  }

  return micros() - start;
}
