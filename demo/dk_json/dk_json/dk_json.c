//
//  dk_json.c
//  dk_json_test
//
//  Created by Slava Gubar on 3/6/17.
//  Copyright © 2017 sl_user. All rights reserved.
//

#include "dk_json.h"
#include <stdlib.h>

static char *__dk_json_parse_value(char *aBuffer, char *aKey,
			DK_JSON_Item *aParent);
static char *__dk_json_parse_key(char *aBuffer, char **aKey);

static DK_JSON_Item *__dk_create_json_item(DK_JSON_ItemType aType, char *aKey,
			DK_JSON_Item *aParent);

#pragma mark -
DK_JSON_Item *dk_json_parse(char *aBuffer)
{
	DK_JSON_Item theJSONItem = {0};
	DK_JSON_Item *theResult = NULL;
	
	if (NULL != __dk_json_parse_value(aBuffer, NULL, &theJSONItem))
	{
		theResult = theJSONItem.child;
	}
	else
	{
		if (NULL != theJSONItem.child)
		{
			dk_json_free(theJSONItem.child);
		}
	}

	return theResult;
}

void dk_json_free(DK_JSON_Item *aJSON)
{
	if (NULL != aJSON)
	{
		DK_JSON_Item *theItem = aJSON->child;
		
		while(NULL != theItem)
		{
			DK_JSON_Item *toFree = theItem;
			theItem = theItem->next.nextChild;
			
			dk_json_free(toFree);
		}
		
		free(aJSON);
	}
}

DK_JSON_Item *dk_json_item_for_key(DK_JSON_Item *aJSON, char *aKey)
{
	DK_JSON_Item *theResult = NULL;
	
	return theResult;
}

#pragma mark -
DK_JSON_Item *__dk_create_json_item(DK_JSON_ItemType aType, char *aKey,
			DK_JSON_Item *aParent)
{
	DK_JSON_Item *theItem = (DK_JSON_Item *)malloc(sizeof(DK_JSON_Item));
	
	if (NULL != theItem)
	{
		theItem->type = aType;
		theItem->parent = aParent;
		theItem->key = aKey;
		
		//nextChild like lastChild for the aParent
		if (NULL == aParent->child)
		{
			aParent->child = theItem;
			aParent->next.lastChild = theItem;
		}
		else
		{
			aParent->next.lastChild->next.nextChild = theItem;
			aParent->next.lastChild = theItem;
		}
		
		aParent->childCount ++;
	}
	
	return theItem;
}

char *__dk_json_parse_value(char *aBuffer, char *aKey, DK_JSON_Item *aParent)
{
	DK_JSON_Item *theItem = NULL;
	
	while (NULL != aBuffer)
	{
		switch (*aBuffer)
		{
			case '{':
			{
				theItem = __dk_create_json_item(kDK_JSON_Object_Type, aKey, aParent);
				
				if (NULL == theItem)
				{
					printf ("[JSON_PARSER]. Fail to create OBJECT");
					aBuffer = NULL;
				}
				else
				{
					aBuffer ++;
					
					while (NULL != aBuffer)
					{
						char *theKey = NULL;
						aBuffer = __dk_json_parse_key(aBuffer, &theKey);
					}
				}
				
				break;
			}
			
			default:
				printf ("[JSON_PARSER]. Unsupported symbol!");
				aBuffer = NULL;
		}
	}
	
	return aBuffer;
}

char *__dk_json_parse_key(char *aBuffer, char **aKey)
{
	DK_JSON_Item *theResult = NULL;
	
	return aBuffer;
}
