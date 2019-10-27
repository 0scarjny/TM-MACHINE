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
       lcd.setCursor(0, 2);
       lcd.print("Volume:");
       lcd.setCursor(0, 3);
       lcd.print(volume);
       lcd.setCursor(2, 3);
       lcd.print("ml");
       
       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_VODKA)
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
      lcd.print("ml de vodka");
            
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < volume){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert1");
      //setColor();
    
      }
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);       

      boisson_prete();
      
      LCDML.goRoot();

      }

 
}
  


void LCDML_DISP_loop_end(LCDML_FUNC_VODKA) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
     
  delay(1000) ;
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
       lcd.setCursor(0, 2);
       lcd.print("Volume:");
       lcd.setCursor(0, 3);
       lcd.print(volume);
       lcd.setCursor(2, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_GIN)
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
      lcd.print("ml de gin");
            
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < volume){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert1");
      //setColor();
    
      }
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);       
       
      LCDML.goRoot();

      }

 
}
  


void LCDML_DISP_loop_end(LCDML_FUNC_GIN) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
      
      Serial.println("Fermé");
       
      detection=digitalRead(capteur); // on lit la broche capteur
      // la sortie OUT du capteur est active sur niveau bas
      while (detection==0) { // objet détecté = niveau 0 sur OUT capteur


      detection=digitalRead(capteur);
      
      lcd.clear();      
      lcd.setCursor(0, 0);
      lcd.print(F("COCKTAIL PRET")); 
     
      Serial.println("COCKTAIL IS READY");
      setColor();
      delay(50);
      pixels.clear();
      pixels.show();
      delay(50);
      }
      
 
  delay(1000) ;
  total_cocktail++;
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
       lcd.setCursor(0, 2);
       lcd.print("Volume:");
       lcd.setCursor(0, 3);
       lcd.print(volume);
       lcd.setCursor(2, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_CURACAO)
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
      lcd.print("ml de curacao");
            
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < volume){
      
      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }
      digitalWrite(PUMP3_IN1, LOW);
      digitalWrite(PUMP3_IN2, LOW);       
       
      LCDML.goRoot();

      }

 
}
  


void LCDML_DISP_loop_end(LCDML_FUNC_CURACAO) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing

      Serial.println("Fermé"); 
           
      detection=digitalRead(capteur); // on lit la broche capteur
      // la sortie OUT du capteur est active sur niveau bas
      while (detection==0) { // objet détecté = niveau 0 sur OUT capteur


      detection=digitalRead(capteur);
      
      lcd.clear();      
      lcd.setCursor(0, 0);
      lcd.print(F("COCKTAIL PRET")); 
     
      Serial.println("COCKTAIL IS READY");
      setColor();
      delay(50);
      pixels.clear();
      pixels.show();
      delay(50);
      }
      
 
  delay(1000) ;
  total_cocktail++;
  volume = 40;
  g_lcdml_initscreen = millis(); // reset initscreen timer

  }


// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_COINTREAU)
// *********************************************************************
{ 
      digitalWrite(PUMP7_IN1, LOW);       
      digitalWrite(PUMP7_IN2, LOW);
      
}

void LCDML_DISP_loop(LCDML_FUNC_COINTREAU)
{
      detection=digitalRead(capteur); // on lit la broche capteur
      // la sortie OUT du capteur est active sur niveau bas
      while (detection==1) { // objet détecté = niveau 0 sur OUT capteur


      
      detection=digitalRead(capteur);
      
      lcd.setCursor(0, 0);
      lcd.print(F("GLASS MISSING")); 
     
      Serial.println("ERROR");
      delay(100);
      
      } 
      lcd.clear();

      float verre1=paverage();

      while(paverage()-verre1 <40){
      
      digitalWrite(PUMP7_IN1, LOW);      
      digitalWrite(PUMP7_IN2, HIGH);
      Serial.println("Ouvert");
     
      lcd.setCursor(0, 0);
      lcd.print(F("4cl cointreau"));
       
      }

     
    LCDML.goRoot();
 
}


void LCDML_DISP_loop_end(LCDML_FUNC_COINTREAU) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
  total_cocktail++;
   digitalWrite(PUMP7_IN1, LOW);       digitalWrite(PUMP7_IN2, LOW);
  Serial.println("Fermé"); 
  delay(1000) ;

  }
  
// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_RHUMBLANC)

// *********************************************************************
{       
       volume =40;
       
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Rhum blanc");
       lcd.setCursor(0, 2);
       lcd.print("Volume:");
       lcd.setCursor(0, 3);
       lcd.print(volume);
       lcd.setCursor(2, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_RHUMBLANC)
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
      lcd.print("ml de rhum blanc");
            
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < volume){
      
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, LOW);       

      boisson_prete();
      
      LCDML.goRoot();

      }

 
}
  


void LCDML_DISP_loop_end(LCDML_FUNC_RHUMBLANC) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing

      
 
  delay(1000) ;
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
       lcd.setCursor(0, 2);
       lcd.print("Volume:");
       lcd.setCursor(0, 3);
       lcd.print(volume);
       lcd.setCursor(2, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_TEQUILA)
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
      lcd.print("ml de tequila");
            
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < volume){
      
      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }
      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, LOW);       

      boisson_prete();
      LCDML.goRoot();
      }
      }

 

  


void LCDML_DISP_loop_end(LCDML_FUNC_TEQUILA) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
 
  delay(1000) ;
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
      lcd.setCursor(4, 0);
      lcd.print("ml de  ");
      lcd.setCursor(0, 1);
      lcd.print("Stop and Go Naked");
      lcd.setCursor(0, 2);
      lcd.print("en preparation ");
                 
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < (1*volume/8)*rho_rhum_blanc){
      
      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }

      digitalWrite(PUMP5_IN1, LOW);
      digitalWrite(PUMP5_IN2, LOW);
      Serial.println("Fermé1");
      
      while(paverage()-verre1-((1*volume/8)*rho_rhum_blanc) < (1*volume/8)*rho_gin){
      
      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }

      digitalWrite(PUMP2_IN1, LOW);
      digitalWrite(PUMP2_IN2, LOW);       

      Serial.println("Fermé2");
      
      while(paverage()-verre1-((1*volume/8)*rho_rhum_blanc)-((1*volume/8)*rho_gin) < (1*volume/8)*rho_vodka){
      
      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, HIGH);
      Serial.println("Ouvert3");
      //setColor();
    
      }

      digitalWrite(PUMP1_IN1, LOW);
      digitalWrite(PUMP1_IN2, LOW);
      Serial.println("Fermé3"); 

 while(paverage()-verre1-((1*volume/8)*rho_rhum_blanc)-((1*volume/8)*rho_gin)-((1*volume/8)*rho_vodka) < (2*volume/8)*rho_cointreau) {
      
      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, HIGH);
      Serial.println("Ouvert4");
      //setColor();
    
      }

      digitalWrite(PUMP4_IN1, LOW);
      digitalWrite(PUMP4_IN2, LOW);
      Serial.println("Fermé4");

 while(paverage()-verre1-((1*volume/8)*rho_rhum_blanc)-((1*volume/8)*rho_gin)-((1*volume/8)*rho_vodka)-((2*volume/8)*rho_cointreau) < (1*volume/8)*rho_tequila) {
      
      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, HIGH);
      Serial.println("Ouvert5");
      //setColor();
    
      }

      digitalWrite(PUMP6_IN1, LOW);
      digitalWrite(PUMP6_IN2, LOW);
      Serial.println("Fermé5"); 

while(paverage()-verre1-((1*volume/8)*rho_rhum_blanc)-((1*volume/8)*rho_gin)-((1*volume/8)*rho_vodka)-((2*volume/8)*rho_cointreau) -((1*volume/8)*rho_tequila)<(2*volume/8)*rho_lime) {
      
      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, HIGH);
      Serial.println("Ouvert6");
      //setColor();
    
      }

      digitalWrite(PUMP12_IN1, LOW);       
      digitalWrite(PUMP12_IN2, LOW);
      Serial.println("Fermé6"); 


      }
}

void LCDML_DISP_loop_end(LCDML_FUNC_STOP_AND_GO_NAKED) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing      
 
  delay(1000) ;
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
       lcd.setCursor(0, 1);
       lcd.print("Volume:");
       lcd.setCursor(8, 1);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_PECHE)
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
      lcd.print("Liqueur de Peche");
                 
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < (volume)*rho_liqueur_peche){
      
      digitalWrite(PUMP13_IN1, LOW);       
      digitalWrite(PUMP13_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }

      digitalWrite(PUMP13_IN1, LOW);       
      digitalWrite(PUMP13_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
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
       lcd.setCursor(0, 1);
       lcd.print("Volume:");
       lcd.setCursor(8, 1);
       lcd.print(volume);
       lcd.setCursor(10, 3);
       lcd.print("ml");

       delay(involontaire);         // pour éviter une sélection involontaire
  
}
void LCDML_DISP_loop(LCDML_FUNC_BRANDY)
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
      lcd.print("Liqueur d'Abricot");
                 
      float verre1=paverage();
      //setColor();
      while(paverage()-verre1 < (volume)*rho_liqueur_peche){
      
      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, HIGH);
      Serial.println("Ouvert");
      //setColor();
    
      }

      digitalWrite(PUMP14_IN1, LOW);       
      digitalWrite(PUMP14_IN2, LOW);
      Serial.println("Fermé1"); 
           
      boisson_prete();
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
