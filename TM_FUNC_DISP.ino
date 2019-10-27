/* ===================================================================== *
 *                                                                       *
 * DISPLAY SYSTEM                                                        *
 *                                                                       *
 * ===================================================================== *
 * every "disp menu function" needs three functions 
 * - void LCDML_DISP_setup(func_name)    
 * - void LCDML_DISP_loop(func_name)     
 * - void LCDML_DISP_loop_end(func_name)
 *
 * EXAMPLE CODE:
    void LCDML_DISP_setup(..menu_func_name..) 
    {
      // setup
      // is called only if it is started

      // starts a trigger event for the loop function every 100 millisecounds
      LCDML_DISP_triggerMenu(100);  
    }
    
    void LCDML_DISP_loop(..menu_func_name..)
    { 
      // loop
      // is called when it is triggert
      // - with LCDML_DISP_triggerMenu( millisecounds ) 
      // - with every button status change

      // check if any button is presed (enter, up, down, left, right)
      if(LCDML_BUTTON_checkAny()) {         
        LCDML_DISP_funcend();
      } 
    }
    
    void LCDML_DISP_loop_end(..menu_func_name..)
    {
      // loop end
      // this functions is ever called when a DISP function is quit
      // you can here reset some global vars or do nothing  
    } 
 * ===================================================================== *
 */
/*
// *********************************************************************
unsigned long g_initscreen_example_counter = 0;
void LCDML_DISP_setup(LCDML_FUNC_initscreen)
// *********************************************************************
{
  // setup function
  LCDML_DISP_triggerMenu(1000); // set trigger for this function to 1000 millisecounds
  lcd.print(F("InitScreen"));  // print first line to lcd display
  g_initscreen_example_counter = 0; // reset or set example counter
}

void LCDML_DISP_loop(LCDML_FUNC_initscreen) 
{
  // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
  // the quit button works in every DISP function without any checks; it starts the loop_end function 
  g_initscreen_example_counter++; // count the example counter above
  lcd.setCursor(0,1); // clear the secound line on lcd 
  lcd.print(F("      "));
  lcd.setCursor(0,1); // print new value to lcd
  lcd.print(g_initscreen_example_counter);
  
  g_lcdml_initscreen = millis(); // reset initscreen timer
  
  if(LCDML_BUTTON_checkAny()) { // check if any button is pressed to left this function
    LCDML_DISP_funcend(); // function end    
  }   
}

void LCDML_DISP_loop_end(LCDML_FUNC_initscreen) 
{  
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
  LCDML.goRoot(); // go to root element (first element of this menu with id=0)
}

*/
// **********************************************************************
void setColor()
// **********************************************************************
{
  redColor = random(20, 200);
  greenColor = random(20,200);
  blueColor = random(20, 200);
  redColor2 = random(0, 255);
  greenColor2 = random(0,255);
  blueColor2 = random(0, 255);



  for (int i=0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
    //pixels.setPixelColor(i-, pixels.Color(redColor2, greenColor2, blueColor2));
    // This sends the updated pixel color to the hardware.
    pixels.show();

    // Delay for a period of time (in milliseconds).
    //delay(delayval);
 
  }

}
// *********************************************************************
//unsigned long g_initscreen_example_counter = 0;
void LCDML_DISP_setup(LCDML_FUNC_initscreen)
// *********************************************************************
{
  // setup function
  LCDML_DISP_triggerMenu(1000); // set trigger for this function to 1000 millisecounds
 
  lcd.setCursor(0, 0);
  lcd.print("Cocktails fait:");
  lcd.setCursor(0, 1);
  lcd.print(total_cocktail);
  LCDML_BACK_start(LCDML_BACKEND_RAINBOW);
}
// uint8_t gHue = 0; // rotating "base color" used by many of the patterns
void LCDML_DISP_loop(LCDML_FUNC_initscreen) 
{
 if(LCDML_BUTTON_checkAny()){
  LCDML_DISP_funcend();
 }

}

void LCDML_DISP_loop_end(LCDML_FUNC_initscreen) 
{  
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
  pixels.clear();
  pixels.show();
  LCDML.goRoot(); // go to root element (first element of this menu with id=0)
  LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
  //pixels.clear();
  //pixels.show();
}


// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_BALANCE)
// *********************************************************************
{
  // setup function
 
  
  
}
// uint8_t gHue = 0; // rotating "base color" used by many of the patterns
void LCDML_DISP_loop(LCDML_FUNC_BALANCE) 
{
lcd.setCursor(0, 0);
lcd.print("Masse:");
lcd.setCursor(0, 1);
lcd.print(paverage());
if (paverage()<100){
  lcd.print("          ");
  lcd.setCursor(4, 1);
}
else {
  lcd.print("          ");
  lcd.setCursor(5, 1);
}
lcd.print("g");
delay(50);

}

void LCDML_DISP_loop_end(LCDML_FUNC_BALANCE) 
{  
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
  
}





// *********************************************************************
float paverage() 
// *********************************************************************  
{
  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1); //scale.get_units() returns a float
  Serial.print(" g"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.println();
  //float mass =scale.get_units(); 
  return scale.get_units();
  delay(50);
  
  }

// **********************************************************************
void setColorred()
// **********************************************************************
{


  for (int i=0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));

    // This sends the updated pixel color to the hardware.
   // pixels.show();

    // Delay for a period of time (in milliseconds).
    //delay(15);
  }
      pixels.show();
}
// **********************************************************************
void boisson_prete()
// **********************************************************************
{
      Serial.println("Fermé"); 
      total_cocktail++;     
      detection=digitalRead(capteur); // on lit la broche capteur
      // la sortie OUT du capteur est active sur niveau bas
      while (detection==0) { // objet détecté = niveau 0 sur OUT capteur


      detection=digitalRead(capteur);
      
      lcd.clear();      
      lcd.setCursor(0, 0);
      lcd.print(F("LA BOISSON EST PRETE")); 
     
      Serial.println("COCKTAIL IS READY");
      setColor();
      delay(50);
      pixels.clear();
      pixels.show();
      delay(50);
      }
}

//****************************************************************************
void menu_choix()
//****************************************************************************
{
  if (LCDML_BUTTON_checkAny()) // check if any button is pressed (enter, up, down, left, right)
  {
    if (LCDML_BUTTON_checkLeft()) 
      {
      LCDML_BUTTON_resetLeft(); // reset  
      volume = volume - 5;
      if(volume<0){
        volume = 0;
      }
       lcd.setCursor(8, 3);
       lcd.print("      ");

       
       if (volume< 100){
         lcd.setCursor(8, 3);
         lcd.print(volume);        
         lcd.setCursor(10, 3);
         lcd.print("ml");       
       }
       
       else{
         lcd.setCursor(8, 3);
         lcd.print(volume);
         lcd.setCursor(11, 3);
         lcd.print("ml");        
       }
      }    

    if (LCDML_BUTTON_checkRight()) 
      {
      LCDML_BUTTON_resetRight(); // reset
      LCDML_BUTTON_resetDown(); // reset 
      volume = volume + 5;
      
      if(volume>300){
        volume = 300;
      }
       lcd.setCursor(8, 3);
       lcd.print("     ");

      }
       if (volume< 100){
         lcd.setCursor(8, 3);
         lcd.print(volume);        
         lcd.setCursor(10, 3);
         lcd.print("ml");       
       }
       
       else{
         lcd.setCursor(8, 3);
         lcd.print(volume);
         lcd.setCursor(11, 3);
         lcd.print("ml");        
       }
  }
}

//****************************************************************************
void verre_manquant()
//****************************************************************************
{
      lcd.clear();      
      lcd.setCursor(0, 0);
      lcd.print(F("VERRE MANQUANT")); 
     
      Serial.println("ERROR");
      setColorred();
      delay(50);
      pixels.clear();
      pixels.show();
      delay(50);
}
