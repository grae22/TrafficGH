#pragma once
#include <string>

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
           const double z ) :
      m_x( x ),
      m_y( y ),
      m_z( z ) {}

    std::string ToString()
    {
      return std::string() +
             "( " + std::to_string( m_x ) + ", "
             "( " + std::to_string( m_y ) + ", "
             "( " + std::to_string( m_z ) + " )";
    }
  };
};

//-----------------------------------------------------------------------------