#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main() {
	RenderWindow app(VideoMode(700, 700), "RainDrop");
	app.setFramerateLimit(60);	//프레임 비율 설정

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

        app.display();

	}
    return 0;
}
