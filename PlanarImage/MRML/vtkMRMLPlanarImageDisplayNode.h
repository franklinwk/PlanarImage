/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkMRMLScalarVolumeDisplayNode.h,v $
  Date:      $Date: 2006/03/19 17:12:29 $
  Version:   $Revision: 1.3 $

=========================================================================auto=*/

#ifndef __vtkMRMLPlanarImageDisplayNode_h
#define __vtkMRMLPlanarImageDisplayNode_h

// MRML includes
#include "vtkMRMLScalarVolumeDisplayNode.h"

// VTK includes
class vtkImageData;
class vtkImageLogic;
class vtkTransform;

// STD includes
#include <vector>

#include "vtkSlicerPlanarImageModuleMRMLExport.h"

/// \brief MRML node for representing planar image display attributes.
///
/// vtkMRMLPlanarImageDisplayNode nodes describe how volume is displayed.
class VTK_SLICER_PLANARIMAGE_MODULE_MRML_EXPORT vtkMRMLPlanarImageDisplayNode : public vtkMRMLVolumeDisplayNode
{
  public:
  static vtkMRMLPlanarImageDisplayNode *New();
  vtkTypeMacro(vtkMRMLPlanarImageDisplayNode,vtkMRMLVolumeDisplayNode);
  void PrintSelf(ostream& os, vtkIndent indent);

  virtual vtkMRMLNode* CreateNodeInstance();

  /// 
  /// Get node XML tag name (like Volume, Model)
  virtual const char* GetNodeTagName() {return "PlanarImageDisplay";};


  //--------------------------------------------------------------------------
  /// Display Information
  //--------------------------------------------------------------------------
  /// Set the pipeline input
  virtual void SetInputImageData(vtkImageData *imageData);

  /// Gets the pipeline input
  virtual vtkImageData* GetInputImageData();

  /// Gets the pipeline output
  virtual vtkImageData* GetOutputImageData();

  virtual void SetInputToImageDataPipeline(vtkImageData* input);

  void SetIJKToRASTransform(vtkTransform *IJKToRAS);
  vtkTransform* GetIJKToRASTransform();
  
  vtkImageData *PlanarImage;
  vtkTransform *IJKToRAS;
  
protected:
  vtkMRMLPlanarImageDisplayNode();
  virtual ~vtkMRMLPlanarImageDisplayNode();
  vtkMRMLPlanarImageDisplayNode(const vtkMRMLPlanarImageDisplayNode&);
  void operator=(const vtkMRMLPlanarImageDisplayNode&);
};

#endif
