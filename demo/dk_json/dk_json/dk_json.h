//
//  dk_json.h
//  dk_json_test
//
//  Created by Slava Gubar on 3/6/17.
//  Copyright © 2017 sl_user. All rights reserved.
//

#ifndef dk_json_h
#define dk_json_h

#include <stdio.h>

typedef enum tagJSONItemType
{
	kDK_JSON_Unknown_Type = -1,
	kDK_JSON_NULL_Type = 0,
	kDK_JSON_Int_Type,
	kDK_JSON_Double_Type,
	kDK_JSON_Bool_Type,
	kDK_JSON_String_Type,
	kDK_JSON_Object_Type,
	kDK_JSON_Array_Type
} DK_JSON_ItemType;

typedef struct tagJSONItem DK_JSON_Type;

typedef struct tagJSONItem
{
	DK_JSON_ItemType type;
	char *key;
	
	DK_JSON_Type *parent;
	DK_JSON_Type *child;
	long childCount;
	union {
	
		DK_JSON_Type *nextChild;
		DK_JSON_Type *lastChild;
	
	} next;
	
	union {
		int intValue;
		double doubleValue;
		char *stringValue;
	} value;
	
}DK_JSON_Item;

DK_JSON_Item *dk_json_parse(char *aBuffer);
void dk_json_free(DK_JSON_Item *aJSON);

DK_JSON_Item *dk_json_item_for_key(DK_JSON_Item *aJSON, char *aKey);

#endif /* dk_json_h */
