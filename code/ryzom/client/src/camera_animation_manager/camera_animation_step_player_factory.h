// Ryzom - MMORPG Framework <http://dev.ryzom.com/projects/ryzom/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef RY_CAMERAANIMATIONSTEPPLAYERFACTORY_H
#define RY_CAMERAANIMATIONSTEPPLAYERFACTORY_H

#include <string>
#include <vector>
#include "nel\misc\bit_mem_stream.h"

/************************************************************************/
/* Interface for camera animation steps.
 * It has to be able to parse the step from an impulse and to play it
 */
/************************************************************************/
class ICameraAnimationStepPlayer
{
public:
	/// This function is called when it's time to init the step from an impulse
	virtual bool initStep(NLMISC::CBitMemStream& impulse) = 0;

	/// Function that plays the step
	virtual void playStep() = 0;

protected:
};

/************************************************************************/
/* Factory class that can instanciate the correct camera animation step player.
 * 
 * \author Fabien Henon
 * \date 2012
 */
/************************************************************************/
class ICameraAnimationStepPlayerFactory
{
public:
	/// Function that will instanciate the correct camera animation step player in function of the step name
	static ICameraAnimationStepPlayer* initStep(const std::string& name, NLMISC::CBitMemStream& impulse);
protected:

	/// Functions used to be able to create the camera animation steps players
	static void init();
	virtual ICameraAnimationStepPlayer* instanciate() = 0;
	static std::vector<std::pair<std::string, ICameraAnimationStepPlayerFactory*> >* Entries;
};

// Define used to register the different types of camera animation steps players
#define CAMERA_ANIMATION_REGISTER_STEP_PLAYER(_class_,_name_) \
class _class_##CameraAnimationStepPlayerFactory : public ICameraAnimationStepPlayerFactory \
{\
public:\
	_class_##CameraAnimationStepPlayerFactory()\
{\
	init();\
	std::string str = std::string(_name_); \
	for (uint i = 0; i < (*Entries).size(); i++ ) \
{\
	if ( (*Entries)[i].first == str || (*Entries)[i].second == this )nlstop;\
}\
	(*Entries).push_back( std::make_pair( str, this ) );\
}\
	ICameraAnimationStepPlayer* instanciate()\
{ \
	return new _class_;\
} \
};\
	static _class_##CameraAnimationStepPlayerFactory* _class_##CameraAnimationStepPlayerFactoryInstance = new _class_##CameraAnimationStepPlayerFactory;


#endif /* RY_CAMERAANIMATIONSTEPPLAYERFACTORY_H */
