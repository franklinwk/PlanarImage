/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
  
==============================================================================*/  
  
// PlanarImage Logic includes
#include "vtkSlicerPlanarImageLogic.h"

// MRML includes
#include "vtkMRMLPlanarImageDisplayNode.h"
#include "vtkMRMLModelNode.h"
#include "vtkMRMLScalarVolumeDisplayNode.h"
#include "vtkMRMLScene.h"

#include <qSlicerApplication.h>
#include "qSlicerLayoutManager.h"

// VTK includes
#include <vtkNew.h>
#include <vtkSmartPointer.h>
#include <vtkObjectFactory.h>

// STD includes
#include <cassert>

//----------------------------------------------------------------------------
vtkStandardNewMacro(vtkSlicerPlanarImageLogic);

//----------------------------------------------------------------------------
vtkSlicerPlanarImageLogic::vtkSlicerPlanarImageLogic()
{

}

//----------------------------------------------------------------------------
vtkSlicerPlanarImageLogic::~vtkSlicerPlanarImageLogic()
{

}

//----------------------------------------------------------------------------
void vtkSlicerPlanarImageLogic::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf( os, indent );
}

//---------------------------------------------------------------------------
void vtkSlicerPlanarImageLogic::SetMRMLSceneInternal(vtkMRMLScene * newScene)
{
  vtkNew<vtkIntArray> events;
  events->InsertNextValue(vtkMRMLScene::NodeAddedEvent);
  events->InsertNextValue(vtkMRMLScene::NodeRemovedEvent);
  events->InsertNextValue(vtkMRMLScene::EndImportEvent);
  events->InsertNextValue(vtkMRMLScene::EndBatchProcessEvent);
  events->InsertNextValue(vtkMRMLScene::StartCloseEvent);
  this->SetAndObserveMRMLSceneEventsInternal(newScene, events.GetPointer());
}

//-----------------------------------------------------------------------------
void vtkSlicerPlanarImageLogic::RegisterNodes()
{
  assert(this->GetMRMLScene() != 0);

  // Display node
  this->GetMRMLScene()->RegisterNodeClass(vtkSmartPointer<vtkMRMLPlanarImageDisplayNode>::New());

  //Just for testing:
  //this->GetMRMLScene()->AddNode(vtkSmartPointer<vtkMRMLPlanarImageDisplayNode>::New());
}