#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CustomRectangleShape : public sf::RectangleShape {
public:
    CustomRectangleShape(const sf::Vector2f &size, const sf::Vector2f &position) : sf::RectangleShape(size)
    {
        setPosition(position);
    }

    void setSpeed(int x_speed, int y_speed, int ro_speed) {
        x_speed = x_speed;
        y_speed = y_speed;
        ro_speed = ro_speed;
    }



    };
    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key){

        float dt = elapsed.asSeconds();

        float h_speed_r = x_speed;
        float h_speed_l = x_speed_;
        float v_speed_u = k_up;
        float v_speed_d = k_down;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            move(0.0, v_speed_u * dt * -1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            move(0.0, v_speed_d * dt);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            move(h_speed_r * dt * -1, 0.0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            move(h_speed_l * dt, 0.0);
        }



        sf::FloatRect rectangle_bounds = getGlobalBounds();

        if(rectangle_bounds.top <= u_){
            y_speed_ = abs(y_speed_);
        }

        if(rectangle_bounds.top + rectangle_bounds.height >= d_bound_){
            y_speed_ = abs(y_speed_) * -1;
            setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }

        if(rectangle_bounds.left <= l_bound_ ){
           x_speed_ = abs(x_speed_);
           setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }

        if(rectangle_bounds.left + rectangle_bounds.width >= r_bound_){
            x_speed_ = abs(x_speed_) * -1;
            setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));

    };
    bool isClicked(sf::Vector2i &mouse_position) const;

}

private:
    int x_speed_ = 0 ;
    int y_speed_ = 0 ;
    int ro_speed_ = 0 ;

    float l_bound_ = 0.0;
    float r_bound_ = 0.0;
    float u_bound_ = 0.0;
    float d_bound_ = 0.0;

    float k_up = 0.0;
    float k_down = 0.0;
    float k_left = 0.0;
    float k_right = 0.0;

};





int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");


    // create some Rectangleshapes
    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(120.0, 60.0);
    CustomRectangleShape rectangle(size, position);
    rectangle.setFillColor(sf::Color(150, 100, 50));
    rectangle.setSpeed(100, 150, 10);
    rectangle.setPosition(500.0, 400.0);
    rectangle.setBounds(0, window.getSize().x, 0, window.getSize().y);








    bool flag_y = false;
    bool flag_x = false;


    // run the program as long as the window is open
    while (window.isOpen()) {


        sf::Clock clock;

        //sf::Time elapsed = clock.restart();
        //float dt = elapsed.asSeconds();





        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
//        std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
//        std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;









        if(rectangle_bounds.top<=0 || rectangle_bounds.top+rectangle_bounds.height>=window.getSize().y)
            {
                if(flag_y != true)
                {
                    //rectangle_velocity_y *= -1;
                    rectangle.setFillColor(sf::Color(rand() % 256,
                                                     rand() % 256,
                                                     rand() % 256));
                }
                flag_y = true;
            }
            else
                flag_y = false;



            if(rectangle_bounds.left<=0 || rectangle_bounds.left+rectangle_bounds.width>=window.getSize().x)
            {
                if(flag_x!=true)
                {
                    //rectangle_velocity_x *= -1;
                    rectangle.setFillColor(sf::Color(rand() % 256,
                                                     rand() % 256,
                                                     rand() % 256));
                }
                flag_x = true;
            }
            else
                flag_x = false;





        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }



        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(rectangle);


        // end the current frame
        window.display();
    }

    return 0;
}
