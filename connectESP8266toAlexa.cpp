#include <BlynkSimpleEsp8266.h> // inclusão da biblioteca blynk

// Configurando os Comandos de Voz com Alexa via IFTTT
//1. Criar uma Conta no IFTTT

    //Vá para IFTTT e crie uma conta ou faça login.

//2. Configurar um Novo Applet no IFTTT
//Configurando o Comando para Ligar o Roteador

    //Criar um Novo Applet:
        //Clique em "Create" no topo da página para criar um novo applet.

    //Configurar o Trigger (Gatilho):
        //Clique em "If This".
        //Procure por "Alexa" e selecione "Say a specific phrase".
        //Digite a frase que você deseja usar para ligar o roteador, por exemplo, "turn on the router in room 3".
        //Clique em "Create trigger".

    //Configurar a Ação:
        //Clique em "Then That".
        //Procure por "Webhooks" e selecione "Make a web request".
        //Preencha os campos da seguinte maneira:
            //URL: http://blynk-cloud.com/SeuAuthToken/update/V2
            //Method: PUT
            //Content Type: application/json
            //Body: ["1"] (para ligar o roteador)

//Configurando o Comando para Desligar o Roteador

    //Criar um Novo Applet:
        //Clique em "Create" no topo da página para criar um novo applet.

    //Configurar o Trigger (Gatilho):
        //Clique em "If This".
        //Procure por "Alexa" e selecione "Say a specific phrase".
        //Digite a frase que você deseja usar para desligar o roteador, por exemplo, "turn off the router in room 3".
        //Clique em "Create trigger".

    //Configurar a Ação:
        //Clique em "Then That".
        //Procure por "Webhooks" e selecione "Make a web request".
        //Preencha os campos da seguinte maneira:
            //URL: http://blynk-cloud.com/SeuAuthToken/update/V2
            //Method: PUT
            //Content Type: application/json
            //Body: ["0"] (para desligar o roteador)


//Integrando com o ESP8266 e Blynk

char auth[] = "SeuAuthToken"; // token de autenticação Blynk
char ssid[] = "SeuSSID";      // rede Wi-Fi
char pass[] = "SuaSenha";     // senha da rede Wi-Fi

const int ledPin = 5; // pino D1 (GPIO 5)

BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); // faz a leitura do valor do botão virtual V1
  digitalWrite(ledPin, pinValue); // define o estado do LED
}

void setup() {
  Serial.begin(115200);       // inicializa a comunicação serial
  Blynk.begin(auth, ssid, pass); // conecta ao Blynk e Wi-Fi
  pinMode(ledPin, OUTPUT);    // define o pino do LED como saída
  digitalWrite(ledPin, LOW);  // garante que o LED comece apagado
}

void loop() {
  Blynk.run(); // mantém a conexão com o servidor Blynk e processa eventos
}

