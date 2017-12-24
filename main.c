#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "McodeMod.h"
//Code to turn the McodeMod.c translations of Morse code into a blinking light on the BeagleBoneBlack,
//To call this on the terminal, './Mcode -w wordToConvert'.
int main (int argc, char **argv) {
  if(!strcmp(argv[1], "-w") == 0) {
    printf("Please indicate '-w' after calling executable");
    return -1;
  }
  FILE *LEDHandle = NULL;
  const char *LEDBrightness = "/sys/class/leds/beaglebone:green:usr0/brightness";
  printf("%s", argv[2]);
  printf("\n");
  char * inputChar = argv[2];
  int length = strlen(inputChar);
  int i = 0;
  while(i < length) {
    char ic = inputChar[i];
    int charToAscii = (int)ic;
    char *asciiToMorse = mcostring(charToAscii);
    printf("%s", asciiToMorse);
    int lengthOfString = 0;
    while(asciiToMorse[lenghtOfString] != '\0'){
      if(asciiToMorse[lengthOfString] == '.') {
        if((LEDHandle = fopen(LEDBrightness, "+r")) != NULL) {
          fwrite("1", sizeof(char), 1, LEDHandle);
          fclose(LEDHandle);
        }
        usleep(1000000);
        usleep(1000000);
        if((LEDHandle = fopen(LEDBrightness, "+r")) != NULL) {
          fwrite("0", sizeof(char), 1, LEDHandle);
          fclose(LEDHandle);
        }
        usleep(1000000);
      } else {
        if((LEDHandle = fopen(LEDBrightness, "+r")) != NULL) {
          fwrite("1", sizeof(char), 1, LEDHandle);
          fclose(LEDHandle);
        }
        usleep(1000000);
        usleep(1000000);
        usleep(1000000);
        if((LEDHandle = fopen(LEDBrightness, "+r")) != NULL) {
          fwrite("0", sizeof(char), 1, LEDHandle);
          fclose(LEDHandle);
        }
        usleep(1000000);
      }
      lengthOfString++;
   }
   usleep(1000000);
   usleep(1000000);
   usleep(1000000);
   usleep(1000000); 
   i++;
  }
  printf("\n");
  return 0;
}
