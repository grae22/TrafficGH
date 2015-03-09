#include "CPathManager.h"
#include "..\Framework\Xml\tinyxml2.h"

//-----------------------------------------------------------------------------

using namespace Global;
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
  g_logInfo << string() + __FUNCTION__ + "Loading '" + filename + "'...";

  XMLDocument doc;

  if( doc.LoadFile( filename.c_str() ) != XML_NO_ERROR )
  {

  }
  else
  {
//    g_logError << string() + __FUNCTION__ + "Failed to load '" + filename + ".";
    return false;
  }

  return true;
}

//-----------------------------------------------------------------------------