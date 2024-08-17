#include <FastBot.h>

#define WIFI_SSID "SSID NAME" // Замените на имя вашей сети WiFi
#define WIFI_PASS "password" // Замените на пароль вашей сети WiFi
#define BOT_TOKEN "your_bot_token" // Замените на токен вашего бота 
#define CHAT_ID "123456789" // Замените на ID чата, в котором бот будет работать

#define red 5
#define green 18
#define blue 19

FastBot bot(BOT_TOKEN);         //Инициализируем бота

void setup() {
  // Настраиваем ПИНЫ
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  // Подключаемся к WiFi
  connectWiFi();
  delay(1000);

  // Устанавливаем ID чата
  bot.setToken(BOT_TOKEN);
  bot.setChatID(CHAT_ID); 
  bot.skipUpdates();
  bot.sendMessage("Я в сети!"); 
  bot.attach(Telegrambot);
}

void Telegrambot(FB_msg& msg) {
  if (msg.text == "/free"){
    bot.sendMessage("Подземелье открыто)");
    analogWrite(green, 150);
    analogWrite(blue, 0);
    analogWrite(red, 0);
  } 
  if (msg.text == "/bored"){
    bot.sendMessage("Прошу что бы не отвлекали)");
    analogWrite(red, 150);
    analogWrite(green, 0);
    analogWrite(blue, 0);
  }
  if (msg.text == "/sleep"){
    bot.sendMessage("Доброй ночи:3");
    analogWrite(blue, 150);
    analogWrite(green, 0);
    analogWrite(red, 0);
  } 
}

void loop() {
  bot.tick();
}


void connectWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);   
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED){ 
    Serial.print(".");
    analogWrite(red, 255);
    delay(25);
    analogWrite(red, 0);
  } 
}
