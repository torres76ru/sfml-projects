#include "Gui.h"

gui::Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned character_size,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
	sf::Color idle_color, sf::Color hover_color, sf::Color active_color)
{
	this->buttonState = BTN_IDLE;
	this->MousePressedInside = false;
	this->MousePressedOutside = false;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idle_color);

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(text_idle_color);
	this->text.setCharacterSize(character_size);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - (this->text.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().left,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - (this->text.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().top
	);

	//Text color
	this->textIdleColor = text_idle_color;
	this->textHoverColor = text_hover_color;
	this->textActiveColor = text_active_color;

	//Button color
	this->idleColor = idle_color;
	this->hoverColor = hover_color;
	this->activeColor = active_color;
}

gui::Button::~Button()
{

}

//Accessors
const bool gui::Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
		return true;
	return false;
}

const bool gui::Button::isReleased() const
{
	if (this->buttonState == BTN_RELEASE)
		return true;
	return false;
}


void gui::Button::setBorder(sf::Color color, float thickness)
{
	this->shape.setOutlineColor(color);
	this->shape.setOutlineThickness(thickness);
}

//Functions

void gui::Button::update(const sf::Vector2i& mousePosWindow)
{
	/*Update the booleans for hover and pressed and release*/

	//Idle
	this->buttonState = BTN_IDLE;

	//Hover
	if (this->shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosWindow)) && !this->MousePressedOutside)
	{
		this->buttonState = BTN_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->MousePressedInside = true;
			this->buttonState = BTN_ACTIVE;
		}
		else
		{
			if (this->MousePressedInside)
				this->buttonState = BTN_RELEASE;
		}
	}
	else
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !this->MousePressedInside)
			this->MousePressedOutside = true;
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->MousePressedOutside = false;
		this->MousePressedInside = false;
	}


	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		this->text.setFillColor(this->textIdleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		this->text.setFillColor(this->textHoverColor);
		break;

	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		this->text.setFillColor(this->textActiveColor);
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		this->shape.setFillColor(sf::Color::Blue);
		break;
	}
}

void gui::Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}

gui::InputField::InputField(
	float x, float y, float width, float height, unsigned max_size,
	sf::Font* font, std::string text, unsigned character_size,
	sf::Color text_color,
	sf::Color background_color,
	sf::Color border_color, sf::Color border_hover_color, sf::Color border_active_color)
{
	this->shape.setPosition(x, y);
	this->shape.setSize(sf::Vector2f(width, height));

	this->mouseReleased = false;
	this->textEnetered = false;

	this->active = false;
	this->maxSize = max_size;
	this->keytimeMax = 0.5f;
	this->keytime = keytimeMax;

	this->paddingTop = 10.f;
	this->paddingRight = 10.f;
	this->paddingBottom = 10.f;
	this->paddingLeft = 10.f;

	this->font = font;
	this->characterSize = character_size;


	this->text.setFont(*this->font);
	this->text.setCharacterSize(character_size);
	this->text.setFillColor(text_color);
	this->text.setPosition(
		this->shape.getPosition().x + this->paddingLeft - this->text.getGlobalBounds().left,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - (this->text.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().top - 12.f
	);

	this->text.setString("");

	this->shape.setFillColor(background_color);
	this->shape.setOutlineThickness(-1.f);

	this->borderColor = border_color;
	this->borderHoverColor = border_hover_color;
	this->borderActiveColor = border_active_color;

	this->shape.setOutlineColor(this->borderColor);

	this->labelText;
	this->labelText.setFillColor(this->borderHoverColor);
	this->labelText.setFont(*this->font);
	this->labelText.setCharacterSize(this->characterSize);
	this->labelText.setString(text);
	this->labelText.setPosition(
		this->shape.getPosition().x + this->paddingLeft - this->labelText.getGlobalBounds().left,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - (this->labelText.getGlobalBounds().height / 2.f) - this->labelText.getGlobalBounds().top
	);

	this->cursor.setPosition(sf::Vector2f(
		this->text.getPosition().x + this->text.getGlobalBounds().width,
		this->shape.getPosition().y + (this->shape.getSize().y - this->shape.getSize().y / 1.25) / 2.f)
	);

	this->cursor.setSize(sf::Vector2f(
		1.f,
		this->shape.getSize().y / 1.25
	));
}

gui::InputField::~InputField()
{
}

const bool gui::InputField::getKeytime()
{
	if (this->keytime >= this->keytimeMax)
	{
		this->keytime = 0.f;
		return true;
	}

	return false;
}

const std::string gui::InputField::getText() const
{
	return this->textString;
}

void gui::InputField::setPosition(float x, float y)
{
	this->shape.setPosition(x, y);
}

void gui::InputField::setSize(float width, float height)
{
	this->shape.setSize(sf::Vector2f(width, height));
}

void gui::InputField::setText(std::string text)
{
	this->text.setString(text);
}

void gui::InputField::setLabel(std::string text)
{
	this->labelText;
	this->labelText.setFillColor(this->borderColor);
	this->labelText.setFont(*this->font);
	this->labelText.setCharacterSize(this->characterSize);
	this->labelText.setString(text);
	this->labelText.setPosition(
		this->shape.getPosition().x + this->paddingLeft - this->labelText.getGlobalBounds().left,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - (this->labelText.getGlobalBounds().height / 2.f) - this->labelText.getGlobalBounds().top
	);
}

void gui::InputField::setActive(bool active)
{
	this->active = active;
}

void gui::InputField::backspace()
{
	if (this->textString.size() > 0)
	{
		this->textString.pop_back();
		this->setText(this->textString);
	}
}

void gui::InputField::updateKeytime(const float& dt)
{
	if (this->keytime < this->keytimeMax)
		this->keytime += dt;
}

void gui::InputField::update(const sf::Vector2i& mousePosWindow, sf::Event& sfEvent, const float& dt, std::map<std::string, gui::InputField*>* inputFields)
{
	this->updateKeytime(dt);

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->mouseReleased == true)
	{
		mouseReleased = false;
	}

	if (this->shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosWindow)))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->mouseReleased == false)
		{

			if (this->active)
				this->active = false;
			else
			{
				for (auto& i : *inputFields)
				{
					i.second->setActive(false);
				}
				this->active = true;
			}


			this->mouseReleased = true;

		}

		this->shape.setOutlineColor(this->borderHoverColor);
	}
	else
	{
		this->shape.setOutlineColor(this->borderColor);
	}


	if (active)
	{
		this->shape.setOutlineColor(this->borderActiveColor);

		char input;


		if (sfEvent.type == sf::Event::TextEntered) {
			input = static_cast<char>(sfEvent.text.unicode);
			if (!this->textEnetered)
			{
				if (int(input) >= 48 && int(input) <= 57 || input == ',')
				{
					if (this->textString.size() < this->maxSize)
					{
						this->textString += input;
						this->setText(this->textString);
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
				{
					this->backspace();
				}
			}
			this->textEnetered = true;
		}
		else
		{
			this->textEnetered = false;
		}

		this->cursor.setPosition(sf::Vector2f(
			this->text.getPosition().x + this->text.getGlobalBounds().width,
			this->shape.getPosition().y + (this->shape.getSize().y - this->shape.getSize().y / 1.25) / 2.f)
		);

		if (this->getKeytime())
		{
			if (this->cursorDisplay)
			{
				this->cursorDisplay = false;
				this->cursor.setFillColor(sf::Color::Transparent);
			}
			else
			{
				this->cursorDisplay = true;
				this->cursor.setFillColor(sf::Color::White);
			}
		}
	}
	else
	{
		this->shape.setOutlineColor(this->borderColor);
	}

}

void gui::InputField::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	std::string str = this->labelText.getString();
	if (this->text.getString() == "")
		target.draw(this->labelText);
	else
		target.draw(this->text);

	if (this->active)
	{
		target.draw(cursor);
	}
}
