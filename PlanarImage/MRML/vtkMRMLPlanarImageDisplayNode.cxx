/*=auto=========================================================================

Portions (c) Copyright 2005 Brigham and Women\"s Hospital (BWH) All Rights Reserved.

See COPYRIGHT.txt
or http://www.slicer.org/copyright/copyright.txt for details.

Program:   3D Slicer
Module:    $RCSfile: vtkMRMLVolumeDisplayNode.cxx,v $
Date:      $Date: 2006/03/17 15:10:10 $
Version:   $Revision: 1.2 $

=========================================================================auto=*/

// MRML includes
#include "vtkEventBroker.h"
#include "vtkMRMLPlanarImageDisplayNode.h"
#include "vtkMRMLVolumeNode.h"

// VTK includes
#include <vtkNew.h>
#include <vtkCallbackCommand.h>
#include <vtkImageData.h>
#include <vtkObjectFactory.h>
#include <vtkTransform.h>

// STD includes
#include <cassert>

//----------------------------------------------------------------------------
vtkMRMLNodeNewMacro(vtkMRMLPlanarImageDisplayNode);

//----------------------------------------------------------------------------
vtkMRMLPlanarImageDisplayNode::vtkMRMLPlanarImageDisplayNode()
{ 
  vtkEventBroker::GetInstance()->AddObservation(
    this, vtkCommand::ModifiedEvent, this, this->MRMLCallbackCommand  , 10000.);
  this->PlanarImage = NULL;
  this->IJKToRAS = NULL;
}

//----------------------------------------------------------------------------
vtkMRMLPlanarImageDisplayNode::~vtkMRMLPlanarImageDisplayNode()
{

}

//----------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayNode::SetInputImageData(vtkImageData *imageData)
{
  if (this->GetInputImageData() != NULL)
    {
    vtkEventBroker::GetInstance()->RemoveObservations(
      this->GetInputImageData(), vtkCommand::ModifiedEvent, this, this->MRMLCallbackCommand );
    }

  this->Superclass::SetInputImageData(imageData);

  if (this->GetInputImageData() != NULL)
    {
    vtkEventBroker::GetInstance()->AddObservation(
      this->GetInputImageData(), vtkCommand::ModifiedEvent, this, this->MRMLCallbackCommand );
    }
}

//----------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayNode::SetInputToImageDataPipeline(vtkImageData *imageData)
{
  // Check if the volume to display is really a planar image
  int dims[3] = {0, 0, 0};
  imageData->GetDimensions(dims);
  if (dims[2] > 1)
  {
    vtkErrorMacro("SetInputToImageDataPipeline: Image to display is not a single slice!");
    return;
  }

  this->PlanarImage = imageData;
}

//----------------------------------------------------------------------------
vtkImageData* vtkMRMLPlanarImageDisplayNode::GetInputImageData()
{
  if (this->PlanarImage)
    {
    return vtkImageData::SafeDownCast(this->PlanarImage);
    }
  return NULL;
}

//----------------------------------------------------------------------------
// Is this a good way to do this? Perhaps let display manager reference the volume directly?
void vtkMRMLPlanarImageDisplayNode::SetIJKToRASTransform(vtkTransform *transform)
{
  this->IJKToRAS = transform;
}

//----------------------------------------------------------------------------
vtkTransform* vtkMRMLPlanarImageDisplayNode::GetIJKToRASTransform()
{
  if (this->IJKToRAS)
    {
    return vtkTransform::SafeDownCast(this->IJKToRAS);
    }
  return NULL;
}

//----------------------------------------------------------------------------
vtkImageData* vtkMRMLPlanarImageDisplayNode::GetOutputImageData()
{
  return this->PlanarImage;
}

//----------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayNode::PrintSelf(ostream& os, vtkIndent indent)
{
  Superclass::PrintSelf(os,indent);
}

