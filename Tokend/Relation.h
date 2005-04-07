/*
 *  Copyright (c) 2004 Apple Computer, Inc. All Rights Reserved.
 * 
 *  @APPLE_LICENSE_HEADER_START@
 *  
 *  This file contains Original Code and/or Modifications of Original Code
 *  as defined in and that are subject to the Apple Public Source License
 *  Version 2.0 (the 'License'). You may not use this file except in
 *  compliance with the License. Please obtain a copy of the License at
 *  http://www.opensource.apple.com/apsl/ and read it before using this
 *  file.
 *  
 *  The Original Code and all software distributed under the License are
 *  distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 *  EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 *  INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 *  Please see the License for the specific language governing rights and
 *  limitations under the License.
 *  
 *  @APPLE_LICENSE_HEADER_END@
 */

/*
 *  Relation.h
 *  TokendMuscle
 */

#ifndef _TOKEND_RELATION_H_
#define _TOKEND_RELATION_H_

#include "Record.h"
#include <vector>

namespace Tokend
{	

class MetaRecord;
class Record;

class Relation : public std::vector< RefPointer<Record> >
{
	NOCOPY(Relation)
public:
	Relation(MetaRecord *metaRecord) : mMetaRecord(metaRecord) { }
	~Relation();

	const MetaRecord &metaRecord() const { return *mMetaRecord; }
	MetaRecord &metaRecord() { return *mMetaRecord; }

	void insertRecord(const RefPointer<Record> &record);
	bool matchesId(RelationId inRelationId) const;

protected:
	MetaRecord *mMetaRecord;
};

} // end namespace Tokend

#endif /* !_TOKEND_RELATION_H_ */

/* arch-tag: E936FF49-DF80-11D8-9195-000A95C4302E */
