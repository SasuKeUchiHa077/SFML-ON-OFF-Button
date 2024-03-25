#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cstdlib>
#include <string>

#define WIDTH 800
#define HEIGHT 600

int main (int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Button", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(120);

    sf::RectangleShape buttonBox;
    buttonBox.setSize(sf::Vector2f(200.0f, 400.0f));
    buttonBox.setFillColor(sf::Color::White);
    buttonBox.setOrigin(sf::Vector2f(200.0f / 2.0f, 400.0f / 2.0f));
    buttonBox.setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f));

    sf::RectangleShape button;
    button.setSize(sf::Vector2f(150.0f, 150.0f));
    button.setFillColor(sf::Color::Red);
    button.setOrigin(sf::Vector2f(150.0f / 2.0f, 150.0f / 2.0f));
    button.setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f));

    sf::Font font;
    if (!font.loadFromFile("font/JetBrainsMonoNerdFont-Bold.ttf")) {
        return EXIT_FAILURE;
    }

    sf::Text buttonCondition;
    buttonCondition.setFont(font);
    buttonCondition.setCharacterSize(24.0f);
    buttonCondition.setOrigin(sf::Vector2f(24.0f / 2.0f, 24.0f / 2.0f));
    buttonCondition.setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f));
    buttonCondition.setFillColor(sf::Color::Black);

    sf::Vector2f button_On_TextPosition = buttonCondition.getPosition();
    sf::Vector2f button_Off_TextPosition;
    button_Off_TextPosition.x = buttonCondition.getPosition().x - 10.0f;
    button_Off_TextPosition.y = buttonCondition.getPosition().y;


    bool isOn = false, isOff = true;
    std::string text_On = "ON", text_Off = "OFF";

    buttonCondition.setPosition(button_Off_TextPosition);
    buttonCondition.setString(text_Off);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (mousePosition.x > WIDTH / 2 - 75 && mousePosition.x < WIDTH / 2 + 75 && mousePosition.y > HEIGHT / 2 - 75 && mousePosition.y < HEIGHT / 2 + 75) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (isOn) {
                            button.setFillColor(sf::Color::Red);
                            isOff = true;
                            isOn = false;

                            buttonCondition.setPosition(button_Off_TextPosition);
                            buttonCondition.setString(text_Off);
                        }

                        else {
                            button.setFillColor(sf::Color::Green);
                            isOn = true;
                            isOff = false;

                            buttonCondition.setPosition(button_On_TextPosition);
                            buttonCondition.setString(text_On);
                        }
                    }
                }
            }
        }

        window.clear();

        window.draw(buttonBox);
        window.draw(button);
        window.draw(buttonCondition);

        window.display();
    }
    return 0;
}
