const unsigned int salidas = 24;
const unsigned int retardo = 100;
// Declarar una variable para almacenar el índice del arreglo
int indice = 0;
// Definir los pines de salida
const int pins[salidas] = {33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};


unsigned long matrizDestelloRojo[17][2] = {
                            {0b000000000000000000, 0}, // 
                      
                            {0b100100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000000000, 375}, // 
                            {0b100100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000000000, 375}, // 
                            {0b100100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000000000, 375}, // 
                            {0b100100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000000000, 375},
                            {0b100100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000000000, 375}, // 
                            {0b100100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000000000, 375}, // 
                            {0b100100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000000000, 375}, // 
                            {0b100100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000000000, 375}
};

int filasTr = sizeof(matrizDestelloRojo) / sizeof(matrizDestelloRojo[0]);
int columnasTr = sizeof(matrizDestelloRojo[0]) / sizeof(matrizDestelloRojo[0][0]);
/*
unsigned long matrizEjecucion[21][2] = {                  // Programación de 2 Fases
                            {0b000000000000000000, 0},    // 
                            
                            {0b001100000000000000, 24000},// ***Escenario 1***

                            {0b000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b001100000000000000, 375}, // Transición de Verde a Ambar
                            {0b000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b001100000000000000, 375}, // Transición de Verde a Ambar
                            {0b000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b001100000000000000, 375}, // Transición de Verde a Ambar
                            {0b000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b001100000000000000, 375}, // Transición de Verde a Ambar

                            {0b010100000000000000, 3000},// Tiempo de ambar
                            
                            {0b100001000000000000, 24000},// ***Escenario 2***

                            {0b100001000000000000, 375}, // Transición de Verde a Ambar
                            {0b100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100001000000000000, 375}, // Transición de Verde a Ambar
                            {0b100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100001000000000000, 375}, // Transición de Verde a Ambar
                            {0b100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100001000000000000, 375}, // Transición de Verde a Ambar
                            {0b100000000000000000, 375}, // Transición de Verde a Ambar

                            {0b100010000000000000, 3000},// Tiempo de ambar               
};
*/

unsigned long matrizEjecucion[31][2] = {                  // Programación de 3 Fases
                            {0b000000000000000000000000, 0},    // 
                            
                            {0b001100100000000000000000, 60000},// ***Escenario 1***

                            {0b000100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b001100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b000100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b001100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b000100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b001100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b000100100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b001100100000000000000000, 375}, // Transición de Verde a Ambar

                            {0b010100100000000000000000, 3000},// Tiempo de ambar
                            
                            {0b100001100000000000000000, 35000},// ***Escenario 2***

                            {0b100001100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100000100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100001100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100000100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100001100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100000100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100001100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100000100000000000000000, 375}, // Transición de Verde a Ambar

                            {0b100010100000000000000000, 3000},// Tiempo de ambar           

                            {0b100100001000000000000000, 25000},// ***Escenario 3***

                            {0b100100000000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100100001000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100100000000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100100001000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100100000000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100100001000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100100000000000000000000, 375}, // Transición de Verde a Ambar
                            {0b100100001000000000000000, 375}, // Transición de Verde a Ambar

                            {0b100100010000000000000000, 3000}// Tiempo de ambar       
};


int filas1 = sizeof(matrizEjecucion) / sizeof(matrizEjecucion[0]);
int columnas1 = sizeof(matrizEjecucion[0]) / sizeof(matrizEjecucion[0][0]);

unsigned long onOff[36][2] = {
                            {0b000000000000000000, 0}, // 
                      
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, // 
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, // 
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, // 
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, //
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, // 
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, //
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, // 
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, //
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, // 
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, //
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, // 
                            {0b111111111111111111, 375}, // Transición de Verde a Ambar
                            {0b000000000000000000, 375}, //
  							            
};

int filas3 = sizeof(onOff) / sizeof(onOff[0]);
int columnas3 = sizeof(onOff[0]) / sizeof(onOff[0][0]);


byte edo = 0;

//Variable de control del Timer (millis)
unsigned long previousTime = 0;

void setup() {
  Serial.begin(9600);

  initReg(); // Inicializa Registros
  
}

void loop() {

  switch (edo) {
    case 0:
      tiempoReal(&matrizDestelloRojo[0][0],&filasTr, &columnasTr);
      break;
    case 1:
      tiempoReal(&matrizEjecucion[0][0],&filas1, &columnas1);
      //tiempoReal(&onOff[0][0],&filas3, &columnas3);
      break;
    case 2:
      //sec();
      edo = 1;
      break;
    } 
  }

void uint2bin(unsigned long num) {    
    //Serial.println(num, BIN);
    // Convertir el número a binario y enviarlo a los pines de salida
    for (int i = 0; i < salidas; i++) {
      // Obtener el bit i-ésimo del número
      byte bit = ((num >> i) & 1) ^ 0x01; //Niega la salida
      // Escribir el bit en el pin correspondiente
      digitalWrite(pins[i], bit);
      //Serial.println(bit, BIN);
    }
}

// Función de tiempo real
unsigned long tiempoReal(unsigned long *matriz, int *filas, int *columnas){
  //Variable de tiempo actual del timer
  //Revisión de tiempo cumplido
  if ( millis() - previousTime >= (*(matriz + indice * (*columnas) + 1)) ){
    previousTime = millis();

    // Incrementar el índice en uno
    indice++;
    // Si el índice llega al final del arreglo, reiniciarlo a cero
    if (indice != *filas) {
        // Ejecución de la Programación
        uint2bin((*(matriz + indice * (*columnas) + 0)));
    }
    else {
        indice = 0;
        edo++;
    }
  }
}

void sec () {
  unsigned long num = 0x00000001;
  
  for (int i = 0; i <= salidas-1; i++) { //Corrimiento hacia la izquierda
    uint2bin(num);
    
    num = num << 1;
    
    // Esperar un segundo antes de generar otro número
  	delay(retardo);
  }
  
  num = num >> 1;
  
  for (int i = 0; i <= salidas-3; i++) { //Corrimiento hacia la derecha
    num = num >> 1;
    uint2bin(num);
    
    // Esperar un segundo antes de generar otro número
  	delay(retardo);
  } 

  edo = 0;
}

// Inicializa Registros de corrimiento
void initReg() {
  //Designación de  pines del mCU como entrada y salida
  ////////////*Definición de pines como salida*////////////
  // Inicializar los pines de salida como salidas
  for (int i = 0; i < salidas; i++) {
    pinMode(pins[i], OUTPUT);
  }
  
  for (int i = 0; i < salidas; i++) {
    ////////////*Desactivar Registros*////////////////////////
    digitalWrite(pins[i], HIGH);
  }
  
  // Apagado de todas las fases
  //ledWrite(0xff,0xff,0xff,0xff);
  //interfaceProg(EscOff);
}