#include "Common.h"

#include "..\Paths\CPathManager.h"

//-----------------------------------------------------------------------------

int main()
{
  CLog::Initialise( "" );

  CPathManager pathManager;
  pathManager.Initialise( "Paths.xml" );

  CLog::Shutdown();

  return 0;
}

//-----------------------------------------------------------------------------