#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

void main() {
    bool game_over = false; //게임 오버 여부
    bool game_clear = false;    //게임 클리어 여부

    srand(time(NULL));

	RenderWindow app(VideoMode(700, 700), "RainDrop");
	app.setFramerateLimit(60);	//프레임 비율 설정

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
            //프로그램 종료 이벤트
            if (event.type == Event::EventType::Closed)
            {
                app.close();
                cout << "프로그램 종료" << endl;
            }
        }

        //좌우로 움직이기
        if (Keyboard::isKeyPressed(Keyboard::Right))
            sprout.move(7, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left))
            sprout.move(-7, 0);

        //햇빛 떨어지기
        v_sun.push_back(Sprite(sun));

        for (int i = 0; i < v_sun.size(); i++) {
            sun.setPosition(rand() % 650, -50);
            v_sun[i].move(0, 5);
            //화면 밖으로 나가면 지워주기
            if (v_sun[i].getPosition().y > 700) v_sun.erase(v_sun.begin() + i);
        }

        //물방울 떨어지기
        v_water.push_back(Sprite(water));

        for (int i = 0; i < v_water.size(); i++) {
            water.setPosition(rand() % 650, -50);
            v_water[i].move(0, 5);
            //화면 밖으로 나가면 지워주기
            if (v_water[i].getPosition().y > 700) v_water.erase(v_water.begin() + i);
        }

        //TODO: 일정 개수의 아이템을 맞으면 성장
        //새싹 -> 잎이 적은 나무 -> 잎이 풍성한 나무(클리어!)

        //TODO: 나무가 되면 게임 클리어

        //TODO: 해로운 아이템(전자파,  맞으면 게임 오버
        
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
