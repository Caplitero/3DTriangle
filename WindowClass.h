#pragma once

#include <SFML/Graphics.hpp>
#include "TriangleClass.h"
class Window {

	sf::RenderWindow* window = nullptr;
	CAP::Triangle triangle;
	sf::VertexArray vertexarray;

	void update()
	{
		triangle.rotate(0, 0.01, 0);
		triangle.move(0.1, 0.1, 0);
		for (int i = 0; i < 3; i++)
			vertexarray[i].position = sf::Vector2f(triangle.corners[i].x, triangle.corners[i].y);


		window->clear();
		window->draw(vertexarray);
		window->display();
	}

	void close(){

		delete window;
	}

	void loop()
	{
		sf::Event event;
		while (window->isOpen())
		{
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window->close();

				}


			}
			update();


		}
		close();


	}


public :

	
	void start(unsigned int Width, unsigned int Height, const char* Title)
	{

		window = new sf::RenderWindow(sf::VideoMode(Width, Height), Title);
		window->setFramerateLimit(144);

		triangle.corners[0] = CAP::Vector3D(100, 100, 75);
		triangle.corners[1] = CAP::Vector3D(200, 100, 100);
		triangle.corners[2] = CAP::Vector3D(300, 200, 75);
		triangle.update();
		vertexarray.setPrimitiveType(sf::Triangles);
		vertexarray.resize(3);

		vertexarray[0].color = sf::Color::Red;
		vertexarray[1].color = sf::Color::Blue;
		vertexarray[2].color = sf::Color::Green;


		loop();

	}

};