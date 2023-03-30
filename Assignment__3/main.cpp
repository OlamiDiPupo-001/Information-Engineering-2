#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main() {

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create road
    sf::RectangleShape road(sf::Vector2f(1200.0, 600.0));
    road.setPosition(0, 450.0);
    road.setFillColor(sf::Color(128, 128, 128));

    // create roadline shape
    sf::RectangleShape line1(sf::Vector2f(1000, 5));
    line1.setPosition(0, 460);
    line1.setFillColor(sf::Color::White);

    sf::RectangleShape line2(sf::Vector2f(1000, 5));
    line2.setPosition(0, 520);
    line2.setFillColor(sf::Color::White);

    sf::RectangleShape line3(sf::Vector2f(1000, 5));
    line3.setPosition(0, 580);
    line3.setFillColor(sf::Color::White);


    // create car
    sf::ConvexShape car(17);
        car.setPoint(0, sf::Vector2f(60, 0));
        car.setPoint(1, sf::Vector2f(90, 0));
        car.setPoint(2, sf::Vector2f(110, 20));
        car.setPoint(3, sf::Vector2f(140, 20));
        car.setPoint(4, sf::Vector2f(140, 50));
        car.setPoint(5, sf::Vector2f(115, 50));
        car.setPoint(6, sf::Vector2f(105, 60));
        car.setPoint(7, sf::Vector2f(95, 60));
        car.setPoint(8, sf::Vector2f(85, 50));
        car.setPoint(9, sf::Vector2f(51, 50));
        car.setPoint(10, sf::Vector2f(40, 60));
        car.setPoint(11, sf::Vector2f(30, 60));
        car.setPoint(12, sf::Vector2f(20, 50));
        car.setPoint(13, sf::Vector2f(0, 50));
        car.setPoint(14, sf::Vector2f(0, 20));
        car.setPoint(15, sf::Vector2f(60, 20));
        car.setPoint(16, sf::Vector2f(60, 0));


        car.setFillColor(sf::Color::Green);
        car.setOutlineThickness(5);
        car.setOutlineColor(sf::Color::Black);

        car.setPosition(0, 500);






    // create some shapes
    sf::CircleShape circle(50.0);
    circle.setPosition(650.0, 280.0);
    circle.setFillColor(sf::Color::Green);

    sf::ConvexShape hexagon1;
        hexagon1.setPointCount(6);
        hexagon1.setPoint(0, sf::Vector2f(40, 0));
        hexagon1.setPoint(1, sf::Vector2f(80, 0));
        hexagon1.setPoint(2, sf::Vector2f(100, 40));
        hexagon1.setPoint(3, sf::Vector2f(80, 80));
        hexagon1.setPoint(4, sf::Vector2f(40, 80));
        hexagon1.setPoint(5, sf::Vector2f(20, 40));
        hexagon1.setPosition(20, 20);
        hexagon1.setFillColor(sf::Color::Red);

    sf::ConvexShape hexagon2;
        hexagon2.setPointCount(6);
        hexagon2.setPoint(0, sf::Vector2f(40, 0));
        hexagon2.setPoint(1, sf::Vector2f(80, 0));
        hexagon2.setPoint(2, sf::Vector2f(100, 40));
        hexagon2.setPoint(3, sf::Vector2f(80, 80));
        hexagon2.setPoint(4, sf::Vector2f(40, 80));
        hexagon2.setPoint(5, sf::Vector2f(20, 40));
        hexagon2.setPosition(300, 20);
        hexagon2.setFillColor(sf::Color::Blue);

    sf::ConvexShape hexagon3;
        hexagon3.setPointCount(6);
        hexagon3.setPoint(0, sf::Vector2f(40, 0));
        hexagon3.setPoint(1, sf::Vector2f(80, 0));
        hexagon3.setPoint(2, sf::Vector2f(100, 40));
        hexagon3.setPoint(3, sf::Vector2f(80,80));
        hexagon3.setPoint(4, sf::Vector2f(40, 80));
        hexagon3.setPoint(5, sf::Vector2f(20, 40));
        hexagon3.setPosition(600, 20);
        hexagon3.setFillColor(sf::Color::Black);


    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(100.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(140.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(60.0, 100.0));
    triangle.setOutlineColor(sf::Color(150, 75, 0));
    triangle.setFillColor(sf::Color(150, 75, 0));
    triangle.setOutlineThickness(2);
    triangle.setPosition(600.0, 350.0);
    sf::Clock clock;

    int hex_x = 50;
    int hex_y = 20;
    int hex_ang = 30;

    int car_velocity_x=200;
    int car_velocity_y=4;
    int car_angular_velocity=10;

    bool flag_y = false;
    bool flag_x = false;


    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();




        sf::FloatRect car_bounds = car.getGlobalBounds();
        if (car_bounds.left + car_bounds.width >= window.getSize().x){
            car.setPosition(0, 500);

        }

        car.move(car_velocity_x*dt, car_velocity_y*dt);


        sf::FloatRect hex1_bounds = hexagon1.getGlobalBounds();

       if(hex1_bounds.top <= 0){
           hex_y = abs(hex_y);
           hexagon1.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex1_bounds.top + hex1_bounds.height >= window.getSize().y){
           hex_y = abs(hex_y) * -1;
           hexagon1.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex1_bounds.left <= 0 ){
          hex_x = abs(hex_x);
          hexagon1.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex1_bounds.left + hex1_bounds.width >= window.getSize().x){
           hex_x = abs(hex_x) * -1;
           hexagon1.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex1_bounds.intersects(car_bounds)){
           hexagon1.setPosition(-100.f, -100.f);
           hexagon1.setFillColor(sf::Color::Transparent);
           car.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

        hexagon1.move(hex_x*dt,hex_y*dt);
        hexagon1.rotate(hex_ang*dt);


        sf::FloatRect hex2_bounds = hexagon2.getGlobalBounds();

       if(hex2_bounds.top <= 0){
           hex_y = abs(hex_y);
           hexagon2.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex2_bounds.top + hex2_bounds.height >= window.getSize().y){
           hex_y = abs(hex_y) * -1;
           hexagon2.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex2_bounds.left <= 0 ){
          hex_x = abs(hex_x);
          hexagon2.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex1_bounds.left + hex2_bounds.width >= window.getSize().x){
           hex_x = abs(hex_x) * -1;
           hexagon2.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex2_bounds.intersects(car_bounds)){
           hexagon2.setPosition(-100.f, -100.f);
           hexagon2.setFillColor(sf::Color::Transparent);
           car.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

        hexagon2.move(hex_y*dt,hex_x*dt);
        hexagon2.rotate(hex_ang*dt);


        sf::FloatRect hex3_bounds = hexagon3.getGlobalBounds();

       if(hex3_bounds.top <= 0){
           hex_y = abs(hex_y);
           hexagon3.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex3_bounds.top + hex3_bounds.height >= window.getSize().y){
           hex_y = abs(hex_y) * -1;
           hexagon3.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex3_bounds.left <= 0 ){
          hex_x = abs(hex_x);
          hexagon3.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex3_bounds.left + hex3_bounds.width >= window.getSize().x){
           hex_x = abs(hex_x) * -1;
           hexagon3.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(hex3_bounds.intersects(car_bounds)){
           hexagon3.setPosition(-100.f, -100.f);
           hexagon3.setFillColor(sf::Color::Transparent);
           car.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

        hexagon3.move(hex_x*dt,hex_x*dt);
        hexagon3.rotate(hex_ang*dt);



        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Yellow);

        // draw everything here...
        window.draw(road);
        window.draw(line1);
        window.draw(line2);
        window.draw(line3);
        window.draw(car);

        window.draw(triangle);
        window.draw(circle);
        window.draw(hexagon1);
        window.draw(hexagon2);
        window.draw(hexagon3);
       // window.draw(rectangle);


        // end the current frame
        window.display();
    }

    return 0;
}
