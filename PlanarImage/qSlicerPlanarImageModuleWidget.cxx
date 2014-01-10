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

#include "vtkSlicerPlanarImageLogic.h"

#include <cmath>

// Qt includes
#include <QDebug>
#include <QtCore>
#include <QDesktopWidget>
#include <QRect>
#include <QTimer>

#include <vtkMRMLScene.h>

// SlicerQt includes
#include "qSlicerPlanarImageModuleWidget.h"
#include "ui_qSlicerPlanarImageModule.h"
#include <qSlicerApplication.h>
#include <qSlicerIOManager.h>

#include <vtkMRMLNode.h>

#include <vtkNew.h>
#include <vtkRenderer.h>

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerPlanarImageModuleWidgetPrivate: public Ui_qSlicerPlanarImageModule
{
  Q_DECLARE_PUBLIC( qSlicerPlanarImageModuleWidget );
protected:
  qSlicerPlanarImageModuleWidget* const q_ptr;
public:
  qSlicerPlanarImageModuleWidgetPrivate( qSlicerPlanarImageModuleWidget& object );
  vtkSlicerPlanarImageLogic* logic() const;
};

//-----------------------------------------------------------------------------
// qSlicerPlanarImageModuleWidgetPrivate methods

//-----------------------------------------------------------------------------
qSlicerPlanarImageModuleWidgetPrivate::qSlicerPlanarImageModuleWidgetPrivate( qSlicerPlanarImageModuleWidget& object )
 : q_ptr( &object )
{
}


vtkSlicerPlanarImageLogic* qSlicerPlanarImageModuleWidgetPrivate::logic() const
{
  Q_Q( const qSlicerPlanarImageModuleWidget );
  return vtkSlicerPlanarImageLogic::SafeDownCast( q->logic() );
}


//-----------------------------------------------------------------------------
// qSlicerPlanarImageModuleWidget methods
//-----------------------------------------------------------------------------
qSlicerPlanarImageModuleWidget::qSlicerPlanarImageModuleWidget(QWidget* _parent) : Superclass( _parent ) , d_ptr( new qSlicerPlanarImageModuleWidgetPrivate(*this))
{

}

//-----------------------------------------------------------------------------
qSlicerPlanarImageModuleWidget::~qSlicerPlanarImageModuleWidget()
{

}

//-----------------------------------------------------------------------------
void qSlicerPlanarImageModuleWidget::enter()
{
  this->Superclass::enter();
}

//-----------------------------------------------------------------------------
void qSlicerPlanarImageModuleWidget::setup()
{
  Q_D(qSlicerPlanarImageModuleWidget);
  d->setupUi(this);
  
  this->Superclass::setup();
  
  //connect(updateTimer, SIGNAL( timeout() ), this, SLOT( onFrameUpdate() ));

}

