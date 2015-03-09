#pragma once

// External includes.
#include <memory>
#include <vector>

// Internal includes.
#include "CommonTypes.h"
#include "Log\CLog.h"

// Namespaces.
using namespace std;
using namespace CommonTypes;

// Globals.
namespace Global
{
  static CLog g_logInfo( "Info" );
  static CLog g_logError( "Error" );
};