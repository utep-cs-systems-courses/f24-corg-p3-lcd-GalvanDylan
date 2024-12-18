#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd_states.h"
#include "buzzer.h"
#include "led.h"

void lcd_start()
{
  clearScreen(COLOR_BLUE);

  drawString5x7(30,50, "Open me!", COLOR_BLACK, COLOR_BLUE);

  u_char width = screenWidth, height = screenHeight;
  // Main body of the envelope as a large white rectangle
  int envelopeX = 5; // X-coordinate start of the envelope
  int envelopeY = 70; // Y-coordinate start of the envelope
  int envelopeWidth = 120; // Width of the envelope

  int envelopeHeight = 60; // Height of the envelope
  fillRectangle(envelopeX, envelopeY, envelopeWidth, envelopeHeight, COLOR_WHITE);

  // Black triangle for the flap (upside down)
  int triangleHeight = (3 * envelopeHeight) / 4; // Height of the triangle is 3/4 the height of the envelope

  // Draw triangle from the top to 3/4 down inside the white rectangle
  for (int row = 0; row < triangleHeight; row++) {
    // Calculate the width of each row of the triangle
    int triangleWidth = envelopeWidth * (triangleHeight - row) / triangleHeight;

    // Calculate the starting x position to center the triangle width within the envelope

    int startX = envelopeX + (envelopeWidth - triangleWidth) / 2;

    // Draw the black line for the current row of the triangle
    fillRectangle(startX, envelopeY + row, triangleWidth, 1, COLOR_BLACK);
  }
}

int lcd_red = 0;


void lcd_siren()

{

  if (lcd_red)

    {

      clearScreen(COLOR_BLACK);//// heart shaped
      drawString5x7(20,100, "VERRR!!! ", COLOR_PINK, COLOR_BLACK);

      int startX = 55; // Adjust this value to move horizontally
      int startY = 20; // Ad just this value to move vertically
      int rectSize = 10; // Size of each rectangle (10x10)

      // Draw top row of the heart (two blocks on each side)
      fillRectangle(startX - 2 * rectSize, startY, rectSize, rectSize, COLOR_RED);
      fillRectangle(startX - rectSize, startY, rectSize, rectSize, COLOR_RED);
      fillRectangle(startX + rectSize, startY, rectSize, rectSize, COLOR_RED);
      fillRectangle(startX + 2 * rectSize, startY, rectSize, rectSize, COLOR_RED);

      // Draw second row of the heart (wider row)
      fillRectangle(startX - 3 * rectSize, startY + rectSize, 7 * rectSize, rectSize, COLOR_RED);

      // Draw third row of the heart (widest row)
      fillRectangle(startX - 4 * rectSize, startY + 2 * rectSize, 9 * rectSize, rectSize, COLOR_RED);
      // Draw fourth row of the heart (narrower row)
      fillRectangle(startX - 3 * rectSize, startY + 3 * rectSize, 7 * rectSize, rectSize, COLOR_RED);

      // Draw fifth row of the heart (narrowest row forming the point)
      fillRectangle(startX - 2 * rectSize, startY + 4 * rectSize, 5 * rectSize, rectSize, COLOR_RED);

      // Draw bottom point of the heart
      fillRectangle(startX - rectSize, startY + 5 * rectSize, 3 * rectSize, rectSize, COLOR_RED) ;

      fillRectangle(startX - rectSize+5, startY + 6 * rectSize ,2 * rectSize, rectSize, COLOR_RED);

      buzzer_set_period(5000);

      lcd_red = 0;
     
    }

  else

    {

      clearScreen(COLOR_RED);//screen changes color
      drawString5x7(20,100, "TE QUIERO", COLOR_PINK, COLOR_RED);

      // fillRectangle(80,60, 60, 60, COLOR_RED);
      int startX = 55; // Adjust this value to move horizontally
      int startY = 20; // Ad just this value to move vertically
      int rectSize = 10; // Size of each rectangle (10x10)

      // Draw top row of the heart (two blocks on each side)
      fillRectangle(startX - 2 * rectSize, startY, rectSize, rectSize, COLOR_BLACK);
      fillRectangle(startX - rectSize, startY, rectSize, rectSize, COLOR_BLACK);
      fillRectangle(startX + rectSize, startY, rectSize, rectSize, COLOR_BLACK);
      fillRectangle(startX + 2 * rectSize, startY, rectSize, rectSize, COLOR_BLACK);

      // Draw second row of the heart (wider row)
      fillRectangle(startX - 3 * rectSize, startY + rectSize, 7 * rectSize, rectSize, COLOR_BLACK);

      // Draw third row of the heart (widest row)
      fillRectangle(startX - 4 * rectSize, startY + 2 * rectSize, 9 * rectSize, rectSize, COLOR_BLACK);
      // Draw fourth row of the heart (narrower row)
      fillRectangle(startX - 3 * rectSize, startY + 3 * rectSize, 7 * rectSize, rectSize, COLOR_BLACK);

      // Draw fifth row of the heart (narrowest row forming the point)
      fillRectangle(startX - 2 * rectSize, startY + 4 * rectSize, 5 * rectSize, rectSize, COLOR_BLACK);

      // Draw bottom point of the heart
      fillRectangle(startX - rectSize, startY + 5 * rectSize, 3 * rectSize, rectSize, COLOR_BLACK) ;

      fillRectangle(startX - rectSize+5, startY + 6 * rectSize ,2 * rectSize, rectSize, COLOR_BLACK);

      
      buzzer_set_period(1000);

      lcd_red = 1;

    }

}



void lcd_siren_update()

{

  static int count = 0;

  count++;

  if (count == 100)

    {

      lcd_siren();

      count = 0;

    }

}
