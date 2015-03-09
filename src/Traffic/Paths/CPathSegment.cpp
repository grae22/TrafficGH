#include "CPathSegment.h"
#include "APathIntersection.h"
#include "Intersections\CPathIntersection_None.h"

//-----------------------------------------------------------------------------

uint CPathSegment::m_nextId = 1;

// Public methods =============================================================

CPathSegment::CPathSegment( const APathIntersection& nextIntersection,
                            const APathIntersection& prevIntersection,
                            const vector< vect3 >& points ) :
  m_id( m_nextId++ ),
  m_nextIntersection( nextIntersection ),
  m_prevIntersection( prevIntersection ),
  m_points( points )
{
}

//-----------------------------------------------------------------------------

CPathSegment::~CPathSegment()
{
}

//-----------------------------------------------------------------------------