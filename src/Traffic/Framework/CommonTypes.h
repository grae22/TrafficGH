#pragma once

//-----------------------------------------------------------------------------

namespace CommonTypes
{
  typedef unsigned char uchar;
  typedef unsigned short ushort;
  typedef unsigned int uint;

  struct vect3
  {
  public:
    double m_x;
    double m_y;
    double m_z;

    vect3( const double x,
           const double y,
           const double z )
      :
      m_x( x ),
      m_y( y ),
      m_z( z ) {}
  };
};

//-----------------------------------------------------------------------------