#include "CLog.h"
#include <assert.h>

//-----------------------------------------------------------------------------

using namespace std;

//-----------------------------------------------------------------------------

CLog::CLog( const string& name ) :
  c_name( name ),
  m_file( nullptr )
{
}

//-----------------------------------------------------------------------------

CLog::~CLog()
{
  *this << "Log ended.";

  if( m_file != nullptr )
  {
    fclose( m_file );
  }
}

//-----------------------------------------------------------------------------

void CLog::Initialise( const std::string& logAbsPath )
{
  errno_t err = fopen_s( &m_file,
    ( logAbsPath + c_name + ".log" ).c_str(),
    "wt" );

  assert( err == 0 );

  if( err != 0 )
  {
    m_file = nullptr;
  }

  *this << "Log started.";
}

//-----------------------------------------------------------------------------

void CLog::operator <<( const string& text )
{
  if( m_file != nullptr )
  {
    fwrite( text.c_str(),
            text.length(),
            1,
            m_file );

    fwrite( "\n",
            1,
            1,
            m_file );
  }
}

//-----------------------------------------------------------------------------

void CLog::operator <<( const char* text )
{
  string s( text );
  *this << s;
}

//-----------------------------------------------------------------------------

void CLog::operator <<( const char& value )
{
  *this << to_string( value );
}

//-----------------------------------------------------------------------------

void CLog::operator <<( const unsigned char& value )
{
  *this << to_string( value );
}

//-----------------------------------------------------------------------------

void CLog::operator <<( const short& value )
{
  *this << to_string( value );
}

//-----------------------------------------------------------------------------

void CLog::operator <<( const unsigned short& value )
{
  *this << to_string( value );
}

//-----------------------------------------------------------------------------

void CLog::operator <<( const int& value )
{
  *this << to_string( value );
}

//-----------------------------------------------------------------------------

void CLog::operator <<( const unsigned int& value )
{
  *this << to_string( value );
}

//-----------------------------------------------------------------------------

void CLog::operator <<( const float& value )
{
  *this << to_string( value );
}

//-----------------------------------------------------------------------------

void CLog::operator <<( const double& value )
{
  *this << to_string( value );
}

//-----------------------------------------------------------------------------