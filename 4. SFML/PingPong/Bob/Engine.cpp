#include "stdafx.h"
#include "Engine.h"

Engine::Engine()
{
    // Get the screen resolution and create an SFML window and View
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Window.create(VideoMode(resolution.x, resolution.y),
        "Simple Game Engine",
        Style::Fullscreen);

    // Load the background into the texture
    // Be sure to scale this image to your screen size
    m_BackgroundTexture.loadFromFile("background.jpg");

    // Associate the sprite with the texture
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

}

void Engine::start()
{
    // Timing
    Clock clock;

    while (m_Window.isOpen())
    {
        // Restart the clock and save the elapsed time into dt
        Time dt = clock.restart();

        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}




//----------------------------------------------- Hacer archivos individuales de estas 3 -----------------------------------------------
// -------------------------------------------------Handling player input-----------------------------------------------------------

#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
    // Handle the player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }

    // Handle the player moving
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        m_Bob.moveLeft();
    }
    else
    {
        m_Bob.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_Bob.moveRight();
    }
    else
    {
        m_Bob.stopRight();
    }

}

// ------------------------------------------------------Updating the game objects-----------------------------------------------------------------------



#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
    m_Bob.update(dtAsSeconds);
}

// ------------------------------------------------------------Drawing the scene-----------------------------------------------------------------



#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
    // Handle the player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }

    // Handle the player moving
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        m_Bob.moveLeft();
    }
    else
    {
        m_Bob.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_Bob.moveRight();
    }
    else
    {
        m_Bob.stopRight();
    }

}

// -----------------------------------------Getting the engine started with Main------------------------------------------------------------------------------------



#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{
    // Rub out the last frame
    m_Window.clear(Color::White);

    // Draw the background
    m_Window.draw(m_BackgroundSprite);
    m_Window.draw(m_Bob.getSprite());

    // Show everything we have just drawn
    m_Window.display();
}