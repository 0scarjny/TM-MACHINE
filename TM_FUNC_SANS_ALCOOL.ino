// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_COKE)

// *********************************************************************
{ 
      volume =150;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Coca-Cola");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
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
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      // la sortie OUT du capteur est active sur niveau bas
      while (distance>distance_verre) { // objet détecté = niveau 0 sur OUT capteur
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(240,10,0),pixels.Color(128,128,128), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Coca-Cola");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (volume)*rho_cola && paverage()>poid_minimal){
      
      digitalWrite(PUMP7_IN1, LOW);       
      digitalWrite(PUMP7_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP7_IN1, LOW);       
      digitalWrite(PUMP7_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_COKE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
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
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_CRANBERRY)
{
 menu_choix();
 
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      // la sortie OUT du capteur est active sur niveau bas
      while (distance>distance_verre) { // objet détecté = niveau 0 sur OUT capteur
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      }
      pixels.TheaterChase(pixels.Color(200,30,100),pixels.Color(190,10,210), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Jus de Cranberry");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (volume)*rho_cranberry && paverage()>poid_minimal){
      
      digitalWrite(PUMP8_IN1, LOW);       
      digitalWrite(PUMP8_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP8_IN1, LOW);       
      digitalWrite(PUMP8_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_CRANBERRY) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
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
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_ORANGE)
{
 menu_choix();
 
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      // la sortie OUT du capteur est active sur niveau bas
      while (distance>distance_verre) { // objet détecté = niveau 0 sur OUT capteur
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(247,135,0),pixels.Color(255,128,128), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Jus d'Orange");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (volume)*rho_orange && paverage()>poid_minimal){
      
      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_ORANGE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
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
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_SPRITE)
{
 menu_choix();
 
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      // la sortie OUT du capteur est active sur niveau bas
      while (distance>distance_verre) { // objet détecté = niveau 0 sur OUT capteur
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      }
      pixels.TheaterChase(pixels.Color(0,150,130),pixels.Color(0,148,255), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de Sprite");
      
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (volume)*rho_sprite && paverage()>poid_minimal){
      
      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_SPRITE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 150;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_LIME)

// *********************************************************************
{ 
      volume =40;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Jus de citron");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_LIME)
{
 menu_choix();
 
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      // la sortie OUT du capteur est active sur niveau bas
      while (distance>distance_verre) { // objet détecté = niveau 0 sur OUT capteur
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      }
      pixels.TheaterChase(pixels.Color(50,50,130),pixels.Color(70,148,55), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de Jus de");
      lcd.setCursor(0, 1);
      lcd.print("Citron");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (volume)*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_LIME) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 40;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_GRENADINE)

// *********************************************************************
{ 
      volume =40;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Sirop de grenadine");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_GRENADINE)
{
 menu_choix();
 
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      // la sortie OUT du capteur est active sur niveau bas
      while (distance>distance_verre) { // objet détecté = niveau 0 sur OUT capteur
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      }
      pixels.TheaterChase(pixels.Color(0,150,130),pixels.Color(0,148,255), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de Grenadine");
      
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (volume)*rho_grenadine && paverage()>poid_minimal){
      
      digitalWrite(PUMP11_IN1, LOW);       
      digitalWrite(PUMP11_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP11_IN1, LOW);       
      digitalWrite(PUMP11_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_GRENADINE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 40;
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
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      // la sortie OUT du capteur est active sur niveau bas
      while (distance>distance_verre) { // objet détecté = niveau 0 sur OUT capteur
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(240,240,0),pixels.Color(255,12,12), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Arabian Sun");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (1*volume/8)*rho_sprite && paverage()>poid_minimal){
      
      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/8)*rho_sprite) < (6*volume/8)*rho_orange && paverage()>poid_minimal){
      
      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, HIGH);
      Serial.println("Ouvert2");
      pixels.Update();
    
      }

      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((1*volume/8)*rho_sprite)-((6*volume/8)*rho_orange) < (1*volume/8)*rho_grenadine && paverage()>poid_minimal){
      
      digitalWrite(PUMP11_IN1, LOW);       
      digitalWrite(PUMP11_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP11_IN1, LOW);       
      digitalWrite(PUMP11_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_ARABIAN_SUN) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
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
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      // la sortie OUT du capteur est active sur niveau bas
      while (distance>distance_verre) { // objet détecté = niveau 0 sur OUT capteur
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(160,210,250),pixels.Color(150,60,255), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Keep Sober");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (10*volume/21)*rho_sprite && paverage()>poid_minimal){
      
      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((10*volume/21)*rho_sprite) < (1*volume/21)*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert2");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((10*volume/21)*rho_sprite)-((1*volume/21)*rho_lime) < (10*volume/21)*rho_cola && paverage()>poid_minimal){
      
      digitalWrite(PUMP7_IN1, LOW);       
      digitalWrite(PUMP7_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP7_IN1, LOW);       
      digitalWrite(PUMP7_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_KEEP_SOBER) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 315;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
