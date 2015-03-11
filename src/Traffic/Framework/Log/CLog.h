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

  static void Log( const Log::Type type, const std::string& text );
  static void Log( const Log::Type type, const char* text );
  static void Log( const Log::Type type, const char& value );
  static void Log( const Log::Type type, const unsigned char& value );
  static void Log( const Log::Type type, const short& value );
  static void Log( const Log::Type type, const unsigned short& value );
  static void Log( const Log::Type type, const int& value );
  static void Log( const Log::Type type, const unsigned int& value );
  static void Log( const Log::Type type, const float& value );
  static void Log( const Log::Type type, const double& value );

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