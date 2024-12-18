/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);
  drawString5x7(20,100, "Te quiero!!!!!!!!!!", COLOR_PINK, COLOR_BLUE);

  // fillRectangle(80,60, 60, 60, COLOR_RED);
  int startX = 55;  // Adjust this value to move horizontally
  int startY = 20;  // Adjust this value to move vertically
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
  fillRectangle(startX - rectSize, startY + 5 * rectSize, 3 * rectSize, rectSize, COLOR_RED);

  fillRectangle(startX - rectSize+5, startY + 6 * rectSize ,2 * rectSize, rectSize, COLOR_RED);
}
