#include "Common.h"
#include "CPathSegment.h"

//-----------------------------------------------------------------------------

class CPathManager
{
public:
  CPathManager();
  ~CPathManager();

private:
  vector< unique_ptr< CPathSegment > > m_segments;
};

//-----------------------------------------------------------------------------