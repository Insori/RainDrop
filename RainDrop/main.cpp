#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

void main() {
	bool game_over = false; //게임 오버 여부
	bool game_clear = false;    //게임 클리어 여부
	int score = 0;
	//TODO: 타이머 구현

	srand(time(NULL));

	RenderWindow app(VideoMode(700, 700), "RainDrop");
	app.setFramerateLimit(60);	//프레임 비율 설정

	Texture d1, d2, d3, d4;
	d1.loadFromFile("images/background.png");
	d2.loadFromFile("images/1.png");
	d3.loadFromFile("images/sun.png");
	d4.loadFromFile("images/fire.png");

	Sprite background(d1), player(d2);
	player.setPosition(325, 605);

	Sprite sun(d3);
	vector<Sprite> v_sun;

	Sprite fire(d4);
	vector<Sprite> v_fire;


	while (app.isOpen()) {
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

		//햇빛 떨어지기
		v_sun.push_back(sun);

		for (int i = 0; i < v_sun.size(); i++)
		{
			sun.setPosition(rand() % 650, -50);
			v_sun[i].move(0, 5);
			//화면 밖으로 나가면 지워주기
			if (v_sun[i].getPosition().y > 700) v_sun.erase(v_sun.begin() + i);
			//햇빛 맞으면 점수 올라가기
			if (player.getGlobalBounds().intersects(v_sun[i].getGlobalBounds()))
			{
				score += 10;
				v_sun.erase(v_sun.begin() + i);
			}
		}

		//불 떨어지기
		v_fire.push_back(fire);

		for (int i = 0; i < v_fire.size(); i++)
		{
			fire.setPosition(rand() % 650, -50);
			v_fire[i].move(0, 5);
			if (v_fire[i].getPosition().y > 700) v_fire.erase(v_fire.begin() + i);
			//불 맞으면 게임 오버
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
		for (int i = 0; i < v_sun.size(); i++)
			app.draw(v_sun[i]);
		for (int i = 0; i < v_fire.size(); i++)
			app.draw(v_fire[i]);

		app.display();

	}
}
