#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main() {
	RenderWindow app(VideoMode(700, 700), "RainDrop");
	app.setFramerateLimit(60);	//������ ���� ����

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

        app.display();

	}
    return 0;
}
