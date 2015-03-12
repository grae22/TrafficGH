#pragma once

#include <string>
#include <map>
#include <stdio.h>

//-----------------------------------------------------------------------------

namespace Log
{
  enum Type
  {
    INFO,
    ERROR
  };
};

using namespace Log;    // So all files including this header get this for free.

//-----------------------------------------------------------------------------

class CLog
{
  //-- Public methods.
public:
  static void Initialise( const std::string& logAbsPath );
  static void Shutdown();

  static void Log( const Log::Type type, const std::string& text, char* function );
  static void Log( const Log::Type type, const char* text, char* function );
  static void Log( const Log::Type type, const char& value, char* function );
  static void Log( const Log::Type type, const unsigned char& value, char* function );
  static void Log( const Log::Type type, const short& value, char* function );
  static void Log( const Log::Type type, const unsigned short& value, char* function );
  static void Log( const Log::Type type, const int& value, char* function );
  static void Log( const Log::Type type, const unsigned int& value, char* function );
  static void Log( const Log::Type type, const float& value, char* function );
  static void Log( const Log::Type type, const double& value, char* function );

  //-- Private methods.
private:
  static void AddLog( const Log::Type type,
                      const std::string& name );

  //-- Private members.
private:
  static std::string m_logAbsPath;
  static std::map< Log::Type, FILE* > m_files;
};

//-----------------------------------------------------------------------------

#define LOG( type, message ) CLog::Log( type, message, __FUNCTION__ )

//-----------------------------------------------------------------------------