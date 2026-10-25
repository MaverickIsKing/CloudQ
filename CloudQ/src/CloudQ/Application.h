#pragma once

#include "Core.h"

namespace CloudQ {
	
	class CLOUDQ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}

