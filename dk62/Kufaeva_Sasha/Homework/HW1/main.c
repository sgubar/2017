//
//  main.c
//  S_K
//
//  Created by air on 27.02.17.
//  Copyright © 2017 O_Student. All rights reserved.
//

#include <stdio.h>
#include "first.h"

int main(int argc, const char * argv[]) {
    
char Binar[7];
    
    printf("please Enter the Binar: ");
   
    fgets(Binar,8,stdin);
    

    int Decal = ConvertToDecal(Binar);
    
    printf("Result in Decal: %i\n",Decal);
    return 0;
}
