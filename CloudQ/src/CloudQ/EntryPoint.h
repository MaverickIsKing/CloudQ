#pragma once

#ifdef CQ_PLATFORM_WINDOWS


extern CloudQ::Application* CloudQ::CreateApplication();

int main(int argc, char** argv)
{
	auto app = CloudQ::CreateApplication();
	app->Run();
	delete app;
	return 0;
}


#endif