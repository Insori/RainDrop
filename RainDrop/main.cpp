#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#define MAX_FIRE 5

using namespace std;
using namespace sf;

void main() 
{
	//타이머
	Clock clock;
	float interval = 0;

	bool game_over = false; //게임 오버 여부

	srand((unsigned int)time(NULL));

	RenderWindow app(VideoMode(700, 700), "RainDrop");
	app.setFramerateLimit(60);	//프레임 비율 설정

	Texture d1, d2, d3;
	d1.loadFromFile("images/background.png");
	d2.loadFromFile("images/1.png");
	d3.loadFromFile("images/fire.png");

	Sprite background(d1), player(d2);
	player.setPosition(325, 605);

	Sprite fire(d3);
	vector<Sprite> v_fire;

	for (int i = 0; i < MAX_FIRE; i++) 
	{
		fire.setPosition(rand() % 650, -50);
		v_fire.push_back(fire);
	}

	while (app.isOpen()) 
	{

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		interval += time;

		Event event;

		while (app.pollEvent(event))
		{
			//프로그램 종료 이벤트
			if (event.type == Event::EventType::Closed)
			{
				app.close();
				cout << "프로그램 종료" << endl;
			}
			if (game_over == true)
			{
				app.close();
				cout << "게임 오버" << endl;
			}

		}
		//좌우로 움직이기
		if (Keyboard::isKeyPressed(Keyboard::Right))
			player.move(7, 0);
		if (Keyboard::isKeyPressed(Keyboard::Left))
			player.move(-7, 0);

		app.clear();

		//불 떨어지기
		if ((int)interval % 1 == 0)
		{
			vector<Sprite>::iterator iter;
			for (iter = v_fire.begin(); iter != v_fire.end(); iter++)
			{
				(*iter).move(0, rand() % (10 - 7 + 1) + 7);

				Vector2f pos = (*iter).getPosition();
				if (pos.y > 700) (*iter).setPosition(rand() % 700, 800);
			}
		}

		//충돌
		vector<Sprite>::iterator iter;
		for (int i = 0; i < v_fire.size(); i++)
		{
			if (player.getGlobalBounds().intersects(v_fire[i].getGlobalBounds()))
			{
				v_fire.erase(v_fire.begin() + i);
				game_over = true;
			}

		}

		
		//그리기
		app.clear();
		app.draw(background);
		app.draw(player);
		for (iter = v_fire.begin(); iter != v_fire.end(); iter++)
		{
			app.draw(*iter);
		}

		app.display();

	}
}
