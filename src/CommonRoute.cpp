/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit 
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any 
number of times.
Output :
Return a Common Route String which covers maxiumum Islands 

Example 1 : 
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ" 
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation : 
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs 
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before 
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB 
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost ) 
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>


char * find_common_route(char * hacklist, char *codelist, int *cost){
	if (hacklist == NULL || codelist == NULL)
		return NULL;
	*cost = 0;
	char start = 'a';
	int i, j, len = 0, pos = 0;
	for (i = 0; hacklist[i] != '\0'; i++)
	{
		for (j = 0; codelist[j] != '\0'; j++)
		{
			if (hacklist[i] == codelist[j])
			{
				int pos1 = i, pos2 = j;
				int currcost = 0; char currstart = hacklist[i], currlen = 0;
				while (hacklist[pos1] == codelist[pos2] && hacklist[pos1] != '\0'&&codelist[pos2] != '\0')
				{
					currcost += hacklist[pos1] - 65 + 1;
					currlen++;
					pos1++;
					pos2++;
				}
				if (currlen>len)
				{
					*cost = currcost;
					start = currstart;
					pos = i;
					len = currlen;
					break;
				}
				if (currlen == len)
				{
					if (currcost<*cost)
					{
						*cost = currcost;
						start = currstart;
						pos = i;
						len = currlen;
						break;
					}
					if (currcost == *cost&&currstart<start)
					{
						*cost = currcost;
						start = currstart;
						pos = i;
						len = currlen;
						break;
					}
				}
				break;

			}
		}
	}
	char *common = (char *)malloc((len + 1)*sizeof(char));
	for (i = 0; i<len; i++)
	{
		common[i] = hacklist[pos++];
	}
	common[i] = '\0';
	return common;

}

