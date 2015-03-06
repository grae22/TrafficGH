#include "CPathIntersection_None.h"

//-----------------------------------------------------------------------------

CPathIntersection_None::CPathIntersection_None()
{

}

//-----------------------------------------------------------------------------

CPathIntersection_None::~CPathIntersection_None()
{

}

//-----------------------------------------------------------------------------

void CPathIntersection_None::DoDetermineActorWithRightOfWayLogic()
{

}

//-----------------------------------------------------------------------------

bool CPathIntersection_None::GetDoesActorHaveRightOfWay( const CActor& actor ) const
{
  // All actors have right-of-way always with this intersection type.
  return true;
}

//-----------------------------------------------------------------------------