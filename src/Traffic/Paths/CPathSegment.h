#pragma once

#include "Common.h"

//-----------------------------------------------------------------------------

class CPathSegment
{
  //-- Public methods.
public:
  CPathSegment();
  virtual ~CPathSegment();

  // Setters.
  void AddNextSegment( const CPathSegment& segment );
  void AddPrevSegment( const CPathSegment& segment );
  void SetPoints( const vector< vect3 >& points );

  //-- Private types.
private:
  struct SegmentJoin
  {
  public:
    const CPathSegment& m_segment;

    SegmentJoin( const CPathSegment& segment )
      :
      m_segment( segment ) {}
  };

  //-- Private members.
private:
  uint m_id;
  vector< unique_ptr< SegmentJoin > > m_nextSegments;
  vector< unique_ptr< SegmentJoin > > m_prevSegments;
  vector< vect3 > m_points;
};

//-----------------------------------------------------------------------------