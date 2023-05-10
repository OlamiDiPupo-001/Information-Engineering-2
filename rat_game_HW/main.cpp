#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


//class CustomSprite : public sf::Sprite {
//private:
//    int xspeed = 50;
//    int yspeed = 50;

//   int bound_top = 0;
//   int bound_bottom = 0;
//   int bound_left = 0;
//   int bound_right = 0;

//public:

//    void setBounds(int left, int right, int top, int bottom)
//     {
//      bound_top = top;
//      bound_bottom = bottom;
//      bound_right = right;
//      bound_left = left;
//     }


//    bool Collision_T(sf::FloatRect wallborders, sf::FloatRect ratborders)
//     {
//      if (ratborders.top > wallborders.top + wallborders.height - 5 && ratborders.left + ratborders.width > wallborders.left
//              && ratborders.left < wallborders.left + wallborders.width)
//       {
//        return 1;
//       }
//      else{return 0;}

//     }

//    bool Collision_B(sf::FloatRect wallborders, sf::FloatRect ratborders)
//     {
//      if (ratborders.top < wallborders.top - ratborders.height + 5 && ratborders.left > wallborders.left - ratborders.width
//              && ratborders.left < wallborders.left + wallborders.width)
//       {
//        return 1;
//       }
//      else{return 0;}

//     }

//    bool Collision_R(sf::FloatRect wallborders, sf::FloatRect ratborders)
//     {
//      if (ratborders.left < wallborders.left - ratborders.width + 5 && ratborders.top > wallborders.top - ratborders.height
//              && ratborders.top < wallborders.top + wallborders.height)
//       {
//        return 1;
//       }
//      else{return 0;}
//    }

//    bool Collision_L(sf::FloatRect wallborders, sf::FloatRect ratborders)
//       {
//        if (ratborders.left > wallborders.left + wallborders.width - 5 && ratborders.top > wallborders.top - ratborders.height
//                && ratborders.top < wallborders.top + wallborders.height)
//         {
//          return 1;
//         }
//        else{return 0;}
//    }

//    void moveInDirection(const sf::Time &delta_time, const sf::Keyboard::Key &key, sf::Sprite &rat, sf::RenderWindow &window, std::vector<sf::Sprite> &walls)
//        {

//        int right = window.getSize().x;
//        int bottom = window.getSize().y;

//         for(auto &wall : walls){
//             sf::FloatRect ratborders = rat.getGlobalBounds();
//             sf::FloatRect wallborders = wall.getGlobalBounds();

//          if(Collision_T(wallborders, ratborders) == 1){
//              rat.setPosition(rat.getPosition().x, wallborders.top + wallborders.height);
//          }
//          if(Collision_L(wallborders, ratborders) == 1){
//              rat.setPosition(wallborders.left + wallborders.width, rat.getPosition().y);
//          }
//          if(Collision_B(wallborders, ratborders) == 1){
//              rat.setPosition(rat.getPosition().x, wallborders.top - ratborders.height);
//          }
//          if(Collision_R(wallborders, ratborders) == 1){
//              rat.setPosition(wallborders.left - ratborders.width, rat.getPosition().y);
//          }


//                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !(ratborders.top <= 0.0))
//                 {
//                  rat.move(0, -yspeed * delta_time.asSeconds());
//                 }
//                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !(ratborders.left >= right - ratborders.width))
//                 {
//                  rat.move(xspeed * delta_time.asSeconds(), 0);
//                 }
//                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !(ratborders.top >= bottom - ratborders.height) && !(ratborders.top >= bottom - ratborders.height))
//                 {
//                  rat.move(0, yspeed * delta_time.asSeconds());
//                 }
//                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !(ratborders.left <= 0.0))
//                 {
//                  rat.move(-xspeed * delta_time.asSeconds(), 0);
//                 }



//         }

//    }
//};





void move_rat(sf::Time &delta_time, const sf::Keyboard::Key &key, sf::Sprite &rat, sf::RenderWindow &window, std::vector<sf::Sprite> &walls){
    int xspeed = 50;
    int yspeed = 50;
    int right = window.getSize().x;
    int bottom = window.getSize().y;


    for(auto &wall : walls){
        sf::FloatRect ratborders = rat.getGlobalBounds();
        sf::FloatRect wallborders = wall.getGlobalBounds();


        if(rat.getGlobalBounds().intersects(wallborders))
        {
            if(ratborders.top > wallborders.top + wallborders.height - 5 && ratborders.left + ratborders.width > wallborders.left
                    && ratborders.left < wallborders.left + wallborders.width){
                rat.setPosition(rat.getPosition().x, wallborders.top + wallborders.height);
                break;
            }
            else if(ratborders.top < wallborders.top - ratborders.height + 5 && ratborders.left > wallborders.left - ratborders.width
                    && ratborders.left < wallborders.left + wallborders.width){
                rat.setPosition(rat.getPosition().x, wallborders.top - ratborders.height);
                break;
            }
            else if(ratborders.left < wallborders.left - ratborders.width + 5 && ratborders.top > wallborders.top - ratborders.height
                    && ratborders.top < wallborders.top + wallborders.height){
                rat.setPosition(wallborders.left - ratborders.width, rat.getPosition().y);
                break;
            }
            else if(ratborders.left > wallborders.left + wallborders.width - 5 && ratborders.top > wallborders.top - ratborders.height
                    && ratborders.top < wallborders.top + wallborders.height){
                rat.setPosition(wallborders.left + wallborders.width, rat.getPosition().y);
                break;
            }
        }


        else{
            if(key == sf::Keyboard::Up && !(ratborders.top <= 0.0)) {
                rat.move(0, -yspeed * delta_time.asSeconds());
            }
            else if(key == sf::Keyboard::Right && !(ratborders.left >= right - ratborders.width)) {
                rat.move(xspeed * delta_time.asSeconds(), 0);
            }
            else if(key == sf::Keyboard::Down && !(ratborders.top >= bottom - ratborders.height) && !(ratborders.top >= bottom - ratborders.height)){
                rat.move(0, yspeed * delta_time.asSeconds());
            }
            else if(key == sf::Keyboard::Left && !(ratborders.left <= 0.0)) {
                rat.move(-xspeed * delta_time.asSeconds(), 0);
            }

        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Window");

    sf::Texture grass_texture;
    grass_texture.loadFromFile("grass.jpg");

    sf::Texture wall_texture;
    wall_texture.loadFromFile("wall.jpg");

    sf::Texture rat_texture;
    rat_texture.loadFromFile("rat.png");

    sf::Texture house_texture;
    house_texture.loadFromFile("house.png");

    sf::Texture trap_texture;
    trap_texture.loadFromFile("trap.jpg");


    sf::Sprite rat;
    rat.setTexture(rat_texture);
    rat.setPosition(0.0, 50.0);

    grass_texture.setRepeated(true);
    sf::Sprite grass;
    grass.setTexture(grass_texture);
    grass.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

    wall_texture.setRepeated(true);
    sf::Sprite wall;
    wall.setTexture(wall_texture);

    sf::Sprite house;
    house.setTexture(house_texture);
    house.setPosition(window.getSize().x - 150, window.getSize().y - 250);

    trap_texture.setRepeated(true);
    sf::Sprite trap;
    trap.setTexture(trap_texture);


    std::vector<sf::Sprite> all_traps;

    trap.setPosition(550, 60.0);
    all_traps.emplace_back(trap);

    trap.setPosition(80.0, 600.0);
    all_traps.emplace_back(trap);







    std::vector<sf::Sprite> all_walls;

    wall.setTextureRect(sf::IntRect(0, 0, 50, window.getSize().y - 125));
    wall.setPosition(0.0, 150.0);
    all_walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50));
    wall.setPosition(0.0, 0.0);
    all_walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 50, window.getSize().y - 250));
    wall.setPosition(window.getSize().x - 50,  50.0);
    all_walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50));
    wall.setPosition(0.0, window.getSize().y - 50);
    all_walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50));
    wall.setPosition(400, 450);
    all_walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 400, 50));
    wall.setPosition(0.0, 300);
    all_walls.emplace_back(wall);






    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time time = clock.restart();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            move_rat(time, sf::Keyboard::Up, rat, window, all_walls);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            move_rat(time, sf::Keyboard::Down, rat, window, all_walls);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            move_rat(time, sf::Keyboard::Left, rat, window, all_walls);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            move_rat(time, sf::Keyboard::Right, rat, window, all_walls);
        }



        sf::Event event;
        while (window.pollEvent(event)) {if (event.type == sf::Event::Closed) window.close();}



        window.draw(grass);


        for(sf::Sprite &wall : all_walls) {
            window.draw(wall);
        }

        for(sf::Sprite &trap : all_traps) {
            window.draw(trap);
        }

        window.draw(rat);
        window.draw(house);

        for (sf::Sprite &trap : all_traps) {
        //sf::FloatRect ratborders = rat.getGlobalBounds();
        sf::FloatRect trapborders = trap.getGlobalBounds();

        if(rat.getGlobalBounds().intersects(trapborders))
            {

            sf::Texture game_over_texture;
                if(!game_over_texture.loadFromFile("game_over.jpg"))
                    std::cerr << "Could not load you loose texture" << std::endl;
                sf::Sprite loose;
                loose.setTexture(game_over_texture);
                loose.setPosition(70.0, 250.0);
                rat.setColor(sf::Color::Transparent);
                window.draw(loose);

            }
        else
                {
                    // Display normal sprites when no intersection
                    window.draw(rat);

                }

        }


        sf::FloatRect houseborders = house.getGlobalBounds();

        if(rat.getGlobalBounds().intersects(houseborders))
            {
            sf::Texture win_texture;
                if(!win_texture.loadFromFile("win.jpg"))
                    std::cerr << "Could not load you win texture" << std::endl;
                sf::Sprite win;
                win.setPosition(30.0, 220.0);
                win.setTexture(win_texture);
                rat.setColor(sf::Color::Transparent);
                window.draw(win);


            }
        else
                {
                    // Display normal sprites when no intersection
                    window.draw(rat);

                }



        window.display();
    }
    return 0;
}



