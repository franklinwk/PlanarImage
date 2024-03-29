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

// .NAME vtkSlicerPlanarImageLogic
// .SECTION Description
#ifndef __vtkSlicerPlanarImageLogic_h
#define __vtkSlicerPlanarImageLogic_h

// Slicer includes
#include "vtkSlicerModuleLogic.h"

// MRML includes
#include <qSlicerApplication.h>

// STD includes
#include <cstdlib>

#include "vtkSlicerPlanarImageModuleLogicExport.h"

/// \ingroup Slicer_QtModules_ExtensionTemplate
class VTK_SLICER_PLANARIMAGE_MODULE_LOGIC_EXPORT vtkSlicerPlanarImageLogic :
  public vtkSlicerModuleLogic
{
public:

  static vtkSlicerPlanarImageLogic *New();
  vtkTypeMacro(vtkSlicerPlanarImageLogic, vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);
  

protected:
  vtkSlicerPlanarImageLogic();
  virtual ~vtkSlicerPlanarImageLogic();

  /// Register MRML Node classes to Scene. Gets called automatically when the MRMLScene is attached to this logic class.
  virtual void RegisterNodes();

  virtual void SetMRMLSceneInternal(vtkMRMLScene* newScene);
  /// Register MRML Node classes to Scene. Gets called automatically when the MRMLScene is attached to this logic class.
  
  
private:

  vtkSlicerPlanarImageLogic(const vtkSlicerPlanarImageLogic&); // Not implemented
  void operator=(const vtkSlicerPlanarImageLogic&);               // Not implemented
};

#endif
