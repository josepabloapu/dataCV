//default_libs
#include <stdlib.h>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
//addicional_libs
#include <Graphics.hpp>
#include <Audio.hpp>
#include <mysql++.h>
//definitions
#define RENDERWIDTH 800
#define RENDERHEIGHT 600
//global_variables
float x_axis_origin = RENDERHEIGHT / 2;
float y_axis_origin = RENDERWIDTH / 2;
float x_separation_length = RENDERWIDTH / 8;
float y_separation_length = RENDERHEIGHT / 8;
int separator_length = 10;
int loop = 0;
using namespace mysqlpp;
//----------------------------
std::string convertInt(int number)
{
	std::stringstream ss;
	ss << number;
	return ss.str();
}
//------------------------------
int main(){
	////window_properties
	sf::RenderWindow window(sf::VideoMode(RENDERWIDTH, RENDERHEIGHT, 32), "Window");
	window.setMouseCursorVisible(true);
	window.setFramerateLimit(1000);
	//xy_axis_properties
	sf::RectangleShape x_axis_line(sf::Vector2f(RENDERWIDTH, 1));
	x_axis_line.setFillColor(sf::Color::White);
	x_axis_line.setPosition(0, x_axis_origin);
	sf::RectangleShape y_axis_line(sf::Vector2f(1, RENDERHEIGHT));
	y_axis_line.setFillColor(sf::Color(sf::Color::White));
	y_axis_line.setPosition(y_axis_origin, 0);
	//axis_guide_lines
	sf::RectangleShape x_axis_guide_lines[6];
	x_axis_guide_lines[0].setSize(sf::Vector2f(1, separator_length));
	x_axis_guide_lines[0].setOutlineColor(sf::Color::White);
	x_axis_guide_lines[0].setPosition(1 * x_separation_length, x_axis_origin);
	x_axis_guide_lines[1].setSize(sf::Vector2f(1, separator_length));
	x_axis_guide_lines[1].setOutlineColor(sf::Color::White);
	x_axis_guide_lines[1].setPosition(2 * x_separation_length, x_axis_origin);
	x_axis_guide_lines[2].setSize(sf::Vector2f(1, separator_length));
	x_axis_guide_lines[2].setOutlineColor(sf::Color::White);
	x_axis_guide_lines[2].setPosition(3 * x_separation_length, x_axis_origin);
	x_axis_guide_lines[3].setSize(sf::Vector2f(1, separator_length));
	x_axis_guide_lines[3].setOutlineColor(sf::Color::White);
	x_axis_guide_lines[3].setPosition(5 * x_separation_length, x_axis_origin);
	x_axis_guide_lines[4].setSize(sf::Vector2f(1, separator_length));
	x_axis_guide_lines[4].setOutlineColor(sf::Color::White);
	x_axis_guide_lines[4].setPosition(6 * x_separation_length, x_axis_origin);
	x_axis_guide_lines[5].setSize(sf::Vector2f(1, separator_length));
	x_axis_guide_lines[5].setOutlineColor(sf::Color::White);
	x_axis_guide_lines[5].setPosition(7 * x_separation_length, x_axis_origin);
	sf::RectangleShape y_axis_guide_lines[6];
	y_axis_guide_lines[0].setSize(sf::Vector2f(separator_length, 1));
	y_axis_guide_lines[0].setOutlineColor(sf::Color::White);
	y_axis_guide_lines[0].setPosition(y_axis_origin, 1 * y_separation_length);
	y_axis_guide_lines[1].setSize(sf::Vector2f(separator_length, 1));
	y_axis_guide_lines[1].setOutlineColor(sf::Color::White);
	y_axis_guide_lines[1].setPosition(y_axis_origin, 2 * y_separation_length);
	y_axis_guide_lines[2].setSize(sf::Vector2f(separator_length, 1));
	y_axis_guide_lines[2].setOutlineColor(sf::Color::White);
	y_axis_guide_lines[2].setPosition(y_axis_origin, 3 * y_separation_length);
	y_axis_guide_lines[3].setSize(sf::Vector2f(separator_length, 1));
	y_axis_guide_lines[3].setOutlineColor(sf::Color::White);
	y_axis_guide_lines[3].setPosition(y_axis_origin, 5 * y_separation_length);
	y_axis_guide_lines[4].setSize(sf::Vector2f(separator_length, 1));
	y_axis_guide_lines[4].setOutlineColor(sf::Color::White);
	y_axis_guide_lines[4].setPosition(y_axis_origin, 6 * y_separation_length);
	y_axis_guide_lines[5].setSize(sf::Vector2f(separator_length, 1));
	y_axis_guide_lines[5].setOutlineColor(sf::Color::White);
	y_axis_guide_lines[5].setPosition(y_axis_origin, 7 * y_separation_length);
	//simulation properties
	float x_min = 0;
	float x_max = 0;
	float y_min = 0;
	float y_max = 5;
	float step = 0;
	float samples = 1000;
	float amplitud_operator = 0;
	//curve properties
	int curve_point = 0;
	float m = 0;
	float x = 0;
	float b = 0;
	float funtion = m * x + b;
	float x_movement = 0;
	float y_movement = 0;
	//mysql_queries
	mysqlpp::Connection mysql(false);
	mysql.connect("test", "localhost", "root", "root");
	Query query = mysql.query();
	query << "SELECT COUNT(*) FROM wave01;";
	StoreQueryResult result = query.store();
	int number_rows = int.Parse(result.ToString());
	int mysql_row = 0;
	//loop
	while(window.isOpen()){
		sf::Event event;
        	while (window.pollEvent(event)){
            		if (event.type == sf::Event::Closed){
	 			window.close();
			}        	
		}
		
		//xy_axis
		window.draw(x_axis_line);
		window.draw(y_axis_line);
		//axis_guide_lines
		window.draw(x_axis_guide_lines[0]);
		window.draw(x_axis_guide_lines[1]);
		window.draw(x_axis_guide_lines[2]);
		window.draw(x_axis_guide_lines[3]);
		window.draw(x_axis_guide_lines[4]);
		window.draw(x_axis_guide_lines[5]);
		window.draw(y_axis_guide_lines[0]);
		window.draw(y_axis_guide_lines[1]);
		window.draw(y_axis_guide_lines[2]);
		window.draw(y_axis_guide_lines[3]);
		window.draw(y_axis_guide_lines[4]);
		window.draw(y_axis_guide_lines[5]);
		//curve
		if(step <= 6 * RENDERWIDTH / 8 - 10){
			funtion = 5 * sin (curve_point * 3.141592654 / 180);
			x_movement = x_separation_length + step + 10;
			y_movement = -1 * funtion * amplitud_operator + x_axis_origin;
			step = step + RENDERWIDTH / samples;
			amplitud_operator = 3 * y_separation_length / y_max;

			sf::CircleShape point[RENDERWIDTH];
			point[curve_point].setRadius(1);
			point[curve_point].setFillColor(sf::Color::Red);
			point[curve_point].setPosition(x_movement, y_movement);
			window.draw(point[curve_point]); 
			++curve_point;
		}
		if (mysql_row <= number_rows){
		//mysql_data
			funtion = 5 * sin (curve_point * 3.141592654 / 180);
			x_movement = x_separation_length + step + 10;
			y_movement = -1 * funtion * amplitud_operator + x_axis_origin;
			step = step + RENDERWIDTH / samples;
			amplitud_operator = 3 * y_separation_length / y_max;

			sf::CircleShape point[RENDERWIDTH];
			point[curve_point].setRadius(1);
			point[curve_point].setFillColor(sf::Color::Blue);
			point[curve_point].setPosition(x_movement, y_movement);
			window.draw(point[curve_point]); 
			++curve_point;
		}
		//text
		sf::Font font;	
		font.loadFromFile("fonts/LiberationSerif-Regular.ttf");
		sf::Text text("", font, 50);
		text.setPosition(RENDERWIDTH / 4, RENDERHEIGHT / 4);
		text.setString(convertInt(step));
		
		window.display();
		
	}
}
