#include "CPathSegment.h"
#include "APathIntersection.h"
#include "Intersections\CPathIntersection_None.h"

//-----------------------------------------------------------------------------

uint CPathSegment::m_nextId = 1;

// Public methods =============================================================

CPathSegment::CPathSegment()
  :
  m_id( m_nextId++ ),
  m_nextIntersection( CPathIntersection_None() ),   // >>>YOU_ARE_HERE<<< TODO: Fix related warning.
  m_prevIntersection( CPathIntersection_None() ),
  m_points()
{
}

//-----------------------------------------------------------------------------

CPathSegment::~CPathSegment()
{
}

//-----------------------------------------------------------------------------

void CPathSegment::AddNextIntersection( const APathIntersection& intersection )
{
  m_nextIntersection = intersection;
}

//-----------------------------------------------------------------------------

void CPathSegment::AddPrevIntersection( const APathIntersection& intersection )
{
  m_prevIntersection = intersection;
}

//-----------------------------------------------------------------------------

void CPathSegment::SetPoints( const vector< vect3 >& points )
{
  m_points = points;
}

//-----------------------------------------------------------------------------