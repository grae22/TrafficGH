#include "Common.h"

#include "..\Paths\CPathManager.h"

//-----------------------------------------------------------------------------

int main()
{
  LOG_INITALISE( "" );

  CPathManager pathManager;
  pathManager.Initialise( "Paths.xml" );

  LOG_SHUTDOWN();

  return 0;
}

//-----------------------------------------------------------------------------