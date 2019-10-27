// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_COKE)

// *********************************************************************
{ 
      volume =150;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Coca-Cola");
       lcd.setCursor(0, 1);
       lcd.print("Volume:");
       lcd.setCursor(8, 1);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_COKE)
{
 menu_choix();
 
  if(LCDML_BUTTON_checkEnter()) {
      Serial.println(volume);
      detection=digitalRead(capteur); // on lit la broche capteur
      // la sortie OUT du capteur est active sur niveau bas
      while (detection==1) { // objet détecté = niveau 0 sur OUT capteur


      detection=digitalRead(capteur);
      
      verre_manquant();
      
      } 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Coca-Cola");
                 
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < (volume)*rho_cola){
      
      digitalWrite(PUMP7_IN1, LOW);       
      digitalWrite(PUMP7_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }

      digitalWrite(PUMP7_IN1, LOW);       
      digitalWrite(PUMP7_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_COKE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
 
  delay(1000) ;
  volume = 150;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_CRANBERRY)

// *********************************************************************
{ 
      volume =150;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Jus de Cranberry");
       lcd.setCursor(0, 1);
       lcd.print("Volume:");
       lcd.setCursor(8, 1);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_CRANBERRY)
{
 menu_choix();
 
  if(LCDML_BUTTON_checkEnter()) {
      Serial.println(volume);
      detection=digitalRead(capteur); // on lit la broche capteur
      // la sortie OUT du capteur est active sur niveau bas
      while (detection==1) { // objet détecté = niveau 0 sur OUT capteur


      detection=digitalRead(capteur);
      
      verre_manquant();
      
      } 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Jus de Cranberry");
                 
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < (volume)*rho_cranberry){
      
      digitalWrite(PUMP8_IN1, LOW);       
      digitalWrite(PUMP8_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }

      digitalWrite(PUMP8_IN1, LOW);       
      digitalWrite(PUMP8_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_CRANBERRY) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
 
  delay(1000) ;
  volume = 150;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_ORANGE)

// *********************************************************************
{ 
      volume =150;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Jus d'Orange");
       lcd.setCursor(0, 1);
       lcd.print("Volume:");
       lcd.setCursor(8, 1);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_ORANGE)
{
 menu_choix();
 
  if(LCDML_BUTTON_checkEnter()) {
      Serial.println(volume);
      detection=digitalRead(capteur); // on lit la broche capteur
      // la sortie OUT du capteur est active sur niveau bas
      while (detection==1) { // objet détecté = niveau 0 sur OUT capteur


      detection=digitalRead(capteur);
    
      verre_manquant();
      
      } 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Jus d'Orange");
                 
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < (volume)*rho_orange){
      
      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }

      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_ORANGE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
 
  delay(1000) ;
  volume = 150;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_SPRITE)

// *********************************************************************
{ 
      volume =150;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Sprite");
       lcd.setCursor(0, 1);
       lcd.print("Volume:");
       lcd.setCursor(8, 1);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_SPRITE)
{
 menu_choix();
 
  if(LCDML_BUTTON_checkEnter()) {
      Serial.println(volume);
      detection=digitalRead(capteur); // on lit la broche capteur
      // la sortie OUT du capteur est active sur niveau bas
      while (detection==1) { // objet détecté = niveau 0 sur OUT capteur


      detection=digitalRead(capteur);
      verre_manquant();
      
      } 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de Sprite");
      
                 
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < (volume)*rho_orange){
      
      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }

      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_SPRITE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
 
  delay(1000) ;
  volume = 150;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_ARABIAN_SUN)

// *********************************************************************
{ 
      volume =200;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Arabian Sun");
       lcd.setCursor(0, 1);
       lcd.print("1x Sprite 6x Orange");
       lcd.setCursor(0, 2);
       lcd.print("1x Grenadine");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_ARABIAN_SUN)
{
 menu_choix();
 
  if(LCDML_BUTTON_checkEnter()) {
      Serial.println(volume);
      detection=digitalRead(capteur); // on lit la broche capteur
      // la sortie OUT du capteur est active sur niveau bas
      while (detection==1) { // objet détecté = niveau 0 sur OUT capteur


      detection=digitalRead(capteur);
      
      verre_manquant();
      
      } 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Arabian Sun");
                 
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < (1*volume/8)*rho_sprite){
      
      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }

      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/8)*rho_sprite) < (6*volume/8)*rho_orange){
      
      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, HIGH);
      Serial.println("Ouvert2");
      //setColor();
    
      }

      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((1*volume/8)*rho_sprite)-((6*volume/8)*rho_orange) < (1*volume/8)*rho_grenadine){
      
      digitalWrite(PUMP11_IN1, LOW);       
      digitalWrite(PUMP11_IN2, HIGH);
      Serial.println("Ouvert3");
      //setColor();
    
      }

      digitalWrite(PUMP11_IN1, LOW);       
      digitalWrite(PUMP11_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_ARABIAN_SUN) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
 
  delay(1000) ;
  volume = 200;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_KEEP_SOBER)

// *********************************************************************
{ 
      volume =315;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Keep Sober");
       lcd.setCursor(0, 1);
       lcd.print("10x Sprite 1x Lime");
       lcd.setCursor(0, 2);
       lcd.print("10x Coca-Cola");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_KEEP_SOBER)
{
 menu_choix();
 
  if(LCDML_BUTTON_checkEnter()) {
      Serial.println(volume);
      detection=digitalRead(capteur); // on lit la broche capteur
      // la sortie OUT du capteur est active sur niveau bas
      while (detection==1) { // objet détecté = niveau 0 sur OUT capteur


      detection=digitalRead(capteur);
      
      verre_manquant();
      
      } 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Keep Sober");
                 
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < (10*volume/21)*rho_sprite){
      
      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }

      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((10*volume/21)*rho_sprite) < (1*volume/21)*rho_lime){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert2");
      //setColor();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((10*volume/21)*rho_sprite)-((1*volume/21)*rho_lime) < (10*volume/21)*rho_cola){
      
      digitalWrite(PUMP7_IN1, LOW);       
      digitalWrite(PUMP7_IN2, HIGH);
      Serial.println("Ouvert3");
      //setColor();
    
      }

      digitalWrite(PUMP7_IN1, LOW);       
      digitalWrite(PUMP7_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_KEEP_SOBER) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
 
  delay(1000) ;
  volume = 315;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
