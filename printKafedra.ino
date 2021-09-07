// библиотека для работы с матрицей
#include <RGBmatrixPanel.h>
// установите и скачайте также библиотеку «Adafruit GFX Library»
// «RGBmatrixPanel» наследуется от «Adafruit GFX Library»

// управляющие пины матрицы
#define CLK   11
#define OE    9
#define LAT   10
#define A     A0
#define B     A1
#define C     A2
#define D     A3

// объявляем объект для работы с матрицей 64х32
// включаем двойную буферизацию
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);

// выводимая строка на матрицу
const char textStr[] = "Hello, World!";
// переменная с X-координатой текста
int textX = matrix.width();

// минимальное значение координаты текста
// количество символов в строке умноженное на ширину одного символа,
// после которой текст начнёт повторно выводиться
int textMin = sizeof(textStr) * -6;                  

void setup() {
  randomSeed(analogRead(A5));
  // инициируем работу с матрицей
  matrix.begin();
  // отключаем перенос текста на следующую строку
  matrix.setTextWrap(false);
  // устанавливаем размер текста
  matrix.setTextSize(1);
  // очищаем экран
  matrix.fillScreen(0);
  // выставляем курсор
  matrix.setCursor(6, 2);
  // устанавливаем цвет
  matrix.setTextColor(matrix.Color888(255, 165, 0));
  // печатаем первую строку
  matrix.println("SPbSUT)))");
  // выставляем курсор
  matrix.setCursor(20, 12);
  // устанавливаем цвет
  matrix.setTextColor(matrix.Color888(0, 0, 255));
  // печатаем первую строку
  matrix.println("ISiT");
  // выставляем курсор
  matrix.setCursor(23, 22);
  // устанавливаем цвет
  matrix.setTextColor(matrix.Color888(255, 0, 0));
  // выводимая вторая строка
  matrix.print("I");
  matrix.setTextColor(matrix.Color888(0, 255, 0));
  matrix.print("K");
  matrix.setTextColor(matrix.Color888(0, 0, 255));
  matrix.print("D");
  // выводим текст из буфера на матрицу
  matrix.swapBuffers(false);
}

void loop() {
}
