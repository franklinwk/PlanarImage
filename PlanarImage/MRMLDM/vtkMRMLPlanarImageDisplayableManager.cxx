/*=========================================================================

  Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $HeadURL: http://svn.slicer.org/Slicer4/trunk/Base/GUI/vtkMRMLPlanarImageDisplayableManager.cxx $
  Date:      $Date: 2010-05-27 14:32:23 -0400 (Thu, 27 May 2010) $
  Version:   $Revision: 13525 $

==========================================================================*/

// MRMLLogic includes

// MRMLDisplayableManager includes
#include "vtkMRMLPlanarImageDisplayableManager.h"
#include "vtkThreeDViewInteractorStyle.h"
#include "vtkMRMLApplicationLogic.h"

// MRML includes
#include <vtkEventBroker.h>
#include <vtkMRMLDisplayableNode.h>
#include <vtkMRMLDisplayNode.h>
#include <vtkMRMLPlanarImageDisplayNode.h>
#include <vtkMRMLLinearTransformNode.h>
#include <vtkMRMLModelDisplayNode.h>
#include <vtkMRMLModelNode.h>
#include <vtkMRMLProceduralColorNode.h>
#include <vtkMRMLScene.h>
#include "vtkMRMLViewNode.h"
#include "vtkMRMLInteractionNode.h"

// VTK includes
#include <vtkAssignAttribute.h>
#include <vtkCellArray.h>
#include <vtkColorTransferFunction.h>
#include <vtkDataSetAttributes.h>
#include <vtkImageActor.h>
#include <vtkImageData.h>
#include <vtkImplicitBoolean.h>
#include <vtkLookupTable.h>
#include <vtkMatrix4x4.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>
#include <vtkPlane.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkPlaneSource.h>
#include <vtkTexture.h>
#include <vtkTransform.h>

// for picking
#include <vtkCellPicker.h>
#include <vtkPointPicker.h>
#include <vtkPropPicker.h>
#include <vtkRendererCollection.h>
#include <vtkWorldPointPicker.h>

// STD includes
#include <cassert>

//---------------------------------------------------------------------------
vtkStandardNewMacro (vtkMRMLPlanarImageDisplayableManager );
vtkCxxRevisionMacro ( vtkMRMLPlanarImageDisplayableManager, "$Revision: 13525 $");

//---------------------------------------------------------------------------
class vtkMRMLPlanarImageDisplayableManager::vtkInternal
{
public:
  vtkInternal();
  ~vtkInternal();

  std::map<std::string, vtkProp3D *>               DisplayedActors;
  std::map<std::string, vtkMRMLDisplayNode *>      DisplayedNodes;
  std::map<std::string, int>                       DisplayedVisibility;
  std::map<std::string, vtkMRMLDisplayableNode *>  DisplayableNodes;
};

//---------------------------------------------------------------------------
// vtkInternal methods

//---------------------------------------------------------------------------
vtkMRMLPlanarImageDisplayableManager::vtkInternal::vtkInternal()
{

}

//---------------------------------------------------------------------------
vtkMRMLPlanarImageDisplayableManager::vtkInternal::~vtkInternal()
{

}

//---------------------------------------------------------------------------
// vtkMRMLPlanarImageDisplayableManager methods

//---------------------------------------------------------------------------
vtkMRMLPlanarImageDisplayableManager::vtkMRMLPlanarImageDisplayableManager()
{
  this->Internal = new vtkInternal();
}

//---------------------------------------------------------------------------
vtkMRMLPlanarImageDisplayableManager::~vtkMRMLPlanarImageDisplayableManager()
{
  // release the DisplayedModelActors
  this->Internal->DisplayedActors.clear();

  delete this->Internal;
}

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::PrintSelf ( ostream& os, vtkIndent indent )
{
  this->vtkObject::PrintSelf ( os, indent );

  os << indent << "vtkMRMLPlanarImageDisplayableManager: " << this->GetClassName() << "\n";
}

/*
//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::AdditionalInitializeStep()
{
  vtkRenderWindowInteractor * interactor = this->GetInteractor();
  if (interactor)
    {
    vtkThreeDViewInteractorStyle * interactorStyle =
        vtkThreeDViewInteractorStyle::SafeDownCast(interactor->GetInteractorStyle());
    if (interactorStyle)
      {
      interactorStyle->SetModelDisplayableManager(this);
      }
    }
}
*/

/*
//---------------------------------------------------------------------------
int vtkMRMLPlanarImageDisplayableManager::ActiveInteractionModes() 
{
  return 0;
}
*/

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::ProcessMRMLNodesEvents(vtkObject *caller,
                                                           unsigned long event,
                                                           void *callData)
{
/*
  if (this->GetMRMLScene() == 0)
    {
    return;
    }
  if ( this->GetInteractor() &&
     this->GetInteractor()->GetRenderWindow() &&
     this->GetInteractor()->GetRenderWindow()->CheckInRenderStatus())
    {
    vtkDebugMacro("skipping ProcessMRMLNodesEvents during render");
    return;
    }

  bool isUpdating = this->GetMRMLScene()->IsBatchProcessing();
  if (vtkMRMLDisplayableNode::SafeDownCast(caller))
    {
    // There is no need to request a render (which can be expensive if the
    // volume rendering is on) if nothing visible has changed.
    bool requestRender = true;
    vtkMRMLDisplayableNode* displayableNode =
      vtkMRMLDisplayableNode::SafeDownCast(caller);
    switch (event)
      {
       case vtkMRMLDisplayableNode::DisplayModifiedEvent:
          requestRender = false;
          break;
          }
      case vtkMRMLModelNode::PolyDataModifiedEvent:
        requestRender = this->OnMRMLDisplayableModelNodeModifiedEvent(displayableNode);
        break;
      default:
        this->SetUpdateFromMRMLRequested(1);
        break;
      }
    if (!isUpdating && requestRender)
      {
      this->RequestRender();
      }
    }

  else
    {
    this->Superclass::ProcessMRMLNodesEvents(caller, event, callData);
    }
    */
}

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::UnobserveMRMLScene()
{
/*
  this->RemoveModelProps();
  this->RemoveModelObservers(1);
  */
}

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::OnMRMLSceneStartClose()
{
  //this->RemoveModelObservers(0);
}

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::OnMRMLSceneEndClose()
{
  // Clean
  //this->RemoveModelProps();
  //this->RemoveModelObservers(1);

  this->SetUpdateFromMRMLRequested(1);
  this->RequestRender();
}

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::UpdateFromMRMLScene()
{
  // UpdateFromMRML will be executed only if there has been some actions
  // during the import that requested it (don't call
  // SetUpdateFromMRMLRequested(1) here, it should be done somewhere else
  // maybe in OnMRMLSceneNodeAddedEvent, OnMRMLSceneNodeRemovedEvent or
  // OnMRMLDisplayableModelNodeModifiedEvent).
  this->RequestRender();
}

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::OnMRMLSceneNodeAdded(vtkMRMLNode* node)
{
  this->SetUpdateFromMRMLRequested(1);

  // Escape if the scene a scene is being closed, imported or connected
  if (this->GetMRMLScene()->IsBatchProcessing())
    {
    return;
    }

  this->RequestRender();
}

//---------------------------------------------------------------------------
bool vtkMRMLPlanarImageDisplayableManager::OnMRMLDisplayableModelNodeModifiedEvent(
    vtkMRMLDisplayableNode * modelNode)
{
  /*
  assert(modelNode);

  // If the node is already cached with an actor process only this one
  // If it was not visible and is still not visible do nothing
  int ndnodes = modelNode->GetNumberOfDisplayNodes();
  bool updateModel = false;
  bool updateMRML = false;
  for (int i=0; i<ndnodes; i++)
    {
    vtkMRMLDisplayNode *dnode = modelNode->GetNthDisplayNode(i);
    assert(dnode);
    bool visible = (dnode->GetVisibility() == 1);
    bool hasActor =
      this->Internal->DisplayedActors.find(dnode->GetID()) != this->Internal->DisplayedActors.end();
    // If the displayNode is visible and doesn't have actors yet, then request
    // an updated
    if (visible && !hasActor)
      {
      updateMRML = true;
      break;
      }
    // If the displayNode visibility has changed or displayNode is visible, then
    // update the model.
    if (!(!visible && this->GetDisplayedModelsVisibility(dnode) == 0))
      {
      updateModel = true;
      break;
      }
    }
  
  if (updateModel)
    {
    this->UpdateModifiedModel(modelNode);
    this->SetUpdateFromMRMLRequested(1);
    }
  if (updateMRML)
    {
    this->SetUpdateFromMRMLRequested(1);
    }
  return updateModel || updateMRML;
  */
  return false; // temp
  
}

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::UpdateFromMRML()
{
  if ( this->GetInteractor() &&
       this->GetInteractor()->GetRenderWindow() &&
       this->GetInteractor()->GetRenderWindow()->CheckInRenderStatus())
    {
    vtkDebugMacro("skipping update during render");
    return;
    }

  //this->RemoveModelProps();

  this->UpdateModelsFromMRML();

  this->SetUpdateFromMRMLRequested(0);
}

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::UpdateModelsFromMRML()
{
  vtkMRMLScene *scene = this->GetMRMLScene();
  vtkMRMLNode *node = 0;

  std::vector<vtkMRMLNode *> dnodes;
  int nnodes = scene ? scene->GetNodesByClass("vtkMRMLPlanarImageDisplayNode", dnodes) : 0;
  for (int n=0; n<nnodes; n++)
    {
    node = dnodes[n];
    vtkMRMLPlanarImageDisplayNode *model = vtkMRMLPlanarImageDisplayNode::SafeDownCast(node);
    // render slices last so that transparent objects are rendered in front of them

    vtkMRMLDisplayNode *dnode = model;
    } // this is silly, but I'm keeping for now until everything works

  // render the rest of the models
  for (int n=0; n<nnodes; n++)
    {
    vtkMRMLPlanarImageDisplayNode *model = vtkMRMLPlanarImageDisplayNode::SafeDownCast(dnodes[n]);

    if (model)
      {
      this->UpdateModifiedModel(model);
      }
    } // end while
}

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::UpdateModifiedModel(vtkMRMLPlanarImageDisplayNode *model)
{
  this->UpdateModel(model);
  //this->SetModelDisplayProperty(model);
}

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::UpdateModel(vtkMRMLPlanarImageDisplayNode *model)
{
  this->UpdateModelPolyData(model);

  vtkEventBroker *broker = vtkEventBroker::GetInstance();
  vtkEventBroker::ObservationVector observations;

  // observe display node
  if (!broker->GetObservationExist(model, vtkMRMLDisplayableNode::DisplayModifiedEvent,
                                         this, this->GetMRMLNodesCallbackCommand()))
    {
    broker->AddObservation(model, vtkMRMLDisplayableNode::DisplayModifiedEvent,
                           this, this->GetMRMLNodesCallbackCommand());
    }
}

//---------------------------------------------------------------------------
void vtkMRMLPlanarImageDisplayableManager::UpdateModelPolyData(vtkMRMLPlanarImageDisplayNode *displayableNode)
{
    vtkMRMLPlanarImageDisplayNode *displayNode = displayableNode;

    vtkProp3D* prop = 0;

    //int visibility = displayNode->GetVisibility();

    vtkPolyData *polyData = NULL;
    vtkImageData *image = displayableNode->GetOutputImageData();
    int dims[3] = {0, 0, 0};
    image->GetDimensions(dims);

    vtkTransform *IJKToRAS = displayableNode->GetIJKToRASTransform();

    double originImage[4] = { 0.0,     0.0,     0.0 };
    double point1Image[4] = { dims[0], 0.0,     0.0 };
    double point2Image[4] = { 0.0,     dims[1], 0.0 };

    double originRAS[4] = { 0.0, 0.0, 0.0 };
    double point1RAS[4] = { 0.0, 0.0, 0.0 };
    double point2RAS[4] = { 0.0, 0.0, 0.0 };

    IJKToRAS->TransformPoint(originImage, originRAS);
    IJKToRAS->TransformPoint(point1Image, point1RAS);
    IJKToRAS->TransformPoint(point2Image, point2RAS);

    vtkSmartPointer<vtkPlaneSource> plane = vtkSmartPointer<vtkPlaneSource>::New();
    plane->SetOrigin(originRAS);
    plane->SetPoint1(point1RAS);
    plane->SetPoint2(point2RAS);

    polyData = plane->GetOutput();
    //polyData = modelDisplayNode->GetOutputPolyData(); // Created quad to display

    vtkSmartPointer<vtkTexture> texture = vtkSmartPointer<vtkTexture>::New();
    texture->SetInput(image);

    std::map<std::string, vtkProp3D *>::iterator ait;
    ait = this->Internal->DisplayedActors.find(displayNode->GetID());
    if (ait == this->Internal->DisplayedActors.end() )
      {
      if (!prop)
        {
        prop = vtkActor::New();
        }
      }
    else
      {
      prop = (*ait).second;
      }

    vtkActor * actor = vtkActor::SafeDownCast(prop);
    if(actor)
      {
      vtkPolyDataMapper *mapper = vtkPolyDataMapper::New();

      mapper->SetInput(polyData);
      

      actor->SetMapper(mapper);
      actor->SetTexture(texture);
      mapper->Delete();
      }

    if (ait == this->Internal->DisplayedActors.end())
      {
      this->GetRenderer()->AddViewProp(prop);
      this->Internal->DisplayedActors[displayableNode->GetID()] = prop;
      this->Internal->DisplayedNodes[std::string(displayableNode->GetID())] = displayableNode;

      prop->Delete();
      }
    /*
    else if (!hasPolyData)
      {
      prop->Delete();
      }
      */
}

//---------------------------------------------------------------------------
// Description:
// return the current actor corresponding to a give MRML ID
vtkProp3D * vtkMRMLPlanarImageDisplayableManager::GetActorByID(const char *id)
{
  if ( !id )
    {
    return (0);
    }

  std::map<std::string, vtkProp3D *>::iterator iter;
  // search for matching string (can't use find, since it would look for
  // matching pointer not matching content)
  for(iter=this->Internal->DisplayedActors.begin(); iter != this->Internal->DisplayedActors.end(); iter++)
    {
    if ( iter->first.c_str() && !strcmp( iter->first.c_str(), id ) )
      {
      return (iter->second);
      }
    }
  return (0);
}

//---------------------------------------------------------------------------
// Description:
// return the ID for the given actor
const char * vtkMRMLPlanarImageDisplayableManager::GetIDByActor(vtkProp3D *actor)
{
  if ( !actor )
    {
    return (0);
    }

  std::map<std::string, vtkProp3D *>::iterator iter;
  for(iter=this->Internal->DisplayedActors.begin();
      iter != this->Internal->DisplayedActors.end();
      iter++)
    {
    if ( iter->second && ( iter->second == actor ) )
      {
      return (iter->first.c_str());
      }
    }
  return (0);
}
