#include <CloudQ.h>


class Sandbox : public CloudQ::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}


};

CloudQ::Application* CloudQ::CreateApplication()
{
	return new Sandbox();
}