#pragma once

#include "Common.h"

//-----------------------------------------------------------------------------

class APathIntersection;

//-----------------------------------------------------------------------------

class CPathSegment
{
  //-- Public methods.
public:
  CPathSegment( const APathIntersection& nextIntersection,
                const APathIntersection& prevIntersection,
                const vector< vect3 >& points );
  virtual ~CPathSegment();

  //-- Private members.
private:
  static uint m_nextId;
  uint m_id;
  const APathIntersection& m_nextIntersection;
  const APathIntersection& m_prevIntersection;
  vector< vect3 > m_points;
};

//-----------------------------------------------------------------------------