#include "APathIntersection.h"

// Public methods =============================================================

APathIntersection::APathIntersection() :
  m_segments(),
  m_actorWithRightOfWay()
{

}

//-----------------------------------------------------------------------------

APathIntersection::~APathIntersection()
{

}

//-----------------------------------------------------------------------------

bool APathIntersection::GetDoesActorHaveRightOfWay( const CActor& actor ) const
{
  // TODO
  return true;
}

// Protect methods ============================================================

void APathIntersection::SetActorWithRightOfWay( const CActor& actor )
{
  // TODO
  //m_actorWithRightOfWay = &actor;
}

//-----------------------------------------------------------------------------