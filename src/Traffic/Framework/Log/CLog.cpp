#include "CLog.h"
#include <assert.h>
#include <ctime>

//-----------------------------------------------------------------------------

using namespace std;

//-----------------------------------------------------------------------------

string CLog::m_logAbsPath = "";
map< Log::Type, FILE* > CLog::m_files = map< Log::Type, FILE* >();

//-----------------------------------------------------------------------------

void CLog::Initialise( const std::string& logAbsPath )
{
  m_logAbsPath = logAbsPath;

  AddLog( INFO, "info" );
  AddLog( ERROR, "error" );
}

//-----------------------------------------------------------------------------

void CLog::Shutdown()
{
  for( map< Log::Type, FILE* >::const_iterator it = m_files.begin();
       it != m_files.end();
       it++ )
  {
    Log( it->first, "Log end" );
    fclose( it->second );
  }
}

//-----------------------------------------------------------------------------

void CLog::Log( const Log::Type type,
                const string& text )
{
  FILE* file = nullptr;

  map< Log::Type, FILE* >::const_iterator it = m_files.find( type );

  assert( it != m_files.end() );

  if( it != m_files.end() )
  {
    file = it->second;

    assert( file != nullptr );

    // Timestamp.
    string timeStamp;
    struct tm newTime;
    __time32_t time32;
    errno_t err;
    _time32( &time32 );
    err = _localtime32_s( &newTime, &time32 );
    if( err == 0 )
    {
      timeStamp += ( newTime.tm_hour < 10 ? "0" : "" );
      timeStamp += to_string( newTime.tm_hour );
      timeStamp += ":";
      timeStamp += ( newTime.tm_min < 10 ? "0" : "" );
      timeStamp += to_string( newTime.tm_min );
      timeStamp += ":";
      timeStamp += ( newTime.tm_sec < 10 ? "0" : "" );
      timeStamp += to_string( newTime.tm_sec );
    }

    // Write it to file.
    string logText( "[" + timeStamp + "] " + text + "\n" );

    fwrite( logText.c_str(),
            logText.length(),
            1,
            file );
  }
}

//-----------------------------------------------------------------------------

void CLog::Log( const Log::Type type,
                const char* text )
{
  string s( text );
  Log( type, s );
}

//-----------------------------------------------------------------------------

void CLog::Log( const Log::Type type,
                const char& value )
{
  Log( type, to_string( value ) );
}

//-----------------------------------------------------------------------------

void CLog::Log( const Log::Type type,
                const unsigned char& value )
{
  Log( type, to_string( value ) );
}

//-----------------------------------------------------------------------------

void CLog::Log( const Log::Type type,
                const short& value )
{
  Log( type, to_string( value ) );
}

//-----------------------------------------------------------------------------

void CLog::Log( const Log::Type type,
                const unsigned short& value )
{
  Log( type, to_string( value ) );
}

//-----------------------------------------------------------------------------

void CLog::Log( const Log::Type type,
                const int& value )
{
  Log( type, to_string( value ) );
}

//-----------------------------------------------------------------------------

void CLog::Log( const Log::Type type,
                const unsigned int& value )
{
  Log( type, to_string( value ) );
}

//-----------------------------------------------------------------------------

void CLog::Log( const Log::Type type,
                const float& value )
{
  Log( type, to_string( value ) );
}

//-----------------------------------------------------------------------------

void CLog::Log( const Log::Type type,
                const double& value )
{
  Log( type, to_string( value ) );
}

//-----------------------------------------------------------------------------

void CLog::AddLog( const Log::Type type,
                   const string& name )
{
  map< Log::Type, FILE* >::const_iterator it =
    m_files.find( type );

  assert( it == m_files.end() );    // Shouldn't already be in the map.

  if( it == m_files.end() )
  {
    FILE* file;

    errno_t err = fopen_s( &file,
      ( m_logAbsPath + name + ".log" ).c_str(),
      "wt" );

    assert( err == 0 );

    if( err == 0 )
    {
      m_files.insert(
        pair< Log::Type, FILE* >( type, file ) );

      Log( type, "Log Started" );
    }
  }
}

//-----------------------------------------------------------------------------