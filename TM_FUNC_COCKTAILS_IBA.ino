// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_BACARDI)

// *********************************************************************
{ 
      volume =75;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Bacardi");
       lcd.setCursor(0, 1);
       lcd.print("2x gren. 9x rhum,");
       lcd.setCursor(0, 2);
       lcd.print("4x citron");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_BACARDI)
{
  menu_choix();

  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      //detection=digitalRead(capteur); // on lit la broche capteur
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      // la sortie OUT du capteur est active sur niveau bas
      while (distance>distance_verre) { // objet détecté = niveau 0 sur OUT capteur
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      } 

      pixels.TheaterChase(pixels.Color(240,40,140),pixels.Color(200,21,16), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de Bacardi");
            
      float verre1=paverage();
      while(paverage()-verre1 < (3*volume/15)*rho_grenadine && paverage()>poid_minimal){
      
      digitalWrite(PUMP11_IN1, LOW);       
      digitalWrite(PUMP11_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP11_IN1, LOW);       
      digitalWrite(PUMP11_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((3*volume/15)*rho_grenadine) < (9*volume/15)*rho_rhum_blanc && paverage()>poid_minimal){
      
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((3*volume/15)*rho_grenadine)-((9*volume/15)*rho_rhum_blanc) < 4*volume/15*rho_lime && paverage()>poid_minimal){
      
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

void LCDML_DISP_loop_end(LCDML_FUNC_BACARDI) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
  
  delay(100) ;
  volume = 75;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(TM_FUNC_TEQUILA_SUNRISE)

// *********************************************************************
{ 
      volume =150;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Tequila Sunrise");
       lcd.setCursor(0, 1);
       lcd.print("3x Tequila,6x Orange");
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
void LCDML_DISP_loop(TM_FUNC_TEQUILA_SUNRISE)
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
      pixels.TheaterChase(pixels.Color(233,60,16),pixels.Color(230,230,0), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de Tequila ");
      lcd.setCursor(0, 1); 
      lcd.print("Sunrise");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (6*volume/10)*rho_orange && paverage()>poid_minimal){
      
      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP9_IN1, LOW);      
      digitalWrite(PUMP9_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((6*volume/10)*rho_orange) < (3*volume/10)*rho_tequila && paverage()>poid_minimal){
      
      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((6*volume/10)*rho_orange)-((3*volume/10)*rho_tequila) < volume/10*rho_grenadine && paverage()>poid_minimal){
      
      digitalWrite(PUMP11_IN1, LOW);       
      digitalWrite(PUMP11_IN2, HIGH);
      Serial.println("Ouvert3");
      ;
    
      }

      digitalWrite(PUMP11_IN1, LOW);       
      digitalWrite(PUMP11_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(TM_FUNC_TEQUILA_SUNRISE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
  
  delay(100) ;
  volume = 150;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_MARGARITA)

// *********************************************************************
{ 
       volume = 70;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Margarita:");
       lcd.setCursor(0, 1);
       lcd.print("7x Tequila,3x Lime");
       lcd.setCursor(0, 2);
       lcd.print("4x Cointreau");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_MARGARITA)
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
      pixels.TheaterChase(pixels.Color(0,200,20),pixels.Color(255,255,255), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de Margarita ");

                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (7*volume/14)*rho_tequila && paverage()>poid_minimal){
      
      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((7*volume/14)*rho_tequila) < (4*volume/14)*rho_cointreau && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((7*volume/14)*rho_tequila)-((4*volume/14)*rho_cointreau) < (3*volume/14)*rho_lime && paverage()>poid_minimal){
      
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

void LCDML_DISP_loop_end(LCDML_FUNC_MARGARITA) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 70;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_COSMOPOLITAN)

// *********************************************************************
{ 
       volume = 100;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("COSMOPOLITAN:");
       lcd.setCursor(0, 1);
       lcd.print("8x Vodka,6x Cramberry");
       lcd.setCursor(0, 2);
       lcd.print("3x Cointreau,3x Lime");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_COSMOPOLITAN)
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
      pixels.TheaterChase(pixels.Color(255,86,245),pixels.Color(255,10,16), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de ");
      lcd.setCursor(0, 1);
      lcd.print("COSMOPOLITAN ");

                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (8*volume/20)*rho_vodka && paverage()>poid_minimal){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((8*volume/20)*rho_vodka) < (3*volume/20)*rho_cointreau && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((8*volume/20)*rho_vodka)-((3*volume/20)*rho_cointreau) < (3*volume/20)*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      Serial.println("Fermé3");

      while(paverage()-verre1-((8*volume/20)*rho_vodka)-((3*volume/20)*rho_cointreau)-((3*volume/20)*rho_lime) < (6*volume/20)*rho_cranberry && paverage()>poid_minimal){
      
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

void LCDML_DISP_loop_end(LCDML_FUNC_COSMOPOLITAN) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 100;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_SCREWDRIVER)

// *********************************************************************
{ 
       volume = 150;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("SCREWDRIVER:");
       lcd.setCursor(0, 1);
       lcd.print("1x Vodka,2x Orange");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_SCREWDRIVER)
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
      pixels.TheaterChase(pixels.Color(255,255,0),pixels.Color(100,240,0), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de Screwdriver ");

                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (volume/3)*rho_vodka && paverage()>poid_minimal){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
      lcd.setCursor(0, 2);
      lcd.print("Vodka ");
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);
      Serial.println("Fermé1");
      lcd.setCursor(0, 2);
      lcd.print("              ");
      
      while(paverage()-verre1-((volume/3)*rho_vodka) < (2*volume/3)*rho_orange && paverage()>poid_minimal){
      
      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
      lcd.setCursor(0, 2);
      lcd.print("Jus d'orange ");
    
      }

      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, LOW);       
      Serial.println("Fermé2");
      lcd.setCursor(0, 2);
      lcd.print("             ");
          
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_SCREWDRIVER) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 150;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_SEX_ON_THE_BEACH)

// *********************************************************************
{ 
       volume = 157;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Sex On The Beach:");
       lcd.setCursor(0, 1);
       lcd.print("2x Vodka,2x Cramberry");
       lcd.setCursor(0, 2);
       lcd.print("2x Orange,1x Peche");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_SEX_ON_THE_BEACH)
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
      pixels.TheaterChase(pixels.Color(255,255,0),pixels.Color(255,60,40), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de ");
      lcd.setCursor(0, 1);
      lcd.print("Sex On The Beach");      

                 
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
      
      while(paverage()-verre1-((2*volume/7)*rho_vodka)-((2*volume/7)*rho_liqueur_peche) < (2*volume/7)*rho_orange && paverage()>poid_minimal){
      
      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, LOW);
      Serial.println("Fermé3");

      while(paverage()-verre1-((2*volume/7)*rho_vodka)-((2*volume/7)*rho_liqueur_peche)-((2*volume/7)*rho_orange) < (2*volume/7)*rho_cranberry && paverage()>poid_minimal){
      
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

void LCDML_DISP_loop_end(LCDML_FUNC_SEX_ON_THE_BEACH) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 100;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_WHITE_LADY)

// *********************************************************************
{ 
       volume = 90;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("White Lady:");
       lcd.setCursor(0, 1);
       lcd.print("4x Gin,2x Lime");
       lcd.setCursor(0, 2);
       lcd.print("3x Cointreau");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_WHITE_LADY)
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
      pixels.TheaterChase(pixels.Color(255,255,255),pixels.Color(90,90,90), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de White ");
      lcd.setCursor(0, 1);
      lcd.print("Lady ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (4*volume/9)*rho_gin && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((4*volume/9)*rho_gin) < (3*volume/9)*rho_cointreau && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((4*volume/9)*rho_gin)-((3*volume/9)*rho_cointreau) < (2*volume/9)*rho_lime && paverage()>poid_minimal){
      
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

void LCDML_DISP_loop_end(LCDML_FUNC_WHITE_LADY) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 90;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_KAMIKAZE)

// *********************************************************************
{ 
       volume = 90;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Kamikaze:");
       lcd.setCursor(0, 1);
       lcd.print("3x Gin,3x Lime");
       lcd.setCursor(0, 2);
       lcd.print("3x Cointreau");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_KAMIKAZE)
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
      pixels.TheaterChase(pixels.Color(135,190,165),pixels.Color(40,240,40), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(3, 1);
      lcd.print("Kamikaze ");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (volume/3)*rho_vodka && paverage()>poid_minimal){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((volume/3)*rho_vodka) < (volume/3)*rho_cointreau && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((volume/3)*rho_vodka)-((volume/3)*rho_cointreau) < (volume/3)*rho_lime && paverage()>poid_minimal){
      
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

void LCDML_DISP_loop_end(LCDML_FUNC_KAMIKAZE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 90;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_CUBA_LIBRE)

// *********************************************************************
{ 
       volume = 180;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Cuba Libre:");
       lcd.setCursor(0, 1);
       lcd.print("5x Rhum, 1x Lime");
       lcd.setCursor(0, 2);
       lcd.print("12x Cola");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_CUBA_LIBRE)
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
      pixels.TheaterChase(pixels.Color(255,255,0),pixels.Color(50,50,50), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(3, 1);
      lcd.print("Cuba Libre ");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (5*volume/18)*rho_rhum_blanc && paverage()>poid_minimal){
      
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((5*volume/18)*rho_rhum_blanc) < (volume/18)*rho_lime && paverage()>poid_minimal){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((5*volume/18)*rho_rhum_blanc)-((volume/18)*rho_lime) < (12*volume/18)*rho_cola && paverage()>poid_minimal){
      
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

void LCDML_DISP_loop_end(LCDML_FUNC_CUBA_LIBRE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 180;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }


// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_LONG_ISLAND_TEA)

// *********************************************************************
{ 
       volume = 115;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Long Island Tea:");
       lcd.setCursor(0, 1);
       lcd.print("Rhum,Lime,Gin,Cola");
       lcd.setCursor(0, 2);
       lcd.print("Vodka,Cointr.,Tequ.");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_LONG_ISLAND_TEA)
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
      pixels.TheaterChase(pixels.Color(255,165,40),pixels.Color(240,160,200), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(4, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1);
      lcd.print("Long Island Tea");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (3*volume/23)*rho_rhum_blanc && paverage()>poid_minimal){
      
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((3*volume/23)*rho_rhum_blanc) < (3*volume/23)*rho_gin && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((3*volume/23)*rho_rhum_blanc)-((3*volume/23)*rho_gin) < (3*volume/23)*rho_vodka && paverage()>poid_minimal){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);
      Serial.println("Fermé3"); 

 while(paverage()-verre1-((3*volume/23)*rho_rhum_blanc)-((3*volume/23)*rho_gin)-((3*volume/23)*rho_vodka) < (3*volume/23)*rho_cointreau && paverage()>poid_minimal) {
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert4");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);
      Serial.println("Fermé4");

 while(paverage()-verre1-((3*volume/23)*rho_rhum_blanc)-((3*volume/23)*rho_gin)-((3*volume/23)*rho_vodka)-((3*volume/23)*rho_cointreau) < (3*volume/23)*rho_tequila && paverage()>poid_minimal) {
      
      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, HIGH);
      Serial.println("Ouvert5");
      pixels.Update();
    
      }

      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, LOW);
      Serial.println("Fermé5"); 

while(paverage()-verre1-((3*volume/23)*rho_rhum_blanc)-((3*volume/23)*rho_gin)-((3*volume/23)*rho_vodka)-((3*volume/23)*rho_cointreau) -((3*volume/23)*rho_tequila)<(2*volume/23)*rho_lime && paverage()>poid_minimal) {
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert6");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      Serial.println("Fermé6"); 

while( paverage()-verre1-((3*volume/23)*rho_rhum_blanc)-((3*volume/23)*rho_gin)-((3*volume/23)*rho_vodka)-((3*volume/23)*rho_cointreau) -((3*volume/23)*rho_tequila)-((2*volume/23)*rho_lime) < (6*volume/23)*rho_cola && paverage()>poid_minimal) {
      
      digitalWrite(PUMP7_IN1, LOW);       
      digitalWrite(PUMP7_IN2, HIGH);
      Serial.println("Ouvert7");
      pixels.Update();
    
      }

      digitalWrite(PUMP7_IN1, LOW);       
      digitalWrite(PUMP7_IN2, LOW);
      Serial.println("Fermé7");
      
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_LONG_ISLAND_TEA) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 115;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_PARADISE)

// *********************************************************************
{ 
       volume = 70;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Paradise:");
       lcd.setCursor(0, 1);
       lcd.print("7x Gin,4x Brandy");
       lcd.setCursor(0, 2);
       lcd.print("3x Jus d'Orange");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_PARADISE)
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
      pixels.TheaterChase(pixels.Color(255,255,0),pixels.Color(0,165,200), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(3, 1);
      lcd.print("Paradise ");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (7*volume/14)*rho_gin){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((7*volume/14)*rho_gin) < (4*volume/14)*rho_liqueur_brandy && paverage()>poid_minimal){
      
      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((7*volume/14)*rho_gin)-((4*volume/14)*rho_liqueur_brandy) < (3*volume/14)*rho_orange && paverage()>poid_minimal){
      
      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP9_IN1, LOW);       
      digitalWrite(PUMP9_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_PARADISE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 70;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_LEMON_DROP_MARTINI)

// *********************************************************************
{ 
       volume = 60;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Lemon Drop Martini:");
       lcd.setCursor(0, 1);
       lcd.print("5x Vodka,4x Cointreau");
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

void LCDML_DISP_loop(LCDML_FUNC_LEMON_DROP_MARTINI)
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
      pixels.TheaterChase(pixels.Color(255,255,140),pixels.Color(255,140,130), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(3, 1);
      lcd.print("Lemon Drop Martini ");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (5*volume/12)*rho_vodka && paverage()>poid_minimal){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((5*volume/12)*rho_vodka) < (4*volume/12)*rho_cointreau && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((5*volume/12)*rho_vodka)-((4*volume/12)*rho_cointreau) < (3*volume/12)*rho_lime && paverage()>poid_minimal){
      
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

void LCDML_DISP_loop_end(LCDML_FUNC_LEMON_DROP_MARTINI) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 60;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_SIDECAR)

// *********************************************************************
{ 
       volume = 75;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Sidecar:");
       lcd.setCursor(0, 1);
       lcd.print("4x Brandy 1x Lime");
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
void LCDML_DISP_loop(LCDML_FUNC_SIDECAR)
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
      pixels.TheaterChase(pixels.Color(130,65,0),pixels.Color(133,70,240), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de Sidecar ");

                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (1*volume/6)*rho_lime){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);;
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/6)*rho_lime) < (1*volume/6)*rho_cointreau){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((1*volume/6)*rho_lime)-((1*volume/6)*rho_cointreau) < (4*volume/6)*rho_liqueur_brandy){
      
      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP14_IN1, LOW);      
      digitalWrite(PUMP14_IN2, LOW);
      

      Serial.println("Fermé3"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_SIDECAR) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 75;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_BETWEEN_THE_SHEETS)

// *********************************************************************
{ 
       volume = 100;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Between The Sheets:");
       lcd.setCursor(0, 1);
       lcd.print("1x Brandy 1x Lime");
       lcd.setCursor(0, 2);
       lcd.print("1x Cointreau 1x Rhum");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(11, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_BETWEEN_THE_SHEETS)
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
      pixels.TheaterChase(pixels.Color(40,130,80),pixels.Color(130,190,0), 240);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de");
      lcd.setCursor(0, 1);
      lcd.print("Between The Sheets");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (1*volume/4)*rho_lime){
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);;
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/4)*rho_lime) < (1*volume/4)*rho_cointreau){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((1*volume/4)*rho_lime)-((1*volume/4)*rho_cointreau) < (1*volume/4)*rho_liqueur_brandy){
      
      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP14_IN1, LOW);      
      digitalWrite(PUMP14_IN2, LOW);
      

      Serial.println("Fermé3"); 

      while(paverage()-verre1-((1*volume/4)*rho_lime)-((1*volume/4)*rho_cointreau)-((1*volume/4)*rho_liqueur_brandy) <(1*volume/4)*rho_rhum_blanc){
      
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, HIGH);
      Serial.println("Ouvert4");
      pixels.Update();
    
      }
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, LOW);

      Serial.println("Fermé4");
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }

      }

void LCDML_DISP_loop_end(LCDML_FUNC_BETWEEN_THE_SHEETS) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 100;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
