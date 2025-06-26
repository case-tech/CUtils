# Copyright (c) 2025 Case Technologies

set(PROJECT_NAME CUtils)

# Sources
set(Coroutine
    "Coroutine/Coroutine.hpp"
    "Coroutine/Coroutine.cpp")

set(DateTime
    "DateTime/DateTime.hpp"
    "DateTime/DateTime.cpp")

set(Encryption
    "Encryption/Encryption.hpp"
    "Encryption/Encryption.cpp")

set(Filesystem
    "Filesystem/Filesystem.hpp"
    "Filesystem/Filesystem.cpp")
	
set(Fusion
    "Fusion/Fusion.hpp"
    "Fusion/Fusion.cpp")

set(INIParser
    "INIParser/INIParser.hpp"
    "INIParser/INIParser.cpp")

set(Multithread
    "Multithread/Multithread.hpp"
    "Multithread/Multithread.cpp")
	
set(NoisePerlin
    "NoisePerlin/NoisePerlin.hpp"
    "NoisePerlin/NoisePerlin.cpp")

set(Notification
    "Notification/Notification.hpp"
    "Notification/Notification.cpp")

set(Options
    "Options/Options.hpp"
    "Options/Options.cpp")

set(Plugins
    "Plugins/Plugins.hpp"
    "Plugins/Plugins.cpp")
	
set(Random
    "Random/Random.hpp"
    "Random/Random.cpp")
	
set(RTTI
    "RTTI/RTTI.hpp"
    "RTTI/RTTI.cpp")

set(Singleton
    "Singleton/Singleton.hpp"
    "Singleton/Singleton.cpp")
	
set(StringHelper
    "StringHelper/StringHelper.hpp"
    "StringHelper/StringHelper.cpp")

set(SystemConfiguration
    "SystemConfiguration/SystemConfiguration.hpp"
    "SystemConfiguration/SystemConfiguration.cpp")

set(Timer
    "Timer/Timer.hpp"
    "Timer/Timer.cpp")

set(UnitTests
    "UnitTests/UnitTests.hpp"
    "UnitTests/UnitTests.cpp")

# Groups
source_group("Coroutine"           FILES ${Coroutine})
source_group("DateTime"            FILES ${DateTime})
source_group("Encryption"          FILES ${Encryption})
source_group("Filesystem"          FILES ${Filesystem})
source_group("Fusion"              FILES ${Fusion}})
source_group("INIParser"           FILES ${INIParser})
source_group("Multithread"         FILES ${Multithread})
source_group("NoisePerlin"         FILES ${NoisePerlin})
source_group("Notification"        FILES ${Notification})
source_group("Options"             FILES ${Options})
source_group("Plugins"             FILES ${Plugins})
source_group("Random"              FILES ${Random})
source_group("RTTI"                FILES ${RTTI})
source_group("Singleton"           FILES ${Singleton})
source_group("StringHelper"        FILES ${StringHelper})
source_group("SystemConfiguration" FILES ${SystemConfiguration})
source_group("Timer"               FILES ${Timer})
source_group("UnitTests"           FILES ${UnitTests})

# Create library
add_library(${PROJECT_NAME} 
    STATIC 
    ${Coroutine}
    ${DateTime}
    ${Encryption}
    ${Filesystem}
    ${Fusion}
    ${INIParser}
    ${Multithread}
    ${NoisePerlin}
    ${Notification}
    ${Options}
    ${Plugins}
    ${Random}
    ${RTTI}
    ${Singleton}
    ${StringHelper}
    ${SystemConfiguration}
    ${Timer}
    ${UnitTests})