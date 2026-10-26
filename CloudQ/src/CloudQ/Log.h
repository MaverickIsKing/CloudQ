#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace CloudQ {

	class CLOUDQ_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define CQ_CORE_CRITICAL(...)	::CloudQ::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define CQ_CORE_ERROR(...)		::CloudQ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CQ_CORE_WARN(...)		::CloudQ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CQ_CORE_INFO(...)		::CloudQ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CQ_CORE_TRACE(...)		::CloudQ::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define CQ_CRITICAL(...)		::CloudQ::Log::GetClientLogger()->critical(__VA_ARGS__)
#define CQ_ERROR(...)			::CloudQ::Log::GetClientLogger()->error(__VA_ARGS__)
#define CQ_WARN(...)			::CloudQ::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CQ_INFO(...)			::CloudQ::Log::GetClientLogger()->info(__VA_ARGS__)
#define CQ_TRACE(...)			::CloudQ::Log::GetClientLogger()->trace(__VA_ARGS__)