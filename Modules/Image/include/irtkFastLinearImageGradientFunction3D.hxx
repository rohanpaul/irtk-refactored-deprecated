/* The Image Registration Toolkit (IRTK)
 *
 * Copyright 2008-2015 Imperial College London
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#ifndef _IRTKFASTLINEARIMAGEGRADIENTFUNCTION3D_HXX
#define _IRTKFASTLINEARIMAGEGRADIENTFUNCTION3D_HXX

#include <irtkFastLinearImageGradientFunction3D.h>
#include <irtkFastLinearImageGradientFunction.hxx>


// -----------------------------------------------------------------------------
template <class TImage>
irtkGenericFastLinearImageGradientFunction3D<TImage>
::irtkGenericFastLinearImageGradientFunction3D()
{
  this->NumberOfDimensions(3);
}

// -----------------------------------------------------------------------------
template <class TImage>
inline typename irtkGenericFastLinearImageGradientFunction3D<TImage>::GradientType
irtkGenericFastLinearImageGradientFunction3D<TImage>
::Get(double x, double y, double z, double t) const
{
  return this->Get3D(x, y, z, t);
}

// -----------------------------------------------------------------------------
template <class TImage>
inline typename irtkGenericFastLinearImageGradientFunction3D<TImage>::GradientType
irtkGenericFastLinearImageGradientFunction3D<TImage>
::GetWithPadding(double x, double y, double z, double t) const
{
  return this->GetWithPadding3D(x, y, z, t);
}

// -----------------------------------------------------------------------------
template <class TImage> template <class TOtherImage>
inline typename irtkGenericFastLinearImageGradientFunction3D<TImage>::GradientType
irtkGenericFastLinearImageGradientFunction3D<TImage>
::Get(const TOtherImage *input, double x, double y, double z, double t) const
{
  return this->Get3D(input, x, y, z, t);
}

// -----------------------------------------------------------------------------
template <class TImage> template <class TOtherImage>
inline typename irtkGenericFastLinearImageGradientFunction3D<TImage>::GradientType
irtkGenericFastLinearImageGradientFunction3D<TImage>
::GetWithPadding(const TOtherImage *input, double x, double y, double z, double t) const
{
  return this->GetWithPadding3D(input, x, y, z, t);
}

// -----------------------------------------------------------------------------
template <class TImage>
inline typename irtkGenericFastLinearImageGradientFunction3D<TImage>::GradientType
irtkGenericFastLinearImageGradientFunction3D<TImage>
::GetInside(double x, double y, double z, double t) const
{
  return this->Get(this->Input(), x, y, z, t);
}

// -----------------------------------------------------------------------------
template <class TImage>
inline typename irtkGenericFastLinearImageGradientFunction3D<TImage>::GradientType
irtkGenericFastLinearImageGradientFunction3D<TImage>
::GetOutside(double x, double y, double z, double t) const
{
  if (this->Extrapolator()) {
    return Get(this->Extrapolator(), x, y, z, t);
  } else {
    return Get(x, y, z, t);
  }
}

// -----------------------------------------------------------------------------
template <class TImage>
inline typename irtkGenericFastLinearImageGradientFunction3D<TImage>::GradientType
irtkGenericFastLinearImageGradientFunction3D<TImage>
::GetWithPaddingInside(double x, double y, double z, double t) const
{
  return this->GetWithPadding(this->Input(), x, y, z, t);
}

// -----------------------------------------------------------------------------
template <class TImage>
inline typename irtkGenericFastLinearImageGradientFunction3D<TImage>::GradientType
irtkGenericFastLinearImageGradientFunction3D<TImage>
::GetWithPaddingOutside(double x, double y, double z, double t) const
{
  if (this->Extrapolator()) {
    return GetWithPadding(this->Extrapolator(), x, y, z, t);
  } else {
    return GetWithPadding(x, y, z, t);
  }
}


#endif
