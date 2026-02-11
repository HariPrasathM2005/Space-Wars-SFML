#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <conio.h>
#include <time.h>
#include <vector>
using namespace std;
using namespace sf;
int main()
{

    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    std::cout << "Desktop"  << "\t"
              << mode.width << "x" << mode.height << " \t "
              << mode.bitsPerPixel << " bpp" << std::endl;


    double screenaxisx, screenaxisy;
    screenaxisx = mode.width;
    screenaxisy = mode.height;
    RenderWindow app(sf::VideoMode(screenaxisx, screenaxisy), "SPACE WARS");



    double playeraxisx = screenaxisx - screenaxisx/2, playeraxisy = screenaxisy - 200;
    int x1 = 1, x2 = 1, x3 = 2, x4 = 2, x5 = 1, e1 = 3, e2 = 8, e3 = 13, e4 = 15, e5 = 20;
    double healthaxisy = -200;
    double  enemyaxisx = screenaxisx/8, enemyaxisy = -screenaxisy/4.5;//200, -200
    double enemybulletaxisy = enemyaxisy + screenaxisy/7.5, enemybulletaxisx = enemyaxisx + screenaxisx/32, playerbulletaxisy = playeraxisy - screenaxisy/90;
    double enemy2axisx = -screenaxisx/3.2 /*-500*/, enemy2axisy = 0, playerbulletaxisx = playeraxisx + screenaxisx/19.753, enemy2bulletaxisx = enemy2axisx + screenaxisx/8, enemy2bulletaxisy = enemy2axisy + screenaxisy/1.8;
    bool  enemycomingright = false, enemycomingleft = false;
    bool  finish = false, playerlife = true, enemylife = false, Enemy2life = false, Enemy3life = false, Enemy4life = false, enemy2comingright = true, enemy2comingleft = false, playershoots = false, enemyshoots = true, enemy2shoots = false, Gameover = false, enemytoarena = true, enemy2toarena = false, start = false, prestart = true;
    bool  enemy3shoots = false, enemy4shoots = false, gamestart = false, enemy1 = true, enemy2 = true, enemy3 = true, enemy4 = true, enemy5 = true, enemy3toarena = false, enemy3comingright = false, enemy3comingleft = false, enemy4comingright = false, enemy4comingleft = false;
    double enemy3axisx = -screenaxisx/4 /*-400*/, enemy3axisy = 0, enemy3bulletaxisy = enemy3axisy + screenaxisy/90, enemy3bulletaxisx = enemy3axisx + screenaxisx/80;
    double enemy4axisx = -screenaxisx/3.5555 /*-450*/, enemy4axisy = 0, enemy4bulletaxisy = enemy4axisy + 50, enemy4bulletaxisx = enemy4axisx + 20;
    double enemy5axisx = -screenaxisx/3.2 /*500*/, enemy5axisy = 0, enemy5bulletaxisy = enemy5axisy + screenaxisy/2.30769, enemy5bulletaxisx = enemy5axisx + screenaxisx/26.6666;
    bool enemy5comingright = false, enemy5comingleft = false, enemy5shoots = false, Enemy5life = false, healthshow = true;
    int start_time, current_time, present_time, enemystart_time, enemycurrent_time, enemypresent_time, enemy2start_time, enemy2current_time, enemy2present_time;
    bool num1 = false, num2 = false, num3 = false, spritemoves = false, playershot = false, enemy5shot = false, enemy5lifeshow = false, playershotwithlaser = false;
    double spriteaxisy = 1000, noofplayerlife = 15, noofenemy5life = e5;
    bool enemyshot = false, enemy2shot = false, enemy3shot = false, enemy4shot = false;
    bool enemylifeshow = false, enemy2lifeshow = false, enemy3lifeshow = false, enemy4lifeshow = false, healthentry = false;
    double noofenemylife = e1, noofenemy2life = e2, noofenemy3life = e3, noofenemy4life = e4;
    double difficulty = 1250;
    bool showcity = false, Vehiclemoves = false;
    double Bus1axisx = 1750, Bus2axisx = 3300, Car1axisx = 1800;
    int enemy3start_time, enemy3current_time, enemy3present_time, enemy4start_time, enemy4current_time, enemy4present_time, enemy5start_time, enemy5current_time, enemy5present_time;
    int endstart_time, endcurrent_time, endpresent_time;
    bool level2 = true;


    Clock clock;    // starts the clock
    Clock enemyclock;
    Clock enemy2clock;
    Clock enemy3clock;
    Clock enemy4clock;
    Clock enemy5clock;
    Clock endclock;

    double player_x  = screenaxisx/8000, player_y = screenaxisy/4500;

    Texture playerTexture;
    playerTexture.loadFromFile("Player.png");
    Sprite playerSprite(playerTexture);
    playerSprite.setScale(player_x, player_y);//0.2f, 0.2f

    Texture enemyTexture;
    enemyTexture.loadFromFile("Enemy.png");
    Sprite enemySprite(enemyTexture);
    enemySprite.setScale(player_x, player_y);//0.2f, 0.2f

    double enemy2_x = screenaxisx/1454.5454, enemy2_y = screenaxisy/818.1818;

    Texture enemy2Texture;
    enemy2Texture.loadFromFile("Enemy 2.png");
    Sprite enemy2Sprite(enemy2Texture);
    enemy2Sprite.setScale(enemy2_x, enemy2_y);//1.1f, 1.1f

    double enemy3_x = screenaxisx/5333.333, enemy3_y = screenaxisy/3000;

    Texture enemy3Texture;
    enemy3Texture.loadFromFile("Enemy 3.png");
    Sprite enemy3Sprite(enemy3Texture);
    enemy3Sprite.setScale(enemy3_x, enemy3_y);//0.3f,0.3f

    Texture enemy4Texture;
    enemy4Texture.loadFromFile("Enemy 4.png");
    Sprite enemy4Sprite(enemy4Texture);
    enemy4Sprite.setScale(screenaxisx/1600, screenaxisy/900);

    double enemy5_x = screenaxisx/1230.769, enemy5_y = screenaxisy/692.307;

    Texture enemy5Texture;
    enemy5Texture.loadFromFile("Enemy 5.png");
    Sprite enemy5Sprite(enemy5Texture);
    enemy5Sprite.setScale(enemy5_x, enemy5_y);//1.3f, 1.3f

    Texture HealthTexture;
    HealthTexture.loadFromFile("Health.png");
    Sprite HealthSprite(HealthTexture);
    HealthSprite.setScale(enemy3_x, enemy3_y);//0.3f, 0.3f




    Texture BackgroundTexture;
    BackgroundTexture.loadFromFile("space1.png");
    Sprite backgroundSprite(BackgroundTexture);
    backgroundSprite.setScale(enemy5_x, enemy5_y);//1.3f,1.3f






    Texture Background2Texture;
    Background2Texture.loadFromFile("Building.png");
    Sprite background2Sprite(Background2Texture);

    Texture roadTexture;
    roadTexture.loadFromFile("Road.jpg");
    Sprite RoadSprite(roadTexture);

    Texture road2Texture;
    road2Texture.loadFromFile("Road.jpg");
    Sprite Road2Sprite(road2Texture);


    double optionscale_x = screenaxisx/3200;

    Texture OptionTexture;
    OptionTexture.loadFromFile("Start Button.png");
    Sprite  optionsprites[10];
    for (int i = 0; i < 10; i++)
    {
        optionsprites[i] =  Sprite(OptionTexture);
        optionsprites[i].setScale(optionscale_x, optionscale_x);//0.5f,0.5f
    }

    double sprites_x = screenaxisx/16000, sprites_y = screenaxisy/9000;

    Texture  enemybulletTexture;
    enemybulletTexture.loadFromFile("Enemy Bullet.png");
    Sprite  sprites[100];
    for (int i = 0; i < 100; ++i)
    {
        sprites[i] =  Sprite(enemybulletTexture);
        sprites[i].setScale(sprites_x, sprites_y);//0.1f, 0.1f
    }

    Texture  enemylaserbulletTexture;
    enemylaserbulletTexture.loadFromFile("Red laser.png");        //laser bullet
    Sprite  lasersprites[100];
    for (int i = 0; i < 100; ++i)
    {
        lasersprites[i] =  Sprite(enemylaserbulletTexture);
        lasersprites[i].setScale(sprites_x, sprites_y);
    }


    Font Tittle;
    Tittle.loadFromFile("arimonbd.ttf");
    Text textTittle("SPACE WARS", Tittle, screenaxisy/9);//100

    Font Finish;
    Finish.loadFromFile("arimonbd.ttf");
    Text textfinish("MISSION ACCOMPLISHED", Finish, screenaxisy/9);//100

    Font life;
    life.loadFromFile("arimonbd.ttf");
    Text textPlayerlife("LIFE:", life, screenaxisy/45);//20


    Font Enemy5Life;
    Enemy5Life.loadFromFile("arimonbd.ttf");
    Text textEnemy5Life("ENEMY 5 LIFE:", Enemy5Life, screenaxisy/45);//20

    Font Enemy4Life;
    Enemy4Life.loadFromFile("arimonbd.ttf");
    Text textEnemy4Life("ENEMY 4 LIFE:", Enemy4Life, screenaxisy/45);//20

    Font Enemy3Life;
    Enemy3Life.loadFromFile("arimonbd.ttf");
    Text textEnemy3Life("ENEMY 3 LIFE:", Enemy3Life, screenaxisy/45);//20

    Font Enemy2Life;
    Enemy2Life.loadFromFile("arimonbd.ttf");
    Text textEnemy2Life("ENEMY 2 LIFE:", Enemy2Life, screenaxisy/45);//20

    Font EnemyLife;
    EnemyLife.loadFromFile("arimonbd.ttf");
    Text textEnemyLife("ENEMY 1 LIFE:", EnemyLife, screenaxisy/45);//20

    Font Difficulty;
    Difficulty.loadFromFile("arimonbd.ttf");
    Text textdifficulty("NUM 1 - EASY, NUM 2 - NORMAL\n\t NUM 3 - HARD", Difficulty , screenaxisy/18);//50

    Font Peacefull;
    Peacefull.loadFromFile("arimonbd.ttf");
    Text textpeacefull("YOU MADE OUR EARTH PEACEFULL", Peacefull , screenaxisy/18);//50

    Texture Bus1Texture;
    Bus1Texture.loadFromFile("Bus 1.png");
    Sprite Bus1sprite(Bus1Texture);
    Bus1sprite.setScale(enemy5_x, enemy5_y);

    double Bus2_x = screenaxisx/2000, Bus2_y = screenaxisy/1406.25;

    Texture Bus2Texture;
    Bus2Texture.loadFromFile("Bus 2.png");
    Sprite Bus2sprite(Bus2Texture);
    Bus2sprite.setScale(Bus2_x, Bus2_y);//0.8f, 0.8f

    double Car1_x = screenaxisx/3200, Car1_y = screenaxisy/1800;

    Texture Car1Texture;
    Car1Texture.loadFromFile("Car 1.png");
    Sprite Car1sprite(Car1Texture);
    Car1sprite.setScale(Car1_x, Car1_y);//0.5f,0.5f











    Font n20;
    n20.loadFromFile("arimonbd.ttf");
    Text textn20("20", n20, screenaxisy/45);//20

    Font n19;
    n19.loadFromFile("arimonbd.ttf");
    Text textn19("19", n19, screenaxisy/45);//20

    Font n18;
    n18.loadFromFile("arimonbd.ttf");
    Text textn18("18", n18, screenaxisy/45);//20

    Font n17;
    n17.loadFromFile("arimonbd.ttf");
    Text textn17("17", n17, screenaxisy/45);//20

    Font n16;
    n16.loadFromFile("arimonbd.ttf");
    Text textn16("16", n16, screenaxisy/45);//20

    Font n15;
    n15.loadFromFile("arimonbd.ttf");
    Text textn15("15", n15, screenaxisy/45);//20

    Font n14;
    n14.loadFromFile("arimonbd.ttf");
    Text textn14("14", n14, screenaxisy/45);//20

    Font n13;
    n13.loadFromFile("arimonbd.ttf");
    Text textn13("13", n13, screenaxisy/45);//20

    Font n12;
    n12.loadFromFile("arimonbd.ttf");
    Text textn12("12", n12, screenaxisy/45);//20

    Font n11;
    n11.loadFromFile("arimonbd.ttf");
    Text textn11("11", n11, screenaxisy/45);//20

    Font n10;
    n10.loadFromFile("arimonbd.ttf");
    Text textn10("10", n10, screenaxisy/45);//20

    Font n9;
    n9.loadFromFile("arimonbd.ttf");
    Text textn9("9", n9, screenaxisy/45);//20

    Font n8;
    n8.loadFromFile("arimonbd.ttf");
    Text textn8("8", n8, screenaxisy/45);//20

    Font n7;
    n7.loadFromFile("arimonbd.ttf");
    Text textn7("7", n7, screenaxisy/45);//20

    Font n6;
    n6.loadFromFile("arimonbd.ttf");
    Text textn6("6", n6, screenaxisy/45);//20

    Font n5;
    n5.loadFromFile("arimonbd.ttf");
    Text textn5("5", n5, screenaxisy/45);//20

    Font n4;
    n4.loadFromFile("arimonbd.ttf");
    Text textn4("4", n4, screenaxisy/45);//20

    Font n3;
    n3.loadFromFile("arimonbd.ttf");
    Text textn3("3", n3, screenaxisy/45);//20

    Font n2;
    n2.loadFromFile("arimonbd.ttf");
    Text textn2("2", n2, screenaxisy/45);//20

    Font n1;
    n1.loadFromFile("arimonbd.ttf");
    Text textn1("1", n1, screenaxisy/45);//20

    Font Credits;
    Finish.loadFromFile("arimonbd.ttf");
    Text textCredits("GAME DONE BY: HARI PRASATH M", Finish, screenaxisy/18);//50

    Font Credits2;
    Finish.loadFromFile("arimonbd.ttf");
    Text textCredits2("GAME DONE BY USING: C++, SFML 2.5.1", Finish, screenaxisy/18);//50


    Font GameOver;
    GameOver.loadFromFile("arimonbd.ttf");
    Text textGameOver("MISSION FAILED", Finish, screenaxisy/9);//100

    Music BGM1;
    if (!BGM1.openFromFile("Space Wars BGM1.ogg"))
        return EXIT_FAILURE;

    Music Shoot;
    if (!Shoot.openFromFile("Shoot.ogg"))
        return EXIT_FAILURE;

    Music Explosion;
    if (!Explosion.openFromFile("Sonic Boom.wav"))
        return EXIT_FAILURE;



    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            if(gamestart)
            {
                if(playerlife)
                {
                    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
                    {
                        if(playeraxisy >= 0)
                        {
                            playeraxisy = playeraxisy - screenaxisy/90;//10
                            playerbulletaxisy = playerbulletaxisy - screenaxisy/90;//10
                        }
                    }
                    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
                    {
                        if(playeraxisy <= screenaxisy - screenaxisy/4.285)//screenaxisy-210
                        {
                            playeraxisy = playeraxisy + screenaxisy/90;//10
                            playerbulletaxisy = playerbulletaxisy + screenaxisy/90;//10
                        }
                    }
                    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
                    {
                        if(playeraxisx <= screenaxisx - screenaxisx/10)//1440
                        {
                            playeraxisx = playeraxisx + screenaxisx/160;//10
                            playerbulletaxisx = playerbulletaxisx + screenaxisx/160;//10
                        }
                    }
                    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
                    {
                        if(playeraxisx >= 0)
                        {
                            playeraxisx = playeraxisx - screenaxisx/160;//10
                            playerbulletaxisx = playerbulletaxisx - screenaxisx/160;//10
                        }
                    }
                    if(event.type == sf::Event::MouseButtonPressed)
                    {
                        if(event.mouseButton.button == sf::Mouse::Left)
                        {
                            sprites[0].setPosition(playeraxisx + screenaxisx/19.75308,playeraxisy - screenaxisy/90);//81, -10
                            playershoots = true;
                            Shoot.play();
                        }
                    }
                }
            }
            if(prestart)
            {
                sf::FloatRect  Startbutton_bounds = optionsprites[1].getGlobalBounds();
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2f mouse = app.mapPixelToCoords(sf::Mouse::getPosition(app));
                    if (Startbutton_bounds.contains(mouse))
                    {
                        prestart = false;
                        gamestart = true;
                        BGM1.play();
                        Time elapsed1 = clock.getElapsedTime();
                        start_time = elapsed1.asSeconds();
                        Time enemyelapsed1 = enemyclock.getElapsedTime();
                        enemystart_time = enemyelapsed1.asSeconds();

                        Time enemy2elapsed1 = enemy2clock.getElapsedTime();
                        enemy2start_time = enemy2elapsed1.asSeconds();

                        Time enemy3elapsed1 = enemy3clock.getElapsedTime();
                        enemy3start_time = enemy3elapsed1.asSeconds();

                        Time enemy4elapsed1 = enemy4clock.getElapsedTime();
                        enemy4start_time = enemy4elapsed1.asSeconds();

                        Time enemy5elapsed1 = enemy5clock.getElapsedTime();
                        enemy5start_time = enemy5elapsed1.asSeconds();

                        Time endelapsed1 = endclock.getElapsedTime();
                        endstart_time = endelapsed1.asSeconds();
                    }
                }
                if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num1))
                    x1 = 1, x2 = 2, x3 = 3, x4 = 3, x5 = 3, e1 = 2, e2 = 6, e3 = 11, e4 = 13, e5 = 16, difficulty = 2000;
                if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num2))
                    x1 = 1, x2 = 2, x3 = 2, x4 = 2, x5 = 2, e1 = 3, e2 = 8, e3 = 13, e4 = 15, e5 = 18, difficulty = 1750;
                if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num3))
                    x1 = 1, x2 = 1, x3 = 1, x4 = 1, x5 = 1, e1 = 5, e2 = 10, e3 = 15, e4 = 17, e5 = 20, difficulty = 1250;
            }
        }
        if(gamestart)
        {
            Time elapsed2 = clock.getElapsedTime();
            current_time =  elapsed2.asSeconds();
            present_time = current_time - start_time;

            if(enemy1)
            {
                if(present_time >= 5)
                {
                    start = true;
                    enemylife = true;
                }
            }
            if(enemy2)
            {
                if(present_time >= 20)
                    Enemy2life = true;
            }
            if(enemy3)
            {
                if(present_time >= 60)
                    Enemy3life = true;
            }
            if(enemy4)
            {
                if(present_time >= 120)
                    Enemy4life = true;
            }
            if(enemy5)
            {
                if(present_time >= 240)
                    Enemy5life = true;
            }
        }
        if(start)
        {
            sf::FloatRect  Health_bounds = HealthSprite.getGlobalBounds();
            sf::FloatRect  player_bounds = playerSprite.getGlobalBounds();
            sf::FloatRect  enemy_bounds = enemySprite.getGlobalBounds();
            sf::FloatRect  enemy2_bounds = enemy2Sprite.getGlobalBounds();
            sf::FloatRect  enemy3_bounds = enemy3Sprite.getGlobalBounds();
            sf::FloatRect  enemy4_bounds = enemy4Sprite.getGlobalBounds();
            sf::FloatRect  enemy5_bounds = enemy5Sprite.getGlobalBounds();

            sf::FloatRect  playerbullet_bounds = sprites[0].getGlobalBounds();            //player

            sf::FloatRect  enemybullet_bounds = sprites[1].getGlobalBounds();           //enemy1

            sf::FloatRect  enemy2bullet_bounds = sprites[2].getGlobalBounds();
            sf::FloatRect  enemy2bullet2_bounds = sprites[3].getGlobalBounds();         //enemy2
            sf::FloatRect  enemy2bullet3_bounds = sprites[4].getGlobalBounds();

            sf::FloatRect  enemy3bullet_bounds = sprites[5].getGlobalBounds();
            sf::FloatRect  enemy3bullet2_bounds = sprites[6].getGlobalBounds();             //enemy3
            sf::FloatRect  enemy3bullet3_bounds = sprites[7].getGlobalBounds();
            sf::FloatRect  enemy3bullet4_bounds = sprites[8].getGlobalBounds();
            sf::FloatRect  enemy3bullet5_bounds = sprites[9].getGlobalBounds();

            sf::FloatRect enemy4bullet_bounds = lasersprites[1].getGlobalBounds();
            sf::FloatRect enemy4bullet2_bounds = lasersprites[2].getGlobalBounds();         //enemy4
            sf::FloatRect enemy4bullet3_bounds = lasersprites[3].getGlobalBounds();
            sf::FloatRect enemy4bullet4_bounds = lasersprites[4].getGlobalBounds();

            sf::FloatRect enemy5bullet_bounds = lasersprites[5].getGlobalBounds();
            sf::FloatRect enemy5bullet2_bounds = lasersprites[6].getGlobalBounds();         //enemy5
            sf::FloatRect enemy5bullet3_bounds = lasersprites[7].getGlobalBounds();
            sf::FloatRect enemy5bullet4_bounds = lasersprites[8].getGlobalBounds();
            sf::FloatRect  enemy5bullet5_bounds = sprites[10].getGlobalBounds();
            sf::FloatRect  enemy5bullet6_bounds = sprites[11].getGlobalBounds();         //enemy2
            sf::FloatRect  enemy5bullet7_bounds = sprites[12].getGlobalBounds();
            if(finish == false)
            {
                if(player_bounds.intersects(enemy_bounds))
                    Gameover = true;

                if(player_bounds.intersects(enemy2_bounds))
                    Gameover = true;

                if(player_bounds.intersects(enemy3_bounds))
                    Gameover = true;

                if(player_bounds.intersects(enemy4_bounds))
                    Gameover = true;

                if(player_bounds.intersects(enemy5_bounds))
                    Gameover = true;

                if (enemybullet_bounds.intersects(player_bounds))
                {
                    enemybulletaxisy = enemyaxisy + screenaxisy/9;//100
                    enemybulletaxisx = enemyaxisx + screenaxisx/20;//80
                    playershot = true;
                }



                if (enemy2bullet_bounds.intersects(player_bounds))
                {
                    enemy2bulletaxisx = enemy2axisx + screenaxisx/53.3333;//30
                    enemy2bulletaxisy = enemy2axisy + screenaxisy/11.25;//80
                    playershot = true;
                }
                if (enemy2bullet2_bounds.intersects(player_bounds))
                {
                    enemy2bulletaxisx = enemy2axisx + screenaxisx/53.3333;//30
                    enemy2bulletaxisy = enemy2axisy + screenaxisy/11.25;//80
                    playershot = true;
                }
                if (enemy2bullet3_bounds.intersects(player_bounds))
                {
                    enemy2bulletaxisx = enemy2axisx + screenaxisx/53.3333;//30
                    enemy2bulletaxisy = enemy2axisy + screenaxisy/11.25;//80
                    playershot = true;
                }



                if (enemy3bullet_bounds.intersects(player_bounds))
                {
                    enemy3bulletaxisy = enemy3axisy + enemyaxisy/18;//50
                    enemy3bulletaxisx = enemy3axisx + enemyaxisx/320;//5
                    playershot = true;
                }

                if (enemy3bullet2_bounds.intersects(player_bounds))
                {
                    enemy3bulletaxisy = enemy3axisy + enemyaxisy/18;//50
                    enemy3bulletaxisx = enemy3axisx + enemyaxisx/320;//80
                    playershot = true;
                }
                if (enemy3bullet3_bounds.intersects(player_bounds))
                {
                    enemy3bulletaxisy = enemy3axisy + enemyaxisy/18;//50
                    enemy3bulletaxisx = enemy3axisx + enemyaxisx/320;//80
                    playershot = true;
                }
                if (enemy3bullet4_bounds.intersects(player_bounds))
                {
                    enemy3bulletaxisy = enemy3axisy + enemyaxisy/18;//50
                    enemy3bulletaxisx = enemy3axisx + enemyaxisx/320;//80
                    playershot = true;
                }
                if (enemy3bullet5_bounds.intersects(player_bounds))
                {
                    enemy3bulletaxisy = enemy3axisy + enemyaxisy/18;//50
                    enemy3bulletaxisx = enemy3axisx + enemyaxisx/320;//80
                    playershot = true;
                }



                if (enemy4bullet_bounds.intersects(player_bounds))
                {
                    enemy4bulletaxisy = enemy4axisy + screenaxisy/6.92307;//130
                    enemy4bulletaxisx = enemy4axisx + screenaxisx/53.33333;//30
                    playershotwithlaser = true;
                }
                if (enemy4bullet2_bounds.intersects(player_bounds))
                {
                    enemy4bulletaxisy = enemy4axisy + screenaxisy/6.92307;//130
                    enemy4bulletaxisx = enemy4axisx + screenaxisx/53.33333;//30
                    playershotwithlaser = true;
                }
                if (enemy4bullet3_bounds.intersects(player_bounds))
                {
                    enemy4bulletaxisy = enemy4axisy + screenaxisy/6.92307;//130
                    enemy4bulletaxisx = enemy4axisx + screenaxisx/53.33333;//30
                    playershotwithlaser = true;
                }
                if (enemy4bullet4_bounds.intersects(player_bounds))
                {
                    enemy4bulletaxisy = enemy4axisy + screenaxisy/6.92307;//130
                    enemy4bulletaxisx = enemy4axisx + screenaxisx/53.33333;//30
                    playershotwithlaser = true;
                }



                if (enemy5bullet_bounds.intersects(player_bounds))
                {
                    enemy5bulletaxisy = enemy5axisy + screenaxisy/2.30769;
                    enemy5bulletaxisx = enemy5axisx + screenaxisx/26.6666;
                    playershotwithlaser = true;
                }
                if (enemy5bullet2_bounds.intersects(player_bounds))
                {
                    enemy5bulletaxisy = enemy5axisy + screenaxisy/2.30769;
                    enemy5bulletaxisx = enemy5axisx + screenaxisx/26.6666;
                    playershotwithlaser = true;
                }
                if (enemy5bullet3_bounds.intersects(player_bounds))
                {
                    enemy5bulletaxisy = enemy5axisy + screenaxisy/2.30769;
                    enemy5bulletaxisx = enemy5axisx + screenaxisx/26.6666;
                    playershotwithlaser = true;
                }
                if (enemy5bullet4_bounds.intersects(player_bounds))
                {
                    enemy5bulletaxisy = enemy5axisy + screenaxisy/2.30769;
                    enemy5bulletaxisx = enemy5axisx + screenaxisx/26.6666;
                    playershotwithlaser = true;
                }
                if (enemy5bullet5_bounds.intersects(player_bounds))
                {
                    enemy5bulletaxisy = enemy5axisy + screenaxisy/2.30769;
                    enemy5bulletaxisx = enemy5axisx + screenaxisx/26.6666;
                    playershot = true;
                }
                if (enemy5bullet6_bounds.intersects(player_bounds))
                {
                    enemy5bulletaxisy = enemy5axisy + screenaxisy/2.30769;
                    enemy5bulletaxisx = enemy5axisx + screenaxisx/26.6666;
                    playershot = true;
                }
                if (enemy5bullet7_bounds.intersects(player_bounds))
                {
                    enemy5bulletaxisy = enemy5axisy + screenaxisy/2.30769;
                    enemy5bulletaxisx = enemy5axisx + screenaxisx/26.6666;
                    playershot = true;
                }

                if(playershotwithlaser)
                {
                    noofplayerlife = noofplayerlife - 2;
                    playershotwithlaser = false;
                }
                if(playershot)
                {
                    noofplayerlife = noofplayerlife - 1;
                    playershot = false;
                }
                if(noofplayerlife <= 0)
                {
                    Gameover = true;
                }



                if(noofenemy5life <= 0)
                    finish = true;
                if(noofenemylife <= 0)
                {
                    noofenemylife = e1;
                    enemyaxisx = -screenaxisx;
                    enemybulletaxisx = 100 * screenaxisx;
                    Explosion.stop();
                }
                if(noofenemy2life <= 0)
                {
                    noofenemy2life = e2;
                    enemy2axisx = -screenaxisx;
                    enemy2bulletaxisx = 100 * screenaxisx;
                    Explosion.stop();
                }
                if(noofenemy3life <= 0)
                {
                    noofenemy3life = e3;
                    enemy3axisx = -screenaxisx;
                    enemy3bulletaxisx = 100 * screenaxisx;
                    Explosion.stop();
                }
                if(noofenemy4life <= 0)
                {
                    noofenemy4life = e4;
                    enemy4axisx = -screenaxisx;
                    enemy4bulletaxisx = 100 * screenaxisx;
                    Explosion.stop();
                }
                if(enemyshot)
                {
                    noofenemylife = noofenemylife - 1;
                    enemyshot = false;
                }
                if(enemy2shot)
                {
                    noofenemy2life = noofenemy2life - 1;
                    enemy2shot = false;
                }
                if(enemy3shot)
                {
                    noofenemy3life = noofenemy3life - 1;
                    enemy3shot = false;
                }
                if(enemy4shot)
                {
                    noofenemy4life = noofenemy4life - 1;
                    enemy4shot = false;
                }
                if(enemy5shot)
                {
                    noofenemy5life = noofenemy5life - 1;
                    enemy5shot = false;
                }



            //for player


                if (playerbullet_bounds.intersects(enemy_bounds))
                {
                    playerbulletaxisy = playeraxisy;
                    playershoots = false;
                    enemyshot = true;
                    Explosion.play();
                }
                if (playerbullet_bounds.intersects(enemy2_bounds))
                {
                    playerbulletaxisy = playeraxisy;
                    playershoots = false;
                    enemy2shot = true;
                    Explosion.play();
                }
                if (playerbullet_bounds.intersects(enemy3_bounds))
                {
                    playerbulletaxisy = playeraxisy;
                    playershoots = false;
                    enemy3shot = true;
                    Explosion.play();
                }
                if (playerbullet_bounds.intersects(enemy4_bounds))
                {
                    playerbulletaxisy = playeraxisy;
                    playershoots = false;
                    enemy4shot = true;
                    Explosion.play();
                }
                if (playerbullet_bounds.intersects(enemy5_bounds))
                {
                    playerbulletaxisy = playeraxisy;
                    playershoots = false;
                    enemy5shot = true;
                    Explosion.play();
                }
                if (player_bounds.intersects(Health_bounds))
                {
                    noofplayerlife = 15;
                    healthaxisy = -1000;
                }
            }

            if(enemylife)
            {
                healthentry = true;
                enemyshoots = true;
                if(enemytoarena)
                {
                    enemyaxisy = enemyaxisy + screenaxisx/16000;//0.1
                    enemycomingright = true;
                }
                if(enemycomingright)
                    enemyaxisx = enemyaxisx + screenaxisx/16000;//0.1
                if(enemycomingleft)
                    enemyaxisx = enemyaxisx - screenaxisx/16000;//0.1
                if(enemyaxisx >= screenaxisx/1.1428)//1400
                {
                    enemycomingleft = true;
                    enemycomingright = false;
                }
                if(enemyaxisy >= screenaxisy/4.5)//200
                    enemytoarena = false;
                if(enemyaxisx <= 0)
                {
                    enemycomingleft = false;
                    enemycomingright = true;
                }
            }

            if(Enemy2life)
            {
                if(enemy2toarena)
                {
                    enemy2axisy = enemy2axisy + screenaxisx/16000;//0.1
                    enemy2comingright = true;
                }
                if(enemy2comingright)
                {
                    enemy2axisx = enemy2axisx + screenaxisx/16000;//0.1
                    enemy2shoots = true;
                }
                if(enemy2comingleft)
                    enemy2axisx = enemy2axisx - screenaxisx/16000;//0.1
                if(enemy2axisx >= screenaxisx/1.2307)//1300
                {
                    enemy2comingleft = true;
                    enemy2comingright = false;
                }
                if(enemy2axisx <= 0)
                {
                    enemy2comingleft = false;
                    enemy2comingright = true;
                }

            }

            if (Enemy3life)
            {
                enemy3shoots = true;
                if(enemy3comingright)
                {
                    enemy3axisx = enemy3axisx + screenaxisx/16000;//0.1
                    enemy3toarena = false;
                }
                if(enemy3comingleft)
                    enemy3axisx = enemy3axisx - screenaxisx/16000;//0.1
                if(enemy3axisx >= screenaxisx/1.3333)//1200
                {
                    enemy3comingleft = true;
                    enemy3comingright = false;
                    enemy3shoots = true;
                }
                if(enemy3axisx <= 0)
                {
                    enemy3comingleft = false;
                    enemy3comingright = true;
                }
            }

            if (Enemy4life)
            {
                enemy4shoots = true;
                if(enemy4comingright)
                    enemy4axisx = enemy4axisx + screenaxisx/16000;//0.1
                if(enemy4comingleft)
                    enemy4axisx = enemy4axisx - screenaxisx/16000;//0.1
                if(enemy4axisx >= screenaxisx/1.3333)//1200
                {
                    enemy4comingleft = true;
                    enemy4comingright = false;
                    enemy4shoots = true;
                }
                if(enemy4axisx <= 0)
                {
                    enemy4comingleft = false;
                    enemy4comingright = true;
                }
            }

            if (Enemy5life)
            {
                enemy5shoots = true;
                if(enemy5comingright)
                    enemy5axisx = enemy5axisx + screenaxisx/16000;//0.1
                if(enemy5comingleft)
                    enemy5axisx = enemy5axisx - screenaxisx/16000;//0.1
                if(enemy5axisx >= screenaxisx/1.4545)
                {
                    enemy5comingleft = true;
                    enemy5comingright = false;
                    enemy5shoots = true;
                }
                if(enemy5axisx <= screenaxisx/32)
                {
                    enemy5comingleft = false;
                    enemy5comingright = true;
                }
            }


            if(enemyshoots)
                enemybulletaxisy = enemybulletaxisy + screenaxisy/1000;//0.9          //bullet speed
            if(enemy2shoots)
                enemy2bulletaxisy = enemy2bulletaxisy + screenaxisy/1000;//0.9
            if(enemy3shoots)
                enemy3bulletaxisy = enemy3bulletaxisy + screenaxisy/1000;//0.9
            if(enemy4shoots)
                enemy4bulletaxisy = enemy4bulletaxisy + screenaxisy/1000;//0.9
            if(enemy5shoots)
                enemy5bulletaxisy = enemy5bulletaxisy + screenaxisy/1000;//0.9



            Time enemyelapsed2 = enemyclock.getElapsedTime();
            enemycurrent_time =  enemyelapsed2.asSeconds();
            enemypresent_time = enemycurrent_time - enemystart_time;

            Time enemy2elapsed2 = enemy2clock.getElapsedTime();
            enemy2current_time =  enemy2elapsed2.asSeconds();
            enemy2present_time = enemy2current_time - enemystart_time;

            Time enemy3elapsed2 = enemy3clock.getElapsedTime();
            enemy3current_time =  enemy3elapsed2.asSeconds();
            enemy3present_time = enemy3current_time - enemystart_time;

            Time enemy4elapsed2 = enemy4clock.getElapsedTime();
            enemy4current_time =  enemy4elapsed2.asSeconds();
            enemy4present_time = enemy4current_time - enemystart_time;

            Time enemy5elapsed2 = enemy5clock.getElapsedTime();
            enemy5current_time =  enemy5elapsed2.asSeconds();
            enemy5present_time = enemy5current_time - enemystart_time;
            if(enemybulletaxisy >= screenaxisy + 100)
            {
                if(enemypresent_time >= x1)
                {
                    enemyclock.restart();
                    enemybulletaxisy = enemyaxisy + screenaxisy/9;//100
                    enemybulletaxisx = enemyaxisx + screenaxisx/20;//80
                }
            }
            if(enemy2bulletaxisy >= screenaxisy + 100)
            {
                if(enemy2present_time >= x2)
                {
                    enemy2clock.restart();
                    enemy2bulletaxisy = enemy2axisy + screenaxisy/11.25;//80
                    enemy2bulletaxisx = enemy2axisx + screenaxisy/45.714;//35
                }
            }
            if(enemy3bulletaxisy >= screenaxisy + 100)
            {
                if(enemy3present_time >= x3)
                {
                    enemy3clock.restart();
                    enemy3bulletaxisy = enemy3axisy + screenaxisy/15;//60
                    enemy3bulletaxisx = enemy3axisx + screenaxisx/320;//5
                }
            }
            if(enemy4bulletaxisy >= screenaxisy + 100)
            {
                if(enemy4present_time >= x4)
                {
                    enemy4clock.restart();
                    enemy4bulletaxisy = enemy4axisy + screenaxisy/6.428;//140
                    enemy4bulletaxisx = enemy4axisx + screenaxisx/53.333;//30
                }
            }
            if(enemy5bulletaxisy >= screenaxisy + 100)
            {
                if(enemy5present_time >= x5)
                {
                    enemy5clock.restart();
                    enemy5bulletaxisy = enemy5axisy + screenaxisy/2.307;//390
                    enemy5bulletaxisx = enemy5axisx + screenaxisx/26.666;//60
                }
            }
        }

        if(gamestart)
        {

            if(playershoots) playerbulletaxisy = playerbulletaxisy - screenaxisx/533.3333;//3
            if (playerbulletaxisy <= 0)
            {
                playerbulletaxisy = playeraxisy;
                playershoots = false;
                Shoot.stop();
            }
            if(healthentry)
            {
                app.draw(HealthSprite);
                healthaxisy = healthaxisy + screenaxisx/20000;//0.08
            }
        }
        if(healthaxisy >= difficulty)
            healthaxisy = -100;

        if(finish)
            spriteaxisy = spriteaxisy - 0.1;
        if(spriteaxisy <= -100)
            spriteaxisy = 1050;

        app.clear();
        playerSprite.setPosition(playeraxisx, playeraxisy);
        enemySprite.setPosition(enemyaxisx, enemyaxisy);
        enemy2Sprite.setPosition(enemy2axisx, enemy2axisy);
        enemy3Sprite.setPosition(enemy3axisx, enemy3axisy);
        enemy4Sprite.setPosition(enemy4axisx, enemy4axisy);
        enemy5Sprite.setPosition(enemy5axisx, enemy5axisy);
        HealthSprite.setPosition(screenaxisx/4, healthaxisy);//400
        textPlayerlife.setPosition(screenaxisx/1.203, screenaxisy/90);//1330, 10
        optionsprites[1].setPosition(screenaxisx/2.666,screenaxisy/1.8);//500,500
        textEnemy5Life.setPosition(screenaxisx/160, screenaxisy/10);//10, 90
        textEnemy4Life.setPosition(screenaxisx/160, screenaxisy/12.857);//10, 70
        textEnemy3Life.setPosition(screenaxisx/160, screenaxisy/18);//10, 50
        textEnemy2Life.setPosition(screenaxisx/160, screenaxisy/30);//10, 30
        textEnemyLife.setPosition(screenaxisx/160, screenaxisy/90);//10, 10
        textTittle.setPosition(screenaxisx/4, screenaxisy/3);//400,300
        textfinish.setPosition(screenaxisx/8, screenaxisy/2.25);//200, 400
        textGameOver.setPosition(screenaxisx/4.5714, screenaxisy/3);//350, 300
        textCredits.setPosition(screenaxisx/4.5714, spriteaxisy);//350
        textCredits2.setPosition(screenaxisx/5.33333, spriteaxisy + screenaxisy/9);//300, 100
        textdifficulty.setPosition(screenaxisx/5.333, screenaxisy/1.5);//300,600
        textEnemyLife.setColor(Color::Yellow);
        textEnemy2Life.setColor(Color::Yellow);
        textEnemy3Life.setColor(Color::Yellow);
        textEnemy4Life.setColor(Color::Yellow);
        textEnemy5Life.setColor(Color::Yellow);
        textPlayerlife.setColor(Color::Yellow);
        textfinish.setColor(Color::Green);
        textGameOver.setColor(Color::Red);
        textTittle.setColor(Color::Cyan);
        textCredits.setColor(Color::Yellow);
        textCredits2.setColor(Color::Yellow);
        textdifficulty.setColor(Color::Yellow);
        sprites[0].setPosition(playerbulletaxisx, playerbulletaxisy);

        sprites[1].setPosition(enemybulletaxisx, enemybulletaxisy);             //enemy1

        sprites[2].setPosition(enemy2bulletaxisx, enemy2bulletaxisy);
        sprites[3].setPosition(enemy2bulletaxisx + screenaxisx/8.888, enemy2bulletaxisy); //180            //enemy2
        sprites[4].setPosition(enemy2bulletaxisx + screenaxisx/18.3908, enemy2bulletaxisy + screenaxisy/8.1818);//87,110

        sprites[5].setPosition(enemy3bulletaxisx, enemy3bulletaxisy);
        sprites[6].setPosition(enemy3bulletaxisx + screenaxisx/6.8965, enemy3bulletaxisy);//232                 //enemy3
        sprites[7].setPosition(enemy3bulletaxisx + screenaxisx/13.333, enemy3bulletaxisy + screenaxisy/5.625);//120, 160
        sprites[8].setPosition(enemy3bulletaxisx + screenaxisx/7.619, enemy3bulletaxisy);//210
        sprites[9].setPosition(enemy3bulletaxisx + screenaxisx/80, enemy3bulletaxisy);//20

        lasersprites[1].setPosition(enemy4bulletaxisx, enemy4bulletaxisy);
        lasersprites[2].setPosition(enemy4bulletaxisx + screenaxisx/11.0344, enemy4bulletaxisy);//145                //enemy4
        lasersprites[3].setPosition(enemy4bulletaxisx + screenaxisx/50, enemy4bulletaxisy + screenaxisy/16.981);//32,53
        lasersprites[4].setPosition(enemy4bulletaxisx + screenaxisx/14.5454, enemy4bulletaxisy + screenaxisy/16.981);//110,53

        lasersprites[5].setPosition(enemy5bulletaxisx, enemy5bulletaxisy);
        lasersprites[6].setPosition(enemy5bulletaxisx +  screenaxisx/5.245, enemy5bulletaxisy);//305
        lasersprites[7].setPosition(enemy5bulletaxisx + screenaxisx/7.804, enemy5bulletaxisy - screenaxisy/9);//205,100       //enemy5
        lasersprites[8].setPosition(enemy5bulletaxisx + screenaxisx/16.8421, enemy5bulletaxisy - screenaxisy/9);//95,100
        sprites[10].setPosition(enemy5bulletaxisx + screenaxisx/10, enemy5bulletaxisy - screenaxisy/12.857);//160,70
        sprites[11].setPosition(enemy5bulletaxisx + screenaxisx/11.851, enemy5bulletaxisy - screenaxisy/10.588);//135,85
        sprites[12].setPosition(enemy5bulletaxisx + screenaxisx/8.648, enemy5bulletaxisy - screenaxisy/10.588);//185,85

        sprites[13].setPosition(screenaxisx/1.142, screenaxisy/90);//1400
        sprites[14].setPosition(screenaxisx/1.142 + screenaxisy/90, screenaxisy/90);
        sprites[15].setPosition(screenaxisx/1.142 + 2*screenaxisy/90, screenaxisy/90);
        sprites[16].setPosition(screenaxisx/1.142 + 3*screenaxisy/90, screenaxisy/90);
        sprites[17].setPosition(screenaxisx/1.142 + 4*screenaxisy/90, screenaxisy/90);
        sprites[18].setPosition(screenaxisx/1.142 + 5*screenaxisy/90, screenaxisy/90);
        sprites[19].setPosition(screenaxisx/1.142 + 6*screenaxisy/90, screenaxisy/90);
        sprites[20].setPosition(screenaxisx/1.142 + 7*screenaxisy/90, screenaxisy/90);
        sprites[21].setPosition(screenaxisx/1.142 + 8*screenaxisy/90, screenaxisy/90);
        sprites[22].setPosition(screenaxisx/1.142 + 9*screenaxisy/90, screenaxisy/90);
        sprites[23].setPosition(screenaxisx/1.142 + 10*screenaxisy/90, screenaxisy/90);
        sprites[24].setPosition(screenaxisx/1.142 + 11*screenaxisy/90, screenaxisy/90);
        sprites[25].setPosition(screenaxisx/1.142 + 12*screenaxisy/90, screenaxisy/90);
        sprites[26].setPosition(screenaxisx/1.142 + 13*screenaxisy/90, screenaxisy/90);
        sprites[27].setPosition(screenaxisx/1.142 + 14*screenaxisy/90, screenaxisy/90);


        textn20.setPosition(screenaxisx/9.41176, screenaxisy/90), textn19.setPosition(screenaxisx/9.41176, screenaxisy/90), textn18.setPosition(screenaxisx/9.41176, screenaxisy/90);
        textn17.setPosition(screenaxisx/9.41176, screenaxisy/90), textn16.setPosition(screenaxisx/9.41176, screenaxisy/90), textn15.setPosition(screenaxisx/9.41176, screenaxisy/90);
        textn14.setPosition(screenaxisx/9.41176, screenaxisy/90), textn13.setPosition(screenaxisx/9.41176, screenaxisy/90), textn12.setPosition(screenaxisx/9.41176, screenaxisy/90);
        textn11.setPosition(screenaxisx/9.41176, screenaxisy/90), textn10.setPosition(screenaxisx/9.41176, screenaxisy/90), textn9.setPosition(screenaxisx/9.41176, screenaxisy/90);
        textn8.setPosition(screenaxisx/9.41176, screenaxisy/90), textn7.setPosition(screenaxisx/9.41176, screenaxisy/90), textn6.setPosition(screenaxisx/9.41176, screenaxisy/90), textn5.setPosition(screenaxisx/9.41176, screenaxisy/90);
        textn4.setPosition(screenaxisx/9.41176, screenaxisy/90), textn3.setPosition(screenaxisx/9.41176, screenaxisy/90);
        textn2.setPosition(screenaxisx/9.41176, screenaxisy/90), textn1.setPosition(screenaxisx/9.41176, screenaxisy/90);//170,10

        if(healthshow)
            app.draw(HealthSprite);

        if(prestart)
        {
            app.draw(textTittle);
            app.draw(optionsprites[1]);
            app.draw(textdifficulty);
        }

        if(gamestart)
        {
            app.draw(backgroundSprite);
            app.draw(HealthSprite);
            app.draw(textPlayerlife);
            if(playerlife)
            {
                if(playershoots)
                {
                    app.draw(sprites[0]);
                }
                app.draw(playerSprite);
            }
            if(Gameover)
            {
                healthshow = false;
                healthentry = false;
                app.draw(textEnemyLife);
                app.draw(textEnemy2Life);
                app.draw(textEnemy3Life);
                app.draw(textEnemy4Life);
                app.draw(textEnemy5Life);
                Explosion.play();
                app.draw(textGameOver);
                Enemy2life = false;
                Enemy3life = false;
                Enemy4life = false;
                Enemy5life = false;
                playerlife = false;
                enemylife = false;
                enemy5shoots = false;
                enemy4shoots = false;
                enemy3shoots = false;
                enemy2shoots = false;
                enemyshoots = false;
                Shoot.stop();
                BGM1.stop();
                Explosion.play();
                Explosion.stop();
                playershoots = false;
            }
            if (finish)
            {
                showcity = true;
                healthshow = false;
                healthentry = false;
                app.draw(textEnemyLife);
                app.draw(textEnemy2Life);
                app.draw(textEnemy3Life);
                app.draw(textEnemy4Life);
                app.draw(textEnemy5Life);
                Enemy5life = false;
                Enemy4life = false;
                Enemy3life = false;
                Enemy2life = false;
                enemylife = false;
                enemy5shoots = false;
                enemy4shoots = false;
                enemy3shoots = false;
                enemy2shoots = false;
                enemyshoots = false;
                Gameover = false;
                Explosion.stop();
                Shoot.stop();
                BGM1.stop();
                playershoots = false;
                spritemoves = true;
            }
            if(enemylife)
            {
                app.draw(textEnemyLife);
                enemylifeshow = true;
                app.draw(enemySprite);
                app.draw(sprites[1]);
            }
            if(Enemy2life)
            {
                app.draw(textEnemy2Life);
                enemy2lifeshow = true;
                app.draw(enemy2Sprite);
                app.draw(sprites[2]);
                app.draw(sprites[3]);
                app.draw(sprites[4]);
            }
            if(Enemy3life)
            {
                app.draw(textEnemy3Life);
                enemy3lifeshow = true;
                app.draw(enemy3Sprite);
                app.draw(sprites[5]);
                app.draw(sprites[6]);
                app.draw(sprites[7]);
                app.draw(sprites[8]);
                app.draw(sprites[9]);
            }
            if(Enemy4life)
            {
                app.draw(textEnemy4Life);
                enemy4lifeshow = true;
                app.draw(enemy4Sprite);
                app.draw(lasersprites[1]);
                app.draw(lasersprites[2]);
                app.draw(lasersprites[3]);
                app.draw(lasersprites[4]);
            }
            if(Enemy5life)
            {
                app.draw(textEnemy5Life);
                enemy5lifeshow = true;
                app.draw(enemy5Sprite);
                app.draw(lasersprites[5]);
                app.draw(lasersprites[6]);
                app.draw(lasersprites[7]);
                app.draw(lasersprites[8]);
                app.draw(sprites[10]);
                app.draw(sprites[11]);
                app.draw(sprites[12]);
            }


            if(noofplayerlife == 15)
            {
                app.draw(sprites[13]);
                app.draw(sprites[14]);
                app.draw(sprites[15]);
                app.draw(sprites[16]);
                app.draw(sprites[17]);
                app.draw(sprites[18]);
                app.draw(sprites[19]);
                app.draw(sprites[20]);
                app.draw(sprites[21]);
                app.draw(sprites[22]);
                app.draw(sprites[23]);
                app.draw(sprites[24]);
                app.draw(sprites[25]);
                app.draw(sprites[26]);
                app.draw(sprites[27]);
            }
            if(noofplayerlife == 14)
            {
                app.draw(sprites[13]);
                app.draw(sprites[14]);
                app.draw(sprites[15]);
                app.draw(sprites[16]);
                app.draw(sprites[17]);
                app.draw(sprites[18]);
                app.draw(sprites[19]);
                app.draw(sprites[20]);
                app.draw(sprites[21]);
                app.draw(sprites[22]);
                app.draw(sprites[23]);
                app.draw(sprites[24]);
                app.draw(sprites[25]);
                app.draw(sprites[26]);
            }
            if(noofplayerlife == 13)
            {
                app.draw(sprites[13]);
                app.draw(sprites[14]);
                app.draw(sprites[15]);
                app.draw(sprites[16]);
                app.draw(sprites[17]);
                app.draw(sprites[18]);
                app.draw(sprites[19]);
                app.draw(sprites[20]);
                app.draw(sprites[21]);
                app.draw(sprites[22]);
                app.draw(sprites[23]);
                app.draw(sprites[24]);
                app.draw(sprites[25]);
            }
            if(noofplayerlife == 12)
            {
                app.draw(sprites[13]);
                app.draw(sprites[14]);
                app.draw(sprites[15]);
                app.draw(sprites[16]);
                app.draw(sprites[17]);
                app.draw(sprites[18]);
                app.draw(sprites[19]);
                app.draw(sprites[20]);
                app.draw(sprites[21]);
                app.draw(sprites[22]);
                app.draw(sprites[23]);
                app.draw(sprites[24]);
            }
            if(noofplayerlife == 11)
            {
                app.draw(sprites[13]);
                app.draw(sprites[14]);
                app.draw(sprites[15]);
                app.draw(sprites[16]);
                app.draw(sprites[17]);
                app.draw(sprites[18]);
                app.draw(sprites[19]);
                app.draw(sprites[20]);
                app.draw(sprites[21]);
                app.draw(sprites[22]);
                app.draw(sprites[23]);
            }
            if(noofplayerlife == 10)
            {
                app.draw(sprites[13]);
                app.draw(sprites[14]);
                app.draw(sprites[15]);
                app.draw(sprites[16]);
                app.draw(sprites[17]);
                app.draw(sprites[18]);
                app.draw(sprites[19]);
                app.draw(sprites[20]);
                app.draw(sprites[21]);
                app.draw(sprites[22]);
            }
            if(noofplayerlife == 9)
            {
                app.draw(sprites[13]);
                app.draw(sprites[14]);
                app.draw(sprites[15]);
                app.draw(sprites[16]);
                app.draw(sprites[17]);
                app.draw(sprites[18]);
                app.draw(sprites[19]);
                app.draw(sprites[20]);
                app.draw(sprites[21]);
            }
            if(noofplayerlife == 8)
            {
                app.draw(sprites[13]);
                app.draw(sprites[14]);
                app.draw(sprites[15]);
                app.draw(sprites[16]);
                app.draw(sprites[17]);
                app.draw(sprites[18]);
                app.draw(sprites[19]);
                app.draw(sprites[20]);
            }
            if(noofplayerlife == 7)
            {
                app.draw(sprites[13]);
                app.draw(sprites[14]);
                app.draw(sprites[15]);
                app.draw(sprites[16]);
                app.draw(sprites[17]);
                app.draw(sprites[18]);
                app.draw(sprites[19]);
            }
            if(noofplayerlife == 6)
            {
                app.draw(sprites[13]);
                app.draw(sprites[14]);
                app.draw(sprites[15]);
                app.draw(sprites[16]);
                app.draw(sprites[17]);
                app.draw(sprites[18]);
            }
            if(noofplayerlife == 5)
            {
                app.draw(sprites[13]);
                app.draw(sprites[14]);
                app.draw(sprites[15]);
                app.draw(sprites[16]);
                app.draw(sprites[17]);
            }
            if(noofplayerlife == 4)
            {
                app.draw(sprites[16]);
                app.draw(sprites[15]);
                app.draw(sprites[14]);
                app.draw(sprites[13]);
            }
            if(noofplayerlife == 3)
            {
                app.draw(sprites[15]);
                app.draw(sprites[14]);
                app.draw(sprites[13]);
            }
            if(noofplayerlife == 2)
            {
                app.draw(sprites[14]);
                app.draw(sprites[13]);
            }
            if(noofplayerlife == 1)
            {
                app.draw(sprites[13]);
            }
            if(noofplayerlife == 0)
            {
            }

            if(enemy5lifeshow)
            {
                textn20.setPosition(screenaxisx/9.41176, screenaxisy/10), textn19.setPosition(screenaxisx/9.41176, screenaxisy/10), textn18.setPosition(screenaxisx/9.41176, screenaxisy/10);
                textn17.setPosition(screenaxisx/9.41176, screenaxisy/10), textn16.setPosition(screenaxisx/9.41176, screenaxisy/10), textn15.setPosition(screenaxisx/9.41176, screenaxisy/10), textn14.setPosition(screenaxisx/9.41176, screenaxisy/10);
                textn13.setPosition(screenaxisx/9.41176, screenaxisy/10), textn12.setPosition(screenaxisx/9.41176, screenaxisy/10);
                textn11.setPosition(screenaxisx/9.41176, screenaxisy/10), textn10.setPosition(screenaxisx/9.41176, screenaxisy/10), textn9.setPosition(screenaxisx/9.41176, screenaxisy/10), textn8.setPosition(screenaxisx/9.41176, screenaxisy/10);
                textn7.setPosition(screenaxisx/9.41176, screenaxisy/10), textn6.setPosition(screenaxisx/9.41176, screenaxisy/10), textn5.setPosition(screenaxisx/9.41176, screenaxisy/10), textn4.setPosition(screenaxisx/9.41176, screenaxisy/10), textn3.setPosition(screenaxisx/9.41176, screenaxisy/10);
                textn2.setPosition(screenaxisx/9.41176, screenaxisy/10), textn1.setPosition(screenaxisx/9.41176, screenaxisy/10);//170, 90
                if(noofenemy5life == 20)
                    app.draw(textn20);
                if(noofenemy5life == 19)
                    app.draw(textn19);
                if(noofenemy5life == 18)
                    app.draw(textn18);
                if(noofenemy5life == 17)
                    app.draw(textn17);
                if(noofenemy5life == 16)
                    app.draw(textn16);
                if(noofenemy5life == 15)
                    app.draw(textn15);
                if(noofenemy5life == 14)
                    app.draw(textn14);
                if(noofenemy5life == 13)
                    app.draw(textn13);
                if(noofenemy5life == 12)
                    app.draw(textn12);
                if(noofenemy5life == 11)
                    app.draw(textn11);
                if(noofenemy5life == 10)
                    app.draw(textn10);
                if(noofenemy5life == 9)
                    app.draw(textn9);
                if(noofenemy5life == 8)
                    app.draw(textn8);
                if(noofenemy5life == 7)
                    app.draw(textn7);
                if(noofenemy5life == 6)
                    app.draw(textn6);
                if(noofenemy5life == 5)
                    app.draw(textn5);
                if(noofenemy5life == 4)
                    app.draw(textn4);
                if(noofenemy5life == 3)
                    app.draw(textn3);
                if(noofenemy5life == 2)
                    app.draw(textn2);
                if(noofenemy5life == 1)
                    app.draw(textn1);
            }
            if(enemylifeshow)
            {
                textn1.setPosition(screenaxisx/9.41176, screenaxisy/90), textn2.setPosition(screenaxisx/9.41176, screenaxisy/90), textn3.setPosition(screenaxisx/9.41176, screenaxisy/90), textn4.setPosition(screenaxisx/9.41176, screenaxisy/90), textn5.setPosition(screenaxisx/9.41176, screenaxisy/90);
                if(noofenemylife == 5)
                    app.draw(textn5);
                if(noofenemylife == 4)
                    app.draw(textn4);
                if(noofenemylife == 3)
                    app.draw(textn3);
                if(noofenemylife == 2)
                    app.draw(textn2);
                if(noofenemylife == 1)
                    app.draw(textn1);
            }
            if(enemy2lifeshow)
            {
                textn10.setPosition(screenaxisx/9.41176, screenaxisy/30), textn9.setPosition(screenaxisx/9.41176, screenaxisy/30), textn8.setPosition(screenaxisx/9.41176, screenaxisy/30);
                textn7.setPosition(screenaxisx/9.41176, screenaxisy/30), textn6.setPosition(screenaxisx/9.41176, screenaxisy/30), textn5.setPosition(screenaxisx/9.41176, screenaxisy/30),textn4.setPosition(screenaxisx/9.41176, screenaxisy/30);
                textn3.setPosition(screenaxisx/9.41176, screenaxisy/30), textn2.setPosition(screenaxisx/9.41176, screenaxisy/30), textn1.setPosition(screenaxisx/9.41176, screenaxisy/30);
                if(noofenemy2life == 10)
                    app.draw(textn10);
                if(noofenemy2life == 9)
                    app.draw(textn9);
                if(noofenemy2life == 8)
                    app.draw(textn8);
                if(noofenemy2life == 7)
                    app.draw(textn7);
                if(noofenemy2life == 6)
                    app.draw(textn6);
                if(noofenemy2life == 5)
                    app.draw(textn5);
                if(noofenemy2life == 4)
                    app.draw(textn4);
                if(noofenemy2life == 3)
                    app.draw(textn3);
                if(noofenemy2life == 2)
                    app.draw(textn2);
                if(noofenemy2life == 1)
                    app.draw(textn1);
            }
            if(enemy3lifeshow)
            {
                textn15.setPosition(screenaxisx/9.41176, screenaxisy/18), textn14.setPosition(screenaxisx/9.41176, screenaxisy/18), textn13.setPosition(screenaxisx/9.41176, screenaxisy/18), textn12.setPosition(screenaxisx/9.41176, screenaxisy/18), textn11.setPosition(screenaxisx/9.41176, screenaxisy/18);
                textn10.setPosition(screenaxisx/9.41176, screenaxisy/18), textn9.setPosition(screenaxisx/9.41176, screenaxisy/18), textn8.setPosition(screenaxisx/9.41176, screenaxisy/18);
                textn7.setPosition(screenaxisx/9.41176, screenaxisy/18), textn6.setPosition(screenaxisx/9.41176, screenaxisy/18), textn5.setPosition(screenaxisx/9.41176, screenaxisy/18),textn4.setPosition(screenaxisx/9.41176, screenaxisy/18);
                textn3.setPosition(screenaxisx/9.41176, screenaxisy/18), textn2.setPosition(screenaxisx/9.41176, screenaxisy/18), textn1.setPosition(screenaxisx/9.41176, screenaxisy/18);
                if(noofenemy3life == 15)
                    app.draw(textn15);
                if(noofenemy3life == 14)
                    app.draw(textn14);
                if(noofenemy3life == 13)
                    app.draw(textn13);
                if(noofenemy3life == 12)
                    app.draw(textn12);
                if(noofenemy3life == 11)
                    app.draw(textn11);
                if(noofenemy3life == 10)
                    app.draw(textn10);
                if(noofenemy3life == 9)
                    app.draw(textn9);
                if(noofenemy3life == 8)
                    app.draw(textn8);
                if(noofenemy3life == 7)
                    app.draw(textn7);
                if(noofenemy3life == 6)
                    app.draw(textn6);
                if(noofenemy3life == 5)
                    app.draw(textn5);
                if(noofenemy3life == 4)
                    app.draw(textn4);
                if(noofenemy3life == 3)
                    app.draw(textn3);
                if(noofenemy3life == 2)
                    app.draw(textn2);
                if(noofenemy3life == 1)
                    app.draw(textn1);
            }
            if(enemy4lifeshow)
            {
                textn17.setPosition(screenaxisx/9.41176, screenaxisy/12.857), textn16.setPosition(screenaxisx/9.41176, screenaxisy/12.857);
                textn15.setPosition(screenaxisx/9.41176, screenaxisy/12.857), textn14.setPosition(screenaxisx/9.41176, screenaxisy/12.857), textn13.setPosition(screenaxisx/9.41176, screenaxisy/12.857), textn12.setPosition(screenaxisx/9.41176, screenaxisy/12.857), textn11.setPosition(screenaxisx/9.41176, screenaxisy/12.857);
                textn10.setPosition(screenaxisx/9.41176, screenaxisy/12.857), textn9.setPosition(screenaxisx/9.41176, screenaxisy/12.857), textn8.setPosition(screenaxisx/9.41176, screenaxisy/12.857), textn7.setPosition(screenaxisx/9.41176, screenaxisy/12.857), textn6.setPosition(screenaxisx/9.41176, screenaxisy/12.857);
                textn5.setPosition(screenaxisx/9.41176, screenaxisy/12.857),textn4.setPosition(screenaxisx/9.41176, screenaxisy/12.857);
                textn3.setPosition(screenaxisx/9.41176, screenaxisy/12.857), textn2.setPosition(screenaxisx/9.41176, screenaxisy/12.857), textn1.setPosition(screenaxisx/9.41176, screenaxisy/12.857);
                if(noofenemy4life == 17)
                    app.draw(textn17);
                if(noofenemy4life == 16)
                    app.draw(textn16);
                if(noofenemy4life == 15)
                    app.draw(textn15);
                if(noofenemy4life == 14)
                    app.draw(textn14);
                if(noofenemy4life == 13)
                    app.draw(textn13);
                if(noofenemy4life == 12)
                    app.draw(textn12);
                if(noofenemy4life == 11)
                    app.draw(textn11);
                if(noofenemy4life == 10)
                    app.draw(textn10);
                if(noofenemy4life == 9)
                    app.draw(textn9);
                if(noofenemy4life == 8)
                    app.draw(textn8);
                if(noofenemy4life == 7)
                    app.draw(textn7);
                if(noofenemy4life == 6)
                    app.draw(textn6);
                if(noofenemy4life == 5)
                    app.draw(textn5);
                if(noofenemy4life == 4)
                    app.draw(textn4);
                if(noofenemy4life == 3)
                    app.draw(textn3);
                if(noofenemy4life == 2)
                    app.draw(textn2);
                if(noofenemy4life == 1)
                    app.draw(textn1);
            }
            if(showcity)
            {
                background2Sprite.setPosition(-screenaxisx/16, screenaxisy/4.5);//-100, 200
                background2Sprite.setScale(screenaxisx/761.904, screenaxisy/1000);//2.1, 0.9
                RoadSprite.setPosition(-screenaxisx/16, screenaxisy/1.5789);//-100, 570
                Road2Sprite.setPosition(-screenaxisx/16, screenaxisy/1.5517);//-100, 580
                RoadSprite.setScale(screenaxisx/175.82417, screenaxisy/1000);//9.1, 0.9
                Road2Sprite.setScale(screenaxisx/175.82417, screenaxisy/1000);//9.1, 0.9
                textpeacefull.setColor(Color::Magenta);
                textpeacefull.setPosition(screenaxisx/5.3333, screenaxisy/1.8);//300,500
                textfinish.setPosition(screenaxisx/8, screenaxisy/2.25);//200, 400
                Bus1sprite.setPosition(Bus1axisx, screenaxisy/1.8);//500
                Bus2sprite.setPosition(Bus2axisx, screenaxisy/1.636363);//550
                Car1sprite.setPosition(Car1axisx + screenaxisx/1.7777, screenaxisy/1.3043);//900, 690
                app.draw(backgroundSprite);
                app.draw(RoadSprite);
                app.draw(Road2Sprite);
                app.draw(background2Sprite);
                app.draw(textfinish);
                app.draw(textpeacefull);
                Vehiclemoves = true;
                app.draw(Car1sprite);
                app.draw(Bus1sprite);
                app.draw(Bus2sprite);
                app.draw(textCredits);
                app.draw(textCredits2);
            }
            if(Vehiclemoves)
            {
                Car1axisx = Car1axisx - screenaxisx/3200;//0.5
                Bus1axisx = Bus1axisx - screenaxisx/3200;//0.5
                Bus2axisx = Bus2axisx - screenaxisx/3200;//0.5
            }
            if(Bus1axisx <= -screenaxisx/1.454545)//-1100
                Bus1axisx = screenaxisx + screenaxisx/8;//200
            if(Bus2axisx <= -screenaxisx/1.454545)//-1100
                Bus2axisx = screenaxisx + screenaxisx/8;//200
            if(Car1axisx <= -screenaxisx/1.454545)//-1100
                Car1axisx = screenaxisx + screenaxisx/8;//200
        }
        app.display();
    }
    return EXIT_SUCCESS;
}




