#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <sstream>

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE, BTN_RELEASE };

namespace gui
{
	class Button
	{
	private:
		short unsigned buttonState;
		bool MousePressedOutside;
		bool MousePressedInside;

		sf::RectangleShape shape;
		sf::Font* font;
		sf::Text text;

		sf::Color textIdleColor;
		sf::Color textHoverColor;
		sf::Color textActiveColor;


		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color activeColor;



	public:
		Button(float x, float y, float width, float height,
			sf::Font* font, std::string text, unsigned character_size,
			sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
			sf::Color idle_color, sf::Color hover_color, sf::Color active_color);
		~Button();

		//Accessors
		const bool isPressed() const;
		const bool isReleased() const;

		//Functions
		void update(const sf::Vector2i& mousePosWindow);
		void render(sf::RenderTarget& target);
	};

	class TextBox
	{
	private:
		sf::Text text;
		sf::RectangleShape shape;

		bool mouseReleased;
		bool textEnetered;
		std::string textString;

		float keytimeMax;
		float keytime;

		sf::Font* font;

		sf::Text labelText;

		unsigned maxSize;
		bool active;

		unsigned characterSize;

		sf::Color borderColor;
		sf::Color borderHoverColor;
		sf::Color borderActiveColor;

		float paddingTop;
		float paddingRight;
		float paddingBottom;
		float paddingLeft;
	public:
		TextBox(
			float x, float y, float width, float height, unsigned max_size,
			sf::Font* font, unsigned character_size, 
			sf::Color text_color = sf::Color::Color(33, 33, 33, 255),
			sf::Color background_color = sf::Color::White,
			sf::Color border_color = sf::Color::Color(158, 158, 158, 255), sf::Color border_hover_color = sf::Color::Color(33, 33, 33, 255), sf::Color border_active_color = sf::Color::Color(9, 0, 238, 255));
		virtual ~TextBox();

		//Accessors
		const bool getKeytime();
		const std::string getText() const;
		
		//Mutators
		void setPosition(float x, float y);
		void setSize(float width, float height);
		void setText(std::string text);
		void setLabel(std::string text);

		//Functions
		void backspace();

		void updateKeytime(const float& dt);
		void update(const sf::Vector2i& mousePosWindow, sf::Event& sfEvent, const float& dt);
		void render(sf::RenderTarget& target);
	};
}
