/*Program to Convert A matrix to Row Echelon Form*/
/*Assignment 1*/
/*Written by Chavva Bala Meghanath Reddy*/
/*USN:- 01JST19CB009*/
#include<stdio.h>
int main()
{
	int iI,iJ,iK;/*For Loop iterations*/
	int iM,iN,iStep;/*For Rows and columns*/
	int iP,iQ;/*For rows and columns to output the steps*/
	int iR1,iR2;/*For Row Exchange*/
	float fArray[50][50];/*For Array Declaration*/
	float fDivider,fMultiplier,fTemp;/*Manipulating the Array elements*/

	printf("Enter the number of rows:\t");
	scanf("%d",&iM);
	printf("Enter the number of columns:\t");
	scanf("%d",&iN);
	printf("Enter the Matrix:\n");
		for(iI=0;iI<iM;iI++)
		{
			for(iJ=0;iJ<iN;iJ++)
			{
				scanf("%f",&fArray[iI][iJ]);
			}
		}
	printf("\n");
	printf("The Matrix is:\n");
		for(iI=0;iI<iM;iI++)
		{
			for(iJ=0;iJ<iN;iJ++)
			{
				printf("%f\t",fArray[iI][iJ]);
			}
		printf("\n");
		}
		iStep=1;
		for(iI=0;iI<iM;iI++)
		{
            if(fArray[iI][iI]==0&&iI!=iN)
            {
                iR1=iI;
                for(iJ=iI+1;iJ<iM;iJ++)
                {
                    if(fArray[iJ][iI]!=0)
                    {
                        iR2=iJ;
                        break;
                    }
                }
                for(iJ=0;iJ<iN;iJ++)
                {
                    fTemp=fArray[iR2][iJ];
                    fArray[iR2][iJ]=fArray[iR1][iJ];
                    fArray[iR1][iJ]=fTemp;
                }
                printf("\nStep %d:\n",iStep);
                for(iP=0;iP<iM;iP++)
                {
                    for(iQ=0;iQ<iN;iQ++)
                    {
                        printf("%f\t",fArray[iP][iQ]);
                    }
                    printf("\n");
                }
                printf("\n");
                iStep++;
            }
			fDivider=fArray[iI][iI];
			if(fDivider!=0)
            {
                for(iJ=0;iJ<iN;iJ++)
                {
                    fArray[iI][iJ]=fArray[iI][iJ]/fDivider;
                }
                printf("\nStep %d:\n",iStep);
                for(iP=0;iP<iM;iP++)
                {
                    for(iQ=0;iQ<iN;iQ++)
                    {
                        printf("%f\t",fArray[iP][iQ]);
                    }
                    printf("\n");
                }
                printf("\n");
                iStep++;
                for(iK=iI+1;iK<iM;iK++)
                {
                    fMultiplier=fArray[iK][iI];
                    for(iJ=iI;iJ<iN;iJ++)
                    {
                        fArray[iK][iJ]=fArray[iK][iJ]-(fArray[iI][iJ]*fMultiplier);
                    }
                     printf("\nStep %d:\n",iStep);
                    for(iP=0;iP<iM;iP++)
                    {
                        for(iQ=0;iQ<iN;iQ++)
                        {
                            printf("%f\t",fArray[iP][iQ]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    iStep++;
                    }
            }
	}
getch();
return 0;
}
