//Constantes para el display LCD
#include <LiquidCrystal.h>

//Pin LCD = RS, RW, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(7,8,9,10,11,12,13);
int contraste = 5; //contrastes con PWM

//Conexión del pulsador
int pulsador = 6;

//Conexión del potenciómetro
int potenciometro = 0;

//Secuencia de dígitos
int teclas[10] = {0,1,2,3,4,5,6,7,8,9};

//Variable para dígitos aleatorios
int teclas_tmp[10];

// Variables para almacenar el PIN
int indice_pin = 0;
int pin[4];

void setup() {
  // Inicialización del display LCD 
  pinMode(contraste, OUTPUT); 
  Serial.begin(9600);
  lcd.begin(16,2);
  analogWrite(contraste, 300); 
  lcd.print("PASSWD PIN="); 
  lcd.setCursor(0,1); 
  orden_teclado(); 
  mostrar_teclado();
  // Definición del pulsador
  pinMode(pulsador, INPUT);
}

/*void loop() {
  int tactil=0;
  int teclas_tmp1;

  // Sistema antirrebote: espera 1 seg. 
  delay(1000);

  // Mientras no se active el pulsador, se 
  // calcula la posición del cursor a través 
  // del valor del potenciómetro. 103
  // equivale a 1024 (máximo valor
  // recibido) /10 (número de dígitos en la // fila)
  while (digitalRead(pulsador) == LOW) {
    tactil = (int) analogRead(A0)/103;
    Serial.println(analogRead(A5));
    lcd.setCursor(tactil,1);
    // Identificar la posición del cursor con un 
    // parpadeo
    lcd.blink();
  }

  // Evitar el parpadeo en una zona del LCD 
  // diferente al teclado
  lcd.noBlink();

  // Al activar el pulsador, se almacena el 
  // dígito seleccionado en teclas_tmp1 
  teclas_tmp1 = teclas_tmp[tactil];

  // Se almacena teclas_tmp1 en la posición 
  // correcta del número PIN.
  //El PIN tendrá cuatro dígitos.
  // La quinta activación del pulsador genera 
  // la introducción de un nuevo PIN,
  // sobreescribiendo el anerior 
  if (indice_pin < 4) {
    pin[indice_pin] = teclas_tmp1; 
    indice_pin++;
    mostrar_pin(); 
    lcd.setCursor(0,1); 
    orden_teclado();
    mostrar_teclado();
  } else {
    indice_pin=0; 
    lcd.setCursor(11,0); 
    lcd.print(" ");
  }
  //leer_teclado(teclas_tmp1);


}*/

// Función para leer un solo dígito del teclado
int leer_digito() {
  int tactil = 0;
  // Esperar 1 seg. como antirrebote
  delay(1000);
  // Leer el valor del potenciómetro y convertirlo en un dígito
  while (digitalRead(pulsador) == LOW) {
    tactil = (int) analogRead(A0) / 103;
    Serial.println(analogRead(A5));
    lcd.setCursor(tactil, 1);
    // Identificar la posición del cursor con un parpadeo
    lcd.blink();
  }
  // Evitar el parpadeo en una zona del LCD diferente al teclado
  lcd.noBlink();
  // Obtener el dígito seleccionado y devolverlo
  int tecla = teclas_tmp[tactil];
  return tecla;
}

// Función para almacenar un dígito en el PIN
void almacenar_digito(int digito) {
  if (indice_pin < 4) {
    pin[indice_pin] = digito;
    indice_pin++;
    mostrar_pin();
    lcd.setCursor(0, 1);
    orden_teclado();
    mostrar_teclado();
  } else {
    indice_pin = 0;
    lcd.setCursor(11, 0);
    lcd.print(" ");
  }
}

void loop() {
  int tecla = leer_digito(); // Leer el primer dígito del teclado
  almacenar_digito(tecla); // Almacenar el dígito en el PIN
}


// Función que reordena aleatoriamente los 
// dígitos del teclado. En la aleatoriedad se 
// evita que se coloque un mismo dígito más 
// de una vez
void orden_teclado() 
{ 
  bool usado[10];
  int index=0;
  int indice=0;
  int k=0;
  for (int i=0; i < 10; i++) {
    usado[i] = false;
  }
  for (int i=0; i < 10; i++) {
    index = (rand() % (10-i)); 
    indice = 0;
    k = 0;
    for (int j=0; j < 10; j++) { 
      if (k <= index) {
        if (!usado[j]) { 
          k++;
        }
        indice=j;
      }
    }
    teclas_tmp[i] = teclas[indice];
    usado[indice] = true;
  }
}

// Función que muestra el teclado aleatorio 
// en el display LCD
void mostrar_teclado() {
  for (int i=0; i < 10; i++) {
    char tmp1[10];
    sprintf(tmp1, "%d", teclas_tmp[i]); 
    lcd.print(tmp1);
  } 
}

// Función que muestra el número PIN en el 
// display LCD
void mostrar_pin() {
  char tmp1[10]; 
  lcd.setCursor(7,0); 
  lcd.print("PIN=");
  for (int i=0; i < indice_pin; i++) {
    sprintf(tmp1, "%d", pin[i]); 
    lcd.setCursor(11+i, 0); 
    lcd.print(tmp1);
  }
}