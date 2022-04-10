// в тетрисе 7 фигурок: I J L O S T Z (тетрамино)
// нарисовала 7 квадратиков разных цветоы для составления +1 бонусный
// сами тетрамино можно представить как табличку (4, 2), где есть "закрашенные" и "не закрашенные" квадратики
//									Например тетрамино L:		будем считать индексы так:
//											0 0								0 1
//											1 0								2 3
//											1 0								4 5
//											1 1								6 7

#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace sf;
// игровое поле:
const int M = 40;
const int N = 20;
int fld[M][N] = { 0 };

int figures[7][4] =
{
	1,3,5,7, // I
	3,5,7,6, // J
	2,3,5,7, // L
	2,3,4,5, // O
	2,4,5,7, // S
	3,5,4,7, // T
	3,5,4,6, // Z
};

struct Point
{
	int x, y;
} a[4];

int main()
{
	char tetramino[7] = { 'I', 'J', 'L', 'O', 'S', 'T', 'Z' };
	char tetr;
	std::cout << "Choose one type: I, J, L, O, S, T, Z\n";
	std::cin >> tetr;

	int type = 0;
	while (tetramino[type] != tetr) type += 1;

	int color = type;
	int bonus;
	srand(time(NULL));
	bonus = rand()%10;
	std::cout << bonus;
	if (bonus == 1) color = 7;


	RenderWindow window(VideoMode(80, 80), "Tetraminos");

	Texture texture;
	texture.loadFromFile("C:\\Users\\syoma\\source\\repos\\Project1\\ttrs.png");
	texture.setSmooth(true);

	Sprite sprite(texture);
	sprite.setTextureRect(IntRect(0, 0, 20, 20));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		for (int i = 0; i < 4; i++)
		{
			a[i].x = figures[type][i] % 2;
			a[i].y = figures[type][i] / 2;
		}

		window.clear(Color::White);

		for (int i = 0; i < 4; i++)
		{
			sprite.setPosition(a[i].x * 20, a[i].y * 20);
			sprite.setTextureRect(IntRect(color * 20, 0, 20, 20));
			sprite.move(50, 0);
			window.draw(sprite);
		}

		window.display();
	}

	return 0;
}
