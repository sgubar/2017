//
// Created by Max on 04.04.2017.
//

#include "sort.h"

void BubbleSorT(SpskOfTrK *TagSpskOfTrK)
{
    for(int i=TagSpskOfTrK->CurrentTrK-1; i>1; i--)
    {
        for(int j=0; j<i; j++)
        {
            if(ObchislennyaPloschi(&TagSpskOfTrK->TrK[j])>ObchislennyaPloschi(&TagSpskOfTrK->TrK[j+1]))
            {
                Trykutnyk FlaG=TagSpskOfTrK->TrK[j];
                TagSpskOfTrK->TrK[j]=TagSpskOfTrK->TrK[j+1];
                TagSpskOfTrK->TrK[j+1]=FlaG;
            }
        }
    }
}

void SelectionSorT(SpskOfTrK *TagSpskOfTrK)
{
    for(int i=0; i<TagSpskOfTrK->CurrentTrK-1; i++)
    {
        int TheMiN=i;
        for(int j=i+1; j<TagSpskOfTrK->CurrentTrK; j++)
        {
            if (ObchislennyaPloschi(&TagSpskOfTrK->TrK[j])<ObchislennyaPloschi(&TagSpskOfTrK->TrK[TheMiN]))
            {
                TheMiN=j;
            }
        }
        Trykutnyk FlaG=TagSpskOfTrK->TrK[i];
        TagSpskOfTrK->TrK[i]=TagSpskOfTrK->TrK[TheMiN];
        TagSpskOfTrK->TrK[TheMiN]=FlaG;
    }
}

void InsertionSorT(SpskOfTrK *TagSpskOfTrK)
{
    for(int i=1; i<TagSpskOfTrK->CurrentTrK; i++)
    {
        Trykutnyk FlaG=TagSpskOfTrK->TrK[i];
        int j=i;
        while(j>0&&ObchislennyaPloschi(&TagSpskOfTrK->TrK[j-1])>=ObchislennyaPloschi(&FlaG))
        {
            TagSpskOfTrK->TrK[j]=TagSpskOfTrK->TrK[j-1];
            --j;
        }
        TagSpskOfTrK->TrK[j]=FlaG;
    }
}

void shellSort(SpskOfTrK *TagSpskOfTrK)
{
    int theInner=0;
    int theOuter=0;
    int theH=1;
    while(theH<=((TagSpskOfTrK->CurrentTrK)/3))
    {
        theH=theH*3+1;
    }
    while(theH>0)
    {
        for(theOuter=theH; theOuter<TagSpskOfTrK->CurrentTrK; theOuter++)
        {
            Trykutnyk theTmp=TagSpskOfTrK->TrK[theOuter];
            theInner=theOuter;
            while(theInner>theH-1&&ObchislennyaPloschi(&TagSpskOfTrK->TrK[theInner-theH])>=ObchislennyaPloschi(&theTmp))
            {
                TagSpskOfTrK->TrK[theInner]=TagSpskOfTrK->TrK[theInner-theH];
                theInner-=theH;
            }
            TagSpskOfTrK->TrK[theInner]=theTmp;
        }
        theH=(theH-1)/3;
    }
}

int line_find(SpskOfTrK *TagSpskOfTrK, int aKey)
{
    int theResult=-1;
    for(int i=0; i<TagSpskOfTrK->CurrentTrK; i++)
    {
        if(ObchislennyaPloschi(&TagSpskOfTrK->TrK[i])==aKey)
        {
            theResult=i;
            break;
        }
    }
    return theResult;
}

