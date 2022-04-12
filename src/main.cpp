/*
  Titre      : Vitesse deplament conduit de déchargement
  Auteur     : Yvan Tankeu
  Date       : 12/04/2022
  Description: examen final, Vitesse deplament conduit de déchargement - Controler MKR1000
  Version    : 0.0.1
*/

// Libraries
#include <Arduino.h>
#include <Keypad.h> // librairie du clavier à télecharger
#include <Wire.h> // Pour la communication I2C

#define peri_addr 9 // Adresse du peripherique I2C qui est le mkr1010

// Constants
#define ROWS 4
#define COLS 4

/*=============Déclaration des broches============*/
// Broches des colones
const uint8_t col_3 = 6;
const uint8_t col_2 = 7;
const uint8_t col_1 = 8;
const uint8_t col_0 = 9;

// Broches des lignes
const uint8_t ligne_3 = 10;
const uint8_t ligne_2 = 11;
const uint8_t ligne_1 = 12;
const uint8_t ligne_0 = 13;

// Touches du clavier
const char keys[COLS][ROWS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

char key;

byte ligneBroches[4] = {ligne_0, ligne_1, ligne_2, ligne_3};
byte colonneBroches[4] = {col_0, col_1, col_2, col_3};

Keypad clavier = Keypad(makeKeymap(keys), ligneBroches, colonneBroches, ROWS, COLS);

void setup()
{
  // Init Serial USB
  Serial.begin(9600);

  // Debute la communication I2C comme un Controleur
  Wire.begin(); 
}

void loop(){

 key = clavier.getKey();
  
  if (key){
    Serial.println(key);
    Wire.beginTransmission(peri_addr); // transmettre au peripherique d'adresse #9
    Wire.write(key);              // envoie la valeur de la touche du clavier
  }
}