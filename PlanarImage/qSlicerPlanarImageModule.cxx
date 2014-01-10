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

// Qt includes
#include <QtPlugin>

// ExtensionTemplate Logic includes
#include <vtkSlicerPlanarImageLogic.h>

// ExtensionTemplate includes
#include "qSlicerPlanarImageModule.h"
#include "qSlicerPlanarImageModuleWidget.h"
#include "PlanarImageInstantiator.h"

#include <vtkMRMLThreeDViewDisplayableManagerFactory.h>

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerPlanarImageModule, qSlicerPlanarImageModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerPlanarImageModulePrivate
{
public:
  qSlicerPlanarImageModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerPlanarImageModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerPlanarImageModulePrivate::qSlicerPlanarImageModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerPlanarImageModule methods

//-----------------------------------------------------------------------------
qSlicerPlanarImageModule::qSlicerPlanarImageModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerPlanarImageModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerPlanarImageModule::~qSlicerPlanarImageModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerPlanarImageModule::helpText()const
{
  return "This module is still under construction";
}

//-----------------------------------------------------------------------------
QString qSlicerPlanarImageModule::acknowledgementText()const
{
  return "";
}

//-----------------------------------------------------------------------------
QStringList qSlicerPlanarImageModule::contributors()const
{
  QStringList moduleContributors;
  moduleContributors << QString( "Franklin King (Queen's University), Csaba Pinter (Queen's University), Andras Lasso (Queen's University)" );
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerPlanarImageModule::icon()const
{
  return QIcon(":/Icons/PlanarImage.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerPlanarImageModule::categories() const
{
  return QStringList() << "PlanarImage";
}

//-----------------------------------------------------------------------------
QStringList qSlicerPlanarImageModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerPlanarImageModule::setup()
{
  this->Superclass::setup();

  vtkMRMLThreeDViewDisplayableManagerFactory::GetInstance()->RegisterDisplayableManager(
     "vtkMRMLPlanarImageDisplayableManager");
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation * qSlicerPlanarImageModule::createWidgetRepresentation()
{
  return new qSlicerPlanarImageModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerPlanarImageModule::createLogic()
{
  return vtkSlicerPlanarImageLogic::New();
}
