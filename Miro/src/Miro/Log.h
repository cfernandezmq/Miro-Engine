#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h" // Log our types

namespace Miro
{
	class MIRO_API Log
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

//Core log macros
#define MR_CORE_ERROR(...) ::Miro::Log::GetCoreLogger()->error(__VA_ARGS__);
#define MR_CORE_WARN(...)  ::Miro::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define MR_CORE_INFO(...)  ::Miro::Log::GetCoreLogger()->info(__VA_ARGS__);
#define MR_CORE_TRACE(...) ::Miro::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define MR_CORE_FATAL(...) ::Miro::Log::GetCoreLogger()->fatal(__VA_ARGS__);

//Client log macros
#define MR_ERROR(...)      ::Miro::Log::GetClientLogger()->error(__VA_ARGS__);
#define MR_WARN(...)       ::Miro::Log::GetClientLogger()->warn(__VA_ARGS__);
#define MR_INFO(...)       ::Miro::Log::GetClientLogger()->info(__VA_ARGS__);
#define MR_TRACE(...)      ::Miro::Log::GetClientLogger()->trace(__VA_ARGS__);
#define MR_FATAL(...)      ::Miro::Log::GetClientLogger()->fatal(__VA_ARGS__);