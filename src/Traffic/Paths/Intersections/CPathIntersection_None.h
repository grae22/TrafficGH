#pragma once

#include "..\APathIntersection.h"

//-----------------------------------------------------------------------------

class CPathIntersection_None : public APathIntersection
{
  //-- Public methods.
public:
  CPathIntersection_None();
  virtual ~CPathIntersection_None();

  // APathIntersection.
  virtual void DoDetermineActorWithRightOfWayLogic();
  virtual bool GetDoesActorHaveRightOfWay( const CActor& actor ) const;
};

//-----------------------------------------------------------------------------