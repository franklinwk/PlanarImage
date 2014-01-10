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

#ifndef __qSlicerPlanarImageModuleWidget_h
#define __qSlicerPlanarImageModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerPlanarImageModuleExport.h"


class qSlicerPlanarImageModuleWidgetPrivate;
class vtkMRMLNode;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_PLANARIMAGE_EXPORT qSlicerPlanarImageModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT

public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerPlanarImageModuleWidget(QWidget *parent=0);
  virtual ~qSlicerPlanarImageModuleWidget();
  
  virtual void enter();

public slots:

  
protected:
  QScopedPointer<qSlicerPlanarImageModuleWidgetPrivate> d_ptr;
  
protected:

  
  virtual void setup();


private:
  Q_DECLARE_PRIVATE(qSlicerPlanarImageModuleWidget);
  Q_DISABLE_COPY(qSlicerPlanarImageModuleWidget);
};

#endif
