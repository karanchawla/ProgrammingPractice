#include <stdio.h>

int secondHighest(int *a, int size){
	int high = a[0];
	int shigh = a[1];
	for (int i=1;i<size;i++){
		if(a[i]>high){
			shigh = high;
			high = a[i]; 
		}
		if(a[i]>shigh && a[i]<high){
			shigh = a[i];
		} 

	}
	return high;
}

int main(void){
	int a[] = {28,188,329,327,72,33,130,270,110,150,335,166,132,123,92,331,222,293,55,302,221,281,230,172,217,109,154,247,334,256,195,36,297,283,182,175,332,45,316,206,37,227,314,174,75,322,319,120,264,103,179,74,300,165,299,324,213,290,162,177,79,34,338,192,156,180,73,301,223,276,114,232,52,155,157,268,95,304,159,160,163,214,47,25,246,243,191,124,50,279,101,63,70,347,39,149,184,62,185,77,225,196,269,202,125,41,280,215,210,266,310,197,343,51,234,53,119,272,48,250,143,326,287,84,139,56,118,323,207,284,32,96,292,148,286,229,83,330,209,176,193,82,76,321,105,67,265,261,142,66,260,68,57,140,58,341,27,40,183,90,311,282,346,31,198,226,134,80,337,133,152,86,255,205,94,263,274,100,78,224,71,131,325,112,170,88,254,54,212,267,248,308,219,307,87,104,305,249,278,147,153,339,333,108,129,106,107,228,49,164,38,42,313,262,336,91,208,296,277,64,190,201,113,271,245,144,60,252,244,303,178,111,291,315,115,318,204,241,128,181,294,317,126,69,220,235,116,320,29,238,173,200,169,342,289,167,30,85,251,345,189,240,253,59,135,312,194,239,65,151,136,237,46,242,102,44,122,285,127,161,273,288,187,218,121,81,138,98,203,141,344,295,233,158,171,186,99,199,236,61,258,43,275,93,168,35,259,145,146,137,211,89,328,216,340,117,97,26,231,257,306,309,298};
	int size =sizeof(a)/sizeof(a[0]);
	printf("%d\n", secondHighest(a,size));
}