/*=========================================================================

  Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   SlicerViewerWidget
  Module:    $HeadURL: http://svn.slicer.org/Slicer4/trunk/Base/GUI/vtkMRMLPlanarImageDisplayableManager.h $
  Date:      $Date: 2010-05-12 08:34:19 -0400 (Wed, 12 May 2010) $
  Version:   $Revision: 13332 $

==========================================================================*/

#ifndef __vtkMRMLPlanarImageDisplayableManager_h
#define __vtkMRMLPlanarImageDisplayableManager_h

// MRMLDisplayableManager includes
#include "vtkMRMLAbstractThreeDViewDisplayableManager.h"
#include "vtkMRMLDisplayableManagerWin32Header.h"

// MRMLLogic includes

// MRML includes
class vtkMRMLDisplayNode;
class vtkMRMLPlanarImageDisplayNode;
class vtkMRMLDisplayableNode;

// VTK includes
#include "vtkRenderWindow.h"
class vtkActor;
class vtkActorText;
class vtkBoundingBox;
class vtkCellArray;
class vtkCellPicker;
class vtkClipPolyData;
class vtkFollower;
class vtkImplicitBoolean;
class vtkMatrix4x4;
class vtkPMatrix4x4;
class vtkPlane;
class vtkPlane;
class vtkPointPicker;
class vtkPolyData;
class vtkProp3D;

#include "vtkSlicerPlanarImageModuleMRMLDisplayableManagerExport.h"

/// \brief Manage display nodes with polydata in 3D views.
///
/// Any display node in the scene that contains a valid output polydata is
/// represented into the view renderer using configured synchronized vtkActors
/// and vtkMappers.
/// Note that the display nodes must be of type vtkMRMLModelDisplayNode
/// (to have an output polydata) but the displayable nodes don't necessarily
/// have to be of type vtkMRMLModelNode.
class VTK_SLICER_PLANARIMAGE_MODULE_MRMLDISPLAYABLEMANAGER_EXPORT vtkMRMLPlanarImageDisplayableManager
  : public vtkMRMLAbstractThreeDViewDisplayableManager
{
public:
  static vtkMRMLPlanarImageDisplayableManager* New();
  vtkTypeRevisionMacro(vtkMRMLPlanarImageDisplayableManager,vtkMRMLAbstractThreeDViewDisplayableManager);
  void PrintSelf(ostream& os, vtkIndent indent);

  /// 
  /// Return the current model actor corresponding to a give MRML ID
  vtkProp3D *GetActorByID(const char *id);

  /// 
  /// Return the current node ID corresponding to a given vtkProp3D
  const char *GetIDByActor(vtkProp3D *actor);

protected:

  vtkMRMLPlanarImageDisplayableManager();
  virtual ~vtkMRMLPlanarImageDisplayableManager();

  //virtual void AdditionalInitializeStep();

  virtual void UnobserveMRMLScene();

  virtual void OnMRMLSceneStartClose();
  virtual void OnMRMLSceneEndClose();
  virtual void UpdateFromMRMLScene();
  virtual void OnMRMLSceneNodeAdded(vtkMRMLNode* node);
  //virtual void OnMRMLSceneNodeRemoved(vtkMRMLNode* node);

  //virtual void OnInteractorStyleEvent(int eventId);
  virtual void ProcessMRMLNodesEvents(vtkObject *caller, unsigned long event, void *callData);

  /// Returns true if something visible in modelNode has changed and would
  /// require a refresh.
  bool OnMRMLDisplayableModelNodeModifiedEvent(vtkMRMLDisplayableNode * modelNode);

  /// Updates Actors based on models in the scene
  void UpdateFromMRML();

  //virtual void RemoveMRMLObservers();

  //friend class vtkThreeDViewInteractorStyle; // Access to RequestRender();

  //void RemoveModelProps();
  //void RemoveModelObservers(int clearCache);
  //void RemoveDisplayable(vtkMRMLDisplayableNode* model);
  //void RemoveDisplayableNodeObservers(vtkMRMLDisplayableNode *model);

  void UpdateModelsFromMRML();
  void UpdateModel(vtkMRMLPlanarImageDisplayNode *model);
  void UpdateModelPolyData(vtkMRMLPlanarImageDisplayNode *model);
  void UpdateModifiedModel(vtkMRMLPlanarImageDisplayNode *model);

  //int GetDisplayedModelsVisibility(vtkMRMLDisplayNode *model);

  //const char* GetActiveScalarName(vtkMRMLDisplayNode* displayNode, vtkMRMLModelNode* model = 0);
  //bool IsCellScalarsActive(vtkMRMLDisplayNode* displayNode, vtkMRMLModelNode* model = 0);


  //void RemoveDispalyedID(std::string &id);
  
private:
  
  vtkMRMLPlanarImageDisplayableManager(const vtkMRMLPlanarImageDisplayableManager&); // Not implemented
  void operator=(const vtkMRMLPlanarImageDisplayableManager&);                 // Not Implemented

  class vtkInternal;
  vtkInternal* Internal;

};

#endif
