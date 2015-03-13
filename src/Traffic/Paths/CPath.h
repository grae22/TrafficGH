#pragma once

#include "Common.h"

//-----------------------------------------------------------------------------

class CPath
{
public:
  CPath();
  virtual ~CPath();

  bool Initialise( const CXmlElement& xml );
};

//-----------------------------------------------------------------------------