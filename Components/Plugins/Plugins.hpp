/*
The MIT License (MIT)
Copyright (c) 2025 Case Technologies

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef CUTILS_PLUGINS_HPP
#define CUTILS_PLUGINS_HPP

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#include <string>
#include <vector>
#include <iostream>

namespace CUtils
{
    class PluginInterface
    {
    public:
        virtual ~PluginInterface() = default;
        virtual void Execute() = 0;
    };

    class Plugins
    {
    public:
        Plugins() = default;
        ~Plugins()
        {
            for (auto plugin_ : loaded_plugins_)
            {
#if defined(_WIN32) || defined(_WIN64)
                FreeLibrary((HMODULE)plugin_);
#else
                dlclose(plugin_);
#endif
            }
        }

        bool LoadPlugin(const std::string& plugin_path_a)
        {
            void* plugin_handle_ = nullptr;

#if defined(_WIN32) || defined(_WIN64)
            plugin_handle_ = LoadLibraryA(plugin_path_a.c_str());
            if (!plugin_handle_)
            {
                std::cerr << "Plugin loading error: " << GetLastError() << "\n";
                return false;
            }

            CreatePlugin create_plugin_ = (CreatePlugin)
                    GetProcAddress((HMODULE)plugin_handle_, "СreatPlugin");
            if (!create_plugin_)
            {
                std::cerr << "The CreatePlugin() function could not be found "
                             "in the plugin\n";
                return false;
            }
#else
            plugin_handle_ = dlopen(plugin_path_a.c_str(), RTLD_LAZY);
            if (!plugin_handle_)
            {
                std::cerr << "Plugin loading error: " << dlerror() << "\n";
                return false;
            }

            create_plugin create_plugin_ = (create_plugin)dlsym(plugin_handle_,
                                                                "createPlugin");
            if (!create_plugin_)
            {
                std::cerr << "the CreatePlugin() function could not be found "
                             "in the plugin\n";
                return false;
            }
#endif

            PluginInterface* plugin_ = create_plugin_();
            if (plugin_)
            {
                loaded_plugins_.push_back(plugin_handle_);
                plugin_->Execute();
                return true;
            } 
            else
            {
                std::cerr << "The plugin could not be created.\n";
                return false;
            }
        }

    private:
        std::vector<void*> loaded_plugins_;

#if defined(_WIN32) || defined(_WIN64)
        typedef PluginInterface* (*CreatePlugin)();
#else
        typedef PluginInterface* (*create_plugin)();
#endif
    };
} // namespace CUtils
#endif