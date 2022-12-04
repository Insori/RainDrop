#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void main() {
    int x = 325, y = 605;

	RenderWindow app(VideoMode(700, 700), "RainDrop");
	app.setFramerateLimit(60);	//프레임 비율 설정

    Texture d1, d2;
    d1.loadFromFile("images/background.png");
    d2.loadFromFile("images/1.png");
    Sprite background(d1), sprout(d2);
    sprout.setPosition(x, y);

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

        app.clear();
        app.draw(background);
        app.draw(sprout);

        app.display();

	}
}
