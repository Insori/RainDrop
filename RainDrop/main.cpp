#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

void main() {
    bool game_over = false; //���� ���� ����
    bool game_clear = false;    //���� Ŭ���� ����

    srand(time(NULL));

	RenderWindow app(VideoMode(700, 700), "RainDrop");
	app.setFramerateLimit(60);	//������ ���� ����

    Texture d1, d2, d3, d4, d5, d6;
    d1.loadFromFile("images/background.png");
    d2.loadFromFile("images/sun.png");
    d3.loadFromFile("images/water.png");
    d4.loadFromFile("images/1.png");
    d5.loadFromFile("images/2.png");
    //d6.loadFromFile("images/3.png");

    Sprite background(d1), sprout(d4);
    sprout.setPosition(325, 605);

    Sprite sun(d2), water(d3);
    vector<Sprite> v_sun, v_water;
    
    
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
        }

        //�¿�� �����̱�
        if (Keyboard::isKeyPressed(Keyboard::Right))
            sprout.move(7, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left))
            sprout.move(-7, 0);

        //�޺� ��������
        v_sun.push_back(Sprite(sun));

        for (int i = 0; i < v_sun.size(); i++) {
            sun.setPosition(rand() % 650, -50);
            v_sun[i].move(0, 5);
            //ȭ�� ������ ������ �����ֱ�
            if (v_sun[i].getPosition().y > 700) v_sun.erase(v_sun.begin() + i);
        }

        //����� ��������
        v_water.push_back(Sprite(water));

        for (int i = 0; i < v_water.size(); i++) {
            water.setPosition(rand() % 650, -50);
            v_water[i].move(0, 5);
            //ȭ�� ������ ������ �����ֱ�
            if (v_water[i].getPosition().y > 700) v_water.erase(v_water.begin() + i);
        }

        //TODO: ���� ������ �������� ������ ����
        //���� -> ���� ���� ���� -> ���� ǳ���� ����(Ŭ����!)

        //TODO: ������ �Ǹ� ���� Ŭ����

        //TODO: �طο� ������(������,  ������ ���� ����
        
        app.clear();
        app.draw(background);
        app.draw(sprout);
        for (int i = 0; i < v_sun.size(); i++) {
            app.draw(v_sun[i]);
        }
        for (int i = 0; i < v_water.size(); i++) {
            app.draw(v_water[i]);
        }

        app.display();

	}
}
