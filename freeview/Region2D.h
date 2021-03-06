/**
 * @file  Region2D.h
 * @brief Region2D data object.
 *
 */
/*
 * Original Author: Ruopeng Wang
 * CVS Revision Info:
 *    $Author: nicks $
 *    $Date: 2011/03/14 23:44:48 $
 *    $Revision: 1.9 $
 *
 * Copyright © 2011 The General Hospital Corporation (Boston, MA) "MGH"
 *
 * Terms and conditions for use, reproduction, distribution and contribution
 * are found in the 'FreeSurfer Software License Agreement' contained
 * in the file 'LICENSE' found in the FreeSurfer distribution, and here:
 *
 * https://surfer.nmr.mgh.harvard.edu/fswiki/FreeSurferSoftwareLicense
 *
 * Reporting: freesurfer@nmr.mgh.harvard.edu
 *
 *
 */

#ifndef Region2D_h
#define Region2D_h

#include <QObject>
#include <QStringList>

class RenderView2D;
class vtkRenderer;

class Region2D : public QObject
{
  Q_OBJECT
public:
  Region2D( RenderView2D* view );
  virtual ~Region2D();

  virtual void Offset( int nX, int nY ) = 0;

  virtual void UpdatePoint( int nIndex, int nX, int nY ) = 0;

  virtual bool Contains( int nX, int nY, int* nPointIndex = NULL ) = 0;

  virtual void Highlight( bool bHighlight = true ) {}

  virtual void AppendProp( vtkRenderer* renderer ) = 0;

  virtual void Show( bool bshow );

  virtual void Update() {}

  virtual void UpdateStats();

  virtual void UpdateSlicePosition( int nPlane, double pos );

  virtual void GetWorldPoint( int nIndex, double* pt ) = 0;

  QString GetShortStats()
  {
    return m_strShortStats;
  }

  QStringList GetLongStats()
  {
    return m_strsLongStats;
  }

signals:
  void StatsUpdated();

protected:
  RenderView2D* m_view;
  QString       m_strShortStats;
  QStringList   m_strsLongStats;
};

#endif


