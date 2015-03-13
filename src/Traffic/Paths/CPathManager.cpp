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

  if( doc.LoadFile( filename.c_str() ) == XML_SUCCESS )
  {
    CXmlElement* root = doc.FirstChildElement( "Root" );

    if( root == 0 )
    {
      LOG( ERROR, "No 'Root' element found in '" + filename + "'." );
      return false;
    }

    CreatePathsFromXml( *root );
  }
  else
  {
    LOG( ERROR, "Failed to load '" + filename + "'." );
    return false;
  }

  return true;
}

//-----------------------------------------------------------------------------

bool CPathManager::CreatePathsFromXml( const CXmlElement& xml )
{
  LOG( INFO, "Creating paths from xml..." );

  return true;
}

//-----------------------------------------------------------------------------