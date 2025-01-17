#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "paddle.h"
#include "upgrade.h"
paddle paddle;
ball ball;
upgrade_item upgradeItem;
std::vector <block> blocks;
std::vector <strong_block> strong_blocks;
std::vector <upgrade_item> upgrade_items;
int main()
{
	sf::Clock clock;
	sf::Clock upgradeItemClock;
	sf::Texture upgrade_texture;
	upgrade_texture.loadFromFile("pill.png");
	upgrade_texture.setSmooth(true);
	upgradeItem.body.setTexture(&upgrade_texture);
	sf::Texture background_texture;
	background_texture.setSmooth(true);
	background_texture.loadFromFile("back.png");
	sf::Sprite background_sprite;
	sf::Texture block_texture;
	block_texture.setSmooth(true);
	block_texture.loadFromFile("rock.png");
	sf::Texture strongBlockTexture;
	strongBlockTexture.setSmooth(true);
	strongBlockTexture.loadFromFile("strong.png");
	background_sprite.setTexture(background_texture);
		float oX = 10;
		float oX_2 = 10;
		for (int i = 0; i < 300; i++)
		{
			upgrade_item uItem;
			uItem.body.setTexture(&upgrade_texture);
			upgrade_items.push_back(uItem);
		}
	for (int i = 0; i < 16; i++)
	{
		sf::Vector2f place({ oX,100 });
		block blok(place);
		blok.body.setTexture(&block_texture);
		blok.body.setFillColor(sf::Color::White);
		blocks.push_back(blok);
		oX = oX+50;
	}
	for (int k = 0; k < 16; k++)
	{
		sf::Vector2f place_2({ oX_2, 30 });
		strong_block strong_blocke(place_2);
		strong_blocke.body.setFillColor(sf::Color::White);
		strong_blocke.body.setTexture(&strongBlockTexture);
		strong_blocks.push_back(strong_blocke);
		oX_2 = oX_2 + 50;
	}
	sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//update
		paddle.movement();
		ball.moving(paddle);
		upgradeItem.intersectWithPaddle(paddle,clock);
		upgradeItem.movement();
		if (clock.getElapsedTime().asSeconds() > 6)
		{
			paddle.changeBackSize();
		}
		//draw
		window.clear();
		window.draw(background_sprite);
		paddle.draw(window);
		ball.draw(window);
		for (int j = 0; j < 16; j++)
		{
			blocks[j].collision(ball);
			blocks[j].draw(window);

		}
		for (int l = 0; l < 16; l++)
		{
			strong_blocks[l].collision_(ball);
			strong_blocks[l].draw(window);
		}
		int temp = 0;
		upgradeItem.draw(window);
		window.display();
	}

	return 0;
}