#include "Common.h"
#include "CPathSegment.h"

//-----------------------------------------------------------------------------

class CPathManager
{
  //-- Public methods.
public:
  CPathManager();
  ~CPathManager();

  bool Initialise( const string& filename );
  bool CreatePathsFromXml( const CXmlElement& xml );

  //-- Private members.
private:
  vector< unique_ptr< CPathSegment > > m_segments;
};

//-----------------------------------------------------------------------------