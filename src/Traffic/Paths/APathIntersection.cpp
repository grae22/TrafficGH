#include "APathIntersection.h"
#include "..\Actors\CActor.h"

//-----------------------------------------------------------------------------

uint APathIntersection::m_nextId = 1;

// Public methods =============================================================

APathIntersection::APathIntersection() :
  m_id( m_nextId++ ),
  m_segments(),
  m_actorsWithRightOfWay()
{

}

//-----------------------------------------------------------------------------

APathIntersection::~APathIntersection()
{

}

//-----------------------------------------------------------------------------

bool APathIntersection::GetDoesActorHaveRightOfWay( const CActor& actor ) const
{
  // TODO: Best way to do this?
  for each ( weak_ptr< CActor > a in m_actorsWithRightOfWay )
  {
    if( a.lock().get() == &actor )
    {
      return true;
    }
  }

  return false;
}

// Protect methods ============================================================

void APathIntersection::SetActorWithRightOfWay( const CActor& actor )
{
  m_actorsWithRightOfWay.clear();

  AddActorWithRightOfWay( actor );
}

//-----------------------------------------------------------------------------

void APathIntersection::AddActorWithRightOfWay( const CActor& actor )
{
  m_actorsWithRightOfWay.push_back(
    weak_ptr< CActor >(
      make_shared< CActor >( actor ) ) );
}

//-----------------------------------------------------------------------------