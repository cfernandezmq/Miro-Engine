#include <Miro.h>

class Sandbox : public Miro::Application
{
public:
	Sandbox() {}


	//~Sandbox();

};

Miro::Application* Miro::CreateApplication()
{
	return new Sandbox();
}