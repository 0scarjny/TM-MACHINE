
/* ===================================================================== *
 *                                                                       *
 * BACKEND SYSTEM                                                        *
 *                                                                       *
 * ===================================================================== *
 * every "backend function" needs three functions 
 * - void LCDML_BACK_setup(..func_name..)    
 * - void LCDML_BACK_loop(..func_name..)     
 * - void LCDML_BACK_stable(..func_name..)
 *
 * - every BACKEND function can be stopped and started
 * EXAMPLE CODE:
    void LCDML_BACK_setup(LCDML_BACKEND_control)
    {
      // setup
      // is called only if it is started or restartet (reset+start)
    }
    
    boolean LCDML_BACK_loop(LCDML_BACKEND_control)
    {    
      // runs in loop
      
     
      return false;  
    }
    
    void LCDML_BACK_stable(LCDML_BACKEND_control)
    {
      // stable stop
      // is called when a backend function is stopped with stopStable  
    }
 * ===================================================================== *
 */


    
  void LCDML_BACK_setup(LCDML_BACKEND_RAINBOW)
    {
      // setup
      // is called only if it is started or restartet (reset+start)
      pixels.RainbowCycle(3);
    }
    
    boolean LCDML_BACK_loop(LCDML_BACKEND_RAINBOW)
    {    
    pixels.Update(); 
    /* if (digitalRead(18) == LOW) // Button #2 pressed
    {
        // Switch to alternating color wipes on Rings1 and 2
        
        pixels.ActivePattern = CLEARSTRIP;
        pixels.TotalSteps = pixels.numPixels();
        LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
        // And update tbe stick
        
    }
    else // Back to normal operation
    {
        // Restore all pattern parameters to normal values
        
        pixels.ActivePattern = RAINBOW_CYCLE;
        pixels.TotalSteps = 255;
        pixels.Interval = min(10, pixels.Interval);
        // And update tbe stick
        
    }*/
 // g_lcdml_initscreen = millis(); // reset initscreen timer
}  
    
    
    void LCDML_BACK_stable(LCDML_BACKEND_RAINBOW)
    {
      // stable stop
      // is called when a backend function is stopped with stopStable 
       
       
    }
