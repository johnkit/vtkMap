/*=========================================================================

  Program:   Visualization Toolkit

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

   This software is distributed WITHOUT ANY WARRANTY; without even
   the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
   PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkGeoMapFeatureSelector - Handler for feature-selection operations
// .SECTION Description
// This class offloads
//
// Note: this file is NOT exported, since it should only be used by
// the vtkMap class.

#ifndef __vtkGeoMapFeatureSelector_h
#define __vtkGeoMapFeatureSelector_h

#include <vtkObject.h>
#include "vtkmap_export.h"

class vtkGeoMapSelection;
class vtkIdList;
class vtkPlanes;
class vtkProp3D;
class vtkRenderer;

class VTKMAP_NO_EXPORT vtkGeoMapFeatureSelector : public vtkObject
{
 public:
  static vtkGeoMapFeatureSelector* New();
  virtual void PrintSelf(ostream &os, vtkIndent indent);
  vtkTypeMacro(vtkGeoMapFeatureSelector, vtkObject);

  void AddFeature(vtkFeature *feature, vtkProp3D *prop);
  void RemoveFeature(vtkFeature *feature, vtkProp3D *prop);
  void PickPoint(vtkRenderer *renderer, int displayCoords[2],
                 vtkGeoMapSelection *selection);

 protected:
  vtkGeoMapFeatureSelector();
  ~vtkGeoMapFeatureSelector();

  void PickPolyDataCells(vtkProp3D *prop, vtkPlanes *frustum,
                         vtkIdList *idList);

 private:
  // Not implemented
  vtkGeoMapFeatureSelector(const vtkGeoMapFeatureSelector&);
  vtkGeoMapFeatureSelector& operator=(const vtkGeoMapFeatureSelector&);

  class vtkGeoMapFeatureSelectorInternal;
  vtkGeoMapFeatureSelectorInternal *Internal;
};

#endif   // __vtkGeoMapFeatureSelector_h
