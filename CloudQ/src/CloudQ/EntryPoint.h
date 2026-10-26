#pragma once

#ifdef CQ_PLATFORM_WINDOWS


extern CloudQ::Application* CloudQ::CreateApplication();

int main(int argc, char** argv)
{

	CloudQ::Log::Init();
	CQ_CORE_WARN("Initialized Core Log");
	int a = 5;
	CQ_INFO("Hello from Client Log, Var = {0}", a);
	auto app = CloudQ::CreateApplication();
	app->Run();
	delete app;
	return 0;
}


#endif