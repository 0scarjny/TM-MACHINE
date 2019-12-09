//--------------------------------------------------------------------------------------------------
// SHOTS SIMPLES
//--------------------------------------------------------------------------------------------------

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_VODKA)

// *********************************************************************
{ 
       volume =40;
        
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Vodka");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");
       
       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_VODKA)
{
  menu_choix();

  if(LCDML_BUTTON_checkEnter()) {
      LCDML_BACK_stopStable(LCDML_BACKEND_RAINBOW);
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      // la sortie OUT du capteur est active sur niveau bas
      while (5>paverage()) { // objet détecté = niveau 0 sur OUT capteur
        
      verre_manquant();
      
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
      } 
      pixels.TheaterChase(pixels.Color(204,255,255),pixels.Color(204,255,0), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de vodka");     
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < volume*rho_vodka && paverage()>poid_minimal ){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert1");
      pixels.Update();
    
    
      }
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);       

      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();

      }

 
}
  


void LCDML_DISP_loop_end(LCDML_FUNC_VODKA) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing

  
  delay(100) ;
  volume = 40;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_GIN)

// *********************************************************************
{ 
       volume =40;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Gin");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_GIN)
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
      pixels.TheaterChase(pixels.Color(102,0,255),pixels.Color(255,120,150), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de gin");
            
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < volume*rho_gin && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert1");
      pixels.Update();
    
      }
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);       
       
      boisson_prete();   
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }

 
}
  


void LCDML_DISP_loop_end(LCDML_FUNC_GIN) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
  
   
  delay(100) ;
  volume = 40;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_CURACAO)

// *********************************************************************
{      
       volume =40;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Curacao");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_CURACAO)
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
      pixels.TheaterChase(pixels.Color(0,51,255),pixels.Color(0,255,255), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de curacao");
            
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < volume*rho_curacao && paverage()>poid_minimal){
      
      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }
      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, LOW);       
       
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }

 
}
  


void LCDML_DISP_loop_end(LCDML_FUNC_CURACAO) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing


  
  delay(100) ;
  volume = 40;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }


// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_COINTREAU)
// *********************************************************************
{       
       volume =40;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Cointreau");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}

void LCDML_DISP_loop(LCDML_FUNC_COINTREAU)
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
      pixels.TheaterChase(pixels.Color(200,50,50),pixels.Color(50,200,50), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de cointreau");
            
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < volume*rho_cointreau && paverage()>poid_minimal){
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);       

      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();

      }

 
}

void LCDML_DISP_loop_end(LCDML_FUNC_COINTREAU) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
  
  delay(100) ;
  volume = 40;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
  
// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_RHUMBLANC)

// *********************************************************************
{       
       volume =40;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Rhum blanc");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_RHUMBLANC)
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
      pixels.TheaterChase(pixels.Color(150,70,150),pixels.Color(255,255,50), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de rhum blanc");
            
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < volume*rho_rhum_blanc && paverage()>poid_minimal){
      
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, LOW);       

      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();

      }

 
}
  


void LCDML_DISP_loop_end(LCDML_FUNC_RHUMBLANC) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing

      
  
  delay(100) ;
  volume = 40;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_TEQUILA)

// *********************************************************************
{ 
       volume =40;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Tequila");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_TEQUILA)
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
      pixels.TheaterChase(pixels.Color(255,105,180),pixels.Color(255,255,102), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de tequila");
            
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < volume*rho_tequila && paverage()>poid_minimal){
      
      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }
      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, LOW);       

      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

 

  


void LCDML_DISP_loop_end(LCDML_FUNC_TEQUILA) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing

  
  delay(100) ;
  volume = 40;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

 // *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_STOP_AND_GO_NAKED)

// *********************************************************************
{ 
       volume = 60;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Stop & Go Naked:");
       lcd.setCursor(0, 1);
       lcd.print("Rhum Lime Gin");
       lcd.setCursor(0, 2);
       lcd.print("Vodka Cointr. Tequ.");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_STOP_AND_GO_NAKED)
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
      pixels.TheaterChase(pixels.Color(255,88,255),pixels.Color(77,32,185), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(4, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1);
      lcd.print("Stop and Go Naked");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (1*volume/8)*rho_rhum_blanc && paverage()>poid_minimal){
      
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/8)*rho_rhum_blanc) < (1*volume/8)*rho_gin && paverage()>poid_minimal){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((1*volume/8)*rho_rhum_blanc)-((1*volume/8)*rho_gin) < (1*volume/8)*rho_vodka && paverage()>poid_minimal){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert3");
      pixels.Update();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);
      Serial.println("Fermé3"); 

 while(paverage()-verre1-((1*volume/8)*rho_rhum_blanc)-((1*volume/8)*rho_gin)-((1*volume/8)*rho_vodka) < (2*volume/8)*rho_cointreau && paverage()>poid_minimal) {
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert4");
      pixels.Update();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);
      Serial.println("Fermé4");

 while(paverage()-verre1-((1*volume/8)*rho_rhum_blanc)-((1*volume/8)*rho_gin)-((1*volume/8)*rho_vodka)-((2*volume/8)*rho_cointreau) < (1*volume/8)*rho_tequila && paverage()>poid_minimal) {
      
      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, HIGH);
      Serial.println("Ouvert5");
      pixels.Update();
    
      }

      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, LOW);
      Serial.println("Fermé5"); 

while(paverage()-verre1-((1*volume/8)*rho_rhum_blanc)-((1*volume/8)*rho_gin)-((1*volume/8)*rho_vodka)-((2*volume/8)*rho_cointreau) -((1*volume/8)*rho_tequila)<(2*volume/8)*rho_lime && paverage()>poid_minimal) {
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert6");
      pixels.Update();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      Serial.println("Fermé6"); 

      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      
      }
}

void LCDML_DISP_loop_end(LCDML_FUNC_STOP_AND_GO_NAKED) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  delay(100) ;
  volume = 115;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  } 

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_PECHE)

// *********************************************************************
{ 
      volume =40;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Liqueur de Peche");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_PECHE)
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
      pixels.TheaterChase(pixels.Color(255,70,0),pixels.Color(124,225,0), 100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Liqueur de Peche");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (volume)*rho_liqueur_peche && paverage()>poid_minimal){
      
      digitalWrite(PUMP13_IN1, LOW);       
      digitalWrite(PUMP13_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP13_IN1, LOW);       
      digitalWrite(PUMP13_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_PECHE) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      

  
  volume = 40;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_BRANDY)
// *********************************************************************
{ 
      volume =40;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Liqueur d'Abricot");
       lcd.setCursor(0, 3);
       lcd.print("Volume:");
       lcd.setCursor(8, 3);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_BRANDY)
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
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(volume);
      lcd.setCursor(3, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1); 
      lcd.print("Liqueur d'Abricot");
                 
      float verre1=paverage();
      pixels.Update();
      while(paverage()-verre1 < (volume)*rho_liqueur_peche){
      
      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, HIGH);
      Serial.println("Ouvert");
      pixels.Update();
    
      }

      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
      LCDML_BACK_restart(LCDML_BACKEND_RAINBOW);
      LCDML.goRoot();
      }
      }

void LCDML_DISP_loop_end(LCDML_FUNC_BRANDY) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
  
  volume = 40;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }
