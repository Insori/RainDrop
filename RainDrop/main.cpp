#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

void main() {
	bool game_over = false; //���� ���� ����
	bool game_clear = false;    //���� Ŭ���� ����
	int score = 0;
	//TODO: Ÿ�̸� ����

	srand(time(NULL));

	RenderWindow app(VideoMode(700, 700), "RainDrop");
	app.setFramerateLimit(60);	//������ ���� ����

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
			//���α׷� ���� �̺�Ʈ
			if (event.type == Event::EventType::Closed)
			{
				app.close();
				cout << "���α׷� ����" << endl;
			}
			if (game_over == true)
			{
				app.close();
				cout << "���� ����" << endl;
			}

		}

		//�¿�� �����̱�
		if (Keyboard::isKeyPressed(Keyboard::Right))
			player.move(7, 0);
		if (Keyboard::isKeyPressed(Keyboard::Left))
			player.move(-7, 0);

		//�޺� ��������
		v_sun.push_back(sun);

		for (int i = 0; i < v_sun.size(); i++)
		{
			sun.setPosition(rand() % 650, -50);
			v_sun[i].move(0, 5);
			//ȭ�� ������ ������ �����ֱ�
			if (v_sun[i].getPosition().y > 700) v_sun.erase(v_sun.begin() + i);
			//�޺� ������ ���� �ö󰡱�
			if (player.getGlobalBounds().intersects(v_sun[i].getGlobalBounds()))
			{
				score += 10;
				v_sun.erase(v_sun.begin() + i);
			}
		}

		//�� ��������
		v_fire.push_back(fire);

		for (int i = 0; i < v_fire.size(); i++)
		{
			fire.setPosition(rand() % 650, -50);
			v_fire[i].move(0, 5);
			if (v_fire[i].getPosition().y > 700) v_fire.erase(v_fire.begin() + i);
			//�� ������ ���� ����
			if (player.getGlobalBounds().intersects(v_fire[i].getGlobalBounds()))
			{
				v_fire.erase(v_fire.begin() + i);
				game_over = true;
			}
		}
		//�׸���
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
