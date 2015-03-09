#pragma once

#include <string>
#include <stdio.h>

//-----------------------------------------------------------------------------

class CLog
{
  //-- Public methods.
public:
  CLog( const std::string& name );
  virtual ~CLog();

  void Initialise( const std::string& logAbsPath );

  void operator <<( const std::string& text );
  void operator <<( const char* text );
  void operator <<( const char& value );
  void operator <<( const unsigned char& value );
  void operator <<( const short& value );
  void operator <<( const unsigned short& value );
  void operator <<( const int& value );
  void operator <<( const unsigned int& value );
  void operator <<( const float& value );
  void operator <<( const double& value );

  //-- Private members.
private:
  const std::string c_name;
  FILE* m_file;
};

//-----------------------------------------------------------------------------