#include "CPathSegment.h"

//-----------------------------------------------------------------------------

CPathSegment::CPathSegment()
  :
  m_id( 0 ),
  m_nextSegments(),
  m_prevSegments(),
  m_points()
{
}

//-----------------------------------------------------------------------------

CPathSegment::~CPathSegment()
{
}

//-----------------------------------------------------------------------------

void CPathSegment::AddNextSegment( const CPathSegment& segment )
{
  m_nextSegments.push_back( make_unique< SegmentJoin >( segment ) );
}

//-----------------------------------------------------------------------------

void CPathSegment::AddPrevSegment( const CPathSegment& segment )
{
  m_prevSegments.push_back( make_unique< SegmentJoin >( segment ) );
}

//-----------------------------------------------------------------------------

void CPathSegment::SetPoints( const vector< vect3 >& points )
{
  m_points = points;
}

//-----------------------------------------------------------------------------