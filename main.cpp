
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

#include "kpgraphics.hpp"

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 600

using namespace std;

int main(int, char const**){
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "IEGA Plot");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "IEGA_Oval_Logo_Border.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    //
    vector<sf::Drawable*> drawings;
    
    /* Vertex Array Test */
    
    sf::VertexArray triangle(sf::Triangles, 3);
    
    // define the position of the triangle's points
    triangle[0].position = sf::Vector2f(100, 100);
    triangle[1].position = sf::Vector2f(100, 400);
    triangle[2].position = sf::Vector2f(400, 400);
    
    // define the color of the triangle's points
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;
    
//    sf::Drawable* triangle_ptr(&triangle);

    /* Create Axes */
    
    sf::VertexArray axes(sf::LineStrip, 3);

    axes[0].position = sf::Vector2f(50, 50);
    axes[1].position = sf::Vector2f(50, 550);
    axes[2].position = sf::Vector2f(750, 550);
    
    axes[0].color = sf::Color::Black;
    axes[1].color = sf::Color::Black;
    axes[2].color = sf::Color::Black;
    
    /* Make example plot */
    
    KTrace kt;
    kt.addPoint(50, 470);
    kt.addPoint(100, 430);
    kt.addPoint(150, 200);
    kt.addPoint(200, 230);
    kt.addPoint(250, 190);
    kt.addPoint(300, 230);
    kt.addPoint(350, 245);
    kt.addPoint(400, 500);
    kt.addPoint(450, 350);
    kt.addPoint(500, 200);
    kt.addPoint(550, 190);
    
    vector<KPoint> tp = tessellate_line(kt, 1);
    sf::VertexArray trace;
    tes_to_vertexarray(tp, &trace, sf::Color::Blue);
    
//    sf::VertexArray trace(sf::LineStrip, 11);
//    trace[0].position = sf::Vector2f(50, 470);
//    trace[1].position = sf::Vector2f(100, 430);
//    trace[2].position = sf::Vector2f(150, 200);
//    trace[3].position = sf::Vector2f(200, 230);
//    trace[4].position = sf::Vector2f(250, 190);
//    trace[5].position = sf::Vector2f(300, 230);
//    trace[6].position = sf::Vector2f(350, 245);
//    trace[7].position = sf::Vector2f(400, 500);
//    trace[8].position = sf::Vector2f(450, 350);
//    trace[9].position = sf::Vector2f(500, 200);
//    trace[10].position = sf::Vector2f(550, 190);
//    
//    trace[0].color = sf::Color::Blue;
//    trace[1].color = sf::Color::Blue;
//    trace[2].color = sf::Color::Blue;
//    trace[3].color = sf::Color::Blue;
//    trace[4].color = sf::Color::Blue;
//    trace[5].color = sf::Color::Blue;
//    trace[6].color = sf::Color::Blue;
//    trace[7].color = sf::Color::Blue;
//    trace[8].color = sf::Color::Blue;
//    trace[9].color = sf::Color::Blue;
//    trace[10].color = sf::Color::Blue;
    
    /* Create Background */
    
    sf::RectangleShape background(sf::Vector2f(WINDOW_HEIGHT, WINDOW_WIDTH));
    background.setFillColor(sf::Color(200, 200, 200));
    background.setPosition(0, 0);
    
    /*
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
     */
     
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "FEC.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Its a work in progress.  IEGA!", font, 50);
    text.setFillColor(sf::Color::Black);

     
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
//    music.play();

    // Start the game loop
    while (window.isOpen()){
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

        window.draw(background);
//        window.draw(triangle);
        window.draw(*triangle_ptr);
        window.draw(axes);
        window.draw(trace);
        
//        // Draw the sprite
//        window.draw(sprite);
//
        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
        
        sf::sleep(sf::milliseconds(100));
    }

    return EXIT_SUCCESS;
}
