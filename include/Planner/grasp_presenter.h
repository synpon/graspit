//######################################################################
//
// GraspIt!
// Copyright (C) 2002-2009  Columbia University in the City of New York.
// All rights reserved.
//
// This software is protected under a Research and Educational Use
// Only license, (found in the file LICENSE.txt), that you should have
// received with this distribution.
//
// Authors: Steffen Knoop
//          Andrew T. Miller 
//
// $Id: grasp_presenter.h,v 1.3 2009/03/25 22:10:24 cmatei Exp $
//
//######################################################################

/***************************************************************************/
/*      FILE:     grasp_presenter.h                                        */
/*      AUTHOR:   Steffen Knoop                                            */
/*      DATE:     03-08-2002                                               */
/***************************************************************************/

#ifndef __GRASP_PRESENTER_H__
#define __GRASP_PRESENTER_H__

/*! \file
 \brief Defines the grasp_presenter class (part of grasp planner)
*/

//! This class is used to present the final list of planned grasps to the user 
/*!
  After the tester has evaluated all of the candidate grasps, the sorted list
  of good grasps is passed to this class.  Then each time the user pushes the
  show button, this class will handle presenting the next grasp in the list.
  Currently, this means that the hand in the main world/window is moved
  into the grasp configuration, and the grasp is evaluated again.  It might
  make more sense to have these presentations take place in another window, so
  as not to move elements in the main world.
*/
class grasp_presenter
{
 private:
  
  //! A pointer to the main viewer
  SoQtExaminerViewer *myViewer;

  //! A pointer to the hand used to present the grasp
  Hand               *my_hand;

  //! A pointer to the world containing the hand
  World              *my_world;

  //! A pointer the Inventor manager
  IVmgr              *ivmgr;

  //! A pointer to the render area for this presentation (not used yet)
  SoQtRenderArea     *graspViewer;

  //! A list of the grasps being presented
  std::list<plannedGrasp*> graspList;
    
  //! An iterator for the grasp list
  std::list<plannedGrasp*>::iterator it_gr;


  int processing;

  void updateGlobals();
  void breakContacts();
  void putHand(finalGraspPosition,bool);
  
  
 public:
  grasp_presenter();
  ~grasp_presenter();
  
  void takeList(std::list<plannedGrasp*>);
  void showGrasp(int, bool);
  void chooseGrasp();
};


#endif





