#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <unistd.h>

int main()
{   
   
    //-------------OKNO-APLIKACJI--------------//
    const unsigned window_width = 896;
    const unsigned window_height = 504;
    sf::RenderWindow oknoAplikacji( sf::VideoMode( window_width, window_height), "Jakub_Kacprzak" ); //usingnamespace sf - srodowisko uzywane w bibliotece sfml
    oknoAplikacji.setFramerateLimit(60);

    // -------------TEKSTURY------------//
    sf::Texture postac;
    postac.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie II/postac_prawo.png");
    sf::Texture postac2;
    postac2.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie II/postac_lewo.png");
    sf::Texture postac3;
    postac3.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/postac_dol.png");
    sf::Texture mob1_t;
    mob1_t.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/mob1.png");
    sf::Texture mob5_t;
    mob5_t.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/fire.png");
    sf::Texture mob6_t;
    mob6_t.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/fire_2.png");
    sf::Texture mob7_t;
    mob7_t.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/fire_4.png");
    sf::Texture mob2_t;
    mob2_t.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/mob3.png");
    sf::Texture mob4_t;
    mob4_t.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/fire_4.png");
    sf::Texture mob3_t;
    mob3_t.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/mob2.png");
    sf::Texture ground_t;
    ground_t.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/ground1.png");
    sf::Texture background;
    background.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/tlo.png");
    sf::Texture money_t;
    money_t.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/coin.png");
    sf::Texture money_t2;
    money_t2.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/coin2.png");
    sf::Texture money_t3;
    money_t3.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/coin2.png");
    sf::Texture money_t4;
    money_t4.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/coin2.png");
    sf::Texture life_t;
    life_t.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/life.png");
    sf::Texture game_overt;
    game_overt.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/Game-Over-PNG-Image.png");
    
    // -------------POSTAC-ANIMACJA------------//
    sf::Sprite postac_sprite;
    postac_sprite.setTexture(postac);
    int score = 0;
    int zycie = 5;
    float aktualnaKlatka = 0; // postac framerate
    float aktualnaKlatka_2 = 0; // background framerate
    float aktualnaKlatka_3 = 0; // money framerate gold
    float aktualnaKlatka_4 = 0; // money framerate silver
    float aktualnaKlatka_5 = 0; // mob1
    float aktualnaKlatka_6 = 0; // life
    float aktualnaKlatka_7 = 0; // mob2
    float aktualnaKlatka_8 = 0; // mob3
    float aktualnaKlatka_9 = 0; // mob4
    float aktualnaKlatka_10 = 0; // mob5
    float aktualnaKlatka_11 = 0; // mob6
    float aktualnaKlatka_12 = 0; // money silver 2
    float aktualnaKlatka_13 = 0; // money silver 3
    float aktualnaKlatka_14 = 0; // mob7
    float aktualnaKlatka_15 = 0; // life
    postac_sprite.setPosition(600,346);
    postac_sprite.setTextureRect( sf::IntRect(0,0,47,64)); //animacja chodzenia
    int space_click = 0;

    sf::Sprite ground;
    ground.setTexture(ground_t);
    ground.setPosition(0,480);

    //-------------FONT----------------------//
    sf::Font font;
    font.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/pixel-bit-advanced.ttf");
    sf::Text text;
    text.setFont(font);
    sf::Text text2;
    text2.setFont(font);
   

    //-------------BACKGROUND-----------------//
    sf::Sprite tlo;
    tlo.setTexture(background);
    tlo.setPosition(0,0);
    tlo.setTextureRect (sf::IntRect(0,0,896,504));

    //-------------GAMEOVER-----------------//
    sf::Sprite gameover;
    gameover.setTexture(game_overt);
    gameover.setPosition(148,72);

    //--------------MONEY-GOLD-------------------//
    sf::Sprite money;
    money.setTexture(money_t);
    money.setPosition(615,276);
    money.setTextureRect (sf::IntRect(0,0,16,16));

     //--------------MONEY-SILVER-------------------//
    sf::Sprite money2;
    money2.setTexture(money_t2);
    money2.setPosition(250,375);
    money2.setTextureRect (sf::IntRect(0,0,16,16));

     //--------------MONEY-SILVER2-------------------//
    sf::Sprite money3;
    money3.setTexture(money_t2);
    money3.setPosition(150,325);
    money3.setTextureRect (sf::IntRect(0,0,16,16));

     //--------------MONEY-SILVER3-------------------//
    sf::Sprite money4;
    money4.setTexture(money_t2);
    money4.setPosition(710,455);
    money4.setTextureRect (sf::IntRect(0,0,16,16));

    //---------------LIFE-------------------------//
    sf::Sprite life;
    life.setTexture(life_t);
    life.setPosition(650, 220);
    life.setTextureRect (sf::IntRect(0,0,32,32));

    //---------------LIFE-5-------------------------//
    sf::Sprite life1,life2,life3,life4,life5;
    life1.setTexture(life_t);
    life1.setPosition(10,5);
    life2.setTexture(life_t);
    life2.setPosition(42,5);
    life3.setTexture(life_t);
    life3.setPosition(74,5);
    life4.setTexture(life_t);
    life4.setPosition(106,5);
    life5.setTexture(life_t);
    life5.setPosition(138,5);
    life1.setTextureRect (sf::IntRect(0,0,32,32));
    life2.setTextureRect (sf::IntRect(0,0,32,32));
    life3.setTextureRect (sf::IntRect(0,0,32,32));
    life4.setTextureRect (sf::IntRect(0,0,32,32));
    life5.setTextureRect (sf::IntRect(0,0,32,32));

    //---------------MOB-1------------------------//
    sf::Sprite mob1;
    mob1.setTexture(mob1_t);
    mob1.setPosition(-400,448);
    mob1.setTextureRect (sf::IntRect(0,0,32,32));

    //---------------MOB-2------------------------//
    sf::Sprite mob2;
    mob2.setTexture(mob2_t);
    mob2.setPosition(-600,448);
    mob2.setTextureRect (sf::IntRect(0,0,32,32));

    //---------------MOB-3------------------------//
    sf::Sprite mob3;
    mob3.setTexture(mob5_t);
    mob3.setPosition(-500,348);
    mob3.setTextureRect (sf::IntRect(0,0,64,64));
    
    //---------------MOB-4------------------------//
    sf::Sprite mob4;
    mob4.setTexture(mob4_t);
    mob4.setPosition(1000,248);
    mob4.setTextureRect (sf::IntRect(0,0,64,64));

    //---------------MOB-5------------------------//
    sf::Sprite mob5;
    mob5.setTexture(mob5_t);
    mob5.setPosition(-300,248);
    mob5.setTextureRect (sf::IntRect(0,0,64,64));

    //---------------MOB-6------------------------//
    sf::Sprite mob6;
    mob6.setTexture(mob6_t);
    mob6.setPosition(-500,148);
    mob6.setTextureRect (sf::IntRect(0,0,64,64));

     //---------------MOB-7------------------------//
    sf::Sprite mob7;
    mob7.setTexture(mob7_t);
    mob7.setPosition(1500,118);
    mob7.setTextureRect (sf::IntRect(0,0,64,64));
    
    //-------------MUSIC-SOUNDS--------------//
    sf::Music background_music;
    background_music.openFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/backgroundmusic.wav");
    background_music.setPlayingOffset(sf::seconds(1));
    background_music.setVolume(2);
    background_music.play();
    

    sf::SoundBuffer jump_buffer;
    jump_buffer.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/jump_sound.wav");
    sf::Sound jump_sound;
    jump_sound.setVolume(15);
    jump_sound.setBuffer(jump_buffer); 

    sf::SoundBuffer money_buffer;
    money_buffer.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/money_sound.wav");
    sf::Sound money_sound;
    money_sound.setVolume(3);
    money_sound.setBuffer(money_buffer); 
    
    sf::SoundBuffer loselife_buffer;
    loselife_buffer.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/loselife_sound.wav");
    sf::Sound loselife_sound;
    loselife_sound.setVolume(12);
    loselife_sound.setBuffer(loselife_buffer); 

    sf::SoundBuffer gameover_buffer;
    gameover_buffer.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/gameover_sound.wav");
    sf::Sound gameover_sound;
    gameover_sound.setVolume(12);
    gameover_sound.setBuffer(gameover_buffer); 
    
    
    

    /* WALKING SOUND
    sf::SoundBuffer walking_buffer;
    walking_buffer.loadFromFile("/Users/qbusv3/Desktop/Gra Technologie Back up/Gra Technologie Back ups 1/Gra Technologie II v1/walking_sound.wav");
    sf::Sound walking_sound;
    walking_sound.setVolume(150);
    walking_sound.setBuffer(walking_buffer); 
    */  
    

    while(oknoAplikacji.isOpen())
    {
        if(zycie>0)
        {
        oknoAplikacji.clear( sf::Color::White );
        oknoAplikacji.draw(tlo);
        aktualnaKlatka_2 +=0.16;
        if (aktualnaKlatka_2 >4) aktualnaKlatka_2 -=4;
        tlo.setTextureRect(sf::IntRect(896*int(aktualnaKlatka_2),0,896,504));

        oknoAplikacji.draw(text);
        text.setString((std::to_string(score)));
        text.setPosition(173,37);
        oknoAplikacji.draw(text2);
        text2.setString("SCORE: ");
        text2.setPosition(16,37);

        switch(zycie)
        {
            case 1:
                oknoAplikacji.draw(life1);
                aktualnaKlatka_15 +=0.2;
                if (aktualnaKlatka_15 >4) aktualnaKlatka_15 -=4;
                life1.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
            break;
            case 2:
                oknoAplikacji.draw(life1);
                oknoAplikacji.draw(life2);
                aktualnaKlatka_15 +=0.2;
                if (aktualnaKlatka_15 >4) aktualnaKlatka_15 -=4;
                life1.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
                life2.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
            break;
            case 3:
                oknoAplikacji.draw(life1);
                oknoAplikacji.draw(life2);
                oknoAplikacji.draw(life3);
                aktualnaKlatka_15 +=0.2;
                if (aktualnaKlatka_15 >4) aktualnaKlatka_15 -=4;
                life1.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
                life2.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
                life3.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
            break;
            case 4:
                oknoAplikacji.draw(life1);
                oknoAplikacji.draw(life2);
                oknoAplikacji.draw(life3);
                oknoAplikacji.draw(life4);
                aktualnaKlatka_15 +=0.2;
                if (aktualnaKlatka_15 >4) aktualnaKlatka_15 -=4;
                life1.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
                life2.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
                life3.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
                life4.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
            break;
            case 5:
                oknoAplikacji.draw(life1);
                oknoAplikacji.draw(life2);
                oknoAplikacji.draw(life3);
                oknoAplikacji.draw(life4);
                oknoAplikacji.draw(life5);
                aktualnaKlatka_15 +=0.2;
                if (aktualnaKlatka_15 >4) aktualnaKlatka_15 -=4;
                life1.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
                life2.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
                life3.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
                life4.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));
                life5.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_15),0,32,32));

            break;
        }

        if(zycie < 3){
        oknoAplikacji.draw(life);
        aktualnaKlatka_6 +=0.2;
        if (aktualnaKlatka_6 >4) aktualnaKlatka_6 -=4;
        life.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_6),0,32,32));

         if (life.getGlobalBounds().intersects(postac_sprite.getGlobalBounds())) 
                {
                    money_sound.play();
                    life.setPosition(rand() % 790 + 50, rand()% 130 + 250);
                    zycie = zycie + (rand() % 2 + 1);
                }
        }
        
        
        oknoAplikacji.draw(money);
        aktualnaKlatka_3 +=0.2;
        if (aktualnaKlatka_3 >5) aktualnaKlatka_3 -=5;
        money.setTextureRect(sf::IntRect(16*int(aktualnaKlatka_3),0,16,16));

       if (money.getGlobalBounds().intersects(postac_sprite.getGlobalBounds())) 
                {
                    money_sound.play();
                    money.setPosition(rand() % 790 + 50, rand()% 380 + 70);
                    score = score +7;
                }
        
        oknoAplikacji.draw(money2);
        aktualnaKlatka_4 +=0.2;
        if (aktualnaKlatka_4 >5) aktualnaKlatka_4 -=5;
        money2.setTextureRect(sf::IntRect(16*int(aktualnaKlatka_4),0,16,16));

        if (money2.getGlobalBounds().intersects(postac_sprite.getGlobalBounds())) 
                {
                    money_sound.play();
                    money2.setPosition(rand() % 790 + 50, rand()% 260 + 50);
                    score = score +3;
                }
        
        oknoAplikacji.draw(money3);
        aktualnaKlatka_12 +=0.2;
        if (aktualnaKlatka_12 >5) aktualnaKlatka_12 -=5;
        money3.setTextureRect(sf::IntRect(16*int(aktualnaKlatka_12),0,16,16));

        if (money3.getGlobalBounds().intersects(postac_sprite.getGlobalBounds())) 
                {
                    money_sound.play();
                    money3.setPosition(rand() % 790 + 50, rand()% 150 + 200);
                    score = score +3;
                }
        
        oknoAplikacji.draw(money4);
        aktualnaKlatka_13 +=0.2;
        if (aktualnaKlatka_13 >5) aktualnaKlatka_13 -=5;
        money4.setTextureRect(sf::IntRect(16*int(aktualnaKlatka_13),0,16,16));

        if (money4.getGlobalBounds().intersects(postac_sprite.getGlobalBounds())) 
                {
                    money_sound.play();
                    money4.setPosition(rand() % 790 + 50, rand()% 350 + 100);
                    score = score +3;
                }
        

        oknoAplikacji.draw(mob1);
        aktualnaKlatka_5 +=0.2;
        if (aktualnaKlatka_5 >6) aktualnaKlatka_5 -=6;
        mob1.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_5),0,32,32));
        mob1.move(3,0);
        if(mob1.getPosition().x >= 1000)
        {
            mob1.setPosition(-400, 448);
        }
        if (mob1.getGlobalBounds().intersects(postac_sprite.getGlobalBounds()))
        {
            loselife_sound.play();
            mob1.setPosition(-400, 448);
            score = score - 8;
            zycie = zycie - 1;
        }

        oknoAplikacji.draw(mob2);
        aktualnaKlatka_7 +=0.2;
        if (aktualnaKlatka_7 >6) aktualnaKlatka_7 -=6;
        mob2.setTextureRect(sf::IntRect(32*int(aktualnaKlatka_7),0,32,32));
        mob2.move(6,0);
        if(mob2.getPosition().x >= 1200)
        {
            mob2.setPosition(-400, 448);
        }
        if (mob2.getGlobalBounds().intersects(postac_sprite.getGlobalBounds()))
        {
            loselife_sound.play();
            mob2.setPosition(-400, 448);
            score = score - 5;
            zycie = zycie - 1;
        }

        oknoAplikacji.draw(mob3);
        aktualnaKlatka_8 +=0.2;
        if (aktualnaKlatka_8 >4) aktualnaKlatka_8 -=4;
        mob3.setTextureRect(sf::IntRect(64*int(aktualnaKlatka_8),0,64,64));
        mob3.move(4.5,0);
        if(mob3.getPosition().x >= 950)
        {
            mob3.setPosition(-400, rand()% 130 + 250);
        }
        if (mob3.getGlobalBounds().intersects(postac_sprite.getGlobalBounds()))
        {
            loselife_sound.play();
            mob3.setPosition(-400, rand()% 130 + 280);
            score = score - 4;
            zycie = zycie - 1;
        }

        oknoAplikacji.draw(mob4);
        aktualnaKlatka_9 +=0.2;
        if (aktualnaKlatka_9 >4) aktualnaKlatka_9 -=4;
        mob4.setTextureRect(sf::IntRect(64*int(aktualnaKlatka_9),0,64,64));
        mob4.move(-8.5,0);
        if(mob4.getPosition().x <= -150)
        {
            mob4.setPosition(1100, rand()% 130 + 150);
        }
        if (mob4.getGlobalBounds().intersects(postac_sprite.getGlobalBounds()))
        {
            loselife_sound.play();
            mob4.setPosition(1000, rand()% 130 + 150);
            score = score - 3;
            zycie = zycie - 1;
        }

        oknoAplikacji.draw(mob5);
        aktualnaKlatka_10 +=0.2;
        if (aktualnaKlatka_10 >4) aktualnaKlatka_10 -=4;
        mob5.setTextureRect(sf::IntRect(64*int(aktualnaKlatka_10),0,64,64));
        mob5.move(9,0);
        if(mob5.getPosition().x >= 1550)
        {
            mob5.setPosition(-400,rand()% 130 + 150);
        }
        if (mob5.getGlobalBounds().intersects(postac_sprite.getGlobalBounds()))
        {
            loselife_sound.play();
            mob5.setPosition(-400,rand()% 130 + 150);
            score = score - 4;
            zycie = zycie - 1;
        }

        oknoAplikacji.draw(mob6);
        aktualnaKlatka_11 +=0.2;
        if (aktualnaKlatka_11 >4) aktualnaKlatka_11 -=4;
        mob6.setTextureRect(sf::IntRect(64*int(aktualnaKlatka_11),0,64,64));
        mob6.move(3,0);
        if(mob6.getPosition().x >= 1350)
        {
            mob6.setPosition(-100, rand()% 110 + 50);
        }
        if (mob6.getGlobalBounds().intersects(postac_sprite.getGlobalBounds()))
        {
            loselife_sound.play();
            mob6.setPosition(-200, rand()% 150 + 40);
            score = score - 9;
            zycie = zycie - 1;
        }

        oknoAplikacji.draw(mob7);
        aktualnaKlatka_14 +=0.2;
        if (aktualnaKlatka_14 >4) aktualnaKlatka_14 -=4;
        mob7.setTextureRect(sf::IntRect(64*int(aktualnaKlatka_11),0,64,64));
        mob7.move(-3.5,0);
        if(mob7.getPosition().x <= -200)
        {
            mob7.setPosition(1200, rand()% 250 + 40);
        }
        if (mob7.getGlobalBounds().intersects(postac_sprite.getGlobalBounds()))
        {
            loselife_sound.play();
            mob7.setPosition(1200, rand()% 170 + 40);
            score = score - 7;
            zycie = zycie - 1;
        }

        oknoAplikacji.draw(ground);
        sf::Event zdarzenie;


        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                 oknoAplikacji.close();
            
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 oknoAplikacji.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            //walking_sound.play();
            postac_sprite.setTexture(postac2);
            postac_sprite.move(-4,0);
            aktualnaKlatka +=0.09;
            if (aktualnaKlatka >4) aktualnaKlatka -=4;
            postac_sprite.setTextureRect(sf::IntRect(47*int(aktualnaKlatka),0,47,64));
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            //walking_sound.play();
            postac_sprite.setTexture(postac);
            postac_sprite.move(4,0);
            aktualnaKlatka +=0.09;
            if (aktualnaKlatka >4) aktualnaKlatka -=4;
            postac_sprite.setTextureRect(sf::IntRect(47*int(aktualnaKlatka),0,47,64));
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            space_click = space_click + 1;
            jump_sound.play();
            
            //auto start = std::chrono::steady_clock::now();
            
            if((postac_sprite.getPosition().y >=0))
            {
                postac_sprite.setTexture(postac2);
                postac_sprite.move(0,-12);
                aktualnaKlatka +=0.09;
                if (aktualnaKlatka >4) aktualnaKlatka -=4;
                postac_sprite.setTextureRect(sf::IntRect(47*int(aktualnaKlatka),0,47,64));
                //auto end = std::chrono::steady_clock::now();
                //double elapsed_time_ns = double (std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());
                //std:: cout << "time" << elapsed_time_ns;
            }    
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {

        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {   
            
             
        }
        if(postac_sprite.getPosition().y <= 417)
        {   
           
            postac_sprite.move(0,3.5);
        }
        if(postac_sprite.getPosition().x <= 1)
        {   
           
            postac_sprite.move(3,0);
        }
        if(postac_sprite.getPosition().x >= 852)
        {   
           
            postac_sprite.move(-3,0);
        }
        
       
        oknoAplikacji.draw(postac_sprite);
        oknoAplikacji.display();
    }
        
        if(zycie <=0)
        {
            oknoAplikacji.clear( sf::Color::Black );
            oknoAplikacji.draw(gameover);
            oknoAplikacji.draw(text);
            text.setString((std::to_string(score)));
            text.setPosition(410,450);
            oknoAplikacji.draw(text2);
            text2.setString("YOUR SCORE");
            text2.setPosition(300,400);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            gameover_sound.play();
            }
            sf::Event zdarzenie;
                while( oknoAplikacji.pollEvent( zdarzenie ) )
            {
                if( zdarzenie.type == sf::Event::Closed )
                    oknoAplikacji.close();
                
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                    oknoAplikacji.close();
            }
            oknoAplikacji.display();

        }
        
    }
    std::cout << "Score: " <<score <<std::endl;
    std::cout << "Life: " <<zycie <<std::endl;
    return 0;
}

//g++ -c main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_1/include
//g++ main.o -o main -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
// zautomatyzowane przez Makefile [make i make clean]
