#include "Common.h"

#include "..\Paths\CPathManager.h"

//-----------------------------------------------------------------------------

using namespace Global;

//-----------------------------------------------------------------------------

int main()
{
  g_logInfo.Initialise( "" );
  g_logError.Initialise( "" );

  CPathManager pathManager;
  pathManager.Initialise( "Paths.xml" );

  return 0;
}

//-----------------------------------------------------------------------------