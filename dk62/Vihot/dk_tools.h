

float modulAB= sqrt(xAB*xAB+yAB*yAB);
float modulBC= sqrt(xBC*xBC+yBC*yBC);
float modulCD= sqrt(xCD*xCD+yCD*yCD);
float modulDA=sqrt(xDA*xDA+yDA*yDA);

float ABDA=xAB*xDA+yAB*yDA;
float BCCD=xBC*xCD+yBC*yCD;
 
float A = ABDA/modulAB*modulDA;
float C = BCCD/	modulBC*modulCD;
float p = (modulAB+modulBC+modulCD+modulDA)/2;
float S = sqrt((p -modulAB )*(p-modulBC)*(p-modulCD)*(p-modulDA)-modulAB*modulBC*modulCD*modulDA*(A*C)/2);
//Основні функції використані в коді.

