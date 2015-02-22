#pragma once

#include "Common.h"

//-----------------------------------------------------------------------------

class CPathSegment;
class CActor;

//-----------------------------------------------------------------------------

class APathIntersection
{
  //-- Public methods.
public:
  APathIntersection();
  virtual ~APathIntersection();

  // Determines which actor (vehicle, pedestrian, etc.) at or approaching the
  // intersection has right-of-way.
  virtual void DoDetermineActorWithRightOfWayLogic() = 0;

  //-- Public getters.
public:
  bool GetDoesActorHaveRightOfWay( const CActor& actor ) const;

  //-- Protected setters.
protected:
  void SetActorWithRightOfWay( const CActor& actor );

  //-- Private members.
private:
  vector< CPathSegment* > m_segments;
  weak_ptr< CActor > m_actorWithRightOfWay;
};

//-----------------------------------------------------------------------------