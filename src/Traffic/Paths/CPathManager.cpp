#include "CPathManager.h"
#include "..\Framework\Xml\tinyxml2.h"

//-----------------------------------------------------------------------------

using namespace tinyxml2;

//-----------------------------------------------------------------------------

CPathManager::CPathManager()
  :
  m_segments()
{

}

//-----------------------------------------------------------------------------

CPathManager::~CPathManager()
{

}

//-----------------------------------------------------------------------------

bool CPathManager::Initialise( const string& filename )
{
  // Load the doc.
  LOG( INFO, "Loading '" + filename + "'..." );

  XMLDocument doc;

  if( doc.LoadFile( filename.c_str() ) != XML_NO_ERROR )
  {

  }
  else
  {
    LOG( ERROR, "Failed to load '" + filename + "." );
    return false;
  }

  return true;
}

//-----------------------------------------------------------------------------