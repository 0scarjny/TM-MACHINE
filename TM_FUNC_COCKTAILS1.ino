// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_BLUE_LAGOON)

// *********************************************************************
{ 
       volume = 225;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Blue Lagoon:");
       lcd.setCursor(0, 1);
       lcd.print("2x Vodka 1x Curacao");
       lcd.setCursor(0, 2);
       lcd.print("6x Limonade");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_BLUE_LAGOON)
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
      
      
      pixels.TheaterChase(pixels.Color(120,255,255), pixels.Color(0,0,255), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1);
      lcd.print("Blue Lagoon ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (1*volume/9)*rho_curacao && paverage()>poid_minimal){
      
      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/9)*rho_curacao) < (2*volume/9)*rho_vodka && paverage()>poid_minimal){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((1*volume/9)*rho_curacao)-((2*volume/9)*rho_vodka) < (6*volume/9)*rho_sprite && paverage()>poid_minimal){
      
      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_BLUE_LAGOON) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
  
  delay(100) ;
  volume = 225;
  g_lcdml_initscreen = millis(); // reset initscreen timer
  

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_WOOWOO)

// *********************************************************************
{      
       volume = 165;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Woo Woo:");
       lcd.setCursor(0, 1);
       lcd.print("2x Vodka 2x Peche");
       lcd.setCursor(0, 2);
       lcd.print("7x Cranberry");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_WOOWOO)
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
      pixels.TheaterChase(pixels.Color(230,16,64), pixels.Color(150,16,60), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1);
      lcd.print("Woo Woo ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (2*volume/11)*rho_liqueur_peche && paverage()>poid_minimal){
      
      digitalWrite(PUMP13_IN1, LOW);      
      digitalWrite(PUMP13_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP13_IN1, LOW);      
      digitalWrite(PUMP13_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((2*volume/11)*rho_liqueur_peche) < (2*volume/1)*rho_vodka && paverage()>poid_minimal){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((2*volume/11)*rho_liqueur_peche)-((2*volume/11)*rho_vodka) < (7*volume/11)*rho_cranberry && paverage()>poid_minimal){
      
      digitalWrite(PUMP8_IN1, LOW);       
      digitalWrite(PUMP8_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP8_IN1, LOW);       
      digitalWrite(PUMP8_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_WOOWOO) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
  
  delay(100) ;
  volume = 165;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_BELLES)

// *********************************************************************
{ 
       
       volume = 102;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Belles Of St Mary's:");
       lcd.setCursor(0, 1);
       lcd.print("6x Gin 5x Abricot");
       lcd.setCursor(0, 2);
       lcd.print("5x Cointr. 1x Lime");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_BELLES)
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
      pixels.TheaterChase(pixels.Color(230,16,64), pixels.Color(110,0,80), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1);
      lcd.print("Belles Of St Mary's ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (5*volume/17)*rho_liqueur_brandy && paverage()>poid_minimal){
      
      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((5*volume/17)*rho_liqueur_brandy) < (6*volume/17)*rho_gin && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((5*volume/17)*rho_liqueur_brandy)-((6*volume/17)*rho_gin) < (5*volume/17)*rho_cointreau && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_BELLES) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
  
  delay(1000) ;
  volume = 102;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_TOJO)

// *********************************************************************
{ 
       
       volume = 60;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Tojo:");
       lcd.setCursor(0, 1);
       lcd.print("1x Gin,1x Brandy");
       lcd.setCursor(0, 2);
       lcd.print("1x Cointreau");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_TOJO)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(255,255,0), pixels.Color(255,255,120), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(3, 1);
      lcd.print("Tojo ");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (1*volume/3)*rho_gin && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/3)*rho_gin) < ((1*volume/3)*rho_liqueur_brandy) && paverage()>poid_minimal){
      
      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((1*volume/3)*rho_gin)-((1*volume/3)*rho_liqueur_brandy) < ((1*volume/3)*rho_cointreau) && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);
      
      Serial.println("Fermé3"); 
      
      while(paverage()-verre1-((1*volume/3)*rho_gin)-((1*volume/3)*rho_liqueur_brandy)-((1*volume/3)*rho_cointreau) < ((1*volume/60)*rho_lime) && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      Serial.println("Fermé 4");      
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_TOJO) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(1000) ;
  volume = 60;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_EXPLORER)

// *********************************************************************
{ 
       
       volume = 60;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Explorer:");
       lcd.setCursor(0, 1);
       lcd.print("2x Vodka 1x Curacao");
       lcd.setCursor(0, 2);
       lcd.print("1x Cointreau");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_EXPLORER)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(200,255,0), pixels.Color(240,200,60), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml d'  ");
      lcd.setCursor(3, 1);
      lcd.print("Explorer ");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (2*volume/4)*rho_vodka){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((2*volume/4)*rho_vodka) < ((1*volume/4)*rho_curacao) && paverage()>poid_minimal){
      
      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((2*volume/4)*rho_vodka)-((1*volume/4)*rho_curacao) < ((1*volume/4)*rho_cointreau) && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);
      
      Serial.println("Fermé3"); 
         
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_EXPLORER) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing  
      
  
  delay(1000) ;
  volume = 60;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_INK_MARTINI)

// *********************************************************************
{      
       volume = 130;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Ink Martini:");
       lcd.setCursor(0, 1);
       lcd.print("3x Curacao 3x Peche");
       lcd.setCursor(0, 2);
       lcd.print("8x Gin 12x Cranb.");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_INK_MARTINI)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(255,255,255),pixels.Color(60,60,60), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(3, 1);
      lcd.print("Ink Martini ");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < ((8*volume/26)*rho_gin) && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((8*volume/26)*rho_gin) < ((3*volume/26)*rho_liqueur_peche) && paverage()>poid_minimal){
      
      digitalWrite(PUMP13_IN1, LOW);       
      digitalWrite(PUMP13_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP13_IN1, LOW);       
      digitalWrite(PUMP13_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((8*volume/26)*rho_gin)-((3*volume/26)*rho_liqueur_peche) < ((3*volume/26)*rho_curacao) && paverage()>poid_minimal){
      
      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, LOW);
      
      Serial.println("Fermé3"); 
      
      while(paverage()-verre1-((8*volume/26)*rho_gin)-((3*volume/26)*rho_liqueur_peche)-((3*volume/26)*rho_curacao) < ((12*volume/26)*rho_cranberry) && paverage()>poid_minimal){
      
      digitalWrite(PUMP8_IN1, LOW);       
      digitalWrite(PUMP8_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP8_IN1, LOW);       
      digitalWrite(PUMP8_IN2, LOW);
      Serial.println("Fermé 4");      
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_INK_MARTINI) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing 

  
  delay(1000) ;
  volume = 130;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_ICE_BEAR)

// *********************************************************************
{ 
       
       volume = 240;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Explorer:");
       lcd.setCursor(0, 1);
       lcd.print("1x Vodka 1x Curacao");
       lcd.setCursor(0, 2);
       lcd.print("10x Sprite");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_ICE_BEAR)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      }
      pixels.TheaterChase(pixels.Color(0,255,222),pixels.Color(0,0,255), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml d'  ");
      lcd.setCursor(3, 1);
      lcd.print("Ice Bear ");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (1*volume/12)*rho_vodka && paverage()>poid_minimal){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/12)*rho_vodka) < ((1*volume/12)*rho_curacao) && paverage()>poid_minimal){
      
      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((1*volume/12)*rho_vodka)-((1*volume/12)*rho_curacao) < ((10*volume/12)*rho_sprite) && paverage()>poid_minimal){
      
      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, LOW);
      
      Serial.println("Fermé3"); 
         
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_ICE_BEAR) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 240;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_APRICOT)

// *********************************************************************
{ 
       
       volume = 80;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Apricot:");
       lcd.setCursor(0, 1);
       lcd.print("3x Gin 1x Brandy");
       lcd.setCursor(0, 2);
       lcd.print("Volume:");
       lcd.setCursor(8, 2);
       lcd.print(volume);
       lcd.setCursor(10, 2);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_APRICOT)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      }
      pixels.TheaterChase(pixels.Color(218,152,0),pixels.Color(240,210,0), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(3, 1);
      lcd.print("Apricot ");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (3*volume/4)*rho_gin && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((3*volume/4)*rho_gin) < (1*volume/4)*rho_liqueur_brandy && paverage()>poid_minimal){
      
      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP14_IN1, LOW);      
      digitalWrite(PUMP14_IN2, LOW);       

      Serial.println("Fermé2"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_APRICOT) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 80;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_ALELLUIA)

// *********************************************************************
{ 
       
       volume = 70;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Alelluia:");
       lcd.setCursor(0, 1);
       lcd.print("2x Vodka,1x Brandy");
       lcd.setCursor(0, 2);
       lcd.print("3x Orange,1x Peche");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_ALELLUIA)
{
  menu_choix();

  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      }
      pixels.TheaterChase(pixels.Color(0,210,180),pixels.Color(0,140,180), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de ");
      lcd.setCursor(0, 1);
      lcd.print("Alelluia");      

                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (2*volume/7)*rho_vodka && paverage()>poid_minimal){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((2*volume/7)*rho_vodka) < (1*volume/7)*rho_liqueur_peche && paverage()>poid_minimal){
      
      digitalWrite(PUMP13_IN1, LOW);       
      digitalWrite(PUMP13_IN2, HIGH);
      Serial.println("Ouvert2");
      pixels.Update();
    
      }

      digitalWrite(PUMP13_IN1, LOW);       
      digitalWrite(PUMP13_IN2, HIGH);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((2*volume/7)*rho_vodka)-((2*volume/7)*rho_liqueur_peche) < (1*volume/7)*rho_liqueur_brandy && paverage()>poid_minimal){
      
      digitalWrite(PUMP14_IN1, LOW);      
      digitalWrite(PUMP14_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP14_IN1, LOW);      
      digitalWrite(PUMP14_IN2, LOW);
      Serial.println("Fermé3");

      while(paverage()-verre1-((2*volume/7)*rho_vodka)-((2*volume/7)*rho_liqueur_peche)-((1*volume/7)*rho_liqueur_brandy) < (3*volume/7)*rho_orange && paverage()>poid_minimal){
      
      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, HIGH);
      Serial.println("Ouvert4");
      pixels.Update();
    
      }

      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, LOW);
      Serial.println("Fermé4");
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_ALELLUIA) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 70;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }


// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_CAPE_CODDER)

// *********************************************************************
{ 
       
       volume = 180;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("COSMOPOLITAN:");
       lcd.setCursor(0, 1);
       lcd.print("2x Vodka 1x Lime");
       lcd.setCursor(0, 2);
       lcd.print("3x Cranberry");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_CAPE_CODDER)
{
  menu_choix();

  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      }
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de ");
      lcd.setCursor(0, 1);
      lcd.print("Cape Codder ");

                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (2*volume/6)*rho_vodka){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);
      Serial.println("Fermé1");
    
      
      while(paverage()-verre1-((2*volume/6)*rho_vodka) < (1*volume/6)*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      Serial.println("Fermé3");

      while(paverage()-verre1-((2*volume/6)*rho_vodka)-((1*volume/6)*rho_lime) < (3*volume/6)*rho_cranberry && paverage()>poid_minimal){
      
      digitalWrite(PUMP8_IN1, LOW);       
      digitalWrite(PUMP8_IN2, HIGH);
      Serial.println("Ouvert4");
      pixels.Update();
    
      }

      digitalWrite(PUMP8_IN1, LOW);       
      digitalWrite(PUMP8_IN2, LOW);
      Serial.println("Fermé4");
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_CAPE_CODDER) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 180;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_BLUE_MARGARITA)

// *********************************************************************
{ 
       
       volume = 90;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Blue Margarita:");
       lcd.setCursor(0, 1);
       lcd.print("3x Tequila 2x Lime");
       lcd.setCursor(0, 2);
       lcd.print("1x Curacao");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_BLUE_MARGARITA)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(100,100,200),pixels.Color(0,0,240), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1);
      lcd.print("Blue Margarita ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (3*volume/6)*rho_tequila && paverage()>poid_minimal){
      
      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((3*volume/6)*rho_tequila) < (1*volume/6)*rho_curacao && paverage()>poid_minimal){
      
      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((3*volume/6)*rho_tequila)-((1*volume/6)*rho_curacao) < (2*volume/6)*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_BLUE_MARGARITA) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(1000) ;
  volume = 90;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_GIMLET)

// *********************************************************************
{ 
       
       volume = 50;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Gimlet:");
       lcd.setCursor(0, 1);
       lcd.print("4x Gin 1x Lime");
       lcd.setCursor(0, 2);
       lcd.print("Volume:");
       lcd.setCursor(8, 2);
       lcd.print(volume);
       lcd.setCursor(10, 2);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_GIMLET)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      }
      pixels.TheaterChase(pixels.Color(255,255,122),pixels.Color(255,255,0), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(3, 1);
      lcd.print("Gimlet ");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (4*volume/5)*rho_gin && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((4*volume/5)*rho_gin) < (1*volume/4)*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);       

      Serial.println("Fermé2"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_GIMLET) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 50;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_ORANGE_MARGARITA)

// *********************************************************************
{ 
       
       volume = 200;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Blue Margarita:");
       lcd.setCursor(0, 1);
       lcd.print("6x Tequ. 30x Orange");
       lcd.setCursor(0, 2);
       lcd.print("3x Cointr. 1x Lime");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_ORANGE_MARGARITA)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      }
      pixels.TheaterChase(pixels.Color(255,140,0),pixels.Color(255,200,0), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1);
      lcd.print("Orange Margarita ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (6*volume/40)*rho_tequila && paverage()>poid_minimal){
      
      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((6*volume/40)*rho_tequila) < (3*volume/40)*rho_cointreau && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((6*volume/40)*rho_tequila)-((3*volume/40)*rho_cointreau) < (1*volume/40)*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      Serial.println("Fermé3"); 

      while(paverage()-verre1-((6*volume/40)*rho_tequila)-((3*volume/40)*rho_cointreau)-((1*volume/40)*rho_lime)< (30*volume/40)*rho_orange && paverage()>poid_minimal){
      
      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, HIGH);
      Serial.println("Ouvert4");
      }     
      digitalWrite(PUMP10_IN1, LOW);       
      digitalWrite(PUMP10_IN2, LOW);
      Serial.println("Fermé4"); 
      
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_ORANGE_MARGARITA) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 200;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
 // *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_BLUE_LADY)

// *********************************************************************
{ 
       
       volume = 50;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Blue Lady:");
       lcd.setCursor(0, 1);
       lcd.print("2x Gin 2x Lime");
       lcd.setCursor(0, 2);
       lcd.print("1x Curacao");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_BLUE_LADY)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(0,255,255),pixels.Color(0,200,250), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de ");
      lcd.setCursor(0, 1);
      lcd.print("Blue Lady ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (1*volume/5)*rho_curacao && paverage()>poid_minimal){
      
      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/5)*rho_curacao) < (2*volume/5)*rho_gin && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert2");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((2*volume/5)*rho_gin)-((1*volume/5)*rho_curacao) < (2*volume/5)*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_BLUE_LADY) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 50;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_BOSTON_SIDECAR)

// *********************************************************************
{ 
       
       volume = 75;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Sidecar:");
       lcd.setCursor(0, 1);
       lcd.print("3x Brandy 2x Lime");
       lcd.setCursor(0, 2);
       lcd.print("3x Cointreau 3x Rhum");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_BOSTON_SIDECAR)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      }
      pixels.TheaterChase(pixels.Color(215,130,0),pixels.Color(255,185,0), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de");
      lcd.setCursor(0, 1);
      lcd.print("Boston Sidecar");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (2*volume/11)*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);;
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((2*volume/11)*rho_lime) < (3*volume/11)*rho_cointreau && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((2*volume/11)*rho_lime)-((3*volume/11)*rho_cointreau) < (3*volume/11)*rho_liqueur_brandy && paverage()>poid_minimal){
      
      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, LOW);
      Serial.println("Fermé3"); 

      while(paverage()-verre1-((2*volume/11)*rho_lime)-((3*volume/11)*rho_cointreau)-((3*volume/11)*rho_liqueur_brandy) < (3*volume/11)*rho_rhum_blanc && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert4");
      }
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);

      Serial.println("Fermé4");
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_BOSTON_SIDECAR) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 75;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_BLUE_ARROW)

// *********************************************************************
{ 
       
       volume = 150;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Blue Lagoon:");
       lcd.setCursor(0, 1);
       lcd.print("1x Lime 1x Curacao");
       lcd.setCursor(0, 2);
       lcd.print("2x Gin 1x Cointreau");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_BLUE_ARROW)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(0,74,164),pixels.Color(0,210,160), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1);
      lcd.print("Blue Arrow ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (1*volume/5)*rho_curacao && paverage()>poid_minimal){
      
      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/5)*rho_curacao) < (2*volume/5)*rho_gin && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((1*volume/5)*rho_curacao)-((2*volume/5)*rho_gin) < (1*volume/5)*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      

      Serial.println("Fermé3"); 

      while(paverage()-verre1-((1*volume/5)*rho_curacao)-((2*volume/5)*rho_gin)-((1*volume/5)*rho_lime) < (1*volume/5)*rho_cointreau && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert4");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);
      

      Serial.println("Fermé4");
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_BLUE_ARROW) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 150;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_JUICY)

// *********************************************************************
{ 
      
      volume =80;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Juicy:");
       lcd.setCursor(0, 1);
       lcd.print("4x Peche 4 Rhum,");
       lcd.setCursor(0, 2);
       lcd.print("3x Lime");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_JUICY)
{
  menu_choix();

  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(0,90,0),pixels.Color(160,50,50), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de Juicy");
            
      float verre1=paverage();
      while(paverage()-verre1 < (4*volume/11)*rho_liqueur_peche && paverage()>poid_minimal){
      
      digitalWrite(PUMP13_IN1, LOW);       
      digitalWrite(PUMP13_IN2, HIGH);
      Serial.println("Ouvert");
    
      }

      digitalWrite(PUMP13_IN1, LOW);       
      digitalWrite(PUMP13_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((4*volume/11)*rho_liqueur_peche) < (4*volume/11)*rho_rhum_blanc && paverage()>poid_minimal){
      
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((4*volume/11)*rho_liqueur_peche)-((4*volume/11)*rho_rhum_blanc) <3*volume/11*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }


      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_JUICY) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(1000) ;
  volume = 80;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_LADY_LYSSNA)

// *********************************************************************
{ 
       
       volume = 70;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("lady Lyssna:");
       lcd.setCursor(0, 1);
       lcd.print("4x Gin,1x Brandy");
       lcd.setCursor(0, 2);
       lcd.print("1x Cointr. 1x Orange");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_LADY_LYSSNA)
{
  menu_choix();
  
  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      while (distance>distance_verre) { // objet détecté distance< distance du verre
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(255,255,0),pixels.Color(255,255,0), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(3, 1);
      lcd.print("Lady Lyssna ");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (1*volume/7)*rho_liqueur_brandy && paverage()>poid_minimal){
      
      digitalWrite(PUMP14_IN1, LOW);
      digitalWrite(PUMP14_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP14_IN1, LOW);
      digitalWrite(PUMP14_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/3)*rho_liqueur_brandy) < ((4*volume/7)*rho_gin) && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);       
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);       
      digitalWrite(PUMP2_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((4*volume/7)*rho_gin)-((1*volume/7)*rho_liqueur_brandy) < ((1*volume/7)*rho_cointreau)){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);
      
      Serial.println("Fermé3"); 
      
      while(paverage()-verre1-((4*volume/7)*rho_gin)-((1*volume/7)*rho_liqueur_brandy)-((1*volume/7)*rho_cointreau) < ((1*volume/7)*rho_orange)){
      
      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, HIGH);
      Serial.println("Ouvert4");
      pixels.Update();
    
      }

      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, LOW);
      Serial.println("Fermé 4");      
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_LADY_LYSSNA) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 70;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
