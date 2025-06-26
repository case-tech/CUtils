#include "SystemConfiguration.hpp"

namespace CUtils
{
#if defined(_WIN32) || defined(_WIN64)
    typedef LONG NTSTATUS;
    typedef NTSTATUS(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);

    std::string SystemConfiguration::GetOSVersion()
    {
        HMODULE h_mod_ = LoadLibraryW(L"ntdll.dll");
        if (h_mod_)
        {
            RtlGetVersionPtr p_rtl_get_version_ = (RtlGetVersionPtr)
                    GetProcAddress(h_mod_, "RtlGetVersion");

            if (p_rtl_get_version_ != nullptr)
            {
                RTL_OSVERSIONINFOW osvi_ = {0};
                osvi_.dwOSVersionInfoSize = sizeof(osvi_);

                if (p_rtl_get_version_(&osvi_) == (NTSTATUS)0x00000000L)
                {
                    std::ostringstream os_version_;
                    os_version_ << osvi_.dwMajorVersion << "."
                                << osvi_.dwMinorVersion << " (Build "
                                << osvi_.dwBuildNumber << ")";
                 
                    FreeLibrary(h_mod_);
                    return os_version_.str();
                }
            }
            FreeLibrary(h_mod_);
        }

        return "Unknown Version";
    }
#else
    std::string SystemConfiguration::GetOSVersion()
    {
        return "Unknown";
    }
#endif

    std::string SystemConfiguration::GetOSName()
    {
#if defined(_WIN32) || defined(_WIN64)
        return "Windows";
#elif __APPLE__
        return "MacOS";
#elif __linux__
        return "Linux";
#else
        return "Unknown OS";
#endif
    }

    std::string SystemConfiguration::GetCPUInfo()
    {
#if defined(_WIN32) || defined(_WIN64)
        SYSTEM_INFO sys_info_;
        GetSystemInfo(&sys_info_);
        std::ostringstream cpu_info_;
        cpu_info_ << "CPU Architecture: ";

        switch (sys_info_.wProcessorArchitecture)
        {
        case PROCESSOR_ARCHITECTURE_AMD64:
            cpu_info_ << "x64 (AMD or Intel)";
            break;
        case PROCESSOR_ARCHITECTURE_ARM:
            cpu_info_ << "ARM";
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:
            cpu_info_ << "x86";
            break;
        default:
            cpu_info_ << "Unknown";
        }

        return cpu_info_.str();

#elif __APPLE__
        return _ExecCommand("sysctl -n machdep.cpu.brand_string");

#elif __linux__
        std::ifstream cpu_info_("/proc/cpuinfo");
        std::string line_;
        while (std::getline(cpu_info_, line_))
        {
            if (line_.find("model name") != std::string::npos)
            {
                return line_.substr(line_.find(":") + 2);
            }
        }

        return "Unknown CPU";
#endif
    }

    std::string SystemConfiguration::GetMemoryInfo()
    {
#if defined(_WIN32) || defined(_WIN64)
        MEMORYSTATUSEX statex_;
        statex_.dwLength = sizeof(statex_);
        GlobalMemoryStatusEx(&statex_);
        std::ostringstream mem_info_;
        mem_info_ << "Total Physical Memory: "
                  << (statex_.ullTotalPhys / (1024 * 1024)) << " MB";
        
        return mem_info_.str();

#elif __APPLE__
        return _ExecCommand("sysctl -n hw.memsize");

#elif __linux__
        std::ifstream mem_info_("/proc/meminfo");
        std::string line_;
        while (std::getline(mem_info_, line_))
        {
            if (line_.find("MemTotal") != std::string::npos)
            {
                return line_.substr(line_.find(":") + 1);
            }
        }

        return "Unknown Memory";
#endif
    }

    std::string SystemConfiguration::GetDiskInfo()
    {
#if defined(_WIN32) || defined(_WIN64)
        ULARGE_INTEGER free_bytes_available_;
        ULARGE_INTEGER total_number_of_bytes_;
        GetDiskFreeSpaceExW(L"C:\\",
                            &free_bytes_available_,
                            &total_number_of_bytes_,
                            NULL);
        
        std::ostringstream disk_info_;
        disk_info_ << "Total Disk Space: "
                   << (total_number_of_bytes_.QuadPart / (1024 * 1024 * 1024))
                   << " GB";
        
        return disk_info_.str();

#elif __APPLE__
        return _ExecCommand("df -h / | awk 'NR==2 {print $2}'");

#elif __linux__
        return _ExecCommand("df -h --total | grep 'total' | awk '{print $2}'");
#endif
    }

#if defined(_WIN32) || defined(_WIN64)
    std::string SystemConfiguration::_ExecCommand(const std::string& command_a)
    {
        return "Command execution not implemented on Windows.";
    }

#else
    std::string SystemConfiguration::_ExecCommand(const char* command_a)
    {
        std::array<char, 128> buffer_;
        std::string result_;
        std::unique_ptr<FILE, decltype(&pclose)> pipe_(popen(command_a, "r"),
                                                       pclose);
        if (!pipe_)
        {
            throw std::runtime_error("popen() failed!");
        }

        while (fgets(buffer_.data(), buffer_.size(), pipe_.get()) != nullptr)
        {
            result_ += buffer_.data();
        }

        return result_;
    }
#endif
} // namespace CUtils
