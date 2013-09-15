/****************************************************************************

 This file is part of the GLC-lib library.
 Copyright (C) 2005-2008 Laurent Ribon (laumaya@users.sourceforge.net)
 http://glc-lib.sourceforge.net

 GLC-lib is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.

 GLC-lib is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with GLC-lib; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*****************************************************************************/

//! \file GLC_object.h Interface for the GLC_Object class.

#ifndef GLC_OBJECT_H_
#define GLC_OBJECT_H_

#include <QtOpenGL>
#include <QString>
#include <QUuid>
#include <QMutex>
#include "glc_global.h"

#include "glc_config.h"

//////////////////////////////////////////////////////////////////////
//! \class GLC_Object
/*! \brief GLC_Object is base class for some GLC class*/

/*! GLC_Object is a abstract class. \n \n
 *  Every GLC_Object have :
 *		- unique ID #m_Uid generated by #GLC_GenID
 *		- virtual OpenGL method GLC_Object::glExecute
 */
//////////////////////////////////////////////////////////////////////

class GLC_LIB_EXPORT GLC_Object
{
//////////////////////////////////////////////////////////////////////
/*! @name Constructor / Destructor */
//@{
//////////////////////////////////////////////////////////////////////
public:

	//! Default constructor
	/*! Construct a GLC_Object , Generate is UID GLC_Object::m_Uid
	 * and set GLC_Object::m_Name to specified name*/
	GLC_Object(const QString& name= QString());

	//! Construct a GLC_Object with the given UID
	GLC_Object(GLC_uint id, const QString& name= QString());

	//! Construct a GLC_Object from the given GLC_Object
	GLC_Object(const GLC_Object& sourceObject);

	//! Virtual destructor
	virtual ~GLC_Object();
//@}

//////////////////////////////////////////////////////////////////////
/*! \name Get Functions*/
//@{
//////////////////////////////////////////////////////////////////////
public:
	//! Return this object id
	inline GLC_uint id() const
	{return m_Uid;}

	//! Return this object name
	inline const QString name() const
	{return m_Name;}

	//! Return true if this object is equal to the given object
	inline bool operator == (const GLC_Object& obj)
	{return (m_Uid == obj.m_Uid) && (m_Name == obj.m_Name);}
//@}

//////////////////////////////////////////////////////////////////////
/*! \name Set Functions*/
//@{
//////////////////////////////////////////////////////////////////////
public:

	//! Set this object Id
	/*! This method is thread safe*/
	void setId(const GLC_uint id);

	//! Set this object Name
	/*! This method is thread safe*/
	void setName(const QString& name);

	//! Set this object from the given object
	/*! This method is thread safe*/
	GLC_Object &operator=(const GLC_Object&);

//@}


//////////////////////////////////////////////////////////////////////
// Protected member
//////////////////////////////////////////////////////////////////////

protected:
	//! The Unique ID of an GLC_Object
	/*! Generated on GLC_Object creation*/
	GLC_uint m_Uid;

	//! Name of an GLC_Object
	QString m_Name;

	//! GLC_Object Mutex
	QMutex m_Mutex;
};
#endif //GLC_OBJECT_H_
