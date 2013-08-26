#include <mysql++.h>
#include <stdlib.h>
#include <Graphics.hpp>
#include <Audio.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
#define RENDERWIDTH 800
#define RENDERHEIGHT 600


using namespace std;
using namespace mysqlpp;

float xOrigin = RENDERWIDTH / 2;
 
int main() {

	//window properties
	sf::RenderWindow window(sf::VideoMode(RENDERWIDTH, RENDERHEIGHT, 32), "Figure");
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(60);

	//axis properties
	sf::RectangleShape xaxis(sf::Vector2f(RENDERWIDTH, 1));
	xaxis.setFillColor(sf::Color(255, 255, 255));
	xaxis.setPosition(0, RENDERHEIGHT / 2);
	sf::RectangleShape yaxis(sf::Vector2f(1, RENDERHEIGHT));
	yaxis.setFillColor(sf::Color(255, 255, 255));
	yaxis.setPosition(xOrigin, 0);
	
	int loop = 0;

	//axis divisions properties
	float xslength = ( RENDERWIDTH / 8 );//x-separation length
	float yslength = ( RENDERHEIGHT / 8 );//y-separation length
	float dlength = 10;//divisor's length
	sf::RectangleShape xdivision[8];
	//	xdivision[0].setSize(sf::Vector2f(1, dlength));
	//	xdivision[0].setOutlineColor(sf::Color::White);
	//	xdivision[0].setPosition(0*slength, RENDERHEIGHT / 2 - dlength / 2);
		xdivision[1].setSize(sf::Vector2f(1, dlength));
		xdivision[1].setOutlineColor(sf::Color::White);
		xdivision[1].setPosition(1*xslength, RENDERHEIGHT / 2 - dlength / 2);
		xdivision[2].setSize(sf::Vector2f(1, dlength));
		xdivision[2].setOutlineColor(sf::Color::White);
		xdivision[2].setPosition(2*xslength, RENDERHEIGHT / 2 - dlength / 2);
		xdivision[3].setSize(sf::Vector2f(1, dlength));
		xdivision[3].setOutlineColor(sf::Color::White);
		xdivision[3].setPosition(3*xslength, RENDERHEIGHT / 2 - dlength / 2);
	//	xdivision[4].setSize(sf::Vector2f(1, dlength));
	//	xdivision[4].setOutlineColor(sf::Color::White);
	//	xdivision[4].setPosition(4*xslength, RENDERHEIGHT / 2 - dlength / 2);
		xdivision[5].setSize(sf::Vector2f(1, dlength));
		xdivision[5].setOutlineColor(sf::Color::White);
		xdivision[5].setPosition(5*xslength, RENDERHEIGHT / 2 - dlength / 2);
		xdivision[6].setSize(sf::Vector2f(1, dlength));
		xdivision[6].setOutlineColor(sf::Color::White);
		xdivision[6].setPosition(6*xslength, RENDERHEIGHT / 2 - dlength / 2);
		xdivision[7].setSize(sf::Vector2f(1, dlength));
		xdivision[7].setOutlineColor(sf::Color::White);
		xdivision[7].setPosition(7*xslength, RENDERHEIGHT / 2 - dlength / 2);
	sf::RectangleShape ydivision[8];
	//	ydivision[0].setSize(sf::Vector2f(dlength, 1));
	//	ydivision[0].setOutlineColor(sf::Color::White);
	//	ydivision[0].setPosition(RENDERWIDTH / 2 - dlength / 2, 0*yslength);
		ydivision[1].setSize(sf::Vector2f(dlength, 1));
		ydivision[1].setOutlineColor(sf::Color::White);
		ydivision[1].setPosition(RENDERWIDTH / 2 - dlength / 2, 1*yslength);
		ydivision[2].setSize(sf::Vector2f(dlength, 1));
		ydivision[2].setOutlineColor(sf::Color::White);
		ydivision[2].setPosition(RENDERWIDTH / 2 - dlength / 2, 2*yslength);
		ydivision[3].setSize(sf::Vector2f(dlength, 1));
		ydivision[3].setOutlineColor(sf::Color::White);
		ydivision[3].setPosition(RENDERWIDTH / 2 - dlength / 2, 3*yslength);
	//	ydivision[4].setSize(sf::Vector2f(dlength, 1));
	//	ydivision[4].setOutlineColor(sf::Color::White);
	//	ydivision[4].setPosition(RENDERWIDTH / 2 - dlength / 2, 4*yslength);
		ydivision[5].setSize(sf::Vector2f(dlength, 1));
		ydivision[5].setOutlineColor(sf::Color::White);
		ydivision[5].setPosition(RENDERWIDTH / 2 - dlength / 2, 5*yslength);
		ydivision[6].setSize(sf::Vector2f(dlength, 1));
		ydivision[6].setOutlineColor(sf::Color::White);
		ydivision[6].setPosition(RENDERWIDTH / 2 - dlength / 2, 6*yslength);
		ydivision[7].setSize(sf::Vector2f(dlength, 1));
		ydivision[7].setOutlineColor(sf::Color::White);
		ydivision[7].setPosition(RENDERWIDTH / 2 - dlength / 2, 7*yslength);

	

	//loop repetitions
	sf::Font font;	
	font.loadFromFile("fonts/LiberationSerif-Regular.ttf");
	sf::Text gridp3("", font, 20);
	gridp3.setPosition(7*xslength - 10, RENDERHEIGHT / 2 - 30);	

	int samples = 500;
	float step = 0;
	int x = 0;

	//funtion
	int y = 0;
	int t = 0;
	float funtion;
	int max;
	int min;
	max = 15;
	min = -15;
	float origin = ( max + min ); 

	float positiony;
	

	while(window.isOpen()){

		sf::Event event;
        	while (window.pollEvent(event)){
            		if (event.type == sf::Event::Closed) window.close();
        	}
		
		funtion = 1 * -y;
		positiony = RENDERHEIGHT / 2;

  		//curve
		sf::CircleShape point[RENDERWIDTH];
		point[x].setRadius(1);
		point[x].setFillColor(sf::Color::Red);
		point[x].setPosition((1 * xslength - 2) + step, positiony);
		step = step + RENDERWIDTH / samples;

       		//xy-axis
		window.draw(xaxis);
		window.draw(yaxis);
		//axis divisions
		window.draw(xdivision[0]);
		window.draw(xdivision[1]);
		window.draw(xdivision[2]);
		window.draw(xdivision[3]);
		window.draw(xdivision[4]);
		window.draw(xdivision[5]);
		window.draw(xdivision[6]);
		window.draw(xdivision[7]);
		window.draw(ydivision[0]);
		window.draw(ydivision[1]);
		window.draw(ydivision[2]);
		window.draw(ydivision[3]);
		window.draw(ydivision[4]);
		window.draw(ydivision[5]);
		window.draw(ydivision[6]);
		window.draw(ydivision[7]);

		window.draw(point[x]);
		window.draw(gridp3);
		window.display();
		
		if (x <= 600) {
		x++;
		y++;
		}
		
		if ( ( 1 * xslength - 2 ) + step >= 700 ){ 
		step = 0;
		}

    }

    

	

	

        mysqlpp::Connection conn(false);
        conn.connect("test", "localhost", "root", "root");
        Query query = conn.query();
 
 
        query << "SELECT * FROM wave01;";
	StoreQueryResult line = query.store();
	cout << line[1]["voltage"];

 
    return 0;
}
