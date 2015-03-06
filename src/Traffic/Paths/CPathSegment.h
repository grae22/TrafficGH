#pragma once

#include "Common.h"

//-----------------------------------------------------------------------------

class APathIntersection;

//-----------------------------------------------------------------------------

class CPathSegment
{
  //-- Public methods.
public:
  CPathSegment();
  virtual ~CPathSegment();

  // Setters.
  void AddNextIntersection( const APathIntersection& intersection );
  void AddPrevIntersection( const APathIntersection& intersection );
  void SetPoints( const vector< vect3 >& points );

  //-- Private members.
private:
  static uint m_nextId;
  uint m_id;
  APathIntersection& m_nextIntersection;
  APathIntersection& m_prevIntersection;
  vector< vect3 > m_points;
};

//-----------------------------------------------------------------------------